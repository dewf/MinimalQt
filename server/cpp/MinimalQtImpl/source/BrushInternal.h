#pragma once

#include "generated/Brush.h"
#include <QBrush>

#define AS_QBRUSH_PTR(x) (reinterpret_cast<QBrush*>(x))
#define QBRUSH_VALUE(x) (x != nullptr ? *AS_QBRUSH_PTR(x) : QBrush())
#define BRUSH_HEAP_NEW(...) (reinterpret_cast<Brush::OwnedRef>(new QBrush(__VA_ARGS__)))

namespace Brush {
}
