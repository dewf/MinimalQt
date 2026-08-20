#pragma once

#include "generated/Pen.h"
#include <QPen>

#define AS_QPEN_PTR(x) (reinterpret_cast<QPen*>(x))
#define QPEN_VALUE(x) (*AS_QPEN_PTR(x))
#define PEN_HEAP_NEW(...) (reinterpret_cast<Pen::OwnedRef>(new QPen(__VA_ARGS__)))

namespace Pen {
}
