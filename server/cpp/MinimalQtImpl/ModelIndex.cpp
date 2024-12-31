#include "generated/ModelIndex.h"

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

// #define WRAPPER (AS_QMODELINDEX_PTR(_this)) // RefCountedWrapper<QModelIndex>*
#define WRAPPER (_this)
#define VALUE (WRAPPER->value)

namespace ModelIndex
{
    bool Handle_isValid(HandleRef _this) {
        return VALUE.isValid();
   }

    int32_t Handle_row(HandleRef _this) {
        return VALUE.row();
    }

    int32_t Handle_column(HandleRef _this) {
        return VALUE.column();
    }

    Variant::OwnedRef Handle_data(HandleRef _this) {
        return new Variant::__Owned(VALUE.data());
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ItemDataRole role) {
        auto qRole = static_cast<Qt::ItemDataRole>(role);
        return new Variant::__Owned(VALUE.data(qRole));
    }

    SafeReturnRef Owned_getSafeReturn(OwnedRef _this) {
        WRAPPER->addRef();
        // return "as" a different type, but not really - this is just to enforce API safety requiring us to call this method to safely return the opaques from a client interface (which is normally unsafe)
        return reinterpret_cast<SafeReturnRef>(_this);
    }

    void Owned_dispose(OwnedRef _this) {
        WRAPPER->release();
    }

    void SafeReturn_dispose(SafeReturnRef _this) {
        WRAPPER->release();
    }

    OwnedRef create() {
        return new __Owned(QModelIndex());
    }
}
