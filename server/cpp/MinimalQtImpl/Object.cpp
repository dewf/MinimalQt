#include "generated/Object.h"

#include <QObject>

#include "util/SignalStuff.h"

#define THIS ((QObject*)_this)

namespace Object
{
    std::string Handle_objectName(HandleRef _this) {
        return THIS->objectName().toStdString();
    }

    void Handle_setObjectName(HandleRef _this, const std::string& name) {
        THIS->setObjectName(QString::fromStdString(name));
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        THIS->setParent(reinterpret_cast<QObject*>(parent));
    }

    void Handle_dumpObjectTree(HandleRef _this) {
        THIS->dumpObjectTree();
    }
}
