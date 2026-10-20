#pragma once

#include "generated/CoreApplication.h"
#include <QCoreApplication>

#define AS_QCOREAPPLICATION_PTR(x) (reinterpret_cast<QCoreApplication*>(x))

namespace CoreApplication {
}
