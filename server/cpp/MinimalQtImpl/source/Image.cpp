#include "generated/Image.h"
#include "ImageInternal.h"

#include "ColorInternal.h"
#include "PointInternal.h"
#include "TransformInternal.h"
#include "SizeInternal.h"
#include "SizeFInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::PaintDevice;
using namespace ::Size;
using namespace ::SizeF;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::Color;
using namespace ::Transform;

#define THIS (AS_QIMAGE_PTR(_this))

namespace Image
{
    PaintDevice::HandleRef Handle_asPaintDevice(HandleRef _this) {
        return reinterpret_cast<PaintDevice::HandleRef>(_this);
    }

    bool Handle_allGray(HandleRef _this) {
        return THIS->allGray();
    }

    int32_t Handle_bitPlaneCount(HandleRef _this) {
        return THIS->bitPlaneCount();
    }

    std::shared_ptr<NativeBuffer<uint8_t>> Handle_bits(HandleRef _this) {
        return std::make_shared<ServerBuffer<uint8_t>>(THIS->bits(), THIS->sizeInBytes());
    }

    size_t Handle_bytesPerLine(HandleRef _this) {
        return THIS->bytesPerLine();
    }

    int64_t Handle_cacheKey(HandleRef _this) {
        return THIS->cacheKey();
    }

    Rgb Handle_color(HandleRef _this, int32_t i) {
        return THIS->color(i);
    }

    int32_t Handle_colorCount(HandleRef _this) {
        return THIS->colorCount();
    }

    std::vector<Rgb> Handle_colorTable(HandleRef _this) {
        return fromQList<QRgb,Rgb>(THIS->colorTable(), [](auto v) { return static_cast<Rgb>(v); });
    }

    void Handle_convertTo(HandleRef _this, Format format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->convertTo(static_cast<QImage::Format>(format), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    OwnedRef Handle_convertToFormat(HandleRef _this, Format format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const auto result = THIS->convertToFormat(static_cast<QImage::Format>(format), static_cast<Qt::ImageConversionFlags>(flags_.value()));
        return IMAGE_HEAP_NEW(result);
    }

    OwnedRef Handle_convertToFormat(HandleRef _this, Format format, const std::vector<Rgb>& colorTable, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const auto qColorTable = toQList<Rgb,QRgb>(colorTable, [](auto c) { return static_cast<QRgb>(c); });
        const auto result = THIS->convertToFormat(static_cast<QImage::Format>(format), qColorTable, static_cast<Qt::ImageConversionFlags>(flags_.value()));
        return IMAGE_HEAP_NEW(result);
    }

    OwnedRef Handle_convertedTo(HandleRef _this, Format format, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        const auto result = THIS->convertedTo(static_cast<QImage::Format>(format), static_cast<Qt::ImageConversionFlags>(flags_.value()));
        return IMAGE_HEAP_NEW(result);
    }

    OwnedRef Handle_copy(HandleRef _this, const std::optional<Rect::HandleRef>& rectangle) {
        QRect qRect;
        if (rectangle.has_value()) qRect = QRECT_VALUE(rectangle.value());
        return IMAGE_HEAP_NEW(THIS->copy(qRect));
    }

    OwnedRef Handle_copy(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        return IMAGE_HEAP_NEW(THIS->copy(x, y, width, height));
    }

    OwnedRef Handle_createAlphaMask(HandleRef _this, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        return IMAGE_HEAP_NEW(THIS->createAlphaMask(static_cast<Qt::ImageConversionFlags>(flags_.value())));
    }

    OwnedRef Handle_createHeuristicMask(HandleRef _this, bool clipTight /* true */) {
        return IMAGE_HEAP_NEW(THIS->createHeuristicMask(clipTight));
    }

    OwnedRef Handle_createMaskFromColor(HandleRef _this, Rgb color, MaskMode mode /* MaskMode::MaskInColor */) {
        return IMAGE_HEAP_NEW(THIS->createMaskFromColor(color, static_cast<Qt::MaskMode>(mode)));
    }

    int32_t Handle_depth(HandleRef _this) {
        return THIS->depth();
    }

    SizeF::OwnedRef Handle_deviceIndependentSize(HandleRef _this) {
        return SIZEF_HEAP_NEW(THIS->deviceIndependentSize());
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    int32_t Handle_dotsPerMeterX(HandleRef _this) {
        return THIS->dotsPerMeterX();
    }

    int32_t Handle_dotsPerMeterY(HandleRef _this) {
        return THIS->dotsPerMeterY();
    }

    void Handle_fill(HandleRef _this, uint32_t pixelValue) {
        return THIS->fill(pixelValue);
    }

    void Handle_fill(HandleRef _this, GlobalColor color) {
        return THIS->fill(static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fill(HandleRef _this, Color::HandleRef color) {
        return THIS->fill(QCOLOR_VALUE(color));
    }

    Format Handle_format(HandleRef _this) {
        return static_cast<Format>(THIS->format());
    }

    bool Handle_hasAlphaChannel(HandleRef _this) {
        return THIS->hasAlphaChannel();
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    void Handle_invertPixels(HandleRef _this, InvertMode mode /* InvertMode::InvertRgb */) {
        THIS->invertPixels(static_cast<QImage::InvertMode>(mode));
    }

    bool Handle_isGrayscale(HandleRef _this) {
        return THIS->isGrayscale();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    bool Handle_load(HandleRef _this, const std::string& filename, const std::optional<std::string>& format) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        return THIS->load(QString::fromStdString(filename), ccFormat);
    }

    bool Handle_loadFromData(HandleRef _this, const std::shared_ptr<NativeBuffer<uint8_t>>& data, const std::optional<std::string>& format) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        size_t length;
        const uchar *buf = data->getSpan(&length);
        return THIS->loadFromData(buf, static_cast<int>(length), ccFormat);
    }

    void Handle_mirror(HandleRef _this, bool horizontal /* false */, bool vertical /* true */) {
        THIS->mirror(horizontal, vertical);
    }

    OwnedRef Handle_mirrored(HandleRef _this, bool horizontal /* false */, bool vertical /* true */) {
        return IMAGE_HEAP_NEW(THIS->mirrored(horizontal, vertical));
    }

    Point::OwnedRef Handle_offset(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->offset());
    }

    Rgb Handle_pixel(HandleRef _this, Point::HandleRef position) {
        return THIS->pixel(QPOINT_VALUE(position));
    }

    Rgb Handle_pixel(HandleRef _this, int32_t x, int32_t y) {
        return THIS->pixel(x, y);
    }

    Color::OwnedRef Handle_pixelColor(HandleRef _this, Point::HandleRef position) {
        return COLOR_HEAP_NEW(THIS->pixelColor(QPOINT_VALUE(position)));
    }

    Color::OwnedRef Handle_pixelColor(HandleRef _this, int32_t x, int32_t y) {
        return COLOR_HEAP_NEW(THIS->pixelColor(x, y));
    }

    int32_t Handle_pixelIndex(HandleRef _this, Point::HandleRef position) {
        return THIS->pixelIndex(QPOINT_VALUE(position));
    }

    int32_t Handle_pixelIndex(HandleRef _this, int32_t x, int32_t y) {
        return THIS->pixelIndex(x, y);
    }

    Rect::OwnedRef Handle_rect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->rect());
    }

    bool Handle_reinterpretAsFormat(HandleRef _this, Format format) {
        return THIS->reinterpretAsFormat(static_cast<QImage::Format>(format));
    }

    void Handle_rgbSwap(HandleRef _this) {
        return THIS->rgbSwap();
    }

    OwnedRef Handle_rgbSwapped(HandleRef _this) {
        return IMAGE_HEAP_NEW(THIS->rgbSwapped());
    }

    bool Handle_save(HandleRef _this, const std::string& fileName, const std::optional<std::string>& format, int32_t quality /* -1 */) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        return THIS->save(QString::fromStdString(fileName), ccFormat, quality);
    }

    OwnedRef Handle_scaled(HandleRef _this, Size::HandleRef size, AspectRatioMode aspectRadioMode /* AspectRatioMode::IgnoreAspectRatio */, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return IMAGE_HEAP_NEW(THIS->scaled(QSIZE_VALUE(size), static_cast<Qt::AspectRatioMode>(aspectRadioMode), static_cast<Qt::TransformationMode>(transformMode)));
    }

    OwnedRef Handle_scaled(HandleRef _this, int32_t width, int32_t height, AspectRatioMode aspectRadioMode /* AspectRatioMode::IgnoreAspectRatio */, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return IMAGE_HEAP_NEW(THIS->scaled(width, height, static_cast<Qt::AspectRatioMode>(aspectRadioMode), static_cast<Qt::TransformationMode>(transformMode)));
    }

    OwnedRef Handle_scaledToHeight(HandleRef _this, int32_t height, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return IMAGE_HEAP_NEW(THIS->scaledToHeight(height, static_cast<Qt::TransformationMode>(transformMode)));
    }

    OwnedRef Handle_scaledToWidth(HandleRef _this, int32_t width, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return IMAGE_HEAP_NEW(THIS->scaledToWidth(width, static_cast<Qt::TransformationMode>(transformMode)));
    }

    std::shared_ptr<NativeBuffer<uint32_t>> Handle_scanLine32(HandleRef _this, int32_t i) {
        auto ptr = THIS->scanLine(i);
        return std::make_shared<ServerBuffer<uint32_t>>(reinterpret_cast<uint32_t*>(ptr), THIS->bytesPerLine() / 4);
    }

    std::shared_ptr<NativeBuffer<uint64_t>> Handle_scanLine64(HandleRef _this, int32_t i) {
        auto ptr = THIS->scanLine(i);
        return std::make_shared<ServerBuffer<uint64_t>>(reinterpret_cast<uint64_t*>(ptr), THIS->bytesPerLine() / 8);
    }

    void Handle_setAlphaChannel(HandleRef _this, HandleRef alphaChannel) {
        THIS->setAlphaChannel(QIMAGE_VALUE(alphaChannel));
    }

    void Handle_setColor(HandleRef _this, int32_t index, Rgb colorValue) {
        THIS->setColor(index, colorValue);
    }

    void Handle_setColorCount(HandleRef _this, int32_t colorCount) {
        THIS->setColorCount(colorCount);
    }

    void Handle_setColorTable(HandleRef _this, const std::vector<Rgb>& colors) {
        THIS->setColorTable(toQList<Rgb,QRgb>(colors, [](auto c) { return static_cast<QRgb>(c); }));
    }

    void Handle_setDevicePixelRatio(HandleRef _this, double scaleFactor) {
        THIS->setDevicePixelRatio(scaleFactor);
    }

    void Handle_setDotsPerMeterX(HandleRef _this, int32_t x) {
        THIS->setDotsPerMeterX(x);
    }

    void Handle_setDotsPerMeterY(HandleRef _this, int32_t y) {
        THIS->setDotsPerMeterY(y);
    }

    void Handle_setOffset(HandleRef _this, Point::HandleRef offset) {
        THIS->setOffset(QPOINT_VALUE(offset));
    }

    void Handle_setPixel(HandleRef _this, Point::HandleRef position, uint32_t index_or_rgb) {
        THIS->setPixel(QPOINT_VALUE(position), index_or_rgb);
    }

    void Handle_setPixel(HandleRef _this, int32_t x, int32_t y, uint32_t index_or_rgb) {
        THIS->setPixel(x, y, index_or_rgb);
    }

    void Handle_setPixelColor(HandleRef _this, Point::HandleRef position, Color::HandleRef color) {
        THIS->setPixelColor(QPOINT_VALUE(position), QCOLOR_VALUE(color));
    }

    void Handle_setPixelColor(HandleRef _this, int32_t x, int32_t y, Color::HandleRef color) {
        THIS->setPixelColor(x, y, QCOLOR_VALUE(color));
    }

    void Handle_setText(HandleRef _this, const std::string& key, const std::string& text) {
        THIS->setText(QString::fromStdString(key), QString::fromStdString(text));
    }

    Size::OwnedRef Handle_size(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->size());
    }

    size_t Handle_sizeInBytes(HandleRef _this) {
        return THIS->sizeInBytes();
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        if (other != nullptr)
        {
            THIS->swap(*AS_QIMAGE_PTR(other));
        } else
        {
            *THIS = QImage();
        }
    }

    std::string Handle_text(HandleRef _this, const std::optional<std::string>& key) {
        const auto qKey = optionalMap<std::string,QString>(key, QString::fromStdString).value_or(QString());
        return THIS->text(qKey).toStdString();
    }

    std::vector<std::string> Handle_textKeys(HandleRef _this) {
        return toVectorStrings(THIS->textKeys());
    }

    OwnedRef Handle_transformed(HandleRef _this, Transform::HandleRef matrix, TransformationMode transformMode /* TransformationMode::FastTransformation */) {
        return IMAGE_HEAP_NEW(THIS->transformed(QTRANSFORM_VALUE(matrix), static_cast<Qt::TransformationMode>(transformMode)));
    }

    bool Handle_valid(HandleRef _this, Point::HandleRef pos) {
        return THIS->valid(QPOINT_VALUE(pos));
    }

    bool Handle_valid(HandleRef _this, int32_t x, int32_t y) {
        return THIS->valid(x, y);
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return IMAGE_HEAP_NEW();
    }

    OwnedRef create(const std::vector<uint8_t>& xpm) {
        return IMAGE_HEAP_NEW(reinterpret_cast<const char *>(xpm.data()));
    }

    OwnedRef create(Size::HandleRef size, Format format) {
        return IMAGE_HEAP_NEW(QSIZE_VALUE(size), static_cast<QImage::Format>(format));
    }

    OwnedRef create(const std::string& filename, const std::optional<std::string>& format) {
        const char *ccFormat = nullptr;
        if (format.has_value()) ccFormat = format.value().c_str();
        return IMAGE_HEAP_NEW(QString::fromStdString(filename), ccFormat);
    }

    OwnedRef create(int32_t width, int32_t height, Format format) {
        return IMAGE_HEAP_NEW(width, height, static_cast<QImage::Format>(format));
    }

    struct CleanupInfo {
        // keep the buffer alive until the Image is done with it
        std::shared_ptr<NativeBuffer<uint8_t>> buffer;
    };

    static void cleanupFunc(void *info) {
        const auto ptr = static_cast<CleanupInfo*>(info);
        delete ptr;
    }

    OwnedRef create(const std::shared_ptr<NativeBuffer<uint8_t>>& data, int32_t width, int32_t height, Format format, const std::optional<size_t>& bytesPerLine) {
        size_t length;
        const auto qdata = data->getSpan(&length);
        const auto qformat = static_cast<QImage::Format>(format);
        const auto cleanupPtr = new CleanupInfo { data };
        if (bytesPerLine.has_value()) {
            const auto qbytesPerLine = static_cast<qsizetype>(bytesPerLine.value());
            return IMAGE_HEAP_NEW(qdata, width, height, qbytesPerLine, qformat, cleanupFunc, cleanupPtr);
        } else {
            return IMAGE_HEAP_NEW(qdata, width, height, qformat, cleanupFunc, cleanupPtr);
        }
    }

    OwnedRef create(HandleRef other) {
        return IMAGE_HEAP_NEW(QIMAGE_VALUE(other));
    }
}
