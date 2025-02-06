#pragma once

#include "generated/Point2.h"
#include <QPoint>

#define AS_QPOINT_PTR(x) (reinterpret_cast<QPoint*>(x))
#define QPOINT_VALUE(x) (*AS_QPOINT_PTR(x))
#define POINT_HEAP_NEW(...) (reinterpret_cast<Point2::OwnedRef>(new QPoint(__VA_ARGS__)))

namespace Point2 {
}
