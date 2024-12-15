#include "generated/RegularExpression.h"

#include "RegularExpressionInternal.h"

namespace RegularExpression
{
    QRegularExpression fromDeferred(const std::shared_ptr<Deferred::Base>& deferred) {
        QRegularExpression ret;
        FromDeferredMatcher matcher(ret);
        deferred->match(&matcher);
        return ret;
    }
}
