
include(../../interfaces/interfaces.pri)

QT              += widgets svg dbus
TEMPLATE         = lib
CONFIG          += plugin c++11 link_pkgconfig
PKGCONFIG       += dtkbase dtkwidget

TARGET          = $$qtLibraryTarget(sound)
DESTDIR          = $$_PRO_FILE_PWD_/../
DISTFILES       += sound.json

HEADERS += \
    soundplugin.h \
    sounditem.h \
    soundapplet.h \
    dbus/dbusaudio.h \
    dbus/dbussink.h \
    horizontalseparator.h

SOURCES += \
    soundplugin.cpp \
    sounditem.cpp \
    soundapplet.cpp \
    dbus/dbusaudio.cpp \
    dbus/dbussink.cpp \
    horizontalseparator.cpp

target.path = $${PREFIX}/lib/dde-dock/plugins/
INSTALLS += target

RESOURCES += \
