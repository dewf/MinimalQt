#pragma once

#include "generated/Margins2.h"
#include <QMargins>

#define AS_QMARGINS_PTR(x) (reinterpret_cast<QMargins*>(x))
#define QMARGINS_VALUE(x) (*AS_QMARGINS_PTR(x))
#define MARGINS_HEAP_NEW(...) (reinterpret_cast<Margins2::OwnedRef>(new QMargins(__VA_ARGS__)))

namespace Margins2 {
}
