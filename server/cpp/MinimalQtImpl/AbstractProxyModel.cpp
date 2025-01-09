#include "generated/AbstractProxyModel.h"
#include "AbstractProxyModelInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"

#include <QModelIndex>

#define THIS (reinterpret_cast<QAbstractProxyModel*>(_this))

namespace AbstractProxyModel
{
    AbstractItemModel::HandleRef Handle_sourceModel(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->sourceModel());
    }

    void Handle_setSourceModel(HandleRef _this, AbstractItemModel::HandleRef sourceModel) {
        THIS->setSourceModel(reinterpret_cast<QAbstractItemModel*>(sourceModel));
    }

    ModelIndex::OwnedRef Handle_mapToSource(HandleRef _this, ModelIndex::HandleRef proxyIndex) {
        const auto retValue = THIS->mapToSource(proxyIndex->value);
        return new ModelIndex::__Owned(retValue);
    }

    SignalConnectionRef Handle_connect_SourceModelChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractProxyModel::sourceModelChanged, [handler] {
            handler->sourceModelChanged();
        });
        return new __SignalConnection { connection };
    }
}
