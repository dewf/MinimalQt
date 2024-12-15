#pragma once

#include <QRegularExpression>
#include "generated/RegularExpression.h"

namespace RegularExpression {
    class FromDeferredMatcher : public Deferred::Matcher {
    private:
        QRegularExpression &qRegex;
    public:
        explicit FromDeferredMatcher(QRegularExpression &qRegex) : qRegex(qRegex) {}

        void onEmpty(const Deferred::Empty *empty) override {
            qRegex = QRegularExpression("");
        }

        void onRegex(const Deferred::Regex *regex) override {
            auto opts = (int)regex->opts;
            qRegex = QRegularExpression(QString::fromStdString(regex->pattern), static_cast<QRegularExpression::PatternOptions>(opts));
        }
    };

    QRegularExpression fromDeferred(const std::shared_ptr<Deferred::Base>& deferred);
}

