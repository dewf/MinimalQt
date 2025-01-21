#pragma once

#include "generated/Variant.h"
#include <QVariant>

#include "util/RefCountedWrapper.h"

namespace Variant {
    struct __Handle : RefCountedWrapper<QVariant> {
        explicit __Handle(const QVariant &init) : RefCountedWrapper(init) {}
    };
    struct __Owned : __Handle {
        explicit __Owned(const QVariant &init) : __Handle(init) {}
        void addRef() {
            addRefInternal();
        }
        void release() {
            releaseInternal();
        }
    };
    // note: these are never actually created/instantiated, we just reinterpret OwnedRef as SafeReturnRef for API purposes
    struct __SafeReturn : __Owned {
        QVariant consume() {
            return consumeInternal();
        }
    };
    inline QVariant fromOptional(const std::optional<HandleRef>& x) {
        QVariant ret;
        if (x.has_value()) ret = x.value()->value;
        return ret;
    }
}
