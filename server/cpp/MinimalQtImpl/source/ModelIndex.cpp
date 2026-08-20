#include "generated/ModelIndex.h"
#include "ModelIndexInternal.h"

#include "VariantInternal.h"

#include "util/convert.h"
#include <QList>

using namespace ::Variant;
using namespace ::Enums;

#define THIS (AS_QMODELINDEX_PTR(_this))

namespace ModelIndex
{
    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(*THIS));
    }

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

    Flags<ItemFlags> Handle_getFlags(HandleRef _this) {
        return static_cast<Flags<ItemFlags>>(THIS->flags());
    }

    size_t Handle_internalId(HandleRef _this) {
        return THIS->internalId();
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
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

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QMODELINDEX_VALUE(lhs) != QMODELINDEX_VALUE(rhs);
    }

    bool operator_lessThan(HandleRef lhs, HandleRef rhs) {
        return QMODELINDEX_VALUE(lhs) < QMODELINDEX_VALUE(rhs);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QMODELINDEX_VALUE(lhs) == QMODELINDEX_VALUE(rhs);
    }

    // list ========================================================
#define LIST_THIS (reinterpret_cast<QList<QModelIndex>*>(_this))

    int32_t List_count(ListRef _this) {
        return LIST_THIS->count();
    }

    OwnedRef List_itemAt(ListRef _this, int32_t index) {
        return MODELINDEX_HEAP_NEW(LIST_THIS->at(index));
    }

    std::vector<OwnedRef> List_items(ListRef _this) {
        return fromQList<QModelIndex,OwnedRef>(*LIST_THIS, [](const auto &item) {
            return MODELINDEX_HEAP_NEW(item);
        });
    }

    void OwnedList_dispose(OwnedListRef _this) {
        delete LIST_THIS;
    }
}
