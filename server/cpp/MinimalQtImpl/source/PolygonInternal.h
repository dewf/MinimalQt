#pragma once

#include "generated/Polygon.h"
#include <QPolygon>

#define AS_QPOLYGON_PTR(x) (reinterpret_cast<QPolygon*>(x))
#define QPOLYGON_VALUE(x) (x != nullptr ? *AS_QPOLYGON_PTR(x) : QPolygon())
#define POLYGON_HEAP_NEW(...) (reinterpret_cast<Polygon::OwnedRef>(new QPolygon(__VA_ARGS__)))

namespace Polygon {
}
