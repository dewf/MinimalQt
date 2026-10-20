#pragma once

#include "generated/Application.h"
#include <QApplication>

#define AS_QAPPLICATION_PTR(x) (reinterpret_cast<QApplication*>(x))

namespace Application {
}
