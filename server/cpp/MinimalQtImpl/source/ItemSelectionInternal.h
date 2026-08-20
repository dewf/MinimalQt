#pragma once

#include <QItemSelection>

#define AS_QITEMSELECTION_PTR(x) (reinterpret_cast<QItemSelection*>(x))
#define QITEMSELECTION_VALUE(x) (*AS_QITEMSELECTION_PTR(x))
#define ITEMSELECTION_HEAP_NEW(...) (reinterpret_cast<ItemSelection::OwnedRef>(new QItemSelection(__VA_ARGS__)))

namespace ItemSelection {
}
