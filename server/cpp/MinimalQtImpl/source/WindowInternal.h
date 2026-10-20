#pragma once

#include "generated/Window.h"
#include <QWindow>

#define AS_QWINDOW_PTR(x) (reinterpret_cast<QWindow*>(x))

namespace Window {
}
