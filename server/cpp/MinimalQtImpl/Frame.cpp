#include "generated/Frame.h"
#include "FrameInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QFrame*>(_this))

namespace Frame
{
    Rect Handle_frameRect(HandleRef _this) {
        return toRect(THIS->frameRect());
    }

    Shadow Handle_frameShadow(HandleRef _this) {
        return static_cast<Shadow>(THIS->frameShadow());
    }

    Shape Handle_frameShape(HandleRef _this) {
        return static_cast<Shape>(THIS->frameShape());
    }

    int32_t Handle_frameStyle(HandleRef _this) {
        return 0;
    }

    int32_t Handle_frameWidth(HandleRef _this) {
        return THIS->frameWidth();
    }

    int32_t Handle_lineWidth(HandleRef _this) {
        return THIS->lineWidth();
    }

    int32_t Handle_midLineWidth(HandleRef _this) {
        return THIS->midLineWidth();
    }

    void Handle_setFrameRect(HandleRef _this, Rect rect) {
        THIS->setFrameRect(toQRect(rect));
    }

    void Handle_setFrameShadow(HandleRef _this, Shadow shadow) {
        THIS->setFrameShadow(static_cast<QFrame::Shadow>(shadow));
    }

    void Handle_setFrameShape(HandleRef _this, Shape shape) {
        THIS->setFrameShape(static_cast<QFrame::Shape>(shape));
    }

    void Handle_setFrameStyle(HandleRef _this, int32_t style) {
        THIS->setFrameStyle(style);
    }

    void Handle_setLineWidth(HandleRef _this, int32_t width) {
        THIS->setLineWidth(width);
    }

    void Handle_setMidLineWidth(HandleRef _this, int32_t width) {
        THIS->setMidLineWidth(width);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, WindowFlags f /* 0 */) {
        return reinterpret_cast<HandleRef>(new QFrame(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(f.value)));
    }
}
