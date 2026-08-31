#include "generated/SizeF.h"
#include "SizeFInternal.h"

#include "SizeInternal.h"
#include "MarginsFInternal.h"

#include "util/convert.h"

using namespace ::Size;
using namespace ::Enums;
using namespace ::MarginsF;

#define THIS (AS_QSIZEF_PTR(_this))

namespace SizeF
{
    OwnedRef Handle_boundedTo(HandleRef _this, HandleRef otherSize) {
        return SIZEF_HEAP_NEW(THIS->boundedTo(QSIZEF_VALUE(otherSize)));
    }

    OwnedRef Handle_expandedTo(HandleRef _this, HandleRef otherSize) {
        return SIZEF_HEAP_NEW(THIS->expandedTo(QSIZEF_VALUE(otherSize)));
    }

    OwnedRef Handle_grownBy(HandleRef _this, MarginsF::HandleRef margins) {
        return SIZEF_HEAP_NEW(THIS->grownBy(QMARGINSF_VALUE(margins)));
    }

    double Handle_height(HandleRef _this) {
        return THIS->height();
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

    void Handle_scale(HandleRef _this, double width, double height, AspectRatioMode mode) {
        THIS->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
    }

    void Handle_scale(HandleRef _this, HandleRef size, AspectRatioMode mode) {
        THIS->scale(QSIZEF_VALUE(size), static_cast<Qt::AspectRatioMode>(mode));
    }

    OwnedRef Handle_scaled(HandleRef _this, double width, double height, AspectRatioMode mode) {
        return SIZEF_HEAP_NEW(THIS->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode)));
    }

    OwnedRef Handle_scaled(HandleRef _this, HandleRef s, AspectRatioMode mode) {
        return SIZEF_HEAP_NEW(THIS->scaled(QSIZEF_VALUE(s), static_cast<Qt::AspectRatioMode>(mode)));
    }

    void Handle_setHeight(HandleRef _this, double height) {
        THIS->setHeight(height);
    }

    void Handle_setWidth(HandleRef _this, double width) {
        THIS->setWidth(width);
    }

    OwnedRef Handle_shrunkBy(HandleRef _this, MarginsF::HandleRef margins) {
        return SIZEF_HEAP_NEW(THIS->shrunkBy(QMARGINSF_VALUE(margins)));
    }

    Size::OwnedRef Handle_toSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->toSize());
    }

    void Handle_transpose(HandleRef _this) {
        THIS->transpose();
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return SIZEF_HEAP_NEW(THIS->transposed());
    }

    double Handle_width(HandleRef _this) {
        return THIS->width();
    }

    HandleRef Handle_operator_multiplyBy(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_incrementBy(HandleRef _this, HandleRef size) {
        THIS->operator+=(QSIZEF_VALUE(size));
        return _this;
    }

    HandleRef Handle_operator_decrementBy(HandleRef _this, HandleRef size) {
        THIS->operator-=(QSIZEF_VALUE(size));
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
        return SIZEF_HEAP_NEW();
    }

    OwnedRef create(Size::HandleRef size) {
        return SIZEF_HEAP_NEW(QSIZE_VALUE(size));
    }

    OwnedRef create(double width, double height) {
        return SIZEF_HEAP_NEW(width, height);
    }

    bool fuzzyCompare(HandleRef lhs, HandleRef rhs) {
        return qFuzzyCompare(QSIZEF_VALUE(lhs), QSIZEF_VALUE(rhs));
    }

    bool fuzzyIsNull(HandleRef size) {
        return qFuzzyIsNull(QSIZEF_VALUE(size));
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QSIZEF_VALUE(lhs) != QSIZEF_VALUE(rhs);
    }

    OwnedRef operator_mul(HandleRef size, double factor) {
        return SIZEF_HEAP_NEW(QSIZEF_VALUE(size) * factor);
    }

    OwnedRef operator_add(HandleRef s1, HandleRef s2) {
        return SIZEF_HEAP_NEW(QSIZEF_VALUE(s1) + QSIZEF_VALUE(s2));
    }

    OwnedRef operator_sub(HandleRef s1, HandleRef s2) {
        return SIZEF_HEAP_NEW(QSIZEF_VALUE(s1) - QSIZEF_VALUE(s2));
    }

    OwnedRef operator_div(HandleRef size, double divisor) {
        return SIZEF_HEAP_NEW(QSIZEF_VALUE(size) / divisor);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QSIZEF_VALUE(lhs) == QSIZEF_VALUE(rhs);
    }

    // ext methods block for: Size::HandleRef ====
    OwnedRef ext_Size_toSizeF(Size::HandleRef this_) {
        return SIZEF_HEAP_NEW(AS_QSIZE_PTR(this_)->toSizeF());
    }
    // ==============================
}
