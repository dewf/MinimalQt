#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define RADIOBUTTON_THIS (WRAPPER->getActual())

namespace RadioButton
{
    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QRadioButton(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
