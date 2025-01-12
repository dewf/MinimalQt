#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QRadioButton*>(_this))

namespace RadioButton
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QRadioButton(fromOptionalHandle(parent)));
    }

    HandleRef create(const std::string& text, const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QRadioButton(QString::fromStdString(text), fromOptionalHandle(parent)));
    }
}
