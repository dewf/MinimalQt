#include "generated/Slider.h"
#include "SliderInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define SLIDER_THIS (WRAPPER->getActual())

namespace Slider
{
    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        SLIDER_THIS->setTickInterval(interval);
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        SLIDER_THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QSlider(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
