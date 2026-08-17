#pragma once

#include "generated/AbstractItemDelegate.h"
#include "ObjectInternal.h"

#include <QAbstractItemDelegate>

#define AS_QABSTRACTITEMDELEGATE_PTR(x) (reinterpret_cast<QAbstractItemDelegate*>(x))

namespace AbstractItemDelegate {
}
