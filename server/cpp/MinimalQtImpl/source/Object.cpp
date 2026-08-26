#include "generated/Object.h"
#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QObject*>(_this))

namespace Object
{
    std::string Handle_objectName(HandleRef _this) {
        return THIS->objectName().toStdString();
    }

    void Handle_setObjectName(HandleRef _this, const std::string& name) {
        THIS->setObjectName(QString::fromStdString(name));
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        const auto qParent = reinterpret_cast<QObject*>(parent);
        THIS->setParent(qParent);
    }

    void Handle_dumpObjectTree(HandleRef _this) {
        THIS->dumpObjectTree();
    }

    void Handle_deleteLater(HandleRef _this) {
        THIS->deleteLater();
    }

    SignalConnectionRef Handle_connect_DestroyedByQt(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QObject::destroyed, [handler](QObject *obj) {
            handler->sig_destroyedByQt();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Destroyed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QObject::destroyed, [handler](QObject *obj) {
            handler->sig_destroyed(reinterpret_cast<HandleRef>(obj));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ObjectNameChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QObject::objectNameChanged, [handler](const QString& name) {
            handler->sig_objectNameChanged(name.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void disconnect(SignalConnectionRef connection) {
        QObject::disconnect(connection->qConnection);
        delete connection;
    }
}
