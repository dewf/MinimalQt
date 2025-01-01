#pragma once

#include "generated/ModelIndex.h"
#include <QModelIndex>

#include "util/RefCountedWrapper.h"

namespace ModelIndex {
    struct __Handle : RefCountedWrapper<QModelIndex> {
        explicit __Handle(const QModelIndex &init) : RefCountedWrapper(init) {}
    };
    struct __Owned : __Handle {
        explicit __Owned(const QModelIndex &init) : __Handle(init) {}
    };
    // note: these are never actually created/instantiated, we just reinterpret OwnedRef as SafeReturnRef for API purposes
    struct __SafeReturn : __Owned {};

    inline QModelIndex fromOptionalIndex(const std::optional<HandleRef>& maybeValue) {
        if (maybeValue.has_value()) {
            return maybeValue.value()->value;
        }
        return {};
    }
}
