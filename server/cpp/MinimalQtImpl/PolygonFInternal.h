#pragma once

#include "generated/PolygonF.h"
#include <QPolygonF>

#define AS_QPOLYGONF_PTR(x) (reinterpret_cast<QPolygonF*>(x))
#define QPOLYGONF_VALUE(x) (*AS_QPOLYGONF_PTR(x))
#define POLYGONF_HEAP_NEW(...) (reinterpret_cast<PolygonF::OwnedRef>(new QPolygonF(__VA_ARGS__)))

namespace PolygonF {
}
