#include "generated/MarginsF.h"
#include "MarginsFInternal.h"

#include "MarginsInternal.h"

using namespace ::Margins;

#define THIS (AS_QMARGINSF_PTR(_this))

namespace MarginsF
{
    double Handle_bottom(HandleRef _this) {
        return THIS->bottom();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    double Handle_left(HandleRef _this) {
        return THIS->left();
    }

    double Handle_right(HandleRef _this) {
        return THIS->right();
    }

    void Handle_setBottom(HandleRef _this, double abottom) {
        THIS->setBottom(abottom);
    }

    void Handle_setLeft(HandleRef _this, double aleft) {
        THIS->setLeft(aleft);
    }

    void Handle_setRight(HandleRef _this, double aright) {
        THIS->setRight(aright);
    }

    void Handle_setTop(HandleRef _this, double atop) {
        THIS->setTop(atop);
    }

    Margins::OwnedRef Handle_toMargins(HandleRef _this) {
        return MARGINS_HEAP_NEW(THIS->toMargins());
    }

    double Handle_top(HandleRef _this) {
        return THIS->top();
    }

    HandleRef Handle_operator_mul(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, HandleRef margins) {
        THIS->operator+=(QMARGINSF_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_add(HandleRef _this, double addend) {
        THIS->operator+=(addend);
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, HandleRef margins) {
        THIS->operator-=(QMARGINSF_VALUE(margins));
        return _this;
    }

    HandleRef Handle_operator_sub(HandleRef _this, double subtrahend) {
        THIS->operator-=(subtrahend);
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
        return MARGINSF_HEAP_NEW();
    }

    OwnedRef create(Margins::HandleRef margins) {
        return MARGINSF_HEAP_NEW(QMARGINS_VALUE(margins));
    }

    OwnedRef create(double left, double top, double right, double bottom) {
        return MARGINSF_HEAP_NEW(left, top, right, bottom);
    }

    bool fuzzyCompare(HandleRef lhs, HandleRef rhs) {
        return qFuzzyCompare(QMARGINSF_VALUE(lhs), QMARGINSF_VALUE(rhs));
    }

    bool fuzzyIsNull(HandleRef margins) {
        return qFuzzyIsNull(QMARGINSF_VALUE(margins));
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QMARGINSF_VALUE(lhs) != QMARGINSF_VALUE(rhs);
    }

    OwnedRef operator_mul(HandleRef lhs, double rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) * rhs);
    }

    OwnedRef operator_add(HandleRef lhs, HandleRef rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) + QMARGINSF_VALUE(rhs));
    }

    OwnedRef operator_add(HandleRef lhs, double rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) + rhs);
    }

    OwnedRef operator_negate(HandleRef margins) {
        return MARGINSF_HEAP_NEW(-QMARGINSF_VALUE(margins));
    }

    OwnedRef operator_sub(HandleRef lhs, HandleRef rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) - QMARGINSF_VALUE(rhs));
    }

    OwnedRef operator_sub(HandleRef lhs, double rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) - rhs);
    }

    OwnedRef operator_div(HandleRef lhs, double rhs) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(lhs) / rhs);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QMARGINSF_VALUE(lhs) == QMARGINSF_VALUE(rhs);
    }

    OwnedRef operator_or(HandleRef m1, HandleRef m2) {
        return MARGINSF_HEAP_NEW(QMARGINSF_VALUE(m1) | QMARGINSF_VALUE(m2));
    }

    // ext methods block for: Margins::HandleRef ====
    OwnedRef ext_Margins_toMarginsF(Margins::HandleRef this_) {
        return MARGINSF_HEAP_NEW(AS_QMARGINS_PTR(this_)->toMarginsF());
    }
}
