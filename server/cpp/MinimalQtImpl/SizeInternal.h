#pragma once

#include "generated/Size.h"
#include <QSize>

#define AS_QSIZE_PTR(x) (reinterpret_cast<QSize*>(x))
#define QSIZE_VALUE(x) (*AS_QSIZE_PTR(x))
#define SIZE_HEAP_NEW(...) (reinterpret_cast<Size::OwnedRef>(new QSize(__VA_ARGS__)))

namespace Size {
}
