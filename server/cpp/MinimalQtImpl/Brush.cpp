#include "generated/Brush.h"

#include "BrushInternal.h"
#include "ColorInternal.h"
#include "ImageInternal.h"
#include "PixmapInternal.h"

#define THIS (AS_QBRUSH_PTR(_this))

namespace Brush
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return BRUSH_HEAP_NEW();
    }

    OwnedRef create(BrushStyle style) {
        return BRUSH_HEAP_NEW(static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(Image::HandleRef image) {
        return BRUSH_HEAP_NEW(QIMAGE_VALUE(image));
    }

    OwnedRef create(Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(GlobalColor color) {
        return BRUSH_HEAP_NEW(static_cast<Qt::GlobalColor>(color));
    }

    OwnedRef create(GlobalColor color, BrushStyle style) {
        return BRUSH_HEAP_NEW(static_cast<Qt::GlobalColor>(color), static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(GlobalColor color, Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(static_cast<Qt::GlobalColor>(color), QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(Color::HandleRef color) {
        return BRUSH_HEAP_NEW(QCOLOR_VALUE(color));
    }

    OwnedRef create(Color::HandleRef color, BrushStyle style) {
        return BRUSH_HEAP_NEW(QCOLOR_VALUE(color), static_cast<Qt::BrushStyle>(style));
    }

    OwnedRef create(Color::HandleRef color, Pixmap::HandleRef pixmap) {
        return BRUSH_HEAP_NEW(QCOLOR_VALUE(color), QPIXMAP_VALUE(pixmap));
    }
}
