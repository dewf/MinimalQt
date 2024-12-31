#include "generated/AbstractProxyModel.h"
#include "AbstractProxyModelInternal.h"

#include <QModelIndex>

#include "ModelIndexInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSPROXYMODEL_THIS (WRAPPER->getActual())

namespace AbstractProxyModel
{
    AbstractItemModel::HandleRef Handle_sourceModel(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(ABSPROXYMODEL_THIS->sourceModel());
    }

    void Handle_setSourceModel(HandleRef _this, AbstractItemModel::HandleRef sourceModel) {
        ABSPROXYMODEL_THIS->setSourceModel(reinterpret_cast<QAbstractItemModel*>(sourceModel));
    }

    ModelIndex::OwnedRef Handle_mapToSource(HandleRef _this, ModelIndex::HandleRef proxyIndex) {
        auto retValue = ABSPROXYMODEL_THIS->mapToSource(proxyIndex->value);
        return new ModelIndex::__Owned(retValue);
    }
}
