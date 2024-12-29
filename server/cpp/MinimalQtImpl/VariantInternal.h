#pragma once

#include "generated/Variant.h"
#include <QVariant>
#include "IconInternal.h"

#include "util/RefCountedWrapper.h"

// #define AS_QVARIANT_PTR(x) (reinterpret_cast<QVariant*>(x))
// #define QVARIANT_VALUE(x) (*AS_QVARIANT_PTR(x))
// #define VARIANT_HEAP_NEW(...) (reinterpret_cast<Variant::OwnedRef>(new QVariant(__VA_ARGS__)))

typedef RefCountedWrapper<QVariant> RefCountedVariant;

#define AS_QVARIANT_PTR(x) (reinterpret_cast<RefCountedVariant*>(x))
#define QVARIANT_VALUE(x) (AS_QVARIANT_PTR(x)->value)
#define VARIANT_HEAP_NEW(...) (reinterpret_cast<Variant::OwnedRef>(new RefCountedVariant(QVariant(__VA_ARGS__))))

namespace Variant {
}
