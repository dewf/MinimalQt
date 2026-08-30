#pragma once

#include "generated/TextOption.h"
#include <QTextOption>

#define AS_QTEXTOPTION_PTR(x) (reinterpret_cast<QTextOption*>(x))
#define QTEXTOPTION_VALUE(x) (x != nullptr ? *AS_QTEXTOPTION_PTR(x) : QTextOption())
#define TEXTOPTION_HEAP_NEW(...) (reinterpret_cast<TextOption::OwnedRef>(new QTextOption(__VA_ARGS__)))

namespace TextOption {
}
