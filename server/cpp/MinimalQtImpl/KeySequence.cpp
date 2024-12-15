#include "generated/KeySequence.h"

#include "KeySequenceInternal.h"

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
            auto key = (Qt::Key)fromKey->key;
            auto mods = (Qt::Modifiers)fromKey->modifiers;
            seq = { key | mods };
        }
    };

    QKeySequence fromDeferred(const std::shared_ptr<Deferred::Base>& deferred) {
        QKeySequence seq;
        FromDeferredMatcher matcher(seq);
        deferred->match(&matcher);
        return seq;
    }
}
