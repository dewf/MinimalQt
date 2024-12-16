#include "generated/Slider.h"

#include <QSlider>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((SliderWithHandler*)_this)

#include "signalrelays/Slider.h"

namespace Slider
{
    class SliderWithHandler : public QSlider {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit SliderWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        THIS->setTickInterval(interval);
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new SliderWithHandler(handler));
    }
}

#include "Slider.moc"
