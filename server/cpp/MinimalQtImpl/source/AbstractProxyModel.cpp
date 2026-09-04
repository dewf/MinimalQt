#include "generated/AbstractProxyModel.h"
#include "AbstractProxyModelInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "ItemSelectionModelInternal.h"

using namespace ::Object;
using namespace ::Enums;
using namespace ::AbstractItemModel;
using namespace ::ModelIndex;
using namespace ::PersistentModelIndex;
using namespace ::ItemSelectionModel;

#define THIS (reinterpret_cast<QAbstractProxyModel*>(_this))

namespace AbstractProxyModel
{

    ModelIndex::OwnedRef Handle_mapFromSource(HandleRef _this, ModelIndex::HandleRef sourceIndex) {
        return MODELINDEX_HEAP_NEW(THIS->mapFromSource(QMODELINDEX_VALUE(sourceIndex)));
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
        return MODELINDEX_HEAP_NEW(THIS->mapFromSource(QMODELINDEX_VALUE(proxyIndex)));
    }

    void Handle_setSourceModel(HandleRef _this, AbstractItemModel::HandleRef sourceModel) {
        THIS->setSourceModel(reinterpret_cast<QAbstractItemModel*>(sourceModel));
    }

    AbstractItemModel::HandleRef Handle_sourceModel(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->sourceModel());
    }

    SignalConnectionRef Handle_connect_SourceModelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractProxyModel::sourceModelChanged, [handler] {
            handler->sig_sourceModelChanged();
        });
        return new __SignalConnection { connection };
    }
}
