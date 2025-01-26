#include "generated/ModelIndex.h"
#include "ModelIndexInternal.h"

#include "VariantInternal.h"

using namespace ::Variant;
using namespace ::Enums;

#define THIS (AS_QMODELINDEX_PTR(_this))

namespace ModelIndex
{
    int32_t Handle_column(HandleRef _this) {
        return THIS->column();
    }

    Variant::OwnedRef Handle_data(HandleRef _this) {
        return VARIANT_HEAP_NEW(THIS->data());
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ItemDataRole role /* ItemDataRole::DisplayRole */) {
        auto qRole = static_cast<Qt::ItemDataRole>(role);
        return VARIANT_HEAP_NEW(THIS->data(qRole));
    }

    ItemFlags Handle_getFlags(HandleRef _this) {
        return ItemFlags(THIS->flags());
    }

    size_t Handle_internalId(HandleRef _this) {
        return THIS->internalId();
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    AbstractItemModelHandleRef Handle_model(HandleRef _this) {
        return (AbstractItemModelHandleRef)THIS->model();
    }

    OwnedRef Handle_parent(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->parent());
    }

    int32_t Handle_row(HandleRef _this) {
        return THIS->row();
    }

    OwnedRef Handle_sibling(HandleRef _this, int32_t row, int32_t column) {
        return MODELINDEX_HEAP_NEW(THIS->sibling(row, column));
    }

    OwnedRef Handle_siblingAtColumn(HandleRef _this, int32_t column) {
        return MODELINDEX_HEAP_NEW(THIS->siblingAtColumn(column));
    }

    OwnedRef Handle_siblingAtRow(HandleRef _this, int32_t row) {
        return MODELINDEX_HEAP_NEW(THIS->siblingAtRow(row));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return MODELINDEX_HEAP_NEW();
    }
}
