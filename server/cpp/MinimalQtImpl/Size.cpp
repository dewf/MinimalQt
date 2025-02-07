#include "generated/Size.h"
#include "SizeInternal.h"

#include "SizeF2Internal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Enums;

#define THIS (AS_QSIZE_PTR(_this))

namespace Size
{
    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(QSIZE_VALUE(_this)));
    }

    OwnedRef Handle_boundedTo(HandleRef _this, HandleRef otherSize) {
        return SIZE_HEAP_NEW(THIS->boundedTo(QSIZE_VALUE(otherSize)));
    }

    OwnedRef Handle_expandedTo(HandleRef _this, HandleRef otherSize) {
        return SIZE_HEAP_NEW(THIS->expandedTo(QSIZE_VALUE(otherSize)));
    }

    OwnedRef Handle_grownBy(HandleRef _this, Margins margins) {
        return SIZE_HEAP_NEW(THIS->grownBy(toQMargins(margins)));
    }

    int32_t Handle_height(HandleRef _this) {
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

    void Handle_scale(HandleRef _this, int32_t width, int32_t height, AspectRatioMode mode) {
        THIS->scale(width, height, static_cast<Qt::AspectRatioMode>(mode));
    }

    void Handle_scale(HandleRef _this, HandleRef size, AspectRatioMode mode) {
        THIS->scale(QSIZE_VALUE(size), static_cast<Qt::AspectRatioMode>(mode));
    }

    OwnedRef Handle_scaled(HandleRef _this, int32_t width, int32_t height, AspectRatioMode mode) {
        return SIZE_HEAP_NEW(THIS->scaled(width, height, static_cast<Qt::AspectRatioMode>(mode)));
    }

    OwnedRef Handle_scaled(HandleRef _this, HandleRef s, AspectRatioMode mode) {
        return SIZE_HEAP_NEW(THIS->scaled(QSIZE_VALUE(s), static_cast<Qt::AspectRatioMode>(mode)));
    }

    void Handle_setHeight(HandleRef _this, int32_t height) {
        THIS->setHeight(height);
    }

    void Handle_setWidth(HandleRef _this, int32_t width) {
        THIS->setWidth(width);
    }

    OwnedRef Handle_shrunkBy(HandleRef _this, Margins margins) {
        return SIZE_HEAP_NEW(THIS->shrunkBy(toQMargins(margins)));
    }

    SizeF_OwnedRef Handle_toSizeF(HandleRef _this) {
        const auto result = SIZEF_HEAP_NEW(THIS->toSizeF());
        return reinterpret_cast<SizeF_OwnedRef>(result); // fwdopaque cast
    }

    void Handle_transpose(HandleRef _this) {
        THIS->transpose();
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->transposed());
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    HandleRef Handle_operator_multiplyBy(HandleRef _this, double factor) {
        THIS->operator*=(factor);
        return _this;
    }

    HandleRef Handle_operator_incrementBy(HandleRef _this, HandleRef size) {
        THIS->operator+=(QSIZE_VALUE(size));
        return _this;
    }

    HandleRef Handle_operator_decrementBy(HandleRef _this, HandleRef size) {
        THIS->operator-=(QSIZE_VALUE(size));
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
        return SIZE_HEAP_NEW();
    }

    OwnedRef create(int32_t width, int32_t height) {
        return SIZE_HEAP_NEW(width, height);
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QSIZE_VALUE(lhs) != QSIZE_VALUE(rhs);
    }

    OwnedRef operator_mul(HandleRef size, double factor) {
        return SIZE_HEAP_NEW(QSIZE_VALUE(size) * factor);
    }

    OwnedRef operator_add(HandleRef s1, HandleRef s2) {
        return SIZE_HEAP_NEW(QSIZE_VALUE(s1) + QSIZE_VALUE(s2));
    }

    OwnedRef operator_sub(HandleRef s1, HandleRef s2) {
        return SIZE_HEAP_NEW(QSIZE_VALUE(s1) - QSIZE_VALUE(s2));
    }

    OwnedRef operator_div(HandleRef size, double divisor) {
        return SIZE_HEAP_NEW(QSIZE_VALUE(size) / divisor);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QSIZE_VALUE(lhs) == QSIZE_VALUE(rhs);
    }
}
