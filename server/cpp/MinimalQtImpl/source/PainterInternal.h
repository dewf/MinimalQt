#pragma once

#include "generated/Painter.h"
#include <QPainter>

#define AS_QPAINTER_PTR(x) (reinterpret_cast<QPainter*>(x))
#define QPAINTER_VALUE(x) (x != nullptr ? *AS_QPAINTER_PTR(x) : QPainter())
#define PAINTER_HEAP_NEW(...) (reinterpret_cast<OwnedRef>(new QPainter(__VA_ARGS__)))

#define AS_QPIXMAPFRAGMENT_PTR(x) (reinterpret_cast<QPainter::PixmapFragment*>(x))
#define QPIXMAPFRAGMENT_VALUE(x) (x != nullptr ? *AS_QPIXMAPFRAGMENT_PTR(x) : QPainter::PixmapFragment())
#define PIXMAPFRAGMENT_HEAP_NEW(...) (reinterpret_cast<Painter::PixmapFragment::OwnedRef>(new QPainter::PixmapFragment(__VA_ARGS__)))

namespace Painter {
}
