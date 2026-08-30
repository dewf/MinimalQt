#pragma once

#include "generated/SizePolicy.h"
#include <QSizePolicy>

#define AS_QSIZEPOLICY_PTR(x) (reinterpret_cast<QSizePolicy*>(x))
#define QSIZEPOLICY_VALUE(x) (x != nullptr ? *AS_QSIZEPOLICY_PTR(x) : QSizePolicy())
#define SIZEPOLICY_HEAP_NEW(...) (reinterpret_cast<SizePolicy::OwnedRef>(new QSizePolicy(__VA_ARGS__)))

namespace SizePolicy {
}
