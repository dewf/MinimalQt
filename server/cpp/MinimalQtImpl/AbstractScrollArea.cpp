#include "generated/AbstractScrollArea.h"
#include "AbstractScrollAreaInternal.h"

#define THIS (reinterpret_cast<QAbstractScrollArea*>(_this))

namespace AbstractScrollArea
{
    ScrollBarPolicy Handle_horizontalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(THIS->horizontalScrollBarPolicy());
    }

    void Handle_setHorizontalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(THIS->sizeAdjustPolicy());
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy(static_cast<QAbstractScrollArea::SizeAdjustPolicy>(policy));
    }

    ScrollBarPolicy Handle_verticalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(THIS->verticalScrollBarPolicy());
    }

    void Handle_setVerticalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }
}
