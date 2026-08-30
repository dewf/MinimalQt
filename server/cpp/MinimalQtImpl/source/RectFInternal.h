#pragma once

#include "generated/RectF.h"
#include <QRectF>

#define AS_QRECTF_PTR(x) (reinterpret_cast<QRectF*>(x))
#define QRECTF_VALUE(x) (x != nullptr ? *AS_QRECTF_PTR(x) : QRectF())
#define RECTF_HEAP_NEW(...) (reinterpret_cast<RectF::OwnedRef>(new QRectF(__VA_ARGS__)))

namespace RectF {
}
