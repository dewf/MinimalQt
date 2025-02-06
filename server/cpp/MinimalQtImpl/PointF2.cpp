#include "generated/PointF2.h"
#include "PointF2Internal.h"

#include "PointInternal.h"

#define THIS (AS_QPOINTF_PTR(_this))

namespace PointF2
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

    Point_OwnedRef Handle_toPoint(HandleRef _this) {
        return reinterpret_cast<Point_OwnedRef>(POINT_HEAP_NEW(THIS->toPoint()));
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

    HandleRef Handle_operator_mul(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, HandleRef point) {
        THIS->operator+=(QPOINTF_VALUE(point));
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, HandleRef point) {
        THIS->operator-=(QPOINTF_VALUE(point));
        return _this;
    }

    HandleRef Handle_operator_div(HandleRef _this, double divisor) {
        THIS->operator/=(divisor);
        return _this;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return POINTF_HEAP_NEW();
    }

    OwnedRef create(Point_HandleRef point) {
        return POINTF_HEAP_NEW(QPOINT_VALUE(point));
    }

    OwnedRef create(double xpos, double ypos) {
        return POINTF_HEAP_NEW(xpos, ypos);
    }

    double dotProduct(HandleRef p1, HandleRef p2) {
        return QPointF::dotProduct(QPOINTF_VALUE(p1), QPOINTF_VALUE(p2));
    }
}
