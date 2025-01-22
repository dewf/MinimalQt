#pragma once

#include "generated/SafeReturn.h"
#include <QModelIndex>
#include <QVariant>

namespace SafeReturn {
    struct __Handle {
        QModelIndex modelIndex;
        QVariant variant;
    };
}
