#pragma once

#include "generated/SplitterHandle.h"
#include <QSplitterHandle>

#define AS_QSPLITTERHANDLE_PTR(x) (reinterpret_cast<QSplitterHandle*>(x))

namespace SplitterHandle {
}
