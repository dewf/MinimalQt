#include "generated/Region.h"
#include "RegionInternal.h"
#include "util/convert.h"

#define THIS ((QRegion*)_this)

namespace Region
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return REGION_HEAP_NEW();
    }

    OwnedRef create(int32_t x, int32_t y, int32_t w, int32_t h, const std::optional<RegionType>& t) {
        const auto qType = static_cast<QRegion::RegionType>(t.value_or(RegionType::Rectangle));
        return REGION_HEAP_NEW(x, y, w, h, qType);
    }

    OwnedRef create(Rect r, const std::optional<RegionType>& t) {
        const auto qType = static_cast<QRegion::RegionType>(t.value_or(RegionType::Rectangle));
        return REGION_HEAP_NEW(toQRect(r), qType);
    }

    OwnedRef create(HandleRef other) {
        return REGION_HEAP_NEW(QREGION_VALUE(other));
    }
}
