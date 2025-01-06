#include "generated/Brush.h"

#include "BrushInternal.h"
#include "ColorInternal.h"
#include "ImageInternal.h"
#include "PixmapInternal.h"

namespace Brush
{
    void Owned_dispose(OwnedRef _this) {
        delete _this;
    }

    OwnedRef create() {
        return new __Owned { QBrush() };
    }

    OwnedRef create(BrushStyle style) {
        return new __Owned { static_cast<Qt::BrushStyle>(style) };
    }

    OwnedRef create(Image::HandleRef image) {
        return new __Owned { QIMAGE_VALUE(image) };
    }

    OwnedRef create(Pixmap::HandleRef pixmap) {
        return new __Owned { pixmap->qPixmap };
    }

    OwnedRef create(GlobalColor color) {
        return new __Owned { QBrush(static_cast<Qt::GlobalColor>(color)) };
    }

    OwnedRef create(GlobalColor color, BrushStyle style) {
        return new __Owned { QBrush(static_cast<Qt::GlobalColor>(color), static_cast<Qt::BrushStyle>(style)) };
    }

    OwnedRef create(GlobalColor color, Pixmap::HandleRef pixmap) {
        return new __Owned { QBrush(static_cast<Qt::GlobalColor>(color), pixmap->qPixmap) };
    }

    OwnedRef create(Color::HandleRef color) {
        return new __Owned { QBrush(color->qColor) };
    }

    OwnedRef create(Color::HandleRef color, BrushStyle style) {
        return new __Owned { QBrush(color->qColor, static_cast<Qt::BrushStyle>(style)) };
    }

    OwnedRef create(Color::HandleRef color, Pixmap::HandleRef pixmap) {
        return new __Owned { QBrush(color->qColor, pixmap->qPixmap) };
    }
}
