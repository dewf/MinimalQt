#include "generated/Slider.h"
#include "SliderInternal.h"

#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::AbstractSlider;

#define THIS (reinterpret_cast<QSlider*>(_this))

namespace Slider
{
    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        THIS->setTickInterval(interval);
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    int32_t Handle_tickInterval(HandleRef _this) {
        return THIS->tickInterval();
    }

    TickPosition Handle_tickPosition(HandleRef _this) {
        return static_cast<TickPosition>(THIS->tickPosition());
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto slider = AS_QSLIDER_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(slider);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(slider);
        case Handle_CastTarget::AbstractSlider_Handle:
            return static_cast<QAbstractSlider*>(slider);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSlider(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Orientation orientation, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QSlider(static_cast<Qt::Orientation>(orientation), AS_QWIDGET_PTR(parent)));
    }
}
