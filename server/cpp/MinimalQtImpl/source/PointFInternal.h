#pragma once

#include "generated/PointF.h"
#include <QPointF>

#define AS_QPOINTF_PTR(x) (reinterpret_cast<QPointF*>(x))
#define QPOINTF_VALUE(x) (*AS_QPOINTF_PTR(x))
#define POINTF_HEAP_NEW(...) (reinterpret_cast<PointF::OwnedRef>(new QPointF(__VA_ARGS__)))

namespace PointF {
}
