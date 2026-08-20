#include "generated/PaintDevice.h"
#include "PaintDeviceInternal.h"

#define THIS (reinterpret_cast<QPaintDevice*>(_this))

namespace PaintDevice
{
    int32_t Handle_colorCount(HandleRef _this) {
        return THIS->colorCount();
    }

    int32_t Handle_depth(HandleRef _this) {
        return THIS->depth();
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    double Handle_devicePixelRatioF(HandleRef _this) {
        return THIS->devicePixelRatioF();
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    int32_t Handle_heightMM(HandleRef _this) {
        return THIS->heightMM();
    }

    int32_t Handle_logicalDpiX(HandleRef _this) {
        return THIS->logicalDpiX();
    }

    int32_t Handle_logicalDpiY(HandleRef _this) {
        return THIS->logicalDpiY();
    }

    bool Handle_paintingActive(HandleRef _this) {
        return THIS->paintingActive();
    }

    int32_t Handle_physicalDpiX(HandleRef _this) {
        return THIS->physicalDpiX();
    }

    int32_t Handle_physicalDpiY(HandleRef _this) {
        return THIS->physicalDpiY();
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    int32_t Handle_widthMM(HandleRef _this) {
        return THIS->widthMM();
    }
}
