#pragma once

#include "generated/RegularExpression.h"
#include <QRegularExpression>

#define AS_QREGEX_PTR(x) (reinterpret_cast<QRegularExpression*>(x))
#define QREGEX_VALUE(x) (x != nullptr ? *AS_QREGEX_PTR(x) : QRegularExpression())
#define REGEX_HEAP_NEW(...) (reinterpret_cast<RegularExpression::OwnedRef>(new QRegularExpression(__VA_ARGS__)))

namespace RegularExpression {
}

