#pragma once

#include "generated/Transform.h"
#include <QTransform>

#define AS_QTRANSFORM_PTR(x) (reinterpret_cast<QTransform*>(x))
#define QTRANSFORM_VALUE(x) (*AS_QTRANSFORM_PTR(x))
#define TRANSFORM_HEAP_NEW(...) (reinterpret_cast<Transform::OwnedRef>(new QTransform(__VA_ARGS__)))

namespace Transform {
}
