#include "generated/KeySequence.h"
#include "KeySequenceInternal.h"

#define THIS (AS_QKEYSEQ_PTR(_this))

namespace KeySequence
{
    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    SequenceMatch Handle_matches(HandleRef _this, HandleRef seq) {
        return static_cast<SequenceMatch>(THIS->matches(QKEYSEQ_VALUE(seq)));
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        THIS->swap(QKEYSEQ_VALUE(other));
    }

    std::string Handle_toString2(HandleRef _this, const std::optional<SequenceFormat>& format) {
        const auto qFormat = static_cast<QKeySequence::SequenceFormat>(format.value_or(SequenceFormat::PortableText));
        return THIS->toString(qFormat).toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return KEYSEQ_HEAP_NEW();
    }

    OwnedRef create(StandardKey key) {
        return KEYSEQ_HEAP_NEW(static_cast<QKeySequence::StandardKey>(key));
    }

    OwnedRef create(const std::string& key, const std::optional<SequenceFormat>& format) {
        const auto qFormat = static_cast<QKeySequence::SequenceFormat>(format.value_or(SequenceFormat::NativeText));
        return KEYSEQ_HEAP_NEW(QString::fromStdString(key), qFormat);
    }

    OwnedRef create(Key key, Modifiers modifiers) {
        auto key2 = static_cast<Qt::Key>(key);
        auto mods2 = static_cast<Qt::Modifiers>(modifiers.value);
        return KEYSEQ_HEAP_NEW(key2 | mods2);
    }

    OwnedRef create(HandleRef other) {
        return KEYSEQ_HEAP_NEW(QKEYSEQ_VALUE(other));
    }
}
