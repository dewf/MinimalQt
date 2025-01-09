#include "generated/Object.h"
#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QObject*>(_this))

namespace Object
{
    void SignalConnection_dispose(SignalConnectionRef _this) {
        delete _this;
    }

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
}
