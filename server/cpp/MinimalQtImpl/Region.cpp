#include "generated/Region.h"
#include "RegionInternal.h"

#define THIS ((QRegion*)_this)

namespace Region
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
