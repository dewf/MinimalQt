#pragma once

#include "generated/Brush.h"
#include <QBrush>

#include "CommonInternal.h" // for PaintStackItem, which we will get rid of someday

namespace Brush {
    struct __Handle : PaintStackItem {
        QBrush qBrush;
        explicit __Handle(const QBrush &q_brush) : qBrush(q_brush) {}
    };
    struct __Owned : __Handle {
        explicit __Owned(const QBrush &q_brush) : __Handle(q_brush) {}
    };
}
