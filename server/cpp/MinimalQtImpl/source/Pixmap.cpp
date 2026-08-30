#include "generated/Pixmap.h"
#include "PixmapInternal.h"

#include "ColorInternal.h"
#include "ImageInternal.h"
#include "RegionInternal.h"
#include "TransformInternal.h"
#include "SizeInternal.h"
#include "SizeFInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::PaintDevice;
using namespace ::Size;
using namespace ::SizeF;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::Image;
using namespace ::Color;
using namespace ::Region;
using namespace ::Transform;

#define THIS (AS_QPIXMAP_PTR(_this))

namespace Pixmap
{
    PaintDevice::HandleRef Handle_asPaintDevice(HandleRef _this) {
        // we're treating QPaintDevice as an interface, not a superclass
        return reinterpret_cast<PaintDevice::HandleRef>(_this);
    }

    int64_t Handle_cacheKey(HandleRef _this) {
        return THIS->cacheKey();
    }

    bool Handle_convertFromImage(HandleRef _this, Image::HandleRef image, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        return THIS->convertFromImage(QIMAGE_VALUE(image), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    OwnedRef Handle_copy(HandleRef _this, const std::optional<Rect::HandleRef>& rect) {
        QRect qRect;
        if (rect.has_value()) qRect = QRECT_VALUE(rect.value());
        return PIXMAP_HEAP_NEW(THIS->copy(qRect));
    }

    OwnedRef Handle_copy(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        return PIXMAP_HEAP_NEW(THIS->copy(x, y, width, height));
    }

    int32_t Handle_depth(HandleRef _this) {
        return THIS->depth();
    }

    void Handle_detach(HandleRef _this) {
        THIS->detach();
    }

    SizeF::OwnedRef Handle_deviceIndependentSize(HandleRef _this) {
        return SIZEF_HEAP_NEW(THIS->deviceIndependentSize());
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    void Handle_fill(HandleRef _this, const std::optional<Color::HandleRef>& color) {
        QColor qColor = Qt::white;
        if (color.has_value()) qColor = QCOLOR_VALUE(color.value());
        THIS->fill(qColor);
    }

    bool Handle_hasAlpha(HandleRef _this) {
        return THIS->hasAlpha();
    }

    bool Handle_hasAlphaChannel(HandleRef _this) {
        return THIS->hasAlphaChannel();
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    bool Handle_isQBitmap(HandleRef _this) {
        return THIS->isQBitmap();
    }

    bool Handle_load(HandleRef _this, const std::string& fileName, const std::optional<std::string>& format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        return THIS->load(QString::fromStdString(fileName), ccFormat, static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    bool Handle_loadFromData(HandleRef _this, const std::shared_ptr<NativeBuffer<uint8_t>>& data, const std::optional<std::string>& format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        size_t length;
        const auto span = data->getSpan(&length);
        return THIS->loadFromData(span, static_cast<int>(length), ccFormat, static_cast<Qt::ImageConversionFlags>(flags_.value()));
        return false;
    }

    bool Handle_loadFromData(HandleRef _this, const std::vector<uint8_t>& data, const std::optional<std::string>& format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        const QByteArray qBytes(reinterpret_cast<const char *>(data.data()), static_cast<qsizetype>(data.size()));
        return THIS->loadFromData(qBytes, ccFormat, static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    Rect::OwnedRef Handle_rect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->rect());
    }

    bool Handle_save(HandleRef _this, const std::string& fileName, const std::optional<std::string>& format, int32_t quality /* -1 */) {
        const char *qFormat = nullptr;
        if (format.has_value()) qFormat = format.value().c_str();
        return THIS->save(QString::fromStdString(fileName),qFormat, quality);
    }

    OwnedRef Handle_scaled(HandleRef _this, Size::HandleRef size, AspectRatioMode aspectRatioMode /* AspectRatioMode::IgnoreAspectRatio */, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return PIXMAP_HEAP_NEW(THIS->scaled(QSIZE_VALUE(size), static_cast<Qt::AspectRatioMode>(aspectRatioMode), static_cast<Qt::TransformationMode>(transformMode)));
    }

    OwnedRef Handle_scaled(HandleRef _this, int32_t width, int32_t height, AspectRatioMode aspectRatioMode /* AspectRatioMode::IgnoreAspectRatio */, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return PIXMAP_HEAP_NEW(THIS->scaled(width, height, static_cast<Qt::AspectRatioMode>(aspectRatioMode), static_cast<Qt::TransformationMode>(transformMode)));
    }

    OwnedRef Handle_scaledToHeight(HandleRef _this, int32_t height, TransformationMode mode /* TransformationMode::FastTransformation */) {
        return PIXMAP_HEAP_NEW(THIS->scaledToHeight(height,  static_cast<Qt::TransformationMode>(mode)));
    }

    OwnedRef Handle_scaledToWidth(HandleRef _this, int32_t width, TransformationMode mode /* TransformationMode::FastTransformation */) {
        return PIXMAP_HEAP_NEW(THIS->scaledToWidth(width,  static_cast<Qt::TransformationMode>(mode)));
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy, Rect::HandleRef rect, const std::optional<Region::HandleRef>& exposed) {
        QRegion *qExposed = nullptr;
        if (exposed.has_value()) qExposed = AS_QREGION_PTR(exposed.value());
        THIS->scroll(dx, dy, QRECT_VALUE(rect), qExposed);
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy, int32_t x, int32_t y, int32_t width, int32_t height, const std::optional<Region::HandleRef>& exposed) {
        QRegion *qExposed = nullptr;
        if (exposed.has_value()) qExposed = AS_QREGION_PTR(exposed.value());
        THIS->scroll(dx, dy, x, y, width, height, qExposed);
    }

    void Handle_setDevicePixelRatio(HandleRef _this, double scaleFactor) {
        THIS->setDevicePixelRatio(scaleFactor);
    }

    Size::OwnedRef Handle_size(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->size());
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        if (other != nullptr)
        {
            THIS->swap(*AS_QPIXMAP_PTR(other));
        } else
        {
            *THIS = QPixmap();
        }
    }

    Image::OwnedRef Handle_toImage(HandleRef _this) {
        return IMAGE_HEAP_NEW(THIS->toImage());
    }

    OwnedRef Handle_transformed(HandleRef _this, Transform::HandleRef transform, TransformationMode mode /* TransformationMode::FastTransformation */) {
        return PIXMAP_HEAP_NEW(THIS->transformed(QTRANSFORM_VALUE(transform), static_cast<Qt::TransformationMode>(mode)));
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create(const std::vector<uint8_t>& xpm) {
        std::vector copy(xpm);
        copy.push_back(0); // null-terminator
        const auto qPtr = reinterpret_cast<const char *>(copy.data());
        return PIXMAP_HEAP_NEW(qPtr);
    }

    OwnedRef create(int32_t width, int32_t height) {
        return PIXMAP_HEAP_NEW(width, height);
    }

    OwnedRef create(const std::string& filename, const std::optional<std::string>& format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        return PIXMAP_HEAP_NEW(QString::fromStdString(filename), ccFormat, static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    OwnedRef create(Size::HandleRef size) {
        return PIXMAP_HEAP_NEW(QSIZE_VALUE(size));
    }

    OwnedRef create(HandleRef other) {
        return PIXMAP_HEAP_NEW(QPIXMAP_VALUE(other));
    }

    int32_t defaultDepth() {
        return QPixmap::defaultDepth();
    }

    OwnedRef fromImage(Image::HandleRef image, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        return PIXMAP_HEAP_NEW(QPixmap::fromImage(QIMAGE_VALUE(image), static_cast<Qt::ImageConversionFlags>(flags_.value())));
    }

    Transform::OwnedRef trueMatrix(Transform::HandleRef matrix, int32_t width, int32_t height) {
        return TRANSFORM_HEAP_NEW(QPixmap::trueMatrix(QTRANSFORM_VALUE(matrix), width, height));
    }
}
