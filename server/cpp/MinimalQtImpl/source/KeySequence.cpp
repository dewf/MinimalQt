#include "generated/KeySequence.h"
#include "KeySequenceInternal.h"

using namespace ::Enums;

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
        if (other != nullptr)
        {
            THIS->swap(*AS_QKEYSEQ_PTR(other));
        } else
        {
            *THIS = QKeySequence();
        }
    }

    std::string Handle_toString2(HandleRef _this, SequenceFormat format /* SequenceFormat::PortableText */) {
        return THIS->toString(static_cast<QKeySequence::SequenceFormat>(format)).toStdString();
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

    OwnedRef create(const std::string& key, SequenceFormat format /* SequenceFormat::NativeText */) {
        return KEYSEQ_HEAP_NEW(QString::fromStdString(key), static_cast<QKeySequence::SequenceFormat>(format));
    }

    OwnedRef create(Key key, Flags<KeyboardModifiers> modifiers) {
        const auto key2 = static_cast<Qt::Key>(key);
        const auto mods2 = static_cast<Qt::KeyboardModifiers>(modifiers.value()); // warning: typicaly int/uint Qt nonsense
        return KEYSEQ_HEAP_NEW(key2 | mods2);
    }

    OwnedRef create(HandleRef other) {
        return KEYSEQ_HEAP_NEW(QKEYSEQ_VALUE(other));
    }
}
