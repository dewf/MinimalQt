#pragma once

#include "generated/Painter.h"

#include <QPainter>

#define AS_QPAINTER_PTR(x) (reinterpret_cast<QPainter*>(x))
// #define AS_QPAINTER_VALUE
// #define PAINTER_HEAP_NEW

namespace Painter {
}
