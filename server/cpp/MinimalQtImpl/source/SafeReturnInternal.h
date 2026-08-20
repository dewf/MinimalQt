#pragma once

#include "generated/SafeReturn.h"
#include <QModelIndex>
#include <QVariant>
#include <QSize>

namespace SafeReturn {
    struct __ModelIndexReturn {
        QModelIndex result;
    };
    struct __VariantReturn {
        QVariant result;
    };
    struct __SizeReturn {
        QSize result;
    };
}
