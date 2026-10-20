#pragma once

#include "generated/AbstractItemModel.h"
#include <QAbstractItemModel>

#define AS_QABSTRACTITEMMODEL_PTR(x) (reinterpret_cast<QAbstractItemModel*>(x))

namespace AbstractItemModel {
}
