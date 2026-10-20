#pragma once

#include "generated/ProgressBar.h"
#include <QProgressBar>

#define AS_QPROGRESSBAR_PTR(x) (reinterpret_cast<QProgressBar*>(x))

namespace ProgressBar {
}
