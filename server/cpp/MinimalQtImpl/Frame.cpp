#include "generated/Frame.h"
#include "FrameInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define FRAME_THIS (WRAPPER->getActual())

namespace Frame
{
    void Handle_setFrameRect(HandleRef _this, Rect rect) {
        FRAME_THIS->setFrameRect(toQRect(rect));
    }

    void Handle_setFrameShadow(HandleRef _this, Shadow shadow) {
        FRAME_THIS->setFrameShadow(static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_setFrameShape(HandleRef _this, Shape shape) {
        FRAME_THIS->setFrameShape(static_cast<QFrame::Shape>(shape));
    }

    int32_t Handle_frameWidth(HandleRef _this) {
        return FRAME_THIS->frameWidth();
    }

    void Handle_setLineWidth(HandleRef _this, int32_t width) {
        FRAME_THIS->setLineWidth(width);
    }

    void Handle_setMidLineWidth(HandleRef _this, int32_t width) {
        FRAME_THIS->setMidLineWidth(width);
    }

    void Handle_setFrameStyle(HandleRef _this, Shape shape, Shadow shadow) {
        FRAME_THIS->setFrameStyle(static_cast<QFrame::Shape>(shape) | static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QFrame(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}

#include "Frame.moc"
