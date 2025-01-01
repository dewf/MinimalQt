#include "generated/DateTime.h"
#include "DateTimeInternal.h"

#define DATETIME_THIS (QDATETIME_VALUE(_this))

namespace DateTime
{
    std::string Handle_toISO8601(HandleRef _this) {
        return DATETIME_THIS.toString(Qt::ISODate).toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete AS_QDATETIME_PTR(_this);
    }

    OwnedRef createFromISO8601(const std::string& value) {
        const auto qValue = QDateTime::fromString(QString::fromStdString(value), Qt::ISODate);
        return DATETIME_HEAP_NEW(qValue);
    }
}
