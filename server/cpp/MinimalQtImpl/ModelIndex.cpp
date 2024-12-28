#include "generated/ModelIndex.h"

#include <QModelIndex>
#include "ModelIndexInternal.h"
#include "VariantInternal.h"

#define THIS (AS_MODELINDEX_PTR(_this))

namespace ModelIndex
{
    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
   }

    int32_t Handle_row(HandleRef _this) {
        return THIS->row();
    }

    int32_t Handle_column(HandleRef _this) {
        return THIS->column();
    }

    Variant::OwnedRef Handle_data(HandleRef _this) {
        return VARIANT_HEAP_NEW(THIS->data());
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ItemDataRole role) {
        auto qrole = static_cast<Qt::ItemDataRole>(role);
        return VARIANT_HEAP_NEW(THIS->data(qrole));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return reinterpret_cast<OwnedRef>(new QModelIndex());
    }
}
