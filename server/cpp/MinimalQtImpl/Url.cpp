#include "generated/Url.h"
#include "UrlInternal.h"

#define THIS (AS_QURL_PTR(_this))

namespace Url
{
    std::string Handle_toAbsoluteInternal(HandleRef _this) {
        return THIS->toString().toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef createFromAbsolute(const std::string& absoluteUrl) {
        return URL_HEAP_NEW(QString::fromStdString(absoluteUrl));
    }
}
