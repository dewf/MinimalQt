#pragma once

#include "generated/Color.h"
#include <QColor>

#define AS_QCOLOR_PTR(x) (reinterpret_cast<QColor*>(x))
#define QCOLOR_VALUE(x) (x != nullptr ? *AS_QCOLOR_PTR(x) : QColor())
#define COLOR_HEAP_NEW(...) (reinterpret_cast<Color::OwnedRef>(new QColor(__VA_ARGS__)))

namespace Color {
    // QColor fromConstant(Constant name);
}
