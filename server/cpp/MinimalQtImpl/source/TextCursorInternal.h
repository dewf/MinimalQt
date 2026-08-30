#pragma once

#include "generated/TextCursor.h"
#include <QTextCursor>

#define AS_QTEXTCURSOR_PTR(x) (reinterpret_cast<QTextCursor*>(x))
#define QTEXTCURSOR_VALUE(x) (x != nullptr ? *AS_QTEXTCURSOR_PTR(x) : QTextCursor())
#define TEXTCURSOR_HEAP_NEW(...) (reinterpret_cast<TextCursor::OwnedRef>(new QTextCursor(__VA_ARGS__)))

namespace TextCursor {
}
