#include "generated/Transform.h"
#include "TransformInternal.h"

#define THIS (AS_QTRANSFORM_PTR(_this))

namespace Transform
{
    double Handle_m11(HandleRef _this) {
        return 0.0;
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
