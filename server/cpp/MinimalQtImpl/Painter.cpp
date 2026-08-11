#include "generated/Painter.h"
#include "PainterInternal.h"

#include "BrushInternal.h"
#include "ColorInternal.h"
#include "FontInternal.h"
#include "ImageInternal.h"
#include "PainterPathInternal.h"
#include "PenInternal.h"
#include "PixmapInternal.h"
#include "PointFInternal.h"
#include "PointInternal.h"
#include "PolygonInternal.h"
#include "PolygonFInternal.h"
#include "RegionInternal.h"
#include "TextOptionInternal.h"
#include "TransformInternal.h"
#include "RectInternal.h"
#include "RectFInternal.h"

#include "util/convert.h"

using namespace ::Point;
using namespace ::PointF;
using namespace ::Rect;
using namespace ::RectF;
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
        OwnedRef create(PointF::HandleRef pos, RectF::HandleRef sourceRect, double scaleX /* 1 */, double scaleY /* 1 */, double rotation /* 0 */, double opacity /* 1 */) {
            const auto ret = QPainter::PixmapFragment::create(QPOINTF_VALUE(pos), QRECTF_VALUE(sourceRect), scaleX, scaleY, rotation, opacity);
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

    RectF::OwnedRef Handle_boundingRect(HandleRef _this, RectF::HandleRef rectangle, int32_t flags_, const std::string& text) {
        return RECTF_HEAP_NEW(THIS->boundingRect(QRECTF_VALUE(rectangle), flags_, QString::fromStdString(text)));
    }

    Rect::OwnedRef Handle_boundingRect(HandleRef _this, Rect::HandleRef rectangle, int32_t flags_, const std::string& text) {
        return RECT_HEAP_NEW(THIS->boundingRect(QRECT_VALUE(rectangle), flags_, QString::fromStdString(text)));
    }

    RectF::OwnedRef Handle_boundingRect(HandleRef _this, RectF::HandleRef rectangle, const std::string& text, const std::optional<TextOption::HandleRef>& option) {
        QTextOption qOption;
        if (option.has_value()) qOption = QTEXTOPTION_VALUE(option.value());
        return RECTF_HEAP_NEW(THIS->boundingRect(QRECTF_VALUE(rectangle), QString::fromStdString(text), qOption));
    }

    Rect::OwnedRef Handle_boundingRect(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h, int32_t flags_, const std::string& text) {
        return RECT_HEAP_NEW(THIS->boundingRect(x, y, w, h, flags_, QString::fromStdString(text)));
    }

    Brush::OwnedRef Handle_brush(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->brush());
    }

    Point::OwnedRef Handle_brushOrigin(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->brushOrigin());
    }

    RectF::OwnedRef Handle_clipBoundingRect(HandleRef _this) {
        return RECTF_HEAP_NEW(THIS->clipBoundingRect());
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

    void Handle_drawArc(HandleRef _this, RectF::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(QRECTF_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawArc(HandleRef _this, Rect::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(QRECT_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawArc(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawArc(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, RectF::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(QRECTF_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, Rect::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(QRECT_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawChord(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawChord(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawConvexPolygon(HandleRef _this, const std::vector<PointF::HandleRef>& points) {
        const auto qPoints = vectorMap<PointF::HandleRef,QPointF>(points, [](auto p) { return QPOINTF_VALUE(p); });
        THIS->drawConvexPolygon(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawConvexPolygon(HandleRef _this, Polygon::HandleRef polygon) {
        THIS->drawConvexPolygon(QPOLYGON_VALUE(polygon));
    }

    void Handle_drawConvexPolygon(HandleRef _this, PolygonF::HandleRef polygon) {
        THIS->drawConvexPolygon(QPOLYGONF_VALUE(polygon));
    }

    void Handle_drawConvexPolygon(HandleRef _this, const std::vector<Point::HandleRef>& points) {
        const auto qPoints = vectorMap<Point::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawConvexPolygon(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawEllipse(HandleRef _this, RectF::HandleRef rectangle) {
        THIS->drawEllipse(QRECTF_VALUE(rectangle));
    }

    void Handle_drawEllipse(HandleRef _this, Rect::HandleRef rectangle) {
        THIS->drawEllipse(QRECT_VALUE(rectangle));
    }

    void Handle_drawEllipse(HandleRef _this, Point::HandleRef center, int32_t rx, int32_t ry) {
        THIS->drawEllipse(QPOINT_VALUE(center), rx, ry);
    }

    void Handle_drawEllipse(HandleRef _this, PointF::HandleRef center, double rx, double ry) {
        THIS->drawEllipse(QPOINTF_VALUE(center), rx, ry);
    }

    void Handle_drawEllipse(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->drawEllipse(x, y, width, height);
    }

    void Handle_drawImage(HandleRef _this, RectF::HandleRef target, Image::HandleRef image, RectF::HandleRef source, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(QRECTF_VALUE(target), QIMAGE_VALUE(image), QRECTF_VALUE(source), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    void Handle_drawImage(HandleRef _this, Point::HandleRef point, Image::HandleRef image) {
        THIS->drawImage(QPOINT_VALUE(point), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, PointF::HandleRef point, Image::HandleRef image) {
        THIS->drawImage(QPOINTF_VALUE(point), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, Rect::HandleRef rectangle, Image::HandleRef image) {
        THIS->drawImage(QRECT_VALUE(rectangle), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, RectF::HandleRef rectangle, Image::HandleRef image) {
        THIS->drawImage(QRECTF_VALUE(rectangle), QIMAGE_VALUE(image));
    }

    void Handle_drawImage(HandleRef _this, Point::HandleRef point, Image::HandleRef image, Rect::HandleRef source, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(QPOINT_VALUE(point), QIMAGE_VALUE(image), QRECT_VALUE(source), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    void Handle_drawImage(HandleRef _this, PointF::HandleRef point, Image::HandleRef image, RectF::HandleRef source, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(QPOINTF_VALUE(point), QIMAGE_VALUE(image), QRECTF_VALUE(source), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    void Handle_drawImage(HandleRef _this, Rect::HandleRef target, Image::HandleRef image, Rect::HandleRef source, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(QRECT_VALUE(target), QIMAGE_VALUE(image), QRECT_VALUE(source), static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    void Handle_drawImage(HandleRef _this, int32_t x, int32_t y, Image::HandleRef image, int32_t sx /* 0 */, int32_t sy /* 0 */, int32_t sw /* -1 */, int32_t sh /* -1 */, Flags<ImageConversionFlags> flags_ /* ImageConversionFlags::AutoColor */) {
        THIS->drawImage(x, y, QIMAGE_VALUE(image), sx, sy, sw, sh, static_cast<Qt::ImageConversionFlags>(flags_.value()));
    }

    void Handle_drawLine(HandleRef _this, Point::HandleRef p1, Point::HandleRef p2) {
        THIS->drawLine(QPOINT_VALUE(p1), QPOINT_VALUE(p2));
    }

    void Handle_drawLine(HandleRef _this, PointF::HandleRef p1, PointF::HandleRef p2) {
        THIS->drawLine(QPOINTF_VALUE(p1), QPOINTF_VALUE(p2));
    }

    void Handle_drawLine(HandleRef _this, int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
        THIS->drawLine(x1, y1, x2, y2);
    }

    void Handle_drawLines(HandleRef _this, const std::vector<Point::HandleRef>& pointPairs) {
        const auto qPointPairs = vectorMap<Point::HandleRef,QPoint>(pointPairs, [](auto p) { return QPOINT_VALUE(p); });
        const auto lineCount = static_cast<int>(qPointPairs.size() - 1);
        THIS->drawLines(qPointPairs.data(), lineCount);
    }

    void Handle_drawLines(HandleRef _this, const std::vector<PointF::HandleRef>& pointPairs) {
        const auto qPointPairs = vectorMap<PointF::HandleRef,QPointF>(pointPairs, [](auto p) { return QPOINTF_VALUE(p); });
        const auto lineCount = static_cast<int>(qPointPairs.size() - 1);
        THIS->drawLines(qPointPairs.data(), lineCount);
    }

    void Handle_drawPath(HandleRef _this, PainterPath::HandleRef path) {
        THIS->drawPath(QPAINTERPATH_VALUE(path));
    }

    void Handle_drawPie(HandleRef _this, RectF::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(QRECTF_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawPie(HandleRef _this, Rect::HandleRef rectangle, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(QRECT_VALUE(rectangle), startAngle, spanAngle);
    }

    void Handle_drawPie(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t startAngle, int32_t spanAngle) {
        THIS->drawPie(x, y, width, height, startAngle, spanAngle);
    }

    void Handle_drawPixmap(HandleRef _this, RectF::HandleRef target, Pixmap::HandleRef pixmap, RectF::HandleRef source) {
        THIS->drawPixmap(QRECTF_VALUE(target), QPIXMAP_VALUE(pixmap), QRECTF_VALUE(source));
    }

    void Handle_drawPixmap(HandleRef _this, Point::HandleRef point, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(QPOINT_VALUE(point), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, PointF::HandleRef point, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(QPOINTF_VALUE(point), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, Rect::HandleRef rectangle, Pixmap::HandleRef pixmap) {
        THIS->drawPixmap(QRECT_VALUE(rectangle), QPIXMAP_VALUE(pixmap));
    }

    void Handle_drawPixmap(HandleRef _this, Point::HandleRef point, Pixmap::HandleRef pixmap, Rect::HandleRef source) {
        THIS->drawPixmap(QPOINT_VALUE(point), QPIXMAP_VALUE(pixmap), QRECT_VALUE(source));
    }

    void Handle_drawPixmap(HandleRef _this, PointF::HandleRef point, Pixmap::HandleRef pixmap, RectF::HandleRef source) {
        THIS->drawPixmap(QPOINTF_VALUE(point), QPIXMAP_VALUE(pixmap), QRECTF_VALUE(source));
    }

    void Handle_drawPixmap(HandleRef _this, Rect::HandleRef target, Pixmap::HandleRef pixmap, Rect::HandleRef source) {
        THIS->drawPixmap(QRECT_VALUE(target), QPIXMAP_VALUE(pixmap), QRECT_VALUE(source));
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

    void Handle_drawPixmapFragments(HandleRef _this, const std::vector<PixmapFragment::HandleRef>& fragments, Pixmap::HandleRef pixmap, Flags<PixmapFragment::Hints> hints /* 0 */) {
        const auto qFragments = vectorMap<PixmapFragment::HandleRef,QPainter::PixmapFragment>(fragments, [](auto f) { return QPIXMAPFRAGMENT_VALUE(f); });
        THIS->drawPixmapFragments(qFragments.data(), static_cast<int>(qFragments.size()), QPIXMAP_VALUE(pixmap), static_cast<QPainter::PixmapFragmentHints>(hints.value()));
    }

    void Handle_drawPoint(HandleRef _this, PointF::HandleRef position) {
        THIS->drawPoint(QPOINTF_VALUE(position));
    }

    void Handle_drawPoint(HandleRef _this, Point::HandleRef position) {
        THIS->drawPoint(QPOINT_VALUE(position));
    }

    void Handle_drawPoint(HandleRef _this, int32_t x, int32_t y) {
        THIS->drawPoint(x, y);
    }

    void Handle_drawPoints(HandleRef _this, const std::vector<PointF::HandleRef>& points) {
        const auto qPoints = vectorMap<PointF::HandleRef,QPointF>(points, [](auto p) { return QPOINTF_VALUE(p); });
        THIS->drawPoints(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPoints(HandleRef _this, Polygon::HandleRef points) {
        THIS->drawPoints(QPOLYGON_VALUE(points));
    }

    void Handle_drawPoints(HandleRef _this, PolygonF::HandleRef points) {
        THIS->drawPoints(QPOLYGONF_VALUE(points));
    }

    void Handle_drawPoints(HandleRef _this, const std::vector<Point::HandleRef>& points) {
        const auto qPoints = vectorMap<Point::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPoints(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPolygon(HandleRef _this, const std::vector<PointF::HandleRef>& points, FillRule fillRule /* FillRule::OddEvenFill */) {
        const auto qPoints = vectorMap<PointF::HandleRef,QPointF>(points, [](auto p) { return QPOINTF_VALUE(p); });
        THIS->drawPolygon(qPoints.data(), static_cast<int>(qPoints.size()), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, Polygon::HandleRef points, FillRule fillRule /* FillRule::OddEvenFill */) {
        THIS->drawPolygon(QPOLYGON_VALUE(points), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, PolygonF::HandleRef points, FillRule fillRule /* FillRule::OddEvenFill */) {
        THIS->drawPolygon(QPOLYGONF_VALUE(points), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolygon(HandleRef _this, const std::vector<Point::HandleRef>& points, FillRule fillRule /* FillRule::OddEvenFill */) {
        const auto qPoints = vectorMap<Point::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPolygon(qPoints.data(), static_cast<int>(qPoints.size()), static_cast<Qt::FillRule>(fillRule));
    }

    void Handle_drawPolyline(HandleRef _this, const std::vector<PointF::HandleRef>& points) {
        const auto qPoints = vectorMap<PointF::HandleRef,QPointF>(points, [](auto p) { return QPOINTF_VALUE(p); });
        THIS->drawPolyline(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawPolyline(HandleRef _this, Polygon::HandleRef points) {
        THIS->drawPolyline(QPOLYGON_VALUE(points));
    }

    void Handle_drawPolyline(HandleRef _this, PolygonF::HandleRef points) {
        THIS->drawPolyline(QPOLYGONF_VALUE(points));
    }

    void Handle_drawPolyline(HandleRef _this, const std::vector<Point::HandleRef>& points) {
        const auto qPoints = vectorMap<Point::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        THIS->drawPolyline(qPoints.data(), static_cast<int>(qPoints.size()));
    }

    void Handle_drawRect(HandleRef _this, RectF::HandleRef rectangle) {
        THIS->drawRect(QRECTF_VALUE(rectangle));
    }

    void Handle_drawRect(HandleRef _this, Rect::HandleRef rectangle) {
        THIS->drawRect(QRECT_VALUE(rectangle));
    }

    void Handle_drawRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->drawRect(x, y, width, height);
    }

    void Handle_drawRects(HandleRef _this, const std::vector<RectF::HandleRef>& rectangles) {
        const auto qRects = vectorMap<RectF::HandleRef,QRectF>(rectangles, [](auto r) { return QRECTF_VALUE(r); });
        THIS->drawRects(qRects.data(), static_cast<int>(qRects.size()));
    }

    void Handle_drawRects(HandleRef _this, const std::vector<Rect::HandleRef>& rectangles) {
        const auto qRects = vectorMap<Rect::HandleRef,QRect>(rectangles, [](auto r) { return QRECT_VALUE(r); });
        THIS->drawRects(qRects.data(), static_cast<int>(qRects.size()));
    }

    void Handle_drawRoundedRect(HandleRef _this, RectF::HandleRef rect, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(QRECTF_VALUE(rect), xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawRoundedRect(HandleRef _this, Rect::HandleRef rect, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(QRECT_VALUE(rect), xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawRoundedRect(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->drawRoundedRect(x, y, w, h, xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_drawText(HandleRef _this, PointF::HandleRef position, const std::string& text) {
        THIS->drawText(QPOINTF_VALUE(position), QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, Point::HandleRef position, const std::string& text) {
        THIS->drawText(QPOINT_VALUE(position), QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, RectF::HandleRef rectangle, const std::string& text, const std::optional<TextOption::HandleRef>& option) {
        QTextOption qOption;
        if (option.has_value()) qOption = QTEXTOPTION_VALUE(option.value());
        THIS->drawText(QRECTF_VALUE(rectangle), QString::fromStdString(text), qOption);
    }

    void Handle_drawText(HandleRef _this, int32_t x, int32_t y, const std::string& text) {
        THIS->drawText(x, y, QString::fromStdString(text));
    }

    void Handle_drawText(HandleRef _this, Rect::HandleRef rectangle, int32_t flags_, const std::string& text, const std::optional<Rect::HandleRef>& boundingRect) {
        QRect brValue;
        QRect *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = QRECT_VALUE(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(QRECT_VALUE(rectangle), flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawText(HandleRef _this, RectF::HandleRef rectangle, int32_t flags_, const std::string& text, const std::optional<RectF::HandleRef>& boundingRect) {
        QRectF brValue;
        QRectF *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = QRECTF_VALUE(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(QRECTF_VALUE(rectangle), flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawText(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, int32_t flags_, const std::string& text, const std::optional<Rect::HandleRef>& boundingRect) {
        QRect brValue;
        QRect *ptr = nullptr;
        if (boundingRect.has_value()) {
            brValue = QRECT_VALUE(boundingRect.value());
            ptr = &brValue;
        }
        THIS->drawText(x, y, width, height, flags_, QString::fromStdString(text), ptr);
    }

    void Handle_drawTiledPixmap(HandleRef _this, RectF::HandleRef rectangle, Pixmap::HandleRef pixmap, const std::optional<PointF::HandleRef>& position) {
        QPointF offset;
        if (position.has_value()) offset = QPOINTF_VALUE(position.value());
        THIS->drawTiledPixmap(QRECTF_VALUE(rectangle), QPIXMAP_VALUE(pixmap), offset);
    }

    void Handle_drawTiledPixmap(HandleRef _this, Rect::HandleRef rectangle, Pixmap::HandleRef pixmap, const std::optional<Point::HandleRef>& position) {
        QPoint offset;
        if (position.has_value()) offset = QPOINT_VALUE(position.value());
        THIS->drawTiledPixmap(QRECT_VALUE(rectangle), QPIXMAP_VALUE(pixmap), offset);
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

    void Handle_eraseRect(HandleRef _this, RectF::HandleRef rectangle) {
        THIS->eraseRect(QRECTF_VALUE(rectangle));
    }

    void Handle_eraseRect(HandleRef _this, Rect::HandleRef rectangle) {
        THIS->eraseRect(QRECT_VALUE(rectangle));
    }

    void Handle_eraseRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->eraseRect(x, y, width, height);
    }

    void Handle_fillPath(HandleRef _this, PainterPath::HandleRef path, Brush::HandleRef brush) {
        THIS->fillPath(QPAINTERPATH_VALUE(path), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, RectF::HandleRef rectangle, Brush::HandleRef brush) {
        THIS->fillRect(QRECTF_VALUE(rectangle), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, Rect::HandleRef rectangle, Preset preset) {
        THIS->fillRect(QRECT_VALUE(rectangle), static_cast<QGradient::Preset>(preset));
    }

    void Handle_fillRect(HandleRef _this, Rect::HandleRef rectangle, BrushStyle style) {
        THIS->fillRect(QRECT_VALUE(rectangle), static_cast<Qt::BrushStyle>(style));
    }

    void Handle_fillRect(HandleRef _this, Rect::HandleRef rectangle, GlobalColor color) {
        THIS->fillRect(QRECT_VALUE(rectangle), static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fillRect(HandleRef _this, Rect::HandleRef rectangle, Brush::HandleRef brush) {
        THIS->fillRect(QRECT_VALUE(rectangle), QBRUSH_VALUE(brush));
    }

    void Handle_fillRect(HandleRef _this, Rect::HandleRef rectangle, Color::HandleRef color) {
        THIS->fillRect(QRECT_VALUE(rectangle), QCOLOR_VALUE(color));
    }

    void Handle_fillRect(HandleRef _this, RectF::HandleRef rectangle, Preset preset) {
        THIS->fillRect(QRECTF_VALUE(rectangle), static_cast<QGradient::Preset>(preset));
    }

    void Handle_fillRect(HandleRef _this, RectF::HandleRef rectangle, BrushStyle style) {
        THIS->fillRect(QRECTF_VALUE(rectangle), static_cast<Qt::BrushStyle>(style));
    }

    void Handle_fillRect(HandleRef _this, RectF::HandleRef rectangle, GlobalColor color) {
        THIS->fillRect(QRECTF_VALUE(rectangle), static_cast<Qt::GlobalColor>(color));
    }

    void Handle_fillRect(HandleRef _this, RectF::HandleRef rectangle, Color::HandleRef color) {
        THIS->fillRect(QRECTF_VALUE(rectangle), QCOLOR_VALUE(color));
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

    Flags<RenderHints> Handle_renderHints(HandleRef _this) {
        return static_cast<Flags<RenderHints>>(THIS->renderHints());
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

    void Handle_setBrushOrigin(HandleRef _this, PointF::HandleRef position) {
        THIS->setBrushOrigin(QPOINTF_VALUE(position));
    }

    void Handle_setBrushOrigin(HandleRef _this, Point::HandleRef position) {
        THIS->setBrushOrigin(QPOINT_VALUE(position));
    }

    void Handle_setBrushOrigin(HandleRef _this, int32_t x, int32_t y) {
        THIS->setBrushOrigin(x, y);
    }

    void Handle_setClipPath(HandleRef _this, PainterPath::HandleRef path, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipPath(QPAINTERPATH_VALUE(path), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, RectF::HandleRef rectangle, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(QRECTF_VALUE(rectangle), static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(x, y, width, height, static_cast<Qt::ClipOperation>(operation));
    }

    void Handle_setClipRect(HandleRef _this, Rect::HandleRef rectangle, ClipOperation operation /* ClipOperation::ReplaceClip */) {
        THIS->setClipRect(QRECT_VALUE(rectangle), static_cast<Qt::ClipOperation>(operation));
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

    void Handle_setRenderHints(HandleRef _this, Flags<RenderHints> hints, bool on /* true */) {
        THIS->setRenderHints(static_cast<QPainter::RenderHints>(hints.value()), on);
    }

    void Handle_setTransform(HandleRef _this, Transform::HandleRef transform, bool combine /* false */) {
        THIS->setTransform(QTRANSFORM_VALUE(transform), combine);
    }

    void Handle_setViewTransformEnabled(HandleRef _this, bool enable) {
        THIS->setViewTransformEnabled(enable);
    }

    void Handle_setViewport(HandleRef _this, Rect::HandleRef rectangle) {
        THIS->setViewport(QRECT_VALUE(rectangle));
    }

    void Handle_setViewport(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->setViewport(x, y, width, height);
    }

    void Handle_setWindow(HandleRef _this, Rect::HandleRef rectangle) {
        THIS->setWindow(QRECT_VALUE(rectangle));
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

    void Handle_translate(HandleRef _this, PointF::HandleRef offset) {
        THIS->translate(QPOINTF_VALUE(offset));
    }

    void Handle_translate(HandleRef _this, Point::HandleRef offset) {
        THIS->translate(QPOINT_VALUE(offset));
    }

    void Handle_translate(HandleRef _this, double dx, double dy) {
        THIS->translate(dx, dy);
    }

    bool Handle_viewTransformEnabled(HandleRef _this) {
        return THIS->viewTransformEnabled();
    }

    Rect::OwnedRef Handle_viewport(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->viewport());
    }

    Rect::OwnedRef Handle_window(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->window());
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
