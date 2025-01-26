#include "generated/SizePolicy.h"
#include "SizePolicyInternal.h"

using namespace ::Enums;

#define THIS (AS_QSIZEPOLICY_PTR(_this))

namespace SizePolicy
{
    ControlType Handle_getControlType(HandleRef _this) {
        return static_cast<ControlType>(THIS->controlType());
    }

    Orientations Handle_expandingDirections(HandleRef _this) {
        return Orientations(THIS->expandingDirections());
    }

    bool Handle_hasHeightForWidth(HandleRef _this) {
        return THIS->hasHeightForWidth();
    }

    bool Handle_hasWidthForHeight(HandleRef _this) {
        return THIS->hasWidthForHeight();
    }

    Policy Handle_horizontalPolicy(HandleRef _this) {
        return THIS->horizontalPolicy();
    }

    int32_t Handle_horizontalStretch(HandleRef _this) {
        return THIS->horizontalStretch();
    }

    bool Handle_retainSizeWhenHidden(HandleRef _this) {
        return THIS->retainSizeWhenHidden();
    }

    void Handle_setControlType(HandleRef _this, ControlType type_) {
        THIS->setControlType(static_cast<QSizePolicy::ControlType>(type_));
    }

    void Handle_setHeightForWidth(HandleRef _this, bool dependent) {
        THIS->setHeightForWidth(dependent);
    }

    void Handle_setHorizontalPolicy(HandleRef _this, Policy policy) {
        THIS->setHorizontalPolicy(static_cast<QSizePolicy::Policy>(policy.value));
    }

    void Handle_setHorizontalStretch(HandleRef _this, int32_t stretchFactor) {
        THIS->setHorizontalStretch(stretchFactor);
    }

    void Handle_setRetainSizeWhenHidden(HandleRef _this, bool retainSize) {
        THIS->setRetainSizeWhenHidden(retainSize);
    }

    void Handle_setVerticalPolicy(HandleRef _this, Policy policy) {
        THIS->setVerticalPolicy(static_cast<QSizePolicy::Policy>(policy.value));
    }

    void Handle_setVerticalStretch(HandleRef _this, int32_t stretchFactor) {
        THIS->setVerticalStretch(stretchFactor);
    }

    void Handle_setWidthForHeight(HandleRef _this, bool dependent) {
        THIS->setWidthForHeight(dependent);
    }

    void Handle_transpose(HandleRef _this) {
        THIS->transpose();
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return SIZEPOLICY_HEAP_NEW(THIS->transposed());
    }

    Policy Handle_verticalPolicy(HandleRef _this) {
        return THIS->verticalPolicy();
    }

    int32_t Handle_verticalStretch(HandleRef _this) {
        return THIS->verticalStretch();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return SIZEPOLICY_HEAP_NEW();
    }

    OwnedRef create(Policy horizontal, Policy vertical, ControlType type_ /* ControlType::DefaultType */) {
        const auto qType = static_cast<QSizePolicy::ControlType>(type_);
        return SIZEPOLICY_HEAP_NEW(static_cast<QSizePolicy::Policy>(horizontal.value), static_cast<QSizePolicy::Policy>(vertical.value), qType);
    }
}
