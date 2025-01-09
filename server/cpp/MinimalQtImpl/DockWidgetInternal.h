#pragma once

#include "generated/DockWidget.h"
#include "WidgetInternal.h"

#include <QDockWidget.h>

#define AS_QDOCKWIDGET_PTR(x) (reinterpret_cast<QDockWidget*>(x))

namespace DockWidget {
}
