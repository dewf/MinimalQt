#include "generated/Object.h"
#include "ObjectInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define OBJECT_THIS (WRAPPER->getActual())

namespace Object
{
    std::map<QObject*, SignalWrapper*> SignalWrapper::objectToWrapperMap;

    SignalWrapper *wrapperForQObject(QObject *obj) {
        if (SignalWrapper::objectToWrapperMap.contains(obj)) {
            return SignalWrapper::objectToWrapperMap[obj];
        }
        return nullptr;
    }

    std::string Handle_objectName(HandleRef _this) {
        return OBJECT_THIS->objectName().toStdString();
    }

    void Handle_setObjectName(HandleRef _this, const std::string& name) {
        OBJECT_THIS->setObjectName(QString::fromStdString(name));
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        const auto parentWrapper = reinterpret_cast<SignalWrapper*>(parent);
        OBJECT_THIS->setParent(parentWrapper->getActual());
    }

    void Handle_dumpObjectTree(HandleRef _this) {
        OBJECT_THIS->dumpObjectTree();
    }
}
