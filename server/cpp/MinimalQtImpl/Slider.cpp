#include "generated/Slider.h"
#include "SliderInternal.h"

#define THIS (reinterpret_cast<QSlider*>(_this))

namespace Slider
{
    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        THIS->setTickInterval(interval);
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QSlider());
    }
}
