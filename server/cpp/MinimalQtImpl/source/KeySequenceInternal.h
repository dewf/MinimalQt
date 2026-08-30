#pragma once

#include <QKeySequence>

#define AS_QKEYSEQ_PTR(x) (reinterpret_cast<QKeySequence*>(x))
#define QKEYSEQ_VALUE(x) (x != nullptr ? *AS_QKEYSEQ_PTR(x) : QKeySequence())
#define KEYSEQ_HEAP_NEW(...) (reinterpret_cast<KeySequence::OwnedRef>(new QKeySequence(__VA_ARGS__)))

namespace KeySequence {
}
