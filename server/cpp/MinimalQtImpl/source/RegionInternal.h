#pragma once

#include "generated/Region.h"
#include <QRegion>

#define AS_QREGION_PTR(x) (reinterpret_cast<QRegion*>(x))
#define QREGION_VALUE(x) (*AS_QREGION_PTR(x))
#define REGION_HEAP_NEW(...) (reinterpret_cast<Region::OwnedRef>(new QRegion(__VA_ARGS__)))

namespace Region {
}

