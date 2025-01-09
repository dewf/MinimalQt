#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"

#define THIS (reinterpret_cast<QRadioButton*>(_this))

namespace RadioButton
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QRadioButton());
    }
}
