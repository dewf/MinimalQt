#include "generated/PushButton.h"
#include "PushButtonInternal.h"

#define THIS (reinterpret_cast<QPushButton*>(_this))

namespace PushButton
{
    bool Handle_autoDefault(HandleRef _this) {
        return THIS->autoDefault();
    }

    void Handle_setAutoDefault(HandleRef _this, bool value) {
        THIS->setAutoDefault(value);
    }

    bool Handle_isDefault(HandleRef _this) {
        return THIS->isDefault();
    }

    void Handle_setDefault(HandleRef _this, bool value) {
        THIS->setDefault(value);
    }

    bool Handle_isFlat(HandleRef _this) {
        return THIS->isFlat();
    }

    void Handle_setFlat(HandleRef _this, bool value) {
        THIS->setFlat(value);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QPushButton());
    }
}
