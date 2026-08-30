#pragma once

#include "generated/Margins.h"
#include <QMargins>

#define AS_QMARGINS_PTR(x) (reinterpret_cast<QMargins*>(x))
#define QMARGINS_VALUE(x) (x != nullptr ? *AS_QMARGINS_PTR(x) : QMargins())
#define MARGINS_HEAP_NEW(...) (reinterpret_cast<Margins::OwnedRef>(new QMargins(__VA_ARGS__)))

namespace Margins {
}
