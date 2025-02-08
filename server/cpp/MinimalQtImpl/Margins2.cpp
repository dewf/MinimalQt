#include "generated/Margins2.h"
#include "Margins2Internal.h"

#include "util/convert.h"

using namespace ::Common;

#define THIS (AS_QMARGINS_PTR(_this))

namespace Margins2
{
    int32_t Handle_bottom(HandleRef _this) {
        return THIS->bottom();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    int32_t Handle_left(HandleRef _this) {
        return THIS->left();
    }

    int32_t Handle_right(HandleRef _this) {
        return THIS->right();
    }

    void Handle_setBottom(HandleRef _this, int32_t bottom) {
        THIS->setBottom(bottom);
    }

    void Handle_setLeft(HandleRef _this, int32_t left) {
        THIS->setLeft(left);
    }

    void Handle_setRight(HandleRef _this, int32_t right) {
        THIS->setRight(right);
    }

    void Handle_setTop(HandleRef _this, int32_t top) {
        THIS->setTop(top);
    }

    MarginsF Handle_toMarginsF(HandleRef _this) {
        return toMarginsF(THIS->toMarginsF());
    }

    int32_t Handle_top(HandleRef _this) {
        return THIS->top();
    }

    HandleRef Handle_operator_mul(HandleRef _this, int32_t factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_mul(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, Margins margins) {
        THIS->operator+=(toQMargins(margins));
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, int32_t addend) {
        THIS->operator+=(addend);
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, Margins margins) {
        THIS->operator-=(toQMargins(margins));
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, int32_t subtrahend) {
        THIS->operator-=(subtrahend);
        return _this;
    }

    HandleRef Handle_operator_div(HandleRef _this, int32_t divisor) {
        THIS->operator/=(divisor);
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
        return MARGINS_HEAP_NEW();
    }

    OwnedRef create(int32_t left, int32_t top, int32_t right, int32_t bottom) {
        return MARGINS_HEAP_NEW(left, top, right, bottom);
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QMARGINS_VALUE(lhs) != QMARGINS_VALUE(rhs);
    }

    OwnedRef operator_mul(HandleRef margins, int32_t factor) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(margins) * factor);
    }

    OwnedRef operator_mul(HandleRef margins, double factor) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(margins) * factor);
    }

    OwnedRef operator_add(HandleRef m1, HandleRef m2) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(m1) + QMARGINS_VALUE(m2));
    }

    OwnedRef operator_add(HandleRef lhs, int32_t rhs) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(lhs) + rhs);
    }

    OwnedRef operator_negate(HandleRef margins) {
        return MARGINS_HEAP_NEW(-QMARGINS_VALUE(margins));
    }

    OwnedRef operator_sub(HandleRef m1, HandleRef m2) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(m1) - QMARGINS_VALUE(m2));
    }

    OwnedRef operator_sub(HandleRef lhs, int32_t rhs) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(lhs) - rhs);
    }

    OwnedRef operator_div(HandleRef margins, int32_t divisor) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(margins) / divisor);
    }

    OwnedRef operator_div(HandleRef margins, double divisor) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(margins) / divisor);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QMARGINS_VALUE(lhs) == QMARGINS_VALUE(rhs);
    }

    OwnedRef operator_or(HandleRef m1, HandleRef m2) {
        return MARGINS_HEAP_NEW(QMARGINS_VALUE(m1) | QMARGINS_VALUE(m2));
    }
}
