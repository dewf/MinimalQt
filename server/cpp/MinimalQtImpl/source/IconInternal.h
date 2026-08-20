#pragma once

#include "generated/Icon.h"
#include <QIcon>

#define AS_QICON_PTR(x) (reinterpret_cast<QIcon*>(x))
#define QICON_VALUE(x) (*AS_QICON_PTR(x))
#define ICON_HEAP_NEW(...) (reinterpret_cast<Icon::OwnedRef>(new QIcon(__VA_ARGS__)))

namespace Icon {
}
