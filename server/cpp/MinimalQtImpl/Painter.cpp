#include "generated/Painter.h"
#include "PainterInternal.h"

#include "BrushInternal.h"
#include "ColorInternal.h"
#include "FontInternal.h"
#include "ImageInternal.h"
#include "PainterPathInternal.h"
#include "PenInternal.h"
#include "PixmapInternal.h"
#include "Point2Internal.h"
#include "PolygonInternal.h"
#include "PolygonFInternal.h"
#include "RegionInternal.h"
#include "TextOptionInternal.h"
#include "TransformInternal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Point2;
using namespace ::Enums;
using namespace ::Color;
using namespace ::Pixmap;
using namespace ::Font;
using namespace ::Pen;
using namespace ::Brush;
using namespace ::TextOption;
using namespace ::Region;
using namespace ::Transform;
using namespace ::Image;
using namespace ::PaintDevice;
using namespace ::PainterPath;
using namespace ::Polygon;
using namespace ::PolygonF;
using namespace ::Gradient;

#define THIS (AS_QPAINTER_PTR(_this))
#define FRAGMENT_THIS (AS_QPIXMAPFRAGMENT_PTR(_this))

namespace Painter
{
    namespace PixmapFragment {
        void Owned_dispose(OwnedRef _this) {
            delete FRAGMENT_THIS;
        }
        OwnedRef create(PointF pos, RectF sourceRect, double scaleX /* 1 */, double scaleY /* 1 */, double rotation /* 0 */, double opacity /* 1 */) {
            const auto ret = QPainter::PixmapFragment::create(toQPointF(pos), toQRectF(sourceRect), scaleX, scaleY, rotation, opacity);
            return PIXMAPFRAGMENT_HEAP_NEW(ret);
        }
    }

    Brush::OwnedRef Handle_background(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->background());
    }

    BGMode Handle_backgroundMode(HandleRef _this) {
        return static_cast<BGMode>(THIS->backgroundMode());
    }

    bool Handle_begin(HandleRef _this, PaintDevice::HandleRef device) {
        return THIS->begin(reinterpret_cast<QPaintDevice*>(device));
    }

    void Handle_beginNativePainting(HandleRef _this) {
        THIS->beginNativePainting();
    }

    RectF Handle_boundingRect(HandleRef _this, RectF rectangle, int32_t flags_, const std::string& text) {
        return toRectF(THIS->boundingRect(toQRectF(rectangle), flags_, QString::fromStdString(text)));
    }

    Rect Handle_boundingRect(HandleRef _this, Rect rectangle, int32_t flags_, const std::string& text) {
        return toRect(THIS->boundingRect(toQRect(rectangle), flags_, QString::fromStdString(text)));
    }

    RectF Handle_boundingRect(HandleRef _this, RectF rectangle, const std::string& text, const std::optional<TextOption::HandleRef>& option) {
        QTextOption qOption;
        if (option.has_value()) qOption = QTEXTOPTION_VALUE(option.value());
        return toRectF(THIS->boundingRect(toQRectF(rectangle), QString::fromStdString(text), qOption));
    }

    Rect Handle_boundingRect(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h, int32_t flags_, const std::string& text) {
        return toRect(THIS->boundingRect(x, y, w, h, flags_, QString::fromStdString(text)));
    }

    Brush::OwnedRef Handle_brush(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->brush());
    }

    Point2::OwnedRef Handle_brushOrigin(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->brushOrigin());
    }

    RectF Handle_clipBoundingRect(HandleRef _this) {
        return toRectF(THIS->clipBoundingRect());
    }

    PainterPath::OwnedRef Handle_clipPath(HandleRef _this) {
        return PAINTERPATH_HEAP_NEW(THIS->clipPath());
    }

    Region::OwnedRef Handle_clipRegion(HandleRef _this) {
        return REGION_HEAP_NEW(THIS->clipRegion());
    }

    Transform::OwnedRef Handle_combinedTransform(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->combinedTransform());
    }

    CompositionMode Handle_getCompositionMode(HandleRef _this) {
        return static_cast<CompositionMode>(THIS->compositionMode());
    }

    PaintDevice::HandleRef Handle_device(HandleRef _this) {
        return reinterpret_cast<PaintDevice::HandleRef>(THIS->device());
    }

    Transform::OwnedRef Handle_deviceTransform(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->deviceTransform());
    }

    void Handle_drawArc(HandleRef _this, RectF rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(toQRectF(rectangle), startAngle, spanAngle);
    }

    void Handle_drawArc(HandleRef _this, Rect rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(toQRect(rectangle), startAngle, spanAngle);
    }

    void Handle_drawArc(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, RectF rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(toQRectF(rectangle), startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, Rect rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(toQRect(rectangle), startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawConvexPolygon(HandleRef _this, const std::vector<PointF>& points) {
        const auto qPoints = vectorMap<PointF,QPointF>(points, [](auto p) { return toQPointF(p); });
        THIS->drawConvexPolygon(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawConvexPolygon(HandleRef _this, Polygon::HandleRef polygon) {
        THIS->drawConvexPolygon(QPOLYGON_VALUE(polygon));
    }

    void Handle_drawConvexPolygon(HandleRef _this, PolygonF::HandleRef polygon) {
        THIS->drawConvexPolygon(QPOLYGONF_VALUE(polygon));
    }

    void Handle_drawConvexPolygon(HandleRef _this, const std::vector<Point2::HandleRef>& points) {
        const auto qPoints = vectorMap<Point2::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawConvexPolygon(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawEllipse(HandleRef _this, RectF rectangle) {
        THIS->drawEllipse(toQRectF(rectangle));
    }

    void Handle_drawEllipse(HandleRef _this, Rect rectangle) {
        THIS->drawEllipse(toQRect(rectangle));
    }

    void Handle_drawEllipse(HandleRef _this, Point2::HandleRef center, int32_t rx, int32_t ry) {
        THIS->drawEllipse(QPOINT_VALUE(center), rx, ry);
    }

    void Handle_drawEllipse(HandleRef _this, PointF center, double rx, double ry) {
        THIS->drawEllipse(toQPointF(center), rx, ry);
    }

    void Handle_drawEllipse(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->drawEllipse(x, y, width, height);
    }

    void Handle_drawImage(HandleRef _this, RectF target, Image::HandleRef image, RectF source, ImageConversionFlags flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(toQRectF(target), QIMAGE_VALUE(image), toQRectF(source), static_cast<Qt::ImageConversionFlags>(flags_.value));
    }

    void Handle_drawImage(HandleRef _this, Point2::HandleRef point, Image::HandleRef image) {
        THIS->drawImage(QPOINT_VALUE(point), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, PointF point, Image::HandleRef image) {
        THIS->drawImage(toQPointF(point), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, Rect rectangle, Image::HandleRef image) {
        THIS->drawImage(toQRect(rectangle), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, RectF rectangle, Image::HandleRef image) {
        THIS->drawImage(toQRectF(rectangle), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, Point2::HandleRef point, Image::HandleRef image, Rect source, ImageConversionFlags flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(QPOINT_VALUE(point), QIMAGE_VALUE(image), toQRect(source), static_cast<Qt::ImageConversionFlags>(flags_.value));
    }

    void Handle_drawImage(HandleRef _this, PointF point, Image::HandleRef image, RectF source, ImageConversionFlags flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(toQPointF(point), QIMAGE_VALUE(image), toQRectF(source), static_cast<Qt::ImageConversionFlags>(flags_.value));
    }

    void Handle_drawImage(HandleRef _this, Rect target, Image::HandleRef image, Rect source, ImageConversionFlags flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(toQRect(target), QIMAGE_VALUE(image), toQRect(source), static_cast<Qt::ImageConversionFlags>(flags_.value));
    }

    void Handle_drawImage(HandleRef _this, int32_t x, int32_t y, Image::HandleRef image, int32_t sx /* 0 */, int32_t sy /* 0 */, int32_t sw /* -1 */, int32_t sh /* -1 */, ImageConversionFlags flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(x, y, QIMAGE_VALUE(image), sx, sy, sw, sh, static_cast<Qt::ImageConversionFlags>(flags_.value));
    }

    void Handle_drawLine(HandleRef _this, Point2::HandleRef p1, Point2::HandleRef p2) {
        THIS->drawLine(QPOINT_VALUE(p1), QPOINT_VALUE(p2));
    }

    void Handle_drawLine(HandleRef _this, PointF p1, PointF p2) {
        THIS->drawLine(toQPointF(p1), toQPointF(p2));
    }

    void Handle_drawLine(HandleRef _this, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
        THIS->drawLine(x1, y1, x2, y2);
    }

    void Handle_drawLines(HandleRef _this, const std::vector<Point2::HandleRef>& pointPairs) {
        const auto qPointPairs = vectorMap<Point2::HandleRef,QPoint>(pointPairs, [](auto p) { return QPOINT_VALUE(p); });
        const auto lineCount = static_cast<int>(qPointPairs.size() - 1);
        THIS->drawLines(qPointPairs.data(), lineCount);
    }

    void Handle_drawLines(HandleRef _this, const std::vector<PointF>& pointPairs) {
        const auto qPointPairs = vectorMap<PointF,QPointF>(pointPairs, [](auto p) { return toQPointF(p); });
        const auto lineCount = static_cast<int>(qPointPairs.size() - 1);
        THIS->drawLines(qPointPairs.data(), lineCount);
    }

    void Handle_drawPath(HandleRef _this, PainterPath::HandleRef path) {
        THIS->drawPath(QPAINTERPATH_VALUE(path));
    }

    void Handle_drawPie(HandleRef _this, RectF rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(toQRectF(rectangle), startAngle, spanAngle);
    }

    void Handle_drawPie(HandleRef _this, Rect rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(toQRect(rectangle), startAngle, spanAngle);
    }

    void Handle_drawPie(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawPixmap(HandleRef _this, RectF target, Pixmap::HandleRef pixmap, RectF source) {
        THIS->drawPixmap(toQRectF(target), QPIXMAP_VALUE(pixmap), toQRectF(source));
    }

    void Handle_drawPixmap(HandleRef _this, Point2::HandleRef point, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(QPOINT_VALUE(point), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, PointF point, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(toQPointF(point), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, Rect rectangle, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(toQRect(rectangle), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, Point2::HandleRef point, Pixmap::HandleRef pixmap, Rect source) {
        THIS->drawPixmap(QPOINT_VALUE(point), QPIXMAP_VALUE(pixmap), toQRect(source));
    }

    void Handle_drawPixmap(HandleRef _this, PointF point, Pixmap::HandleRef pixmap, RectF source) {
        THIS->drawPixmap(toQPointF(point), QPIXMAP_VALUE(pixmap), toQRectF(source));
    }

    void Handle_drawPixmap(HandleRef _this, Rect target, Pixmap::HandleRef pixmap, Rect source) {
        THIS->drawPixmap(toQRect(target), QPIXMAP_VALUE(pixmap), toQRect(source));
    }

    void Handle_drawPixmap(HandleRef _this, int32_t x, int32_t y, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(x, y, QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(x, y, width, height, QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, int32_t x, int32_t y, Pixmap::HandleRef pixmap, int32_t sx, int32_t sy, int32_t sw, int32_t sh) {
        THIS->drawPixmap(x, y, QPIXMAP_VALUE(pixmap), sx, sy, sw, sh);
    }

    void Handle_drawPixmap(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h, Pixmap::HandleRef pixmap, int32_t sx, int32_t sy, int32_t sw, int32_t sh) {
        THIS->drawPixmap(x, y, w, h, QPIXMAP_VALUE(pixmap), sx, sy, sw, sh);
    }

    void Handle_drawPixmapFragments(HandleRef _this, const std::vector<PixmapFragment::HandleRef>& fragments, Pixmap::HandleRef pixmap, PixmapFragment::Hints hints /* 0 */) {
        const auto qFragments = vectorMap<PixmapFragment::HandleRef,QPainter::PixmapFragment>(fragments, [](auto f) { return QPIXMAPFRAGMENT_VALUE(f); });
        THIS->drawPixmapFragments(qFragments.data(), static_cast<int>(qFragments.size()), QPIXMAP_VALUE(pixmap), static_cast<QPainter::PixmapFragmentHints>(hints.value));
    }

    void Handle_drawPoint(HandleRef _this, PointF position) {
        THIS->drawPoint(toQPointF(position));
    }

    void Handle_drawPoint(HandleRef _this, Point2::HandleRef position) {
        THIS->drawPoint(QPOINT_VALUE(position));
    }

    void Handle_drawPoint(HandleRef _this, int32_t x, int32_t y) {
        THIS->drawPoint(x, y);
    }

    void Handle_drawPoints(HandleRef _this, const std::vector<PointF>& points) {
        const auto qPoints = vectorMap<PointF,QPointF>(points, [](auto p) { return toQPointF(p); });
        THIS->drawPoints(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPoints(HandleRef _this, Polygon::HandleRef points) {
        THIS->drawPoints(QPOLYGON_VALUE(points));
    }

    void Handle_drawPoints(HandleRef _this, PolygonF::HandleRef points) {
        THIS->drawPoints(QPOLYGONF_VALUE(points));
    }

    void Handle_drawPoints(HandleRef _this, const std::vector<Point2::HandleRef>& points) {
        const auto qPoints = vectorMap<Point2::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPoints(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPolygon(HandleRef _this, const std::vector<PointF>& points, FillRule fillRule /* FillRule::OddEvenFill */) {
        const auto qPoints = vectorMap<PointF,QPointF>(points, [](auto p) { return toQPointF(p); });
        THIS->drawPolygon(qPoints.data(), static_cast<int>(qPoints.size()), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, Polygon::HandleRef points, FillRule fillRule /* FillRule::OddEvenFill */) {
        THIS->drawPolygon(QPOLYGON_VALUE(points), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, PolygonF::HandleRef points, FillRule fillRule /* FillRule::OddEvenFill */) {
        THIS->drawPolygon(QPOLYGONF_VALUE(points), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, const std::vector<Point2::HandleRef>& points, FillRule fillRule /* FillRule::OddEvenFill */) {
        const auto qPoints = vectorMap<Point2::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPolygon(qPoints.data(), static_cast<int>(qPoints.size()), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolyline(HandleRef _this, const std::vector<PointF>& points) {
        const auto qPoints = vectorMap<PointF,QPointF>(points, [](auto p) { return toQPointF(p); });
        THIS->drawPolyline(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPolyline(HandleRef _this, Polygon::HandleRef points) {
        THIS->drawPolyline(QPOLYGON_VALUE(points));
    }

    void Handle_drawPolyline(HandleRef _this, PolygonF::HandleRef points) {
        THIS->drawPolyline(QPOLYGONF_VALUE(points));
    }

    void Handle_drawPolyline(HandleRef _this, const std::vector<Point2::HandleRef>& points) {
        const auto qPoints = vectorMap<Point2::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPolyline(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawRect(HandleRef _this, RectF rectangle) {
        THIS->drawRect(toQRectF(rectangle));
    }

    void Handle_drawRect(HandleRef _this, Rect rectangle) {
        THIS->drawRect(toQRect(rectangle));
    }

    void Handle_drawRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->drawRect(x, y, width, height);
    }

    void Handle_drawRects(HandleRef _this, const std::vector<RectF>& rectangles) {
        const auto qRects = vectorMap<RectF,QRectF>(rectangles, [](auto r) { return toQRectF(r); });
        THIS->drawRects(qRects.data(), static_cast<int>(qRects.size()));
    }

    void Handle_drawRects(HandleRef _this, const std::vector<Rect>& rectangles) {
        const auto qRects = vectorMap<Rect,QRect>(rectangles, [](auto r) { return toQRect(r); });
        THIS->drawRects(qRects.data(), static_cast<int>(qRects.size()));
    }

    void Handle_drawRoundedRect(HandleRef _this, RectF rect, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(toQRectF(rect), xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawRoundedRect(HandleRef _this, Rect rect, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(toQRect(rect), xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawRoundedRect(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(x, y, w, h, xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawText(HandleRef _this, PointF position, const std::string& text) {
        THIS->drawText(toQPointF(position), QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, Point2::HandleRef position, const std::string& text) {
        THIS->drawText(QPOINT_VALUE(position), QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, RectF rectangle, const std::string& text, const std::optional<TextOption::HandleRef>& option) {
        QTextOption qOption;
        if (option.has_value()) qOption = QTEXTOPTION_VALUE(option.value());
        THIS->drawText(toQRectF(rectangle), QString::fromStdString(text), qOption);
    }

    void Handle_drawText(HandleRef _this, int32_t x, int32_t y, const std::string& text) {
        THIS->drawText(x, y, QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, Rect rectangle, int32_t flags_, const std::string& text, const std::optional<Rect>& boundingRect) {
        QRect brValue;
        QRect *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = toQRect(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(toQRect(rectangle), flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawText(HandleRef _this, RectF rectangle, int32_t flags_, const std::string& text, const std::optional<RectF>& boundingRect) {
        QRectF brValue;
        QRectF *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = toQRectF(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(toQRectF(rectangle), flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawText(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t flags_, const std::string& text, const std::optional<Rect>& boundingRect) {
        QRect brValue;
        QRect *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = toQRect(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(x, y, width, height, flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawTiledPixmap(HandleRef _this, RectF rectangle, Pixmap::HandleRef pixmap, const std::optional<PointF>& position) {
        QPointF offset;
        if (position.has_value()) offset = toQPointF(position.value());
        THIS->drawTiledPixmap(toQRectF(rectangle), QPIXMAP_VALUE(pixmap), offset);
    }

    void Handle_drawTiledPixmap(HandleRef _this, Rect rectangle, Pixmap::HandleRef pixmap, const std::optional<Point2::HandleRef>& position) {
        QPoint offset;
        if (position.has_value()) offset = QPOINT_VALUE(position.value());
        THIS->drawTiledPixmap(toQRect(rectangle), QPIXMAP_VALUE(pixmap), offset);
    }

    void Handle_drawTiledPixmap(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, Pixmap::HandleRef pixmap, int32_t sx /* 0 */, int32_t sy /* 0 */) {
        THIS->drawTiledPixmap(x, y, width, height, QPIXMAP_VALUE(pixmap), sx, sy);
    }

    bool Handle_end(HandleRef _this) {
        return THIS->end();
    }

    void Handle_endNativePainting(HandleRef _this) {
        THIS->endNativePainting();
    }

    void Handle_eraseRect(HandleRef _this, RectF rectangle) {
        THIS->eraseRect(toQRectF(rectangle));
    }

    void Handle_eraseRect(HandleRef _this, Rect rectangle) {
        THIS->eraseRect(toQRect(rectangle));
    }

    void Handle_eraseRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->eraseRect(x, y, width, height);
    }

    void Handle_fillPath(HandleRef _this, PainterPath::HandleRef path, Brush::HandleRef brush) {
        THIS->fillPath(QPAINTERPATH_VALUE(path), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, RectF rectangle, Brush::HandleRef brush) {
        THIS->fillRect(toQRectF(rectangle), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, Rect rectangle, Preset preset) {
        THIS->fillRect(toQRect(rectangle), static_cast<QGradient::Preset>(preset));
    }

    void Handle_fillRect(HandleRef _this, Rect rectangle, BrushStyle style) {
        THIS->fillRect(toQRect(rectangle), static_cast<Qt::BrushStyle>(style));
    }

    void Handle_fillRect(HandleRef _this, Rect rectangle, GlobalColor color) {
        THIS->fillRect(toQRect(rectangle), static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fillRect(HandleRef _this, Rect rectangle, Brush::HandleRef brush) {
        THIS->fillRect(toQRect(rectangle), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, Rect rectangle, Color::HandleRef color) {
        THIS->fillRect(toQRect(rectangle), QCOLOR_VALUE(color));
    }

    void Handle_fillRect(HandleRef _this, RectF rectangle, Preset preset) {
        THIS->fillRect(toQRectF(rectangle), static_cast<QGradient::Preset>(preset));
    }

    void Handle_fillRect(HandleRef _this, RectF rectangle, BrushStyle style) {
        THIS->fillRect(toQRectF(rectangle), static_cast<Qt::BrushStyle>(style));
    }

    void Handle_fillRect(HandleRef _this, RectF rectangle, GlobalColor color) {
        THIS->fillRect(toQRectF(rectangle), static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fillRect(HandleRef _this, RectF rectangle, Color::HandleRef color) {
        THIS->fillRect(toQRectF(rectangle), QCOLOR_VALUE(color));
    }

    void Handle_fillRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, Preset preset) {
        THIS->fillRect(x, y, width, height, static_cast<QGradient::Preset>(preset));
    }

    void Handle_fillRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, BrushStyle style) {
        THIS->fillRect(x, y, width, height, static_cast<Qt::BrushStyle>(style));
    }

    void Handle_fillRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, GlobalColor color) {
        THIS->fillRect(x, y, width, height, static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fillRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, Brush::HandleRef brush) {
        THIS->fillRect(x, y, width, height, QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, Color::HandleRef color) {
        THIS->fillRect(x, y, width, height, QCOLOR_VALUE(color));
    }

    Font::OwnedRef Handle_font(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    bool Handle_hasClipping(HandleRef _this) {
        return THIS->hasClipping();
    }

    bool Handle_isActive(HandleRef _this) {
        return THIS->isActive();
    }

    LayoutDirection Handle_layoutDirection(HandleRef _this) {
        return static_cast<LayoutDirection>(THIS->layoutDirection());
    }

    double Handle_opacity(HandleRef _this) {
        return THIS->opacity();
    }

    Pen::OwnedRef Handle_pen(HandleRef _this) {
        return PEN_HEAP_NEW(THIS->pen());
    }

    RenderHints Handle_renderHints(HandleRef _this) {
        return RenderHints(THIS->renderHints());
    }

    void Handle_resetTransform(HandleRef _this) {
        THIS->resetTransform();
    }

    void Handle_restore(HandleRef _this) {
        THIS->restore();
    }

    void Handle_rotate(HandleRef _this, double angle) {
        THIS->rotate(angle);
    }

    void Handle_save(HandleRef _this) {
        THIS->save();
    }

    void Handle_scale(HandleRef _this, double sx, double sy) {
        THIS->scale(sx, sy);
    }

    void Handle_setBackground(HandleRef _this, Brush::HandleRef brush) {
        THIS->setBackground(QBRUSH_VALUE(brush));
    }

    void Handle_setBackgroundMode(HandleRef _this, BGMode mode) {
        THIS->setBackgroundMode(static_cast<Qt::BGMode>(mode));
    }

    void Handle_setBrush(HandleRef _this, Brush::HandleRef brush) {
        THIS->setBrush(QBRUSH_VALUE(brush));
    }

    void Handle_setBrush(HandleRef _this, BrushStyle style) {
        THIS->setBrush(static_cast<Qt::BrushStyle>(style));
    }

    void Handle_setBrushOrigin(HandleRef _this, PointF position) {
        THIS->setBrushOrigin(toQPointF(position));
    }

    void Handle_setBrushOrigin(HandleRef _this, Point2::HandleRef position) {
        THIS->setBrushOrigin(QPOINT_VALUE(position));
    }

    void Handle_setBrushOrigin(HandleRef _this, int32_t x, int32_t y) {
        THIS->setBrushOrigin(x, y);
    }

    void Handle_setClipPath(HandleRef _this, PainterPath::HandleRef path, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipPath(QPAINTERPATH_VALUE(path), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, RectF rectangle, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(toQRectF(rectangle), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(x, y, width, height, static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, Rect rectangle, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(toQRect(rectangle), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRegion(HandleRef _this, Region::HandleRef region, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRegion(QREGION_VALUE(region), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipping(HandleRef _this, bool enable) {
        THIS->setClipping(enable);
    }

    void Handle_setCompositionMode(HandleRef _this, CompositionMode mode) {
        THIS->setCompositionMode(static_cast<QPainter::CompositionMode>(mode));
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    void Handle_setLayoutDiretion(HandleRef _this, LayoutDirection direction) {
        THIS->setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
    }

    void Handle_setOpacity(HandleRef _this, double opacity) {
        THIS->setOpacity(opacity);
    }

    void Handle_setPen(HandleRef _this, Pen::HandleRef pen) {
        THIS->setPen(QPEN_VALUE(pen));
    }

    void Handle_setPen(HandleRef _this, PenStyle style) {
        THIS->setPen(static_cast<Qt::PenStyle>(style));
    }

    void Handle_setPen(HandleRef _this, Color::HandleRef color) {
        THIS->setPen(QCOLOR_VALUE(color));
    }

    void Handle_setRenderHint(HandleRef _this, RenderHint hint, bool on /* true */) {
        THIS->setRenderHint(static_cast<QPainter::RenderHint>(hint), on);
    }

    void Handle_setRenderHints(HandleRef _this, RenderHints hints, bool on /* true */) {
        THIS->setRenderHints(static_cast<QPainter::RenderHints>(hints.value), on);
    }

    void Handle_setTransform(HandleRef _this, Transform::HandleRef transform, bool combine /* false */) {
        THIS->setTransform(QTRANSFORM_VALUE(transform), combine);
    }

    void Handle_setViewTransformEnabled(HandleRef _this, bool enable) {
        THIS->setViewTransformEnabled(enable);
    }

    void Handle_setViewport(HandleRef _this, Rect rectangle) {
        THIS->setViewport(toQRect(rectangle));
    }

    void Handle_setViewport(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->setViewport(x, y, width, height);
    }

    void Handle_setWindow(HandleRef _this, Rect rectangle) {
        THIS->setWindow(toQRect(rectangle));
    }

    void Handle_setWindow(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->setWindow(x, y, width, height);
    }

    void Handle_setWorldMatrixEnabled(HandleRef _this, bool enable) {
        THIS->setWorldMatrixEnabled(enable);
    }

    void Handle_setWorldTransform(HandleRef _this, Transform::HandleRef matrix, bool combine /* false */) {
        THIS->setWorldTransform(QTRANSFORM_VALUE(matrix), combine);
    }

    void Handle_shear(HandleRef _this, double sh, double sv) {
        THIS->shear(sh, sv);
    }

    void Handle_strokePath(HandleRef _this, PainterPath::HandleRef path, Pen::HandleRef pen) {
        THIS->strokePath(QPAINTERPATH_VALUE(path), QPEN_VALUE(pen));
    }

    bool Handle_testRenderHint(HandleRef _this, RenderHint hint) {
        return THIS->testRenderHint(static_cast<QPainter::RenderHint>(hint));
    }

    Transform::OwnedRef Handle_transform(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->transform());
    }

    void Handle_translate(HandleRef _this, PointF offset) {
        THIS->translate(toQPointF(offset));
    }

    void Handle_translate(HandleRef _this, Point2::HandleRef offset) {
        THIS->translate(QPOINT_VALUE(offset));
    }

    void Handle_translate(HandleRef _this, double dx, double dy) {
        THIS->translate(dx, dy);
    }

    bool Handle_viewTransformEnabled(HandleRef _this) {
        return THIS->viewTransformEnabled();
    }

    Rect Handle_viewport(HandleRef _this) {
        return toRect(THIS->viewport());
    }

    Rect Handle_window(HandleRef _this) {
        return toRect(THIS->window());
    }

    bool Handle_worldMatrixEnabled(HandleRef _this) {
        return THIS->worldMatrixEnabled();
    }

    Transform::OwnedRef Handle_worldTransform(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->worldTransform());
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return PAINTER_HEAP_NEW();
    }

    OwnedRef create(PaintDevice::HandleRef device) {
        return PAINTER_HEAP_NEW(reinterpret_cast<QPaintDevice*>(device));
    }
}
