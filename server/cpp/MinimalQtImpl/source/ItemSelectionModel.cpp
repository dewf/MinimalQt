#include "generated/ItemSelectionModel.h"
#include "ItemSelectionModelInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::ModelIndex;
using namespace ::AbstractItemModel;

#define THIS (reinterpret_cast<QItemSelectionModel*>(_this))

namespace ItemSelectionModel
{
    bool Handle_columnIntersectsSelection(HandleRef _this, int32_t column, ::ModelIndex::HandleRef parent) {
        return THIS->columnIntersectsSelection(column, QMODELINDEX_VALUE(parent));
    }

    ModelIndex::OwnedRef Handle_currentIndex(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->currentIndex());
    }

    bool Handle_hasSelection(HandleRef _this) {
        return THIS->hasSelection();
    }

    bool Handle_isColumnSelected(HandleRef _this, int32_t column, ::ModelIndex::HandleRef parent) {
        return THIS->isColumnSelected(column, QMODELINDEX_VALUE(parent));
    }

    bool Handle_isRowSelected(HandleRef _this, int32_t row, ::ModelIndex::HandleRef parent) {
        return THIS->isRowSelected(row, QMODELINDEX_VALUE(parent));
    }

    bool Handle_isSelected(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->isSelected(QMODELINDEX_VALUE(index));
    }

    AbstractItemModel::HandleRef Handle_model(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->model());
    }

    bool Handle_rowIntersectsSelection(HandleRef _this, int32_t row, ::ModelIndex::HandleRef parent) {
        return THIS->rowIntersectsSelection(row, QMODELINDEX_VALUE(parent));
    }

    OwnedListRef Handle_selectedColumns(HandleRef _this, int32_t row /* 0 */) {
        return MODELINDEX_LIST_HEAP_NEW(THIS->selectedColumns(row));
    }

    OwnedListRef Handle_selectedIndexes(HandleRef _this) {
        return MODELINDEX_LIST_HEAP_NEW(THIS->selectedIndexes());
    }

    OwnedListRef Handle_selectedRows(HandleRef _this, int32_t column /* 0 */) {
        return MODELINDEX_LIST_HEAP_NEW(THIS->selectedRows(column));
    }

    ItemSelection::OwnedRef Handle_selection(HandleRef _this) {
        return ITEMSELECTION_HEAP_NEW(THIS->selection());
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
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

    void Handle_select(HandleRef _this, ItemSelection::HandleRef selection, Flags<SelectionFlags> command) {
        THIS->select(QITEMSELECTION_VALUE(selection), static_cast<QItemSelectionModel::SelectionFlags>(command.value()));
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef index, Flags<SelectionFlags> command) {
        THIS->select(QMODELINDEX_VALUE(index), static_cast<QItemSelectionModel::SelectionFlags>(command.value()));
    }

    void Handle_setCurrentIndex(HandleRef _this, ModelIndex::HandleRef index, Flags<SelectionFlags> command) {
        THIS->setCurrentIndex(QMODELINDEX_VALUE(index), static_cast<QItemSelectionModel::SelectionFlags>(command.value()));
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            QModelIndex current2(current);
            QModelIndex previous2(previous);
            handler->sig_currentChanged(reinterpret_cast<ModelIndex::HandleRef>(&current2), reinterpret_cast<ModelIndex::HandleRef>(reinterpret_cast<ModelIndex::HandleRef>(&previous2)));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentColumnChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentColumnChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            QModelIndex current2(current);
            QModelIndex previous2(previous);
            handler->sig_currentColumnChanged(reinterpret_cast<ModelIndex::HandleRef>(&current2), reinterpret_cast<ModelIndex::HandleRef>(&previous2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentRowChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::currentRowChanged, [handler](const QModelIndex &current, const QModelIndex &previous) {
            QModelIndex current2(current);
            QModelIndex previous2(previous);
            handler->sig_currentRowChanged(reinterpret_cast<ModelIndex::HandleRef>(&current2), reinterpret_cast<ModelIndex::HandleRef>(&previous2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::modelChanged, [handler](QAbstractItemModel *model) {
            handler->sig_modelChanged(reinterpret_cast<AbstractItemModel::HandleRef>(model));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QItemSelectionModel::selectionChanged, [handler](const QItemSelection &selected, const QItemSelection &deselected) {
            QItemSelection selected2(selected);
            QItemSelection deselected2(deselected);
            handler->sig_selectionChanged(reinterpret_cast<ItemSelection::HandleRef>(&selected2), reinterpret_cast<ItemSelection::HandleRef>(&deselected2));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto model = AS_QITEMSELECTIONMODEL_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(model);
        }
        std::unreachable();
    }

    HandleRef create(AbstractItemModel::HandleRef model /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QItemSelectionModel(reinterpret_cast<QAbstractItemModel*>(model)));
    }

    HandleRef create(AbstractItemModel::HandleRef model, Object::HandleRef parent) {
        return reinterpret_cast<HandleRef>(new QItemSelectionModel(reinterpret_cast<QAbstractItemModel*>(model), AS_QOBJECT_PTR(parent)));
    }

    // ItemSelection stuff ====================================================
#define ITEMSELECTION_THIS (AS_QITEMSELECTION_PTR(_this))

    namespace ItemSelection {
        bool Handle_contains(HandleRef _this, ModelIndex::HandleRef index) {
            return ITEMSELECTION_THIS->contains(QMODELINDEX_VALUE(index));
        }

        OwnedListRef Handle_indexes(HandleRef _this) {
            return MODELINDEX_LIST_HEAP_NEW(ITEMSELECTION_THIS->indexes());
        }

        void Handle_merge(HandleRef _this, HandleRef other, Flags<SelectionFlags> command) {
            ITEMSELECTION_THIS->merge(QITEMSELECTION_VALUE(other), static_cast<QItemSelectionModel::SelectionFlags>(command.value()));
        }

        void Handle_select(HandleRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
            ITEMSELECTION_THIS->select(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight));
        }

        void Owned_dispose(OwnedRef _this) {
            delete ITEMSELECTION_THIS;
        }

        OwnedRef create() {
            return ITEMSELECTION_HEAP_NEW();
        }

        OwnedRef create(ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
            return ITEMSELECTION_HEAP_NEW(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight));
        }
    }

}
