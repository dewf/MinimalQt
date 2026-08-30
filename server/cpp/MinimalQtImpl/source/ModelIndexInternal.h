#pragma once

#include "generated/ModelIndex.h"
#include <QModelIndex>

#define AS_QMODELINDEX_PTR(x) (reinterpret_cast<QModelIndex*>(x))
#define QMODELINDEX_VALUE(x) (x != nullptr ? *AS_QMODELINDEX_PTR(x) : QModelIndex())
#define MODELINDEX_HEAP_NEW(...) (reinterpret_cast<ModelIndex::OwnedRef>(new QModelIndex(__VA_ARGS__)))

#define MODELINDEX_LIST_HEAP_NEW(...) (reinterpret_cast<ModelIndex::OwnedListRef>(new QModelIndexList(__VA_ARGS__)))

namespace ModelIndex {
    inline QModelIndex fromOptionalIndex(const std::optional<HandleRef>& x) {
        QModelIndex ret;
        if (x.has_value()) ret = QMODELINDEX_VALUE(x.value());
        return ret;
    }
}
