#include "generated/AbstractScrollArea.h"
#include "AbstractScrollAreaInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSCROLLAREA_THIS (WRAPPER->getActual())

namespace AbstractScrollArea
{
    ScrollBarPolicy Handle_horizontalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(ABSCROLLAREA_THIS->horizontalScrollBarPolicy());
    }

    void Handle_setHorizontalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        ABSCROLLAREA_THIS->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(ABSCROLLAREA_THIS->sizeAdjustPolicy());
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        ABSCROLLAREA_THIS->setSizeAdjustPolicy(static_cast<QAbstractScrollArea::SizeAdjustPolicy>(policy));
    }

    ScrollBarPolicy Handle_verticalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(ABSCROLLAREA_THIS->verticalScrollBarPolicy());
    }

    void Handle_setVerticalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        ABSCROLLAREA_THIS->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }
}
