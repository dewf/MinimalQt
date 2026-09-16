#include "generated/Color.h"
#include "ColorInternal.h"

#include "util/convert.h"

using namespace ::Enums;

#define THIS (AS_QCOLOR_PTR(_this))

namespace Color
{
    int32_t Handle_alpha(HandleRef _this) {
        return THIS->alpha();
    }

    float Handle_alphaF(HandleRef _this) {
        return THIS->alphaF();
    }

    void Handle_setAlpha(HandleRef _this, int32_t alpha) {
        THIS->setAlpha(alpha);
    }

    void Handle_setAlphaF(HandleRef _this, float alpha) {
        THIS->setAlphaF(alpha);
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return COLOR_HEAP_NEW();
    }

    OwnedRef create(Rgb color) {
        return COLOR_HEAP_NEW(color);
    }

    OwnedRef create(const std::string& name) {
        return COLOR_HEAP_NEW(QString::fromStdString(name));
    }

    OwnedRef create(int32_t r, int32_t g, int32_t b, int32_t a /* 255 */) {
        return COLOR_HEAP_NEW(r, g, b, a);
    }

    OwnedRef create(GlobalColor color) {
        return COLOR_HEAP_NEW(static_cast<Qt::GlobalColor>(color));
    }

    std::vector<std::string> colorNames() {
        return fromQStringList(QColor::colorNames());
    }

    OwnedRef fromCmyk(int32_t c, int32_t m, int32_t y, int32_t k, int32_t a /* 255 */) {
        return COLOR_HEAP_NEW(QColor::fromCmyk(c, m, y, k, a));
    }

    OwnedRef fromCmykF(float c, float m, float y, float k, float a /* 1.0 */) {
        return COLOR_HEAP_NEW(QColor::fromCmykF(c, m, y, k, a));
    }

    OwnedRef fromHsl(int32_t h, int32_t s, int32_t l, int32_t a /* 255 */) {
        return COLOR_HEAP_NEW(QColor::fromHsl(h, s, l, a));
    }

    OwnedRef fromHslF(float h, float s, float l, float a /* 1.0 */) {
        return COLOR_HEAP_NEW(QColor::fromHslF(h, s, l, a));
    }

    OwnedRef fromHsv(int32_t h, int32_t s, int32_t v, int32_t a /* 255 */) {
        return COLOR_HEAP_NEW(QColor::fromHsv(h, s, v, a));
    }

    OwnedRef fromHsvF(float h, float s, float v, float a /* 1.0 */) {
        return COLOR_HEAP_NEW(QColor::fromHsvF(h, s, v, a));
    }

    OwnedRef fromRgb(Rgb rgb) {
        return COLOR_HEAP_NEW(QColor::fromRgb(rgb));
    }

    OwnedRef fromRgb(int32_t r, int32_t g, int32_t b, int32_t a /* 255 */) {
        return COLOR_HEAP_NEW(QColor::fromRgb(r, g, b, a));
    }

    OwnedRef fromRgba64(uint16_t r, uint16_t g, uint16_t b, uint16_t a /* 0xFFFF */) {
        return COLOR_HEAP_NEW(QColor::fromRgba64(r, g, b, a));
    }

    OwnedRef fromRgbF(float r, float g, float b, float a /* 1.0 */) {
        return COLOR_HEAP_NEW(QColor::fromRgbF(r, g, b, a));
    }

    OwnedRef fromRgba(Rgb rgba) {
        return COLOR_HEAP_NEW(QColor::fromRgba(rgba));
    }

    OwnedRef fromString(const std::string& name) {
        return COLOR_HEAP_NEW(QColor::fromString(QString::fromStdString(name)));
    }

    bool isValidColorName(const std::string& name) {
        return QColor::isValidColorName(QString::fromStdString(name));
    }
}
