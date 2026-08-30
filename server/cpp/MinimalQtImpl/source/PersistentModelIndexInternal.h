#pragma once

#include "generated/PersistentModelIndex.h"
#include <QPersistentModelIndex>

#define AS_QPERSISTENTMODELINDEX_PTR(x) (reinterpret_cast<QPersistentModelIndex*>(x))
#define QPERSISTENTMODELINDEX_VALUE(x) (x != nullptr ? *AS_QPERSISTENTMODELINDEX_PTR(x) : QPersistentModelIndex())
#define PERSISTENTMODELINDEX_HEAP_NEW(...) (reinterpret_cast<PersistentModelIndex::OwnedRef>(new QPersistentModelIndex(__VA_ARGS__)))

namespace PersistentModelIndex {
}
