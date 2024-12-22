#include "generated/KeySequence.h"

#include "KeySequenceInternal.h"

#define THIS ((QKeySequence*)_this)

namespace KeySequence
{
    class FromDeferredMatcher : public Deferred::Matcher {
    private:
        QKeySequence &seq;
    public:
        explicit FromDeferredMatcher(QKeySequence &seq) : seq(seq) {}
        void onFromString(const Deferred::FromString *fromString) override {
            seq = { QString::fromStdString(fromString->s) };
        }
        void onFromStandard(const Deferred::FromStandard *fromStandard) override {
            seq = { (QKeySequence::StandardKey)fromStandard->key };
        }
        void onFromKey(const Deferred::FromKey *fromKey) override {
            // could have also used a QKeyCombination instead of 'key | mods'
            auto key = static_cast<Qt::Key>(fromKey->key);
            auto mods = static_cast<Qt::Modifiers>(fromKey->modifiers);
            seq = { key | mods };
        }
        void onFromHandle(const Deferred::FromHandle *value) override {
            seq = KEYSEQ_VALUE(value->handle);
        }
    };

    QKeySequence fromDeferred(const std::shared_ptr<Deferred::Base>& deferred) {
        QKeySequence seq;
        FromDeferredMatcher matcher(seq);
        deferred->match(&matcher);
        return seq;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create(const std::string& s) {
        return KEYSEQ_HEAP_NEW(QString::fromStdString(s));
    }

    OwnedRef create(StandardKey key) {
        return KEYSEQ_HEAP_NEW(static_cast<QKeySequence::StandardKey>(key));
    }

    OwnedRef create(Key key, Modifiers modifiers) {
        auto key2 = static_cast<Qt::Key>(key);
        auto mods2 = static_cast<Qt::Modifiers>(modifiers);
        return KEYSEQ_HEAP_NEW(key2 | mods2);
    }
}
