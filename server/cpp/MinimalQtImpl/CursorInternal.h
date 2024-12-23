#pragma once

#include "generated/Cursor.h"

#include <QCursor>

#define AS_QCURSOR_PTR(x) (reinterpret_cast<QCursor*>(x))
#define QCURSOR_VALUE(x) (*AS_QCURSOR_PTR(x))
#define CURSOR_HEAP_NEW(x) (reinterpret_cast<Cursor::OwnedRef>(new QCursor(x)))

