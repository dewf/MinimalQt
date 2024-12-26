#include "generated/PushButton.h"
#include "PushButtonInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define PUSHBUTTON_THIS (WRAPPER->getActual())

namespace PushButton
{
    bool Handle_autoDefault(HandleRef _this) {
        return PUSHBUTTON_THIS->autoDefault();
    }

    void Handle_setAutoDefault(HandleRef _this, bool value) {
        PUSHBUTTON_THIS->setAutoDefault(value);
    }

    bool Handle_isDefault(HandleRef _this) {
        return PUSHBUTTON_THIS->isDefault();
    }

    void Handle_setDefault(HandleRef _this, bool value) {
        PUSHBUTTON_THIS->setDefault(value);
    }

    bool Handle_isFlat(HandleRef _this) {
        return PUSHBUTTON_THIS->isFlat();
    }

    void Handle_setFlat(HandleRef _this, bool value) {
        PUSHBUTTON_THIS->setFlat(value);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QPushButton(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
