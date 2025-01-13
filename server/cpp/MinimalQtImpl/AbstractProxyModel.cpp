#include "generated/AbstractProxyModel.h"
#include "AbstractProxyModelInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "ItemSelectionInternal.h"

#define THIS (reinterpret_cast<QAbstractProxyModel*>(_this))

namespace AbstractProxyModel
{

    ModelIndex::OwnedRef Handle_mapFromSource(HandleRef _this, ModelIndex::HandleRef sourceIndex) {
        return new ModelIndex::__Owned { THIS->mapFromSource(sourceIndex->value) };
    }

    ItemSelection::OwnedRef Handle_mapSelectionFromSource(HandleRef _this, ItemSelection::HandleRef sourceSelection) {
        const auto ret = THIS->mapSelectionFromSource(QITEMSELECTION_VALUE(sourceSelection));
        return ITEMSELECTION_HEAP_NEW(ret);
    }

    ItemSelection::OwnedRef Handle_mapSelectionToSource(HandleRef _this, ItemSelection::HandleRef proxySelection) {
        const auto ret = THIS->mapSelectionToSource(QITEMSELECTION_VALUE(proxySelection));
        return ITEMSELECTION_HEAP_NEW(ret);
    }

    ModelIndex::OwnedRef Handle_mapToSource(HandleRef _this, ModelIndex::HandleRef proxyIndex) {
        return new ModelIndex::__Owned { THIS->mapFromSource(proxyIndex->value) };
    }

    void Handle_setSourceModel(HandleRef _this, AbstractItemModel::HandleRef sourceModel) {
        THIS->setSourceModel(reinterpret_cast<QAbstractItemModel*>(sourceModel));
    }

    AbstractItemModel::HandleRef Handle_sourceModel(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->sourceModel());
    }

    SignalConnectionRef Handle_connect_SourceModelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractProxyModel::sourceModelChanged, [handler] {
            handler->sourceModelChanged();
        });
        return new __SignalConnection { connection };
    }
}
