#include "generated/AbstractScrollArea.h"

#include <QAbstractScrollArea>

#define THIS ((QAbstractScrollArea*)_this)

namespace AbstractScrollArea
{
    void Handle_setHorizontalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setHorizontalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy((QAbstractScrollArea::SizeAdjustPolicy)policy);
    }

    void Handle_setVerticalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setVerticalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
    }
}
