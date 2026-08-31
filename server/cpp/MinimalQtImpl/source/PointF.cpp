#include "generated/PointF.h"
#include "PointFInternal.h"

#include "PointInternal.h"

#define THIS (AS_QPOINTF_PTR(_this))

namespace PointF
{
    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    double Handle_manhattanLength(HandleRef _this) {
        return THIS->manhattanLength();
    }

    void Handle_setX(HandleRef _this, double x) {
        THIS->setX(x);
    }

    void Handle_setY(HandleRef _this, double y) {
        THIS->setY(y);
    }

    Point::OwnedRef Handle_toPoint(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->toPoint());
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return POINTF_HEAP_NEW(THIS->transposed());
    }

    double Handle_x(HandleRef _this) {
        return THIS->x();
    }

    double Handle_y(HandleRef _this) {
        return THIS->y();
    }

    HandleRef Handle_operator_multiplyBy(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_incrementBy(HandleRef _this, HandleRef point) {
        THIS->operator+=(QPOINTF_VALUE(point));
        return _this;
    }

    HandleRef Handle_operator_decrementBy(HandleRef _this, HandleRef point) {
        THIS->operator-=(QPOINTF_VALUE(point));
        return _this;
    }

    HandleRef Handle_operator_divideBy(HandleRef _this, double divisor) {
        THIS->operator/=(divisor);
        return _this;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return POINTF_HEAP_NEW();
    }

    OwnedRef create(Point::HandleRef point) {
        return POINTF_HEAP_NEW(QPOINT_VALUE(point));
    }

    OwnedRef create(double xpos, double ypos) {
        return POINTF_HEAP_NEW(xpos, ypos);
    }

    double dotProduct(HandleRef p1, HandleRef p2) {
        return QPointF::dotProduct(QPOINTF_VALUE(p1), QPOINTF_VALUE(p2));
    }

    bool fuzzyCompare(HandleRef p1, HandleRef p2) {
        return qFuzzyCompare(QPOINTF_VALUE(p1), QPOINTF_VALUE(p2));
    }

    bool fuzzyIsNull(HandleRef point) {
        return qFuzzyIsNull(QPOINTF_VALUE(point));
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QPOINTF_VALUE(lhs) != QPOINTF_VALUE(rhs);
    }

    OwnedRef operator_mul(HandleRef point, double factor) {
        return POINTF_HEAP_NEW(QPOINTF_VALUE(point) * factor);
    }

    OwnedRef operator_add(HandleRef p1, HandleRef p2) {
        return POINTF_HEAP_NEW(QPOINTF_VALUE(p1) + QPOINTF_VALUE(p2));
    }

    OwnedRef operator_sub(HandleRef p1, HandleRef p2) {
        return POINTF_HEAP_NEW(QPOINTF_VALUE(p1) - QPOINTF_VALUE(p2));
    }

    OwnedRef operator_negate(HandleRef point) {
        return POINTF_HEAP_NEW(-QPOINTF_VALUE(point));
    }

    OwnedRef operator_div(HandleRef point, double divisor) {
        return POINTF_HEAP_NEW(QPOINTF_VALUE(point) / divisor);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QPOINTF_VALUE(lhs) == QPOINTF_VALUE(rhs);
    }

    // ext methods block for: Point::HandleRef ====
    OwnedRef ext_Point_toPointF(Point::HandleRef this_) {
        return POINTF_HEAP_NEW(AS_QPOINT_PTR(this_)->toPointF());
    }
    // ==============================
}
