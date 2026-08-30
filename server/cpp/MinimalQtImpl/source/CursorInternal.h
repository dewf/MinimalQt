#pragma once

#include "generated/Cursor.h"
#include <QCursor>

#define AS_QCURSOR_PTR(x) (reinterpret_cast<QCursor*>(x))
#define QCURSOR_VALUE(x) (x != nullptr ? *AS_QCURSOR_PTR(x) : QCursor())
#define CURSOR_HEAP_NEW(...) (reinterpret_cast<Cursor::OwnedRef>(new QCursor(__VA_ARGS__)))

namespace Cursor {
}
