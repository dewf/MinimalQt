#pragma once

#include "generated/SizeF.h"
#include <QSizeF>

#define AS_QSIZEF_PTR(x) (reinterpret_cast<QSizeF*>(x))
#define QSIZEF_VALUE(x) (*AS_QSIZEF_PTR(x))
#define SIZEF_HEAP_NEW(...) (reinterpret_cast<SizeF::OwnedRef>(new QSizeF(__VA_ARGS__)));

namespace SizeF {
}
