#pragma once

#include "generated/MenuBar.h"
#include <QMenuBar>

#define AS_QMENUBAR_PTR(x) (reinterpret_cast<QMenuBar*>(x))

namespace MenuBar {
}
