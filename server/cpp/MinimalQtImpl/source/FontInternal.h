#pragma once

#include <QFont>

#define AS_QFONT_TAG_PTR(x) (reinterpret_cast<QFont::Tag*>(x))
#define QFONT_TAG_VALUE(x) (*AS_QFONT_TAG_PTR(x))
#define FONT_TAG_HEAP_NEW(...) (reinterpret_cast<Font::Tag::OwnedRef>(new QFont::Tag(__VA_ARGS__)))

#define AS_QFONT_PTR(x) (reinterpret_cast<QFont*>(x))
#define QFONT_VALUE(x) (*AS_QFONT_PTR(x))
#define FONT_HEAP_NEW(...) (reinterpret_cast<Font::OwnedRef>(new QFont(__VA_ARGS__)))

namespace Font {
    // nothing yet
}
