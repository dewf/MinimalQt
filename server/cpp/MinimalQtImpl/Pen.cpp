#include "generated/Pen.h"
#include "PenInternal.h"

#define THIS (AS_QPEN_PTR(_this))

namespace Pen
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
