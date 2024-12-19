#include "generated/Frame.h"
#include "FrameInternal.h"

#include <QFrame>

#include "util/convert.h"

#define THIS ((FrameWithHandler*)_this)

namespace Frame
{
    class FrameWithHandler : public QFrame {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit FrameWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setFrameRect(HandleRef _this, Rect rect) {
        THIS->setFrameRect(toQRect(rect));
    }

    void Handle_setFrameShadow(HandleRef _this, Shadow shadow) {
        THIS->setFrameShadow(static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_setFrameShape(HandleRef _this, Shape shape) {
        THIS->setFrameShape(static_cast<QFrame::Shape>(shape));
    }

    int32_t Handle_frameWidth(HandleRef _this) {
        return THIS->frameWidth();
    }

    void Handle_setLineWidth(HandleRef _this, int32_t width) {
        THIS->setLineWidth(width);
    }

    void Handle_setMidLineWidth(HandleRef _this, int32_t width) {
        THIS->setMidLineWidth(width);
    }

    void Handle_setFrameStyle(HandleRef _this, Shape shape, Shadow shadow) {
        THIS->setFrameStyle(static_cast<QFrame::Shape>(shape) | static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new FrameWithHandler(handler));
    }
}

#include "Frame.moc"
