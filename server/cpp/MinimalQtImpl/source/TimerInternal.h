#pragma once

#include "generated/Timer.h"
#include <QTimer>

#define AS_QTIMER_PTR(x) (reinterpret_cast<QTimer*>(x))

namespace Timer {
}
