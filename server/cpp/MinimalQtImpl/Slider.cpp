#include "generated/Slider.h"
#include "SliderInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QSlider*>(_this))

namespace Slider
{
    int32_t Handle_tickInterval(HandleRef _this) {
        return THIS->tickInterval();
    }

    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        THIS->setTickInterval(interval);
    }

    TickPosition Handle_tickPosition(HandleRef _this) {
        return static_cast<TickPosition>(THIS->tickPosition());
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QSlider(Widget::fromOptionalHandle(parent)));
    }

    HandleRef create(Orientation orientation, const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QSlider(static_cast<Qt::Orientation>(orientation), Widget::fromOptionalHandle(parent)));
    }
}
