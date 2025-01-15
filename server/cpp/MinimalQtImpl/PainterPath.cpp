#include "generated/PainterPath.h"
#include "PainterPathInternal.h"

#include "util/convert.h"

#define THIS (AS_QPAINTERPATH_PTR(_this))

namespace PainterPath
{
    void Handle_addEllipse(HandleRef _this, RectF boundingRectangle) {
        THIS->addEllipse(toQRectF(boundingRectangle));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return PAINTERPATH_HEAP_NEW();
    }

    OwnedRef create(PointF startPoint) {
        return PAINTERPATH_HEAP_NEW(toQPointF(startPoint));
    }

    OwnedRef create(HandleRef path) {
        return PAINTERPATH_HEAP_NEW(QPAINTERPATH_VALUE(path));
    }
}
