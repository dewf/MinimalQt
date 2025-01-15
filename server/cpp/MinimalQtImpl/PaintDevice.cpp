#include "generated/PaintDevice.h"
#include "PaintDeviceInternal.h"

#define THIS (reinterpret_cast<QPaintDevice*>(_this))

namespace PaintDevice
{
    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }
}
