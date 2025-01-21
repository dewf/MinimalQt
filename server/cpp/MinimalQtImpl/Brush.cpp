#include "generated/Brush.h"

#include "BrushInternal.h"
#include "ColorInternal.h"
#include "GradientInternal.h"
#include "ImageInternal.h"
#include "PixmapInternal.h"
#include "TransformInternal.h"

#define THIS (AS_QBRUSH_PTR(_this))

namespace Brush
{
    Color::OwnedRef Handle_color(HandleRef _this) {
        return COLOR_HEAP_NEW(THIS->color());
    }

    bool Handle_isOpaque(HandleRef _this) {
        return THIS->isOpaque();
    }

    void Handle_setColor(HandleRef _this, Color::HandleRef color) {
        THIS->setColor(QCOLOR_VALUE(color));
    }

    void Handle_setColor(HandleRef _this, GlobalColor color) {
        THIS->setColor(static_cast<Qt::GlobalColor>(color));
    }

    void Handle_setStyle(HandleRef _this, BrushStyle style) {
        THIS->setStyle(static_cast<Qt::BrushStyle>(style));
    }

    void Handle_setTexture(HandleRef _this, Pixmap::HandleRef pixmap) {
        THIS->setTexture(QPIXMAP_VALUE(pixmap));
    }

    void Handle_setTextureImage(HandleRef _this, Image::HandleRef image) {
        THIS->setTextureImage(QIMAGE_VALUE(image));
    }

    void Handle_setTransform(HandleRef _this, Transform::HandleRef transform) {
        THIS->setTransform(QTRANSFORM_VALUE(transform));
    }

    BrushStyle Handle_style(HandleRef _this) {
        return static_cast<BrushStyle>(THIS->style());
    }

    Pixmap::OwnedRef Handle_texture(HandleRef _this) {
        return PIXMAP_HEAP_NEW(THIS->texture());
    }

    Image::OwnedRef Handle_textureImage(HandleRef _this) {
        return IMAGE_HEAP_NEW(THIS->textureImage());
    }

    Transform::OwnedRef Handle_transform(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->transform());
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return BRUSH_HEAP_NEW();
    }

    OwnedRef create(BrushStyle style) {
        return BRUSH_HEAP_NEW(static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(Gradient::HandleRef gradient) {
        return BRUSH_HEAP_NEW(QGRADIENT_VALUE(gradient));
    }

    OwnedRef create(Image::HandleRef image) {
        return BRUSH_HEAP_NEW(QIMAGE_VALUE(image));
    }

    OwnedRef create(Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(GlobalColor color, BrushStyle style /* BrushStyle::SolidPattern */) {
        return BRUSH_HEAP_NEW(static_cast<Qt::GlobalColor>(color), static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(GlobalColor color, Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(static_cast<Qt::GlobalColor>(color), QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(Color::HandleRef color, BrushStyle style /* BrushStyle::SolidPattern */) {
        return BRUSH_HEAP_NEW(QCOLOR_VALUE(color), static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(Color::HandleRef color, Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(QCOLOR_VALUE(color), QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(HandleRef other) {
        return BRUSH_HEAP_NEW(QBRUSH_VALUE(other));
    }
}
