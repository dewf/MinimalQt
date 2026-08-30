#pragma once

#include "generated/DateTime.h"
#include <QDateTime>

#define AS_QDATETIME_PTR(x) (reinterpret_cast<QDateTime*>(x))
#define QDATETIME_VALUE(x) (x != nullptr ? *AS_QDATETIME_PTR(x) : QDateTime())
#define DATETIME_HEAP_NEW(...) (reinterpret_cast<DateTime::OwnedRef>(new QDateTime(__VA_ARGS__)))

namespace DateTime {
}
