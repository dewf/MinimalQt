#pragma once

#include "generated/TextCharFormat.h"
#include <QTextCharFormat>

#define AS_QTEXTCHARFORMAT_PTR(x) (reinterpret_cast<QTextCharFormat*>(x))
#define QTEXTCHARFORMAT_VALUE(x) (x != nullptr ? *AS_QTEXTCHARFORMAT_PTR(x) : QTextCharFormat())
#define TEXTCHARFORMAT_HEAP_NEW(...) (reinterpret_cast<TextCharFormat::OwnedRef>(new QTextCharFormat(__VA_ARGS__)))

namespace TextCharFormat {
}
