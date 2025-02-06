#include "generated/Point.h"
#include "PointInternal.h"

#include "util/convert.h"

using namespace ::Common;

#define THIS (AS_QPOINT_PTR(_this))

namespace Point
{
    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    int32_t Handle_manhattanLength(HandleRef _this) {
        return THIS->manhattanLength();
    }

    void Handle_setX(HandleRef _this, int32_t x) {
        THIS->setX(x);
    }

    void Handle_setY(HandleRef _this, int32_t y) {
        THIS->setY(y);
    }

    PointF Handle_toPointF(HandleRef _this) {
        return toPointF(THIS->toPointF());
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->transposed());
    }

    int32_t Handle_x(HandleRef _this) {
        return THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return THIS->y();
    }

    HandleRef Handle_operator_mul(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_mul(HandleRef _this, float factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_mul(HandleRef _this, int32_t factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, HandleRef point) {
        THIS->operator+=(QPOINT_VALUE(point));
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, HandleRef point) {
        THIS->operator-=(QPOINT_VALUE(point));
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
        return POINT_HEAP_NEW();
    }

    OwnedRef create(int32_t xpos, int32_t ypos) {
        return POINT_HEAP_NEW(xpos, ypos);
    }

    int32_t dotProduct(HandleRef p1, HandleRef p2) {
        return QPoint::dotProduct(QPOINT_VALUE(p1), QPOINT_VALUE(p2));
    }
}
