#include "generated/ItemSelectionModel.h"
#include "ItemSelectionModelInternal.h"

#include "ModelIndexInternal.h"
#include "ItemSelectionInternal.h"
#include "util/convert.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QItemSelectionModel*>(_this))

namespace ItemSelectionModel
{
    std::vector<ModelIndex::OwnedRef> Handle_selectedIndexes(HandleRef _this) {
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(THIS->selectedIndexes(), [](auto index) {
            return new ModelIndex::__Owned(index);
        });
    }

    bool Handle_columnIntersectsSelection(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->columnIntersectsSelection(column, fromOptionalIndex(parent));
    }

    ModelIndex::OwnedRef Handle_currentIndex(HandleRef _this) {
        return new ModelIndex::__Owned(THIS->currentIndex());
    }

    bool Handle_hasSelection(HandleRef _this) {
        return THIS->hasSelection();
    }

    bool Handle_isColumnSelected(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->isColumnSelected(column, fromOptionalIndex(parent));
    }

    bool Handle_isRowSelected(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->isRowSelected(row, fromOptionalIndex(parent));
    }

    bool Handle_isSelected(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->isSelected(index->value);
    }

    bool Handle_rowIntersectsSelection(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->rowIntersectsSelection(row, fromOptionalIndex(parent));
    }

    std::vector<ModelIndex::OwnedRef> Handle_selectedColumns(HandleRef _this, const std::optional<int32_t>& row) {
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(THIS->selectedColumns(row.value_or(0)), [](auto index) {
            return new ModelIndex::__Owned(index);
        });
    }

    std::vector<ModelIndex::OwnedRef> Handle_selectedRows(HandleRef _this, const std::optional<int32_t>& column) {
        return fromQList<QModelIndex,ModelIndex::OwnedRef>(THIS->selectedRows(column.value_or(0)), [](auto index) {
            return new ModelIndex::__Owned(index);
        });
    }

    ItemSelection::OwnedRef Handle_selection(HandleRef _this) {
        return ITEMSELECTION_HEAP_NEW(THIS->selection());
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_clearCurrentIndex(HandleRef _this) {
        THIS->clearCurrentIndex();
    }

    void Handle_clearSelection(HandleRef _this) {
        THIS->clearSelection();
    }

    void Handle_reset(HandleRef _this) {
        THIS->reset();
    }

    void Handle_select(HandleRef _this, ItemSelection::HandleRef selection, SelectionFlags command) {
        THIS->select(QITEMSELECTION_VALUE(selection), static_cast<QItemSelectionModel::SelectionFlags>(command.value));
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef index, SelectionFlags command) {
        THIS->select(index->value, static_cast<QItemSelectionModel::SelectionFlags>(command.value));
    }

    void Handle_setCurrentIndex(HandleRef _this, ModelIndex::HandleRef index, SelectionFlags command) {
        THIS->setCurrentIndex(index->value, static_cast<QItemSelectionModel::SelectionFlags>(command.value));
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            ModelIndex::__Owned current2(current);
            ModelIndex::__Owned previous2(previous);
            handler->currentChanged(&current2, &previous2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentColumnChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentColumnChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            ModelIndex::__Owned current2(current);
            ModelIndex::__Owned previous2(previous);
            handler->currentColumnChanged(&current2, &previous2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentRowChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentRowChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            ModelIndex::__Owned current2(current);
            ModelIndex::__Owned previous2(previous);
            handler->currentRowChanged(&current2, &previous2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::modelChanged, [handler](QAbstractItemModel *model) {
            handler->modelChanged(reinterpret_cast<AbstractItemModel::HandleRef>(model));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::selectionChanged, [handler](const QItemSelection &selected, const QItemSelection &deselected) {
            handler->selectionChanged((ItemSelection::HandleRef)&selected, (ItemSelection::HandleRef)&deselected);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }
}
