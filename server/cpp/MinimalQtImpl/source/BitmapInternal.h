#pragma once

#include "generated/Bitmap.h"
#include <QBitmap>

#define AS_QBITMAP_PTR(x) (reinterpret_cast<QBitmap*>(x))
#define QBITMAP_VALUE(x) (x != nullptr ? *AS_QBITMAP_PTR(x) : QBitmap())
#define BITMAP_HEAP_NEW(...) (reinterpret_cast<Bitmap::OwnedRef>(new QBitmap(__VA_ARGS__)))

namespace Bitmap {
}
