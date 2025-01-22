#pragma once

#include "generated/Variant.h"
#include <QVariant>

#define AS_QVARIANT_PTR(x) (reinterpret_cast<QVariant*>(x))
#define QVARIANT_VALUE(x) (*AS_QVARIANT_PTR(x))
#define VARIANT_HEAP_NEW(...) (reinterpret_cast<Variant::OwnedRef>(new QVariant(__VA_ARGS__)))

namespace Variant {
    inline QVariant fromOptional(const std::optional<HandleRef>& x) {
        QVariant ret;
        if (x.has_value()) ret = QVARIANT_VALUE(x.value());
        return ret;
    }
}
