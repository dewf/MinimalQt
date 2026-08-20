#pragma once

#include "generated/Screen.h"
#include <QScreen>

#define AS_QSCREEN_PTR(x) (reinterpret_cast<QScreen*>(x))

namespace Screen {
}
