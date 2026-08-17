#include "generated/PersistentModelIndex.h"
#include "PersistentModelIndexInternal.h"

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

#include <QList>

#include "util/convert.h"

using namespace ::ModelIndex;
using namespace ::Variant;
using namespace ::Enums;

#define THIS (AS_QPERSISTENTMODELINDEX_PTR(_this))

namespace PersistentModelIndex
{
    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(*THIS));
    }

    int32_t Handle_column(HandleRef _this) {
        return THIS->column();
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ItemDataRole role /* ItemDataRole::DisplayRole */) {
        return VARIANT_HEAP_NEW(THIS->data(static_cast<int>(role)));
    }

    Flags<ItemFlags> Handle_flags_(HandleRef _this) {
        return static_cast<Flags<ItemFlags>>(THIS->flags());
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    ModelIndex::OwnedRef Handle_parent(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->parent());
    }

    int32_t Handle_row(HandleRef _this) {
        return THIS->row();
    }

    ModelIndex::OwnedRef Handle_sibling(HandleRef _this, int32_t row, int32_t column) {
        return MODELINDEX_HEAP_NEW(THIS->sibling(row, column));
    }

    ModelIndex::OwnedRef Handle_asModelIndex(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(*THIS);
    }

    HandleRef Handle_operator_assign(HandleRef _this, HandleRef other) {
        THIS->operator=(QPERSISTENTMODELINDEX_VALUE(other));
        return _this;
    }

    HandleRef Handle_operator_assign(HandleRef _this, ModelIndex::HandleRef other) {
        THIS->operator=(QMODELINDEX_VALUE(other));
        return _this;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create(ModelIndex::HandleRef index) {
        return PERSISTENTMODELINDEX_HEAP_NEW(QMODELINDEX_VALUE(index));
    }

    OwnedRef create(HandleRef other) {
        return PERSISTENTMODELINDEX_HEAP_NEW(QPERSISTENTMODELINDEX_VALUE(other));
    }

    bool operator_notEqual(HandleRef lhs, ModelIndex::HandleRef rhs) {
        return QPERSISTENTMODELINDEX_VALUE(lhs) != QMODELINDEX_VALUE(rhs);
    }

    bool operator_notEqual(HandleRef lhs, HandleRef rhs) {
        return QPERSISTENTMODELINDEX_VALUE(lhs) != QPERSISTENTMODELINDEX_VALUE(rhs);
    }

    bool operator_lessThan(HandleRef lhs, HandleRef rhs) {
        return QPERSISTENTMODELINDEX_VALUE(lhs) < QPERSISTENTMODELINDEX_VALUE(rhs);
    }

    bool operator_equal(HandleRef lhs, ModelIndex::HandleRef rhs) {
        return QPERSISTENTMODELINDEX_VALUE(lhs) == QMODELINDEX_VALUE(rhs);
    }

    bool operator_equal(HandleRef lhs, HandleRef rhs) {
        return QPERSISTENTMODELINDEX_VALUE(lhs) == QPERSISTENTMODELINDEX_VALUE(rhs);
    }

    // list ===========================================================================
#define LIST_THIS (reinterpret_cast<QList<QPersistentModelIndex>*>(_this))

    int32_t List_count(ListRef _this) {
        return LIST_THIS->count();
    }

    OwnedRef List_itemAt(ListRef _this, int32_t index) {
        return PERSISTENTMODELINDEX_HEAP_NEW(LIST_THIS->at(index));
    }

    std::vector<OwnedRef> List_items(ListRef _this) {
        return fromQList<QPersistentModelIndex,OwnedRef>(*LIST_THIS, [](const auto& index) {
            return PERSISTENTMODELINDEX_HEAP_NEW(index);
        });
    }

    void OwnedList_dispose(OwnedListRef _this) {
        delete LIST_THIS;
    }
}
