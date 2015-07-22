#include "panel.h"
#include "dockpluginproxy.h"
#include "dockpluginmanager.h"
#include "Controller/dockmodedata.h"
#include <QHBoxLayout>

Panel::Panel(QWidget *parent)
    : QLabel(parent),parentWidget(parent)
{
    this->setObjectName("Panel");

    rightLayout = new DockLayout(this);
    rightLayout->setSortDirection(DockLayout::RightToLeft);
    rightLayout->setSpacing(dockCons->getAppletsItemSpacing());
    rightLayout->resize(0,dockCons->getItemHeight());

    leftLayout = new DockLayout(this);
    leftLayout->setSpacing(dockCons->getAppItemSpacing());
    leftLayout->resize(this->width() - rightLayout->width(),dockCons->getItemHeight());
    leftLayout->move(0,1);

    connect(leftLayout, &DockLayout::dragStarted, this, &Panel::slotDragStarted);
    connect(leftLayout, &DockLayout::itemDropped, this, &Panel::slotItemDropped);
    connect(leftLayout, &DockLayout::contentsWidthChange, this, &Panel::slotLayoutContentsWidthChanged);
    connect(rightLayout, &DockLayout::contentsWidthChange, this, &Panel::slotLayoutContentsWidthChanged);

    connect(dockCons, &DockModeData::dockModeChanged, this, &Panel::changeDockMode);

    DockPluginManager *pluginManager = new DockPluginManager(this);

    connect(dockCons, &DockModeData::dockModeChanged, pluginManager, &DockPluginManager::onDockModeChanged);
    connect(pluginManager, &DockPluginManager::itemAdded, [=](AbstractDockItem* item) {
        rightLayout->addItem(item);
    });
    connect(pluginManager, &DockPluginManager::itemRemoved, [=](AbstractDockItem* item) {
        int index = rightLayout->indexOf(item);
        if (index != -1) {
            rightLayout->removeItem(index);
        }
    });

    pluginManager->initAll();

    initAppManager();
    initHSManager();
    initState();

    //TODO ,move panel to center on fashion mode
    QTimer::singleShot(10, [=](){
        reanchorsLayout(dockCons->getDockMode());
    });

    updateBackground();
}

void Panel::showScreenMask()
{
//    qWarning() << "[Info:]" << "Show Screen Mask.";
    maskWidget = new ScreenMask();
    connect(maskWidget,SIGNAL(itemDropped(QPoint)),this,SLOT(slotItemDropped()));
    connect(maskWidget,SIGNAL(itemEntered()),this,SLOT(slotEnteredMask()));
    connect(maskWidget,SIGNAL(itemExited()),this,SLOT(slotExitedMask()));
}

bool Panel::isFashionMode()
{
    return m_isFashionMode;
}

void Panel::hideScreenMask()
{
//    qWarning() << "[Info:]" << "Hide Screen Mask.";
    disconnect(maskWidget,SIGNAL(itemDropped(QPoint)),this,SLOT(slotItemDropped()));
    disconnect(maskWidget,SIGNAL(itemEntered()),this,SLOT(slotEnteredMask()));
    disconnect(maskWidget,SIGNAL(itemExited()),this,SLOT(slotExitedMask()));
    maskWidget->hide();
    maskWidget->deleteLater();
    maskWidget = NULL;
}

void Panel::slotDragStarted()
{
    showScreenMask();
}

void Panel::slotItemDropped()
{
    hideScreenMask();
    leftLayout->clearTmpItem();
    leftLayout->relayout();
}

void Panel::slotEnteredMask()
{
    leftLayout->relayout();
}

void Panel::slotExitedMask()
{
    leftLayout->relayout();
}

void Panel::changeDockMode(Dock::DockMode newMode, Dock::DockMode oldMode)
{
    updateBackground();

    if (dockCons->getDockMode() == Dock::FashionMode)
    {
        leftLayout->setVerticalAlignment(DockLayout::AlignTop);
        rightLayout->setVerticalAlignment(DockLayout::AlignTop);
    }
    else
    {
        leftLayout->setVerticalAlignment(DockLayout::AlignVCenter);
        rightLayout->setVerticalAlignment(DockLayout::AlignVCenter);
    }

    leftLayout->relayout();
    rightLayout->relayout();

    reanchorsLayout(newMode);

    qWarning() << "AppCount:********" << leftLayout->getItemCount();
}

void Panel::slotLayoutContentsWidthChanged()
{
    reanchorsLayout(dockCons->getDockMode());
}

void Panel::slotAddAppItem(AbstractDockItem *item)
{
    leftLayout->addItem(item);
}

void Panel::slotRemoveAppItem(const QString &id)
{
    QList<AbstractDockItem *> tmpList = leftLayout->getItemList();
    for (int i = 0; i < tmpList.count(); i ++)
    {
        AppItem *tmpItem = qobject_cast<AppItem *>(tmpList.at(i));
        if (tmpItem && tmpItem->itemId() == id)
        {
            leftLayout->removeItem(i);
            return;
        }
    }
}

void Panel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
        showMenu();
}

void Panel::mouseReleaseEvent(QMouseEvent *event)
{

}

void Panel::reanchorsLayout(Dock::DockMode mode)
{
    if (mode == Dock::FashionMode)
    {
        leftLayout->resize(leftLayout->getContentsWidth() + dockCons->getAppItemSpacing(),dockCons->getItemHeight());
        rightLayout->setSortDirection(DockLayout::LeftToRight);
        rightLayout->resize(rightLayout->getContentsWidth(),dockCons->getItemHeight());
        this->setFixedSize(FASHION_PANEL_LPADDING
                           + FASHION_PANEL_RPADDING
                           + leftLayout->getContentsWidth()
                           + rightLayout->getContentsWidth()
                           ,dockCons->getDockHeight());
        leftLayout->move(FASHION_PANEL_LPADDING,1);

        rightLayout->move(leftLayout->x() + leftLayout->width() - dockCons->getAppItemSpacing(),1);
        this->move((parentWidget->width() - width()) / 2,0);
    }
    else
    {
        rightLayout->setSortDirection(DockLayout::RightToLeft);
        rightLayout->resize(rightLayout->getContentsWidth(),dockCons->getItemHeight());
        rightLayout->move(parentWidget->width() - rightLayout->width(),1);

        leftLayout->move(0,1);
        leftLayout->resize(parentWidget->width() - rightLayout->width() ,dockCons->getItemHeight());

        this->setFixedSize(leftLayout->width() + rightLayout->width(),dockCons->getDockHeight());
        this->move((parentWidget->width() - leftLayout->width() - rightLayout->width()) / 2,0);
    }
}

void Panel::showMenu()
{
    QPoint tmpPos = QCursor::pos();

    PanelMenu::instance()->showMenu(tmpPos.x(),tmpPos.y());
}

void Panel::updateBackground()
{
    m_isFashionMode = dockCons->getDockMode() == Dock::FashionMode;

    style()->unpolish(this);
    style()->polish(this);// force a stylesheet recomputation
}

void Panel::initAppManager()
{
    m_appManager = new AppManager(this);
    connect(m_appManager,SIGNAL(entryAdded(AbstractDockItem*)),this, SLOT(slotAddAppItem(AbstractDockItem*)));
    connect(m_appManager, SIGNAL(entryRemoved(QString)),this, SLOT(slotRemoveAppItem(QString)));
    m_appManager->updateEntries();
}

void Panel::hasShown()
{
    m_HSManager->SetState(1);
    emit panelHasShown();
}

void Panel::hasHidden()
{
    m_HSManager->SetState(3);
    emit panelHasHidden();
}

void Panel::hideStateChanged(int value)
{
    if (value == 0)
    {
        emit startShow();
    }
    else if (value == 1)
    {
        emit startHide();
    }
}

void Panel::initHSManager()
{
    m_HSManager = new DBusHideStateManager(this);
    connect(m_HSManager,&DBusHideStateManager::ChangeState,this,&Panel::hideStateChanged);
}

void Panel::initState()
{
    QStateMachine * machine = new QStateMachine(this);
    QState * showState = new QState(machine);
    showState->assignProperty(this,"pos",QPoint(0,0));
    QState * hideState = new QState(machine);
    hideState->assignProperty(this,"pos",QPoint(0,height()));

    machine->setInitialState(showState);

    QPropertyAnimation *sa = new QPropertyAnimation(this, "pos");
    sa->setDuration(200);
    sa->setEasingCurve(QEasingCurve::InSine);
    connect(sa,&QPropertyAnimation::finished,this,&Panel::hasShown);

    QPropertyAnimation *ha = new QPropertyAnimation(this, "pos");
    ha->setDuration(200);
    ha->setEasingCurve(QEasingCurve::InSine);
    connect(ha,&QPropertyAnimation::finished,this,&Panel::hasHidden);

    QSignalTransition *ts1 = showState->addTransition(this,SIGNAL(startHide()), hideState);
    ts1->addAnimation(ha);
    connect(ts1,&QSignalTransition::triggered,[=](int value = 2){
        m_HSManager->SetState(value);
    });
    QSignalTransition *ts2 = hideState->addTransition(this,SIGNAL(startShow()),showState);
    ts2->addAnimation(sa);
    connect(ts2,&QSignalTransition::triggered,[=](int value = 0){
        m_HSManager->SetState(value);
    });

    machine->start();
}

Panel::~Panel()
{

}

