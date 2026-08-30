#pragma once

#include "generated/Pixmap.h"
#include <QPixmap>

#define AS_QPIXMAP_PTR(x) (reinterpret_cast<QPixmap*>(x))
#define QPIXMAP_VALUE(x) (x != nullptr ? *AS_QPIXMAP_PTR(x) : QPixmap())
#define PIXMAP_HEAP_NEW(...) (reinterpret_cast<Pixmap::OwnedRef>(new QPixmap(__VA_ARGS__)))

namespace Pixmap {
}
