#include "generated/Bitmap.h"
#include "BitmapInternal.h"

#include "TransformInternal.h"
#include "VariantInternal.h"
#include "SizeInternal.h"
#include "ImageInternal.h"
#include "PixmapInternal.h"
#include "ColorInternal.h"

using namespace ::Pixmap;
using namespace ::Size;
using namespace ::Transform;
using namespace ::Variant;
using namespace ::Image;
using namespace ::Enums;
using namespace ::Color;

#define THIS (AS_QBITMAP_PTR(_this))

namespace Bitmap
{
    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        if (other != nullptr)
        {
            THIS->swap(*AS_QBITMAP_PTR(other));
        } else
        {
            *THIS = QBitmap();
        }
    }

    OwnedRef Handle_transformed(HandleRef _this, Transform::HandleRef matrix) {
        return BITMAP_HEAP_NEW(THIS->transformed(QTRANSFORM_VALUE(matrix)));
    }

    Variant::OwnedRef Handle_operator_QVariant(HandleRef _this) {
        return VARIANT_HEAP_NEW(QBITMAP_VALUE(_this));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return BITMAP_HEAP_NEW();
    }
    OwnedRef create(Size::HandleRef size) {
        return BITMAP_HEAP_NEW(QSIZE_VALUE(size));
    }
    OwnedRef create(const std::string& fileName, const std::optional<std::string>& format /* {} */) {
        const char *formatPtr = nullptr;
        if (format.has_value())
        {
            formatPtr = format.value().c_str();
        }
        return BITMAP_HEAP_NEW(QString::fromStdString(fileName), formatPtr);
    }
    OwnedRef create(int32_t width, int32_t height) {
        return BITMAP_HEAP_NEW(width, height);
    }
    OwnedRef fromData(Size::HandleRef size, const std::vector<uint8_t>& bits, Format monoFormat /* Format::MonoLSB */) {
        return BITMAP_HEAP_NEW(
            QBitmap::fromData(QSIZE_VALUE(size),
                bits.data(),
                static_cast<QImage::Format>(monoFormat)));
    }
    OwnedRef fromImage(Image::HandleRef image, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        return BITMAP_HEAP_NEW(
            QBitmap::fromImage(
                QIMAGE_VALUE(image),
                Qt::ImageConversionFlags::fromInt(flags_.value())));
    }
    OwnedRef fromPixmap(Pixmap::HandleRef pixmap) {
        return BITMAP_HEAP_NEW(QBitmap::fromPixmap(QPIXMAP_VALUE(pixmap)));
    }

    // Pixmap extension methods =============================
#define PIXMAP_THIS (AS_QPIXMAP_PTR(this_))

    OwnedRef ext_Pixmap_createHeuristicMask(Pixmap::HandleRef this_, bool clipTight /* true */) {
        return BITMAP_HEAP_NEW(PIXMAP_THIS->createHeuristicMask(clipTight));
    }

    OwnedRef ext_Pixmap_createMaskFromColor(Pixmap::HandleRef this_, Color::HandleRef maskColor, MaskMode mode /* MaskMode::MaskInColor */) {
        return BITMAP_HEAP_NEW(PIXMAP_THIS->createMaskFromColor(QCOLOR_VALUE(maskColor), static_cast<Qt::MaskMode>(mode)));
    }

    OwnedRef ext_Pixmap_mask(Pixmap::HandleRef this_) {
        return BITMAP_HEAP_NEW(PIXMAP_THIS->mask());
    }

    void ext_Pixmap_setMask(Pixmap::HandleRef this_, HandleRef mask) {
        PIXMAP_THIS->setMask(QBITMAP_VALUE(mask));
    }
}
