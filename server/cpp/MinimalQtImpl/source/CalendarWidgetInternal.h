#pragma once

#include "generated/CalendarWidget.h"
#include "WidgetInternal.h"

#include <QCalendarWidget>

#define AS_QCALENDARWIDGET_PTR(x) (reinterpret_cast<QCalendarWidget*>(x))

namespace CalendarWidget {
}
