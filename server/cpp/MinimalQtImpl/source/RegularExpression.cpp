#include "generated/RegularExpression.h"
#include "RegularExpressionInternal.h"
#include "util/convert.h"

using namespace ::Enums;

#define THIS (AS_QREGEX_PTR(_this))

namespace RegularExpression
{
    namespace Match {
#define MATCH_THIS (AS_QREGEX_MATCH_PTR(_this))
        void Owned_dispose(OwnedRef _this) {
            delete MATCH_THIS;
        }
    }

    namespace MatchIterator {
#define MATCHITERATOR_THIS (AS_QREGEX_MATCHITERATOR_PTR(_this))
        bool Handle_hasNext(HandleRef _this) {
            return MATCHITERATOR_THIS->hasNext();
        }

        bool Handle_isValid(HandleRef _this) {
            return MATCHITERATOR_THIS->isValid();
        }

        Flags<MatchOptions> Handle_getMatchOptions(HandleRef _this) {
            return Flags<MatchOptions>(MATCHITERATOR_THIS->matchOptions());
        }

        MatchType Handle_getMatchType(HandleRef _this) {
            return static_cast<MatchType>(MATCHITERATOR_THIS->matchType());
        }

        Match::OwnedRef Handle_next(HandleRef _this) {
            return REGEX_MATCH_HEAP_NEW(MATCHITERATOR_THIS->next());
        }

        Match::OwnedRef Handle_peekNext(HandleRef _this) {
            return REGEX_MATCH_HEAP_NEW(MATCHITERATOR_THIS->peekNext());
        }

        void Handle_swap(HandleRef _this, HandleRef other) {
            if (other != nullptr)
            {
                MATCHITERATOR_THIS->swap(*AS_QREGEX_MATCHITERATOR_PTR(other));
            } else
            {
                *MATCHITERATOR_THIS = QRegularExpressionMatchIterator();
            }
        }

        void Owned_dispose(OwnedRef _this) {
            delete MATCHITERATOR_THIS;
        }

        OwnedRef create() {
            return REGEX_MATCHITERATOR_HEAP_NEW();
        }

        OwnedRef create(HandleRef other) {
            return REGEX_MATCHITERATOR_HEAP_NEW(QREGEX_MATCHITERATOR_VALUE(other));
        }
    }

    // actual RegularExpression methods ========================
#define THIS (AS_QREGEX_PTR(_this))

    int32_t Handle_captureCount(HandleRef _this) {
        return THIS->captureCount();
    }

    std::string Handle_errorString(HandleRef _this) {
        return THIS->errorString().toStdString();
    }

    MatchIterator::OwnedRef Handle_globalMatch(HandleRef _this, const std::string& subject, size_t offset /* 0 */, MatchType matchType /* MatchType::NormalMatch */, Flags<MatchOptions> matchOptions /* MatchOptions::NoMatchOption */) {
        return REGEX_MATCHITERATOR_HEAP_NEW(
            THIS->globalMatch(
                QString::fromStdString(subject),
                offset,
                static_cast<QRegularExpression::MatchType>(matchType),
                QRegularExpression::MatchOptions::fromInt(matchOptions.value())
                )
            );
    }

    bool Handle_isValid(HandleRef _this) {
        return THIS->isValid();
    }

    Match::OwnedRef Handle_match_(HandleRef _this, const std::string& subject, size_t offset /* 0 */, MatchType matchType /* MatchType::NormalMatch */, Flags<MatchOptions> matchOptions /* MatchOptions::NoMatchOption */) {
        return REGEX_MATCH_HEAP_NEW(
            THIS->match(
                QString::fromStdString(subject),
                offset,
                static_cast<QRegularExpression::MatchType>(matchType),
                QRegularExpression::MatchOptions::fromInt(matchOptions.value())
                )
            );
    }

    std::vector<std::string> Handle_namedCaptureGroups(HandleRef _this) {
        return fromQStringList(THIS->namedCaptureGroups());
    }

    void Handle_optimize(HandleRef _this) {
        THIS->optimize();
    }

    std::string Handle_pattern(HandleRef _this) {
        return THIS->pattern().toStdString();
    }

    size_t Handle_patternErrorOffset(HandleRef _this) {
        return THIS->patternErrorOffset();
    }

    Flags<PatternOptions> Handle_getPatternOptions(HandleRef _this) {
        return Flags<PatternOptions>(THIS->patternOptions());
    }

    void Handle_setPattern(HandleRef _this, const std::string& pattern) {
        THIS->setPattern(QString::fromStdString(pattern));
    }

    void Handle_setPatternOptions(HandleRef _this, Flags<PatternOptions> options_) {
        THIS->setPatternOptions(QRegularExpression::PatternOptions::fromInt(options_.value()));
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        if (other != nullptr)
        {
            THIS->swap(*AS_QREGEX_PTR(other));
        } else
        {
            *THIS = QRegularExpression();
        }
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return REGEX_HEAP_NEW();
    }

    OwnedRef create(const std::string& pattern, Flags<PatternOptions> options_ /* PatternOptions::NoPatternOption */) {
        return REGEX_HEAP_NEW(QString::fromStdString(pattern), QRegularExpression::PatternOptions::fromInt(options_.value()));
    }

    OwnedRef create(HandleRef other) {
        return REGEX_HEAP_NEW(QREGEX_VALUE(other));
    }

    // static methods etc ================================

    std::string anchoredPattern(const std::string& expression) {
        return QRegularExpression::anchoredPattern(QString::fromStdString(expression)).toStdString();
    }

    std::string escape(const std::string& str) {
        return QRegularExpression::escape(QString::fromStdString(str)).toStdString();
    }

    OwnedRef fromWildcard(const std::string& pattern, CaseSensitivity cs /* CaseSensitivity::CaseInsensitive */, Flags<WildcardConversionOptions> options_ /* WildcardConversionOptions::DefaultWildcardConversion */) {
        return REGEX_HEAP_NEW(
            QRegularExpression::fromWildcard(
                QString::fromStdString(pattern),
                static_cast<Qt::CaseSensitivity>(cs),
                QRegularExpression::WildcardConversionOptions::fromInt(options_.value())));
    }

    std::string wildcardToRegularExpression(const std::string& pattern, Flags<WildcardConversionOptions> options_ /* WildcardConversionOptions::DefaultWildcardConversion */) {
        return QRegularExpression::wildcardToRegularExpression(
            QString::fromStdString(pattern),
            QRegularExpression::WildcardConversionOptions::fromInt(options_.value()))
        .toStdString();
    }

    OwnedRef ext_MatchIterator_regularExpression(MatchIterator::HandleRef iterator) {
        return REGEX_HEAP_NEW(AS_QREGEX_MATCHITERATOR_PTR(iterator)->regularExpression());
    }
}
