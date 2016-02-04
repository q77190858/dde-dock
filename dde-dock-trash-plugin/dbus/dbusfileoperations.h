/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusFileOperations -p dbusfileoperations com.deepin.filemanager.Backend.Operations.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSFILEOPERATIONS_H_1437701966
#define DBUSFILEOPERATIONS_H_1437701966

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.filemanager.Backend.Operations
 */
class DBusFileOperations: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.filemanager.Backend.Operations")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        foreach(const QString &prop, changedProps.keys()) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
 	            Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticServerPath()
    { return "com.deepin.filemanager.Backend.Operations"; }
    static inline const char *staticInterfacePath()
    { return "/com/deepin/filemanager/Backend/Operations"; }
    static inline const char *staticInterfaceName()
    { return "com.deepin.filemanager.Backend.Operations"; }

public:
    DBusFileOperations(QObject *parent = 0);

    ~DBusFileOperations();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewChmodJob(const QString &in0, uint in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("NewChmodJob"), argumentList);
    }
    inline QDBusReply<QString> NewChmodJob(const QString &in0, uint in1, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewChmodJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewChownJob(const QString &in0, const QString &in1, const QString &in2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        return asyncCallWithArgumentList(QStringLiteral("NewChownJob"), argumentList);
    }
    inline QDBusReply<QString> NewChownJob(const QString &in0, const QString &in1, const QString &in2, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewChownJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewCopyJob(const QStringList &in0, const QString &in1, const QString &in2, uint in3, const QString &in4, const QString &in5, const QString &in6)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5) << QVariant::fromValue(in6);
        return asyncCallWithArgumentList(QStringLiteral("NewCopyJob"), argumentList);
    }
    inline QDBusReply<QString> NewCopyJob(const QStringList &in0, const QString &in1, const QString &in2, uint in3, const QString &in4, const QString &in5, const QString &in6, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5) << QVariant::fromValue(in6);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewCopyJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewCreateDirectoryJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        return asyncCallWithArgumentList(QStringLiteral("NewCreateDirectoryJob"), argumentList);
    }
    inline QDBusReply<QString> NewCreateDirectoryJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewCreateDirectoryJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewCreateFileFromTemplateJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        return asyncCallWithArgumentList(QStringLiteral("NewCreateFileFromTemplateJob"), argumentList);
    }
    inline QDBusReply<QString> NewCreateFileFromTemplateJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewCreateFileFromTemplateJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewCreateFileJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, const QString &in5)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5);
        return asyncCallWithArgumentList(QStringLiteral("NewCreateFileJob"), argumentList);
    }
    inline QDBusReply<QString> NewCreateFileJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, const QString &in5, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewCreateFileJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewDeleteJob(const QStringList &in0, bool in1, const QString &in2, const QString &in3, const QString &in4)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        return asyncCallWithArgumentList(QStringLiteral("NewDeleteJob"), argumentList);
    }
    inline QDBusReply<QString> NewDeleteJob(const QStringList &in0, bool in1, const QString &in2, const QString &in3, const QString &in4, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewDeleteJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewEmptyTrashJob(bool in0, const QString &in1, const QString &in2, const QString &in3)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        return asyncCallWithArgumentList(QStringLiteral("NewEmptyTrashJob"), argumentList);
    }
    inline QDBusReply<QString> NewEmptyTrashJob(bool in0, const QString &in1, const QString &in2, const QString &in3, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewEmptyTrashJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewGetAllLaunchAppsJob()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("NewGetAllLaunchAppsJob"), argumentList);
    }
    inline QDBusReply<QString> NewGetAllLaunchAppsJob(QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewGetAllLaunchAppsJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewGetDefaultLaunchAppJob(const QString &in0, bool in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("NewGetDefaultLaunchAppJob"), argumentList);
    }
    inline QDBusReply<QString> NewGetDefaultLaunchAppJob(const QString &in0, bool in1, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewGetDefaultLaunchAppJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewGetRecommendedLaunchAppsJob(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("NewGetRecommendedLaunchAppsJob"), argumentList);
    }
    inline QDBusReply<QString> NewGetRecommendedLaunchAppsJob(const QString &in0, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewGetRecommendedLaunchAppsJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewGetTemplateJob()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("NewGetTemplateJob"), argumentList);
    }
    inline QDBusReply<QString> NewGetTemplateJob(QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewGetTemplateJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewLinkJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        return asyncCallWithArgumentList(QStringLiteral("NewLinkJob"), argumentList);
    }
    inline QDBusReply<QString> NewLinkJob(const QString &in0, const QString &in1, const QString &in2, const QString &in3, const QString &in4, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewLinkJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewListJob(const QString &in0, int in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("NewListJob"), argumentList);
    }
    inline QDBusReply<QString> NewListJob(const QString &in0, int in1, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewListJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewMoveJob(const QStringList &in0, const QString &in1, const QString &in2, uint in3, const QString &in4, const QString &in5, const QString &in6)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5) << QVariant::fromValue(in6);
        return asyncCallWithArgumentList(QStringLiteral("NewMoveJob"), argumentList);
    }
    inline QDBusReply<QString> NewMoveJob(const QStringList &in0, const QString &in1, const QString &in2, uint in3, const QString &in4, const QString &in5, const QString &in6, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4) << QVariant::fromValue(in5) << QVariant::fromValue(in6);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewMoveJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewRenameJob(const QString &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("NewRenameJob"), argumentList);
    }
    inline QDBusReply<QString> NewRenameJob(const QString &in0, const QString &in1, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewRenameJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewSetDefaultLaunchAppJob(const QString &in0, const QString &in1)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        return asyncCallWithArgumentList(QStringLiteral("NewSetDefaultLaunchAppJob"), argumentList);
    }
    inline QDBusReply<QString> NewSetDefaultLaunchAppJob(const QString &in0, const QString &in1, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewSetDefaultLaunchAppJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewStatJob(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("NewStatJob"), argumentList);
    }
    inline QDBusReply<QString> NewStatJob(const QString &in0, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewStatJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

    inline QDBusPendingReply<QString, QDBusObjectPath, QString> NewTrashJob(const QStringList &in0, bool in1, const QString &in2, const QString &in3, const QString &in4)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        return asyncCallWithArgumentList(QStringLiteral("NewTrashJob"), argumentList);
    }
    inline QDBusReply<QString> NewTrashJob(const QStringList &in0, bool in1, const QString &in2, const QString &in3, const QString &in4, QDBusObjectPath &out1, QString &out2)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3) << QVariant::fromValue(in4);
        QDBusMessage reply = callWithArgumentList(QDBus::Block, QStringLiteral("NewTrashJob"), argumentList);
        if (reply.type() == QDBusMessage::ReplyMessage && reply.arguments().count() == 3) {
            out1 = qdbus_cast<QDBusObjectPath>(reply.arguments().at(1));
            out2 = qdbus_cast<QString>(reply.arguments().at(2));
        }
        return reply;
    }

Q_SIGNALS: // SIGNALS
// begin property changed signals
};

namespace com {
  namespace deepin {
    namespace filemanager {
//      namespace Backend {
//        typedef ::DBusFileOperations Operations;
//      }
    }
  }
}
#endif
