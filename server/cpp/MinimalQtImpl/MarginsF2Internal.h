#pragma once

#include "generated/MarginsF2.h"
#include <QMarginsF>

#define AS_QMARGINSF_PTR(x) (reinterpret_cast<QMarginsF*>(x))
#define QMARGINSF_VALUE(x) (*AS_QMARGINSF_PTR(x))
#define MARGINSF_HEAP_NEW(...) (reinterpret_cast<MarginsF2::OwnedRef>(new QMarginsF(__VA_ARGS__)))

namespace MarginsF2 {
}
