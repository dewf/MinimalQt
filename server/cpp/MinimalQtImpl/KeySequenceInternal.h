#pragma once

#include <QKeySequence>

// from a KeySequence::Handle to a QKeySequence*
#define AS_KEYSEQ_PTR(x) (reinterpret_cast<QKeySequence*>(x))

// from a KeySequence::Handle to a QKeySequence value
#define KEYSEQ_VALUE(x) (*AS_KEYSEQ_PTR(x))

// create an owned heap-allocated copy of an existing QKeySequence value
#define KEYSEQ_HEAP_NEW(x) (reinterpret_cast<KeySequence::OwnedRef>(new QKeySequence(x)))

namespace KeySequence {
    // struct __Handle {
    //     QKeySequence seq;
    //     explicit __Handle(const QKeySequence &seq) : seq(seq) {}
    // };
    // struct __Owned : __Handle {
    //     explicit __Owned(const QKeySequence &seq) : __Handle(seq) {}
    // };
    QKeySequence fromDeferred(const std::shared_ptr<Deferred::Base>& deferred);
}
