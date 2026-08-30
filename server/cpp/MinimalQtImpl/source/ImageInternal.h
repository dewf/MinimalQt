#pragma once

#include "generated/Image.h"
#include <QImage>

#define AS_QIMAGE_PTR(x) (reinterpret_cast<QImage*>(x))
#define QIMAGE_VALUE(x) (x != nullptr ? *AS_QIMAGE_PTR(x) : QImage())
#define IMAGE_HEAP_NEW(...) (reinterpret_cast<Image::OwnedRef>(new QImage(__VA_ARGS__)))

namespace Image {
}
