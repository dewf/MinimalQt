#pragma once

#include "generated/SessionManager.h"
#include <QSessionManager>

#define AS_QSESSIONMANAGER_PTR(x) (reinterpret_cast<QSessionManager*>(x))

namespace SessionManager {
}
