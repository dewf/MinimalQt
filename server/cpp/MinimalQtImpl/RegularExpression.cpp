#include "generated/RegularExpression.h"
#include "RegularExpressionInternal.h"

#define THIS (AS_QREGEX_PTR(_this))

namespace RegularExpression
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
