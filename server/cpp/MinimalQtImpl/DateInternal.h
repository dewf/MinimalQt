#pragma once

#include "generated/Date.h"
#include <QDate>

#define AS_QDATE_PTR(x) (reinterpret_cast<QDate*>(x))
#define QDATE_VALUE(x) (*AS_QDATE_PTR(x))
#define DATE_HEAP_NEW(...) (reinterpret_cast<Date::OwnedRef>(new QDate(__VA_ARGS__)))

namespace Date {
}
