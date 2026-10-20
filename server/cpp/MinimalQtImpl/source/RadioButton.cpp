#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"

#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::AbstractButton;

#define THIS (reinterpret_cast<QRadioButton*>(_this))

namespace RadioButton
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto radio = AS_QRADIOBUTTON_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(radio);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(radio);
        case Handle_CastTarget::AbstractButton_Handle:
            return static_cast<QAbstractButton*>(radio);
            break;
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRadioButton(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRadioButton(QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }
}
