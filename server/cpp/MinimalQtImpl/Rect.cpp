#include "generated/Rect.h"
#include "RectInternal.h"

#include "PointInternal.h"
#include "SizeInternal.h"
#include "RectFInternal.h"
#include "MarginsInternal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Point;
using namespace ::Size;
using namespace ::Margins;

#define THIS (AS_QRECT_PTR(_this))

namespace Rect
{
    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(*THIS));
    }

    void Handle_adjust(HandleRef _this, int32_t dx1, int32_t dy1, int32_t dx2, int32_t dy2) {
        THIS->adjust(dx1, dy1, dx2, dy2);
    }

    OwnedRef Handle_adjusted(HandleRef _this, int32_t dx1, int32_t dy1, int32_t dx2, int32_t dy2) {
        return RECT_HEAP_NEW(THIS->adjusted(dx1, dy1, dx2, dy2));
    }

    int32_t Handle_bottom(HandleRef _this) {
        return THIS->bottom();
    }

    Point::OwnedRef Handle_bottomLeft(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->bottomLeft());
    }

    Point::OwnedRef Handle_bottomRight(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->bottomRight());
    }

    Point::OwnedRef Handle_center(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->center());
    }

    bool Handle_contains(HandleRef _this, Point::HandleRef point, bool proper /* false */) {
        return THIS->contains(QPOINT_VALUE(point), proper);
    }

    bool Handle_contains(HandleRef _this, HandleRef rectangle, bool proper /* false */) {
        return THIS->contains(QRECT_VALUE(rectangle), proper);
    }

    bool Handle_contains(HandleRef _this, int32_t x, int32_t y) {
        return THIS->contains(x, y);
    }

    bool Handle_contains(HandleRef _this, int32_t x, int32_t y, bool proper) {
        return THIS->contains(x, y, proper);
    }

    std::tuple<int32_t,int32_t,int32_t,int32_t> Handle_getCoords(HandleRef _this) {
        int x1, y1, x2, y2;
        THIS->getCoords(&x1, &y1, &x2, &y2);
        return std::tuple{ x1, y1, x2, y2 };
    }

    std::tuple<int32_t,int32_t,int32_t,int32_t> Handle_getRect(HandleRef _this) {
        int x, y, w, h;
        THIS->getRect(&x, &y, &w, &h);
        return std::tuple{ x, y, w, h };
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef rectangle) {
        return RECT_HEAP_NEW(THIS->intersected(QRECT_VALUE(rectangle)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef rectangle) {
        return THIS->intersects(QRECT_VALUE(rectangle));
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    int32_t Handle_left(HandleRef _this) {
        return THIS->left();
    }

    OwnedRef Handle_marginsAdded(HandleRef _this, Margins::HandleRef margins) {
        return RECT_HEAP_NEW(THIS->marginsAdded(QMARGINS_VALUE(margins)));
    }

    OwnedRef Handle_marginsRemoved(HandleRef _this, Margins::HandleRef margins) {
        return RECT_HEAP_NEW(THIS->marginsRemoved(QMARGINS_VALUE(margins)));
    }

    void Handle_moveBottom(HandleRef _this, int32_t y) {
        THIS->moveBottom(y);
    }

    void Handle_moveBottomLeft(HandleRef _this, Point::HandleRef position) {
        THIS->moveBottomLeft(QPOINT_VALUE(position));
    }

    void Handle_moveBottomRight(HandleRef _this, Point::HandleRef position) {
        THIS->moveBottomRight(QPOINT_VALUE(position));
    }

    void Handle_moveCenter(HandleRef _this, Point::HandleRef position) {
        THIS->moveCenter(QPOINT_VALUE(position));
    }

    void Handle_moveLeft(HandleRef _this, int32_t x) {
        THIS->moveLeft(x);
    }

    void Handle_moveRight(HandleRef _this, int32_t x) {
        THIS->moveRight(x);
    }

    void Handle_moveTo(HandleRef _this, Point::HandleRef position) {
        THIS->moveTo(QPOINT_VALUE(position));
    }

    void Handle_moveTo(HandleRef _this, int32_t x, int32_t y) {
        THIS->moveTo(x, y);
    }

    void Handle_moveTop(HandleRef _this, int32_t y) {
        THIS->moveTop(y);
    }

    void Handle_moveTopLeft(HandleRef _this, Point::HandleRef position) {
        THIS->moveTopLeft(QPOINT_VALUE(position));
    }

    void Handle_moveTopRight(HandleRef _this, Point::HandleRef position) {
        THIS->moveTopRight(QPOINT_VALUE(position));
    }

    OwnedRef Handle_normalized(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->normalized());
    }

    int32_t Handle_right(HandleRef _this) {
        return THIS->right();
    }

    void Handle_setBottom(HandleRef _this, int32_t y) {
        THIS->setBottom(y);
    }

    void Handle_setBottomLeft(HandleRef _this, Point::HandleRef position) {
        THIS->setBottomLeft(QPOINT_VALUE(position));
    }

    void Handle_setBottomRight(HandleRef _this, Point::HandleRef position) {
        THIS->setBottomRight(QPOINT_VALUE(position));
    }

    void Handle_setCoords(HandleRef _this, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
        THIS->setCoords(x1, y1, x2, y2);
    }

    void Handle_setHeight(HandleRef _this, int32_t height) {
        THIS->setHeight(height);
    }

    void Handle_setLeft(HandleRef _this, int32_t x) {
        THIS->setLeft(x);
    }

    void Handle_setRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->setRect(x, y, width, height);
    }

    void Handle_setRight(HandleRef _this, int32_t x) {
        THIS->setRight(x);
    }

    void Handle_setSize(HandleRef _this, Size::HandleRef size) {
        THIS->setSize(QSIZE_VALUE(size));
    }

    void Handle_setTop(HandleRef _this, int32_t y) {
        THIS->setTop(y);
    }

    void Handle_setTopLeft(HandleRef _this, Point::HandleRef position) {
        THIS->setTopLeft(QPOINT_VALUE(position));
    }

    void Handle_setTopRight(HandleRef _this, Point::HandleRef position) {
        THIS->setTopRight(QPOINT_VALUE(position));
    }

    void Handle_setWidth(HandleRef _this, int32_t width) {
        THIS->setWidth(width);
    }

    void Handle_setX(HandleRef _this, int32_t x) {
        THIS->setX(x);
    }

    void Handle_setY(HandleRef _this, int32_t y) {
        THIS->setY(y);
    }

    Size::OwnedRef Handle_size(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->size());
    }

    RectF_OwnedRef Handle_toRectF(HandleRef _this) {
        const auto result = RECTF_HEAP_NEW(THIS->toRectF());
        // fwd opaque cast:
        return reinterpret_cast<RectF_OwnedRef>(result);
    }

    int32_t Handle_top(HandleRef _this) {
        return THIS->top();
    }

    Point::OwnedRef Handle_topLeft(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->topLeft());
    }

    Point::OwnedRef Handle_topRight(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->topRight());
    }

    void Handle_translate(HandleRef _this, int32_t dx, int32_t dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, Point::HandleRef offset) {
        THIS->translate(QPOINT_VALUE(offset));
    }

    OwnedRef Handle_translated(HandleRef _this, int32_t dx, int32_t dy) {
        return RECT_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, Point::HandleRef offset) {
        return RECT_HEAP_NEW(THIS->translated(QPOINT_VALUE(offset)));
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->transposed());
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef rectangle) {
        return RECT_HEAP_NEW(THIS->united(QRECT_VALUE(rectangle)));
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    int32_t Handle_x(HandleRef _this) {
        return THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return THIS->y();
    }

    HandleRef Handle_operator_intersectWith(HandleRef _this, HandleRef rectangle) {
        THIS->operator&=(QRECT_VALUE(rectangle));
        return _this;
    }

    HandleRef Handle_operator_incrementBy(HandleRef _this, Margins::HandleRef margins) {
        THIS->operator+=(QMARGINS_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_decrementBy(HandleRef _this, Margins::HandleRef margins) {
        THIS->operator-=(QMARGINS_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_uniteWith(HandleRef _this, HandleRef rectangle) {
        THIS->operator|=(QRECT_VALUE(rectangle));
        return _this;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return RECT_HEAP_NEW();
    }

    OwnedRef create(Point::HandleRef topLeft, Point::HandleRef bottomRight) {
        return RECT_HEAP_NEW(QPOINT_VALUE(topLeft), QPOINT_VALUE(bottomRight));
    }

    OwnedRef create(Point::HandleRef topLeft, Size::HandleRef size) {
        return RECT_HEAP_NEW(QPOINT_VALUE(topLeft), QSIZE_VALUE(size));
    }

    OwnedRef create(int32_t x, int32_t y, int32_t width, int32_t height) {
        return RECT_HEAP_NEW(x, y, width, height);
    }

    OwnedRef span(Point::HandleRef p1, Point::HandleRef p2) {
        return RECT_HEAP_NEW(QRect::span(QPOINT_VALUE(p1), QPOINT_VALUE(p2)));
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QRECT_VALUE(lhs) != QRECT_VALUE(rhs);
    }

    OwnedRef operator_add(HandleRef rectangle, Margins::HandleRef margins) {
        return RECT_HEAP_NEW(QRECT_VALUE(rectangle) + QMARGINS_VALUE(margins));
    }

    OwnedRef operator_sub(HandleRef lhs, Margins::HandleRef rhs) {
        return RECT_HEAP_NEW(QRECT_VALUE(lhs) - QMARGINS_VALUE(rhs));
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QRECT_VALUE(lhs) == QRECT_VALUE(rhs);
    }
}
