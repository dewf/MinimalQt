#include "generated/Frame.h"
#include "FrameInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QFrame*>(_this))

namespace Frame
{
    Rect Handle_frameRect(HandleRef _this) {
        return toRect(THIS->frameRect());
    }

    void Handle_setFrameRect(HandleRef _this, Rect rect) {
        THIS->setFrameRect(toQRect(rect));
    }

    Shadow Handle_frameShadow(HandleRef _this) {
        return static_cast<Shadow>(THIS->frameShadow());
    }

    void Handle_setFrameShadow(HandleRef _this, Shadow shadow) {
        THIS->setFrameShadow(static_cast<QFrame::Shadow>(shadow));
    }

    Shape Handle_frameShape(HandleRef _this) {
        return static_cast<Shape>(THIS->frameShape());
    }

    void Handle_setFrameShape(HandleRef _this, Shape shape) {
        THIS->setFrameShape(static_cast<QFrame::Shape>(shape));
    }

    int32_t Handle_frameWidth(HandleRef _this) {
        return THIS->frameWidth();
    }

    int32_t Handle_lineWidth(HandleRef _this) {
        return THIS->lineWidth();
    }

    void Handle_setLineWidth(HandleRef _this, int32_t width) {
        THIS->setLineWidth(width);
    }

    int32_t Handle_midLineWidth(HandleRef _this) {
        return THIS->midLineWidth();
    }

    void Handle_setMidLineWidth(HandleRef _this, int32_t width) {
        THIS->setMidLineWidth(width);
    }

    void Handle_setFrameStyle(HandleRef _this, Shape shape, Shadow shadow) {
        THIS->setFrameStyle(static_cast<QFrame::Shape>(shape) | static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QFrame());
    }
}
