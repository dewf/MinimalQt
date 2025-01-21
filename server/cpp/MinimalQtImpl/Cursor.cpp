#include "generated/Cursor.h"
#include "CursorInternal.h"

#include "PixmapInternal.h"
#include "ScreenInternal.h"

#include "util/convert.h"

#define THIS ((QCursor*)_this)

namespace Cursor
{
    Point Handle_hotSpot(HandleRef _this) {
        return toPoint(THIS->hotSpot());
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this) {
        return PIXMAP_HEAP_NEW(THIS->pixmap());
    }

    void Handle_setShape(HandleRef _this, CursorShape shape) {
        THIS->setShape(static_cast<Qt::CursorShape>(shape));
    }

    CursorShape Handle_shape(HandleRef _this) {
        return static_cast<CursorShape>(THIS->shape());
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    // ctors ===========================================
    OwnedRef create() {
        return CURSOR_HEAP_NEW();
    }

    OwnedRef create(CursorShape shape) {
        return CURSOR_HEAP_NEW(static_cast<Qt::CursorShape>(shape));
    }

    OwnedRef create(Pixmap::HandleRef pixmap, int32_t hotX /* -1 */, int32_t hotY /* -1 */) {
        return CURSOR_HEAP_NEW(QPIXMAP_VALUE(pixmap), hotX, hotY);
    }

    OwnedRef create(HandleRef other) {
        return CURSOR_HEAP_NEW(QCURSOR_VALUE(other));
    }

    // static methods ==================================
    Point pos() {
        return toPoint(QCursor::pos());
    }

    Point pos(Screen::HandleRef screen) {
        return toPoint(QCursor::pos(AS_QSCREEN_PTR(screen)));
    }

    void setPos(int32_t x, int32_t y) {
        QCursor::setPos(x, y);
    }

    void setPos(Screen::HandleRef screen, int32_t x, int32_t y) {
        QCursor::setPos(AS_QSCREEN_PTR(screen), x, y);
    }

    void setPos(Point p) {
        QCursor::setPos(toQPoint(p));
    }

    void setPos(Screen::HandleRef screen, Point p) {
        QCursor::setPos(AS_QSCREEN_PTR(screen), toQPoint(p));
    }
}
