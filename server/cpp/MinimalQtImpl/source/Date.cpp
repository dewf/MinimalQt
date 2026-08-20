#include "generated/Date.h"
#include "DateInternal.h"

#define THIS (AS_QDATE_PTR(_this))

namespace Date
{
    std::string Handle_toISO8601(HandleRef _this) {
        return THIS->toString(Qt::ISODate).toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef createFromISO8601(const std::string& text) {
        const auto qDate = QDate::fromString(QString::fromStdString(text), Qt::ISODate);
        return DATE_HEAP_NEW(qDate);
    }
}
