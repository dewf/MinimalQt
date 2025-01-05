#pragma once

#include <QIcon>

// from a Icon::Handle to an QIcon*
#define AS_QICON_PTR(x) (reinterpret_cast<QIcon*>(x))

// from a Icon::Handle to a Icon value
#define QICON_VALUE(x) (*AS_QICON_PTR(x))

// create an owned heap-allocated copy of an existing QIcon value
#define ICON_HEAP_NEW(...) (reinterpret_cast<Icon::OwnedRef>(new QIcon(__VA_ARGS__)))

namespace Icon {
}
