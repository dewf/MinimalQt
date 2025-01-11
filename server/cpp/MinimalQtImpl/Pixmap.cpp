#include "generated/Pixmap.h"

#include <QPixmap>

#include "ColorInternal.h"
#include "ImageInternal.h"
#include "PixmapInternal.h"
#include "RegionInternal.h"
#include "TransformInternal.h"

#include "util/convert.h"

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

    bool Handle_convertFromImage(HandleRef _this, Image::HandleRef image, const std::optional<ImageConversionFlags>& flags_) {
        Qt::ImageConversionFlags qFlags = optionOrDefaultStaticCast(flags_, Qt::AutoColor);
        return THIS->convertFromImage(QIMAGE_VALUE(image), qFlags);
    }

    OwnedRef Handle_copy(HandleRef _this, const std::optional<Rect>& rect) {
        QRect qRect;
        if (rect.has_value()) qRect = toQRect(rect.value());
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

    SizeF Handle_deviceIndependentSize(HandleRef _this) {
        return toSizeF(THIS->deviceIndependentSize());
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

    bool Handle_load(HandleRef _this, const std::string& fileName, const FilenameOptions& opts) {
        const auto format = opts.mapOrDefaultFormat([](auto fmt) { return fmt.c_str(); }, static_cast<const char *>(nullptr));
        const auto flags = static_cast<Qt::ImageConversionFlags>(opts.getOrDefaultImageConversionFlags(AutoColor));
        return THIS->load(QString::fromStdString(fileName), format, flags);
    }

    bool Handle_loadFromData(HandleRef _this, const std::shared_ptr<NativeBuffer<uint8_t>>& data, const FilenameOptions& opts) {
        const auto format = opts.mapOrDefaultFormat([](auto fmt) { return fmt.c_str(); }, static_cast<const char *>(nullptr));
        const auto flags = static_cast<Qt::ImageConversionFlags>(opts.getOrDefaultImageConversionFlags(AutoColor));
        size_t length;
        const auto span = data->getSpan(&length);
        return THIS->loadFromData(span, static_cast<int>(length), format, flags);
        return false;
    }

    bool Handle_loadFromData(HandleRef _this, const std::vector<uint8_t>& data, const FilenameOptions& opts) {
        const auto format = opts.mapOrDefaultFormat([](auto fmt) { return fmt.c_str(); }, static_cast<const char *>(nullptr));
        const auto flags = static_cast<Qt::ImageConversionFlags>(opts.getOrDefaultImageConversionFlags(AutoColor));
        const QByteArray qBytes(reinterpret_cast<const char *>(data.data()), static_cast<qsizetype>(data.size()));
        return THIS->loadFromData(qBytes, format, flags);
    }

    Rect Handle_rect(HandleRef _this) {
        return toRect(THIS->rect());
    }

    bool Handle_save(HandleRef _this, const std::string& fileName, const std::optional<std::string>& format, const std::optional<int32_t>& quality) {
        const char *qFormat = nullptr;
        if (format.has_value()) qFormat = format.value().c_str();
        return THIS->save(QString::fromStdString(fileName),qFormat, quality.value_or(-1));
    }

    OwnedRef Handle_scaled(HandleRef _this, Size size, const std::optional<AspectRatioMode>& aspectRatioMode, const std::optional<TransformationMode>& transformMode) {
        const auto qAspect = optionOrDefaultStaticCast(aspectRatioMode, Qt::IgnoreAspectRatio);
        const auto qTransform = optionOrDefaultStaticCast(transformMode, Qt::FastTransformation);
        return PIXMAP_HEAP_NEW(THIS->scaled(toQSize(size), qAspect, qTransform));
    }

    OwnedRef Handle_scaled(HandleRef _this, int32_t width, int32_t height, const std::optional<AspectRatioMode>& aspectRatioMode, const std::optional<TransformationMode>& transformMode) {
        const auto qAspect = optionOrDefaultStaticCast(aspectRatioMode, Qt::IgnoreAspectRatio);
        const auto qTransform = optionOrDefaultStaticCast(transformMode, Qt::FastTransformation);
        return PIXMAP_HEAP_NEW(THIS->scaled(width, height, qAspect, qTransform));
    }

    OwnedRef Handle_scaledToHeight(HandleRef _this, int32_t height, const std::optional<TransformationMode>& mode) {
        const auto qTransform = optionOrDefaultStaticCast(mode, Qt::FastTransformation);
        return PIXMAP_HEAP_NEW(THIS->scaledToHeight(height, qTransform));
    }

    OwnedRef Handle_scaledToWidth(HandleRef _this, int32_t width, const std::optional<TransformationMode>& mode) {
        const auto qTransform = optionOrDefaultStaticCast(mode, Qt::FastTransformation);
        return PIXMAP_HEAP_NEW(THIS->scaledToWidth(width, qTransform));
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy, Rect rect, const std::optional<Region::HandleRef>& exposed) {
        QRegion *qExposed = nullptr;
        if (exposed.has_value()) qExposed = AS_QREGION_PTR(exposed.value());
        THIS->scroll(dx, dy, toQRect(rect), qExposed);
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy, int32_t x, int32_t y, int32_t width, int32_t height, const std::optional<Region::HandleRef>& exposed) {
        QRegion *qExposed = nullptr;
        if (exposed.has_value()) qExposed = AS_QREGION_PTR(exposed.value());
        THIS->scroll(dx, dy, x, y, width, height, qExposed);
    }

    void Handle_setDevicePixelRatio(HandleRef _this, double scaleFactor) {
        THIS->setDevicePixelRatio(scaleFactor);
    }

    Size Handle_size(HandleRef _this) {
        return toSize(THIS->size());
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        THIS->swap(QPIXMAP_VALUE(other));
    }

    Image::OwnedRef Handle_toImage(HandleRef _this) {
        return IMAGE_HEAP_NEW(THIS->toImage());
    }

    OwnedRef Handle_transformed(HandleRef _this, Transform::HandleRef transform, const std::optional<TransformationMode>& mode) {
        const auto qTransform = optionOrDefaultStaticCast(mode, Qt::FastTransformation);
        return PIXMAP_HEAP_NEW(THIS->transformed(QTRANSFORM_VALUE(transform), qTransform));
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

    OwnedRef create(const std::string& filename, const FilenameOptions& opts) {
        const auto format = opts.mapOrDefaultFormat([](auto fmt) { return fmt.c_str(); }, static_cast<const char *>(nullptr));
        const auto flags = static_cast<Qt::ImageConversionFlags>(opts.getOrDefaultImageConversionFlags(AutoColor));
        return PIXMAP_HEAP_NEW(QString::fromStdString(filename), format, flags);
    }

    OwnedRef create(Size size) {
        return PIXMAP_HEAP_NEW(toQSize(size));
    }

    OwnedRef create(HandleRef other) {
        return PIXMAP_HEAP_NEW(QPIXMAP_VALUE(other));
    }

    int32_t defaultDepth() {
        return QPixmap::defaultDepth();
    }

    OwnedRef fromImage(Image::HandleRef image, const std::optional<ImageConversionFlags>& imageConversionFlags) {
        const auto qFlags = static_cast<Qt::ImageConversionFlags>(imageConversionFlags.value_or(AutoColor));
        return PIXMAP_HEAP_NEW(QPixmap::fromImage(QIMAGE_VALUE(image), qFlags));
    }

    Transform::OwnedRef trueMatrix(Transform::HandleRef matrix, int32_t width, int32_t height) {
        return TRANSFORM_HEAP_NEW(QPixmap::trueMatrix(QTRANSFORM_VALUE(matrix), width, height));
    }
}
