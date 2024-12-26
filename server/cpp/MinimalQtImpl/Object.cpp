#include "generated/Object.h"
#include "ObjectInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define OBJECT_THIS (WRAPPER->getActual())

namespace Object
{
    std::string Handle_objectName(HandleRef _this) {
        return OBJECT_THIS->objectName().toStdString();
    }

    void Handle_setObjectName(HandleRef _this, const std::string& name) {
        OBJECT_THIS->setObjectName(QString::fromStdString(name));
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        OBJECT_THIS->setParent(reinterpret_cast<QObject*>(parent));
    }

    void Handle_dumpObjectTree(HandleRef _this) {
        OBJECT_THIS->dumpObjectTree();
    }
}
