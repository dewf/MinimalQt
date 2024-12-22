#pragma once

#include <QFont>

// from Font::Handle to QFont*
#define AS_QFONT_PTR(x) (reinterpret_cast<QFont*>(x))

// from Font::Handle to QFont value
#define QFONT_VALUE(x) (*AS_QFONT_PTR(x))

// create an owned, heap-allocated copy of existing QFont value
#define FONT_HEAP_NEW(x) (reinterpret_cast<Font::OwnedRef>(new QFont(x)))

namespace Font {
    // nothing yet
}
