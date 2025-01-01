#include "generated/ItemSelectionModel.h"
#include "ItemSelectionModelInternal.h"

#include "ModelIndexInternal.h"
#include "ItemSelectionInternal.h"
#include <algorithm>

#define WRAPPER (reinterpret_cast<ItemSelectionModel::SignalWrapper*>(_this))
#define ITEMSELMODEL_THIS (WRAPPER->getActual())

namespace ItemSelectionModel
{
    std::vector<ModelIndex::OwnedRef> Handle_selectedIndexes(HandleRef _this) {
        std::vector<ModelIndex::OwnedRef> result;
        for (const auto &index : ITEMSELMODEL_THIS->selectedIndexes()) {
            result.push_back(new ModelIndex::__Owned(index));
        }
        return result;
    }

    bool Handle_columnIntersectsSelection(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return ITEMSELMODEL_THIS->columnIntersectsSelection(column, fromOptionalIndex(parent));
    }

    ModelIndex::OwnedRef Handle_currentIndex(HandleRef _this) {
        return new ModelIndex::__Owned(ITEMSELMODEL_THIS->currentIndex());
    }

    bool Handle_hasSelection(HandleRef _this) {
        return ITEMSELMODEL_THIS->hasSelection();
    }

    bool Handle_isColumnSelected(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return ITEMSELMODEL_THIS->isColumnSelected(column, fromOptionalIndex(parent));
    }

    bool Handle_isRowSelected(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return ITEMSELMODEL_THIS->isRowSelected(row, fromOptionalIndex(parent));
    }

    bool Handle_isSelected(HandleRef _this, ModelIndex::HandleRef index) {
        return ITEMSELMODEL_THIS->isSelected(index->value);
    }

    bool Handle_rowIntersectsSelection(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return ITEMSELMODEL_THIS->rowIntersectsSelection(row, fromOptionalIndex(parent));
    }

    std::vector<ModelIndex::OwnedRef> Handle_selectedColumns(HandleRef _this, const std::optional<int32_t>& row) {
        std::vector<ModelIndex::OwnedRef> result;
        for (const auto &index : ITEMSELMODEL_THIS->selectedColumns(row.value_or(0))) {
            result.push_back(new ModelIndex::__Owned(index));
        }
        return result;
    }

    std::vector<ModelIndex::OwnedRef> Handle_selectedRows(HandleRef _this, const std::optional<int32_t>& column) {
        std::vector<ModelIndex::OwnedRef> result;
        for (const auto &index : ITEMSELMODEL_THIS->selectedRows(column.value_or(0))) {
            result.push_back(new ModelIndex::__Owned(index));
        }
        return result;
    }

    ItemSelection::OwnedRef Handle_selection(HandleRef _this) {
        return ITEMSELECTION_HEAP_NEW(ITEMSELMODEL_THIS->selection());
    }

    void Handle_clear(HandleRef _this) {
        ITEMSELMODEL_THIS->clear();
    }

    void Handle_clearCurrentIndex(HandleRef _this) {
        ITEMSELMODEL_THIS->clearCurrentIndex();
    }

    void Handle_clearSelection(HandleRef _this) {
        ITEMSELMODEL_THIS->clearSelection();
    }

    void Handle_reset(HandleRef _this) {
        ITEMSELMODEL_THIS->reset();
    }

    void Handle_select(HandleRef _this, ItemSelection::HandleRef selection, SelectionFlags command) {
        ITEMSELMODEL_THIS->select(QITEMSELECTION_VALUE(selection), static_cast<QItemSelectionModel::SelectionFlags>(command));
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef index, SelectionFlags command) {
        ITEMSELMODEL_THIS->select(index->value, static_cast<QItemSelectionModel::SelectionFlags>(command));
    }

    void Handle_setCurrentIndex(HandleRef _this, ModelIndex::HandleRef index, SelectionFlags command) {
        ITEMSELMODEL_THIS->setCurrentIndex(index->value, static_cast<QItemSelectionModel::SelectionFlags>(command));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask signalMask) {
        WRAPPER->setSignalMask(signalMask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }
}
