#include "generated/RegularExpression.h"
#include "RegularExpressionInternal.h"

#define THIS (AS_QREGEX_PTR(_this))

namespace RegularExpression
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return REGEX_HEAP_NEW();
    }

    OwnedRef create(const std::string& pattern, PatternOptions options_ /* PatternOptions::NoPatternOption */) {
        return REGEX_HEAP_NEW(QString::fromStdString(pattern), static_cast<QRegularExpression::PatternOptions>(options_.value));
    }

    OwnedRef create(HandleRef other) {
        return REGEX_HEAP_NEW(QREGEX_VALUE(other));
    }
}
