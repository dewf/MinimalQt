#include "generated/Frame.h"
#include "FrameInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define FRAME_THIS (WRAPPER->getActual())

namespace Frame
{
    Rect Handle_frameRect(HandleRef _this) {
        return toRect(FRAME_THIS->frameRect());
    }

    void Handle_setFrameRect(HandleRef _this, Rect rect) {
        FRAME_THIS->setFrameRect(toQRect(rect));
    }

    Shadow Handle_frameShadow(HandleRef _this) {
        return static_cast<Shadow>(FRAME_THIS->frameShadow());
    }

    void Handle_setFrameShadow(HandleRef _this, Shadow shadow) {
        FRAME_THIS->setFrameShadow(static_cast<QFrame::Shadow>(shadow));
    }

    Shape Handle_frameShape(HandleRef _this) {
        return static_cast<Shape>(FRAME_THIS->frameShape());
    }

    void Handle_setFrameShape(HandleRef _this, Shape shape) {
        FRAME_THIS->setFrameShape(static_cast<QFrame::Shape>(shape));
    }

    int32_t Handle_frameWidth(HandleRef _this) {
        return FRAME_THIS->frameWidth();
    }

    int32_t Handle_lineWidth(HandleRef _this) {
        return FRAME_THIS->lineWidth();
    }

    void Handle_setLineWidth(HandleRef _this, int32_t width) {
        FRAME_THIS->setLineWidth(width);
    }

    int32_t Handle_midLineWidth(HandleRef _this) {
        return FRAME_THIS->midLineWidth();
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
