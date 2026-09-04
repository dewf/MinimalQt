#pragma once

#include "generated/ItemSelectionModel.h"

#include <QItemSelectionModel>

#define AS_QITEMSELECTIONMODEL_PTR(x) (reinterpret_cast<QItemSelectionModel*>(x))

#define AS_QITEMSELECTION_PTR(x) (reinterpret_cast<QItemSelection*>(x))
#define QITEMSELECTION_VALUE(x) (x != nullptr ? *AS_QITEMSELECTION_PTR(x) : QItemSelection())
#define ITEMSELECTION_HEAP_NEW(...) (reinterpret_cast<ItemSelection::OwnedRef>(new QItemSelection(__VA_ARGS__)))

namespace ItemSelectionModel {
}
