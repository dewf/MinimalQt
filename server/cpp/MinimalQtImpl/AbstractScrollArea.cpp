#include "generated/AbstractScrollArea.h"
#include "AbstractScrollAreaInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSCROLLAREA_THIS (WRAPPER->getActual())

namespace AbstractScrollArea
{
    void Handle_setHorizontalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        ABSCROLLAREA_THIS->setHorizontalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        ABSCROLLAREA_THIS->setSizeAdjustPolicy((QAbstractScrollArea::SizeAdjustPolicy)policy);
    }

    void Handle_setVerticalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        ABSCROLLAREA_THIS->setVerticalScrollBarPolicy((Qt::ScrollBarPolicy)policy);
    }
}

