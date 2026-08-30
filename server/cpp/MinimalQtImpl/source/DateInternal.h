#pragma once

#include "generated/Date.h"
#include <QDate>

#define AS_QDATE_PTR(x) (reinterpret_cast<QDate*>(x))
#define QDATE_VALUE(x) (x != nullptr ? *AS_QDATE_PTR(x) : QDate())
#define DATE_HEAP_NEW(...) (reinterpret_cast<Date::OwnedRef>(new QDate(__VA_ARGS__)))

namespace Date {
}
