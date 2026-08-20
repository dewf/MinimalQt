#pragma once

#include "generated/MarginsF.h"
#include <QMarginsF>

#define AS_QMARGINSF_PTR(x) (reinterpret_cast<QMarginsF*>(x))
#define QMARGINSF_VALUE(x) (*AS_QMARGINSF_PTR(x))
#define MARGINSF_HEAP_NEW(...) (reinterpret_cast<MarginsF::OwnedRef>(new QMarginsF(__VA_ARGS__)))

namespace MarginsF {
}
