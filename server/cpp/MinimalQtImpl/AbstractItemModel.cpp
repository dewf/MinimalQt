#include "generated/AbstractItemModel.h"
#include "AbstractItemModelInternal.h"

#include <QModelIndex>

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSITEMMODEL_THIS (WRAPPER->getActual())

namespace AbstractItemModel
{
    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column) {
        auto value = ABSITEMMODEL_THIS->index(row, column);
        return MODELINDEX_HEAP_COPY(value);
    }

    ModelIndex::OwnedRef Handle_index(HandleRef _this, int32_t row, int32_t column, ModelIndex::HandleRef parent) {
        auto value = ABSITEMMODEL_THIS->index(row, column, QMODELINDEX_VALUE(parent));
        return MODELINDEX_HEAP_COPY(value);
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value) {
        return ABSITEMMODEL_THIS->setData(QMODELINDEX_VALUE(index), QVARIANT_VALUE(value));
    }

    bool Handle_setData(HandleRef _this, ModelIndex::HandleRef index, Variant::HandleRef value, ItemDataRole role) {
        auto qrole = static_cast<Qt::ItemDataRole>(role);
        return ABSITEMMODEL_THIS->setData(QMODELINDEX_VALUE(index), QVARIANT_VALUE(value), qrole);
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index) {
        auto value = ABSITEMMODEL_THIS->data(QMODELINDEX_VALUE(index));
        return VARIANT_HEAP_NEW(value);
    }

    Variant::OwnedRef Handle_data(HandleRef _this, ModelIndex::HandleRef index, ItemDataRole role) {
        auto qrole = static_cast<Qt::ItemDataRole>(role);
        auto value = ABSITEMMODEL_THIS->data(QMODELINDEX_VALUE(index), qrole);
        return VARIANT_HEAP_NEW(value);
    }

    void Handle_sort(HandleRef _this, int32_t column) {
        ABSITEMMODEL_THIS->sort(column);
    }

    void Handle_sort(HandleRef _this, int32_t column, SortOrder order) {
        auto qorder = static_cast<Qt::SortOrder>(order);
        ABSITEMMODEL_THIS->sort(column, qorder);
    }
}
