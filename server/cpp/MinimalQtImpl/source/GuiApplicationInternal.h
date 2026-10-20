#pragma once

#include "generated/GuiApplication.h"
#include <QGuiApplication>

#define AS_QGUIAPPLICATION_PTR(x) (reinterpret_cast<QGuiApplication*>(x))

namespace GuiApplication {
}
