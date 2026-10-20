#pragma once

#include "generated/MainWindow.h"

#include <QMainWindow>

#define AS_QMAINWINDOW_PTR(x) (reinterpret_cast<QMainWindow*>(x))

namespace MainWindow {
}
