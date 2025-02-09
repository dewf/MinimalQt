#include "generated/RectF.h"
#include "RectFInternal.h"

#include "PointFInternal.h"
#include "SizeFInternal.h"
#include "RectInternal.h"
#include "MarginsFInternal.h"

#include "util/convert.h"

using namespace ::PointF;
using namespace ::SizeF;
using namespace ::Rect;
using namespace ::MarginsF;

#define THIS (AS_QRECTF_PTR(_this))

namespace RectF
{
    void Handle_adjust(HandleRef _this, double dx1, double dy1, double dx2, double dy2) {
        THIS->adjust(dx1, dy1, dx2, dy2);
    }

    OwnedRef Handle_adjusted(HandleRef _this, double dx1, double dy1, double dx2, double dy2) {
        return RECTF_HEAP_NEW(THIS->adjusted(dx1, dy1, dx2, dy2));
    }

    double Handle_bottom(HandleRef _this) {
        return THIS->bottom();
    }

    PointF::OwnedRef Handle_bottomLeft(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->bottomLeft());
    }

    PointF::OwnedRef Handle_bottomRight(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->bottomRight());
    }

    PointF::OwnedRef Handle_center(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->center());
    }

    bool Handle_contains(HandleRef _this, PointF::HandleRef point) {
        return THIS->contains(QPOINTF_VALUE(point));
    }

    bool Handle_contains(HandleRef _this, HandleRef rectangle) {
        return THIS->contains(QRECTF_VALUE(rectangle));
    }

    bool Handle_contains(HandleRef _this, double x, double y) {
        return THIS->contains(x, y);
    }

    std::tuple<double,double,double,double> Handle_getCoords(HandleRef _this) {
        double x1, y1, x2, y2;
        THIS->getCoords(&x1, &y1, &x2, &y2);
        return std::tuple{ x1, y1, x2, y2 };
    }

    std::tuple<double,double,double,double> Handle_getRect(HandleRef _this) {
        double x, y, width, height;
        THIS->getRect(&x, &y, &width, &height);
        return std::tuple{ x, y, width, height };
    }

    double Handle_height(HandleRef _this) {
        return THIS->height();
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef rectangle) {
        return RECTF_HEAP_NEW(THIS->intersected(QRECTF_VALUE(rectangle)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef rectangle) {
        return THIS->intersects(QRECTF_VALUE(rectangle));
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

    double Handle_left(HandleRef _this) {
        return THIS->left();
    }

    OwnedRef Handle_marginsAdded(HandleRef _this, MarginsF::HandleRef margins) {
        return RECTF_HEAP_NEW(THIS->marginsAdded(QMARGINSF_VALUE(margins)));
    }

    OwnedRef Handle_marginsRemoved(HandleRef _this, MarginsF::HandleRef margins) {
        return RECTF_HEAP_NEW(THIS->marginsRemoved(QMARGINSF_VALUE(margins)));
    }

    void Handle_moveBottom(HandleRef _this, double y) {
        THIS->moveBottom(y);
    }

    void Handle_moveBottomLeft(HandleRef _this, PointF::HandleRef position) {
        THIS->moveBottomLeft(QPOINTF_VALUE(position));
    }

    void Handle_moveBottomRight(HandleRef _this, PointF::HandleRef position) {
        THIS->moveBottomRight(QPOINTF_VALUE(position));
    }

    void Handle_moveCenter(HandleRef _this, PointF::HandleRef position) {
        THIS->moveCenter(QPOINTF_VALUE(position));
    }

    void Handle_moveLeft(HandleRef _this, double x) {
        THIS->moveLeft(x);
    }

    void Handle_moveRight(HandleRef _this, double x) {
        THIS->moveRight(x);
    }

    void Handle_moveTo(HandleRef _this, double x, double y) {
        THIS->moveTo(x, y);
    }

    void Handle_moveTo(HandleRef _this, PointF::HandleRef position) {
        THIS->moveTo(QPOINTF_VALUE(position));
    }

    void Handle_moveTop(HandleRef _this, double y) {
        THIS->moveTop(y);
    }

    void Handle_moveTopLeft(HandleRef _this, PointF::HandleRef position) {
        THIS->moveTopLeft(QPOINTF_VALUE(position));
    }

    void Handle_moveTopRight(HandleRef _this, PointF::HandleRef position) {
        THIS->moveTopRight(QPOINTF_VALUE(position));
    }

    OwnedRef Handle_normalized(HandleRef _this) {
        return RECTF_HEAP_NEW(THIS->normalized());
    }

    double Handle_right(HandleRef _this) {
        return THIS->right();
    }

    void Handle_setBottom(HandleRef _this, double y) {
        THIS->setBottom(y);
    }

    void Handle_setBottomLeft(HandleRef _this, PointF::HandleRef position) {
        THIS->setBottomLeft(QPOINTF_VALUE(position));
    }

    void Handle_setBottomRight(HandleRef _this, PointF::HandleRef position) {
        THIS->setBottomRight(QPOINTF_VALUE(position));
    }

    void Handle_setCoords(HandleRef _this, double x1, double y1, double x2, double y2) {
        THIS->setCoords(x1, y1, x2, y2);
    }

    void Handle_setHeight(HandleRef _this, double height) {
        THIS->setHeight(height);
    }

    void Handle_setLeft(HandleRef _this, double x) {
        THIS->setLeft(x);
    }

    void Handle_setRect(HandleRef _this, double x, double y, double width, double height) {
        THIS->setRect(x, y, width, height);
    }

    void Handle_setRight(HandleRef _this, double x) {
        THIS->setRight(x);
    }

    void Handle_setSize(HandleRef _this, SizeF::HandleRef size) {
        THIS->setSize(QSIZEF_VALUE(size));
    }

    void Handle_setTop(HandleRef _this, double y) {
        THIS->setTop(y);
    }

    void Handle_setTopLeft(HandleRef _this, PointF::HandleRef position) {
        THIS->setTopLeft(QPOINTF_VALUE(position));
    }

    void Handle_setTopRight(HandleRef _this, PointF::HandleRef position) {
        THIS->setTopRight(QPOINTF_VALUE(position));
    }

    void Handle_setWidth(HandleRef _this, double width) {
        THIS->setWidth(width);
    }

    void Handle_setX(HandleRef _this, double x) {
        THIS->setX(x);
    }

    void Handle_setY(HandleRef _this, double y) {
        THIS->setY(y);
    }

    SizeF::OwnedRef Handle_size(HandleRef _this) {
        return SIZEF_HEAP_NEW(THIS->size());
    }

    Rect::OwnedRef Handle_toAlignedRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->toAlignedRect());
    }

    Rect::OwnedRef Handle_toRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->toRect());
    }

    double Handle_top(HandleRef _this) {
        return THIS->top();
    }

    PointF::OwnedRef Handle_topLeft(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->topLeft());
    }

    PointF::OwnedRef Handle_topRight(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->topRight());
    }

    void Handle_translate(HandleRef _this, double dx, double dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, PointF::HandleRef offset) {
        THIS->translate(QPOINTF_VALUE(offset));
    }

    OwnedRef Handle_translated(HandleRef _this, double dx, double dy) {
        return RECTF_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, PointF::HandleRef offset) {
        return RECTF_HEAP_NEW(THIS->translated(QPOINTF_VALUE(offset)));
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return RECTF_HEAP_NEW(THIS->transposed());
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef rectangle) {
        return RECTF_HEAP_NEW(THIS->united(QRECTF_VALUE(rectangle)));
    }

    double Handle_width(HandleRef _this) {
        return THIS->width();
    }

    double Handle_x(HandleRef _this) {
        return THIS->x();
    }

    double Handle_y(HandleRef _this) {
        return THIS->y();
    }

    HandleRef Handle_operator_intersectWith(HandleRef _this, HandleRef rectangle) {
        THIS->operator&=(QRECTF_VALUE(rectangle));
        return _this;
    }

    HandleRef Handle_operator_incrementBy(HandleRef _this, MarginsF::HandleRef margins) {
        THIS->operator+=(QMARGINSF_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_decrementBy(HandleRef _this, MarginsF::HandleRef margins) {
        THIS->operator-=(QMARGINSF_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_uniteWith(HandleRef _this, HandleRef rectangle) {
        THIS->operator|=(QRECTF_VALUE(rectangle));
        return _this;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return RECTF_HEAP_NEW();
    }

    OwnedRef create(Rect::HandleRef rectangle) {
        return RECTF_HEAP_NEW(QRECT_VALUE(rectangle));
    }

    OwnedRef create(PointF::HandleRef topLeft, PointF::HandleRef bottomRight) {
        return RECTF_HEAP_NEW(QPOINTF_VALUE(topLeft), QPOINTF_VALUE(bottomRight));
    }

    OwnedRef create(PointF::HandleRef topLeft, SizeF::HandleRef size) {
        return RECTF_HEAP_NEW(QPOINTF_VALUE(topLeft), QSIZEF_VALUE(size));
    }

    OwnedRef create(double x, double y, double width, double height) {
        return RECTF_HEAP_NEW(x, y, width, height);
    }

    bool fuzzyCompare(HandleRef lhs, HandleRef rhs) {
        return qFuzzyCompare(QRECTF_VALUE(lhs), QRECTF_VALUE(rhs));
    }

    bool fuzzyIsNull(HandleRef rect) {
        return qFuzzyIsNull(QRECTF_VALUE(rect));
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QRECT_VALUE(lhs) != QRECT_VALUE(rhs);
    }

    OwnedRef operator_add(HandleRef lhs, MarginsF::HandleRef rhs) {
        return RECTF_HEAP_NEW(QRECTF_VALUE(lhs) + QMARGINSF_VALUE(rhs));
    }

    OwnedRef operator_sub(HandleRef lhs, MarginsF::HandleRef rhs) {
        return RECTF_HEAP_NEW(QRECTF_VALUE(lhs) - QMARGINSF_VALUE(rhs));
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QRECTF_VALUE(lhs) == QRECTF_VALUE(rhs);
    }
}
