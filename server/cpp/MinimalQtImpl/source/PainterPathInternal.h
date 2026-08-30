#pragma once

#include "generated/PainterPath.h"
#include <QPainterPath>

#define AS_QPAINTERPATH_PTR(x) (reinterpret_cast<QPainterPath*>(x))
#define QPAINTERPATH_VALUE(x) (x != nullptr ? *AS_QPAINTERPATH_PTR(x) : QPainterPath())
#define PAINTERPATH_HEAP_NEW(...) (reinterpret_cast<PainterPath::OwnedRef>(new QPainterPath(__VA_ARGS__)))

namespace PainterPath {
}
