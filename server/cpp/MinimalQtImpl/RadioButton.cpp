#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QRadioButton*>(_this))

namespace RadioButton
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRadioButton(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRadioButton(QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }
}
