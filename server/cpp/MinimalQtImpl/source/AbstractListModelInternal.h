#pragma once

#include "generated/AbstractListModel.h"
#include "AbstractItemModelInternal.h"

#include <QAbstractListModel>

#define AS_QABSTRACTLISTMODEL_PTR(x) (reinterpret_cast<QAbstractListModel*>(x))

namespace AbstractListModel {
}
