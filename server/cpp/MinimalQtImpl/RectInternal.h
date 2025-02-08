#pragma once

#include "generated/Rect.h"
#include <QRect>

#define AS_QRECT_PTR(x) (reinterpret_cast<QRect*>(x))
#define QRECT_VALUE(x) (*AS_QRECT_PTR(x))
#define RECT_HEAP_NEW(...) (reinterpret_cast<Rect::OwnedRef>(new QRect(__VA_ARGS__)))

namespace Rect {
}
