#pragma once

#include "generated/Image.h"
#include <QImage>
#include <utility>
#include "CommonInternal.h" // for PaintStackItem
#include "PaintDeviceInternal.h"

#define AS_QIMAGE_PTR(x) (reinterpret_cast<QImage*>(x))
#define QIMAGE_VALUE(x) (*AS_QIMAGE_PTR(x))
#define IMAGE_HEAP_NEW(...) (reinterpret_cast<Image::OwnedRef>(new QImage(__VA_ARGS__)))

namespace Image {
}
