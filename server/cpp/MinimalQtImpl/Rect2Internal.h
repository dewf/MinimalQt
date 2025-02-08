#pragma once

#include "generated/Rect2.h"
#include <QRect>

#define AS_QRECT_PTR(x) (reinterpret_cast<QRect*>(x))
#define QRECT_VALUE(x) (*AS_QRECT_PTR(x))
#define RECT_HEAP_NEW(...) (reinterpret_cast<Rect2::OwnedRef>(new QRect(__VA_ARGS__)))

namespace Rect2 {
}
