#pragma once

#include "generated/StatusBar.h"
#include <QStatusBar>

#define AS_QSTATUSBAR_PTR(x) (reinterpret_cast<QStatusBar*>(x))

namespace StatusBar {
}
