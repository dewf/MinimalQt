#pragma once

#include "generated/RectF2.h"
#include <QRectF>

#define AS_QRECTF_PTR(x) (reinterpret_cast<QRectF*>(x))
#define QRECTF_VALUE(x) (*AS_QRECTF_PTR(x))
#define RECTF_HEAP_NEW(...) (reinterpret_cast<RectF2::OwnedRef>(new QRectF(__VA_ARGS__)))

namespace RectF2 {
}
