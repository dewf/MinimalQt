#include "generated/PainterPath.h"

#include "FontInternal.h"
#include "PainterPathInternal.h"
#include "RegionInternal.h"
#include "PolygonFInternal.h"
#include "TransformInternal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Enums;
using namespace ::Region;
using namespace ::Font;
using namespace ::PolygonF;
using namespace ::Transform;

#define THIS (AS_QPAINTERPATH_PTR(_this))

namespace PainterPath
{
    void Handle_addEllipse(HandleRef _this, RectF boundingRectangle) {
        THIS->addEllipse(toQRectF(boundingRectangle));
    }

    void Handle_addEllipse(HandleRef _this, PointF center, double rx, double ry) {
        THIS->addEllipse(toQPointF(center), rx, ry);
    }

    void Handle_addEllipse(HandleRef _this, double x, double y, double width, double height) {
        THIS->addEllipse(x, y, width, height);
    }

    void Handle_addPath(HandleRef _this, HandleRef path) {
        THIS->addPath(QPAINTERPATH_VALUE(path));
    }

    void Handle_addPolygon(HandleRef _this, PolygonF::HandleRef polygon) {
        THIS->addPolygon(QPOLYGONF_VALUE(polygon));
    }

    void Handle_addRect(HandleRef _this, RectF rectangle) {
        THIS->addRect(toQRectF(rectangle));
    }

    void Handle_addRect(HandleRef _this, double x, double y, double width, double height) {
        THIS->addRect(x, y, width, height);
    }

    void Handle_addRegion(HandleRef _this, Region::HandleRef region) {
        THIS->addRegion(QREGION_VALUE(region));
    }

    void Handle_addRoundedRect(HandleRef _this, RectF rect, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->addRoundedRect(toQRectF(rect), xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_addRoundedRect(HandleRef _this, double x, double y, double w, double h, double xRadius, double yRadius, SizeMode mode /* SizeMode::AbsoluteSize */) {
        THIS->addRoundedRect(x, y, w, h, xRadius, yRadius, static_cast<Qt::SizeMode>(mode));
    }

    void Handle_addText(HandleRef _this, PointF point, Font::HandleRef font, const std::string& text) {
        THIS->addText(toQPointF(point), QFONT_VALUE(font), QString::fromStdString(text));
    }

    void Handle_addText(HandleRef _this, double x, double y, Font::HandleRef font, const std::string& text) {
        THIS->addText(x, y, QFONT_VALUE(font), QString::fromStdString(text));
    }

    double Handle_angleAtPercent(HandleRef _this, double t) {
        return THIS->angleAtPercent(t);
    }

    void Handle_arcMoveTo(HandleRef _this, RectF rectangle, double angle) {
        THIS->arcMoveTo(toQRectF(rectangle), angle);
    }

    void Handle_arcMoveTo(HandleRef _this, double x, double y, double width, double height, double angle) {
        THIS->arcMoveTo(x, y, width, height, angle);
    }

    void Handle_arcTo(HandleRef _this, RectF rectangle, double startAngle, double sweepLength) {
        THIS->arcTo(toQRectF(rectangle), startAngle, sweepLength);
    }

    void Handle_arcTo(HandleRef _this, double x, double y, double width, double height, double startAngle, double sweepLength) {
        THIS->arcTo(x, y, width, height, startAngle, sweepLength);
    }

    RectF Handle_boundingRect(HandleRef _this) {
        return toRectF(THIS->boundingRect());
    }

    int32_t Handle_capacity(HandleRef _this) {
        return THIS->capacity();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_closeSubpath(HandleRef _this) {
        THIS->closeSubpath();
    }

    void Handle_connectPath(HandleRef _this, HandleRef path) {
        THIS->connectPath(QPAINTERPATH_VALUE(path));
    }

    bool Handle_contains(HandleRef _this, HandleRef p) {
        return THIS->contains(QPAINTERPATH_VALUE(p));
    }

    bool Handle_contains(HandleRef _this, PointF point) {
        return THIS->contains(toQPointF(point));
    }

    bool Handle_contains(HandleRef _this, RectF rectangle) {
        return THIS->contains(toQRectF(rectangle));
    }

    RectF Handle_controlPointRect(HandleRef _this) {
        return toRectF(THIS->controlPointRect());
    }

    void Handle_cubicTo(HandleRef _this, PointF c1, PointF c2, PointF endPoint) {
        THIS->cubicTo(toQPointF(c1), toQPointF(c2), toQPointF(endPoint));
    }

    void Handle_cubicTo(HandleRef _this, double c1X, double c1Y, double c2X, double c2Y, double endPointX, double endPointY) {
        THIS->cubicTo(c1X, c1Y, c2X, c2Y, endPointX, endPointY);
    }

    PointF Handle_currentPosition(HandleRef _this) {
        return toPointF(THIS->currentPosition());
    }

    int32_t Handle_elementCount(HandleRef _this) {
        return THIS->elementCount();
    }

    FillRule Handle_fillRule(HandleRef _this) {
        return static_cast<FillRule>(THIS->fillRule());
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef p) {
        return PAINTERPATH_HEAP_NEW(THIS->intersected(QPAINTERPATH_VALUE(p)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef p) {
        return THIS->intersects(QPAINTERPATH_VALUE(p));
    }

    bool Handle_intersects(HandleRef _this, RectF rectangle) {
        return THIS->intersects(toQRectF(rectangle));
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    double Handle_length(HandleRef _this) {
        return THIS->length();
    }

    void Handle_lineTo(HandleRef _this, PointF endPoint) {
        THIS->lineTo(toQPointF(endPoint));
    }

    void Handle_lineTo(HandleRef _this, double x, double y) {
        THIS->lineTo(x, y);
    }

    void Handle_moveTo(HandleRef _this, PointF point) {
        THIS->moveTo(toQPointF(point));
    }

    void Handle_moveTo(HandleRef _this, double x, double y) {
        THIS->moveTo(x, y);
    }

    double Handle_percentAtLength(HandleRef _this, double len) {
        return THIS->percentAtLength(len);
    }

    PointF Handle_pointAtPercent(HandleRef _this, double t) {
        return toPointF(THIS->pointAtPercent(t));
    }

    void Handle_quadTo(HandleRef _this, PointF c, PointF endPoint) {
        THIS->quadTo(toQPointF(c), toQPointF(endPoint));
    }

    void Handle_quadTo(HandleRef _this, double cx, double cy, double endPointX, double endPointY) {
        THIS->quadTo(cx, cy, endPointX, endPointY);
    }

    void Handle_reserve(HandleRef _this, int32_t size) {
        THIS->reserve(size);
    }

    void Handle_setElementPositionAt(HandleRef _this, int32_t index, double x, double y) {
        THIS->setElementPositionAt(index, x, y);
    }

    void Handle_setFillRule(HandleRef _this, FillRule fillRule) {
        THIS->setFillRule(static_cast<Qt::FillRule>(fillRule));
    }

    OwnedRef Handle_simplified(HandleRef _this) {
        return PAINTERPATH_HEAP_NEW(THIS->simplified());
    }

    double Handle_slopeAtPercent(HandleRef _this, double t) {
        return THIS->slopeAtPercent(t);
    }

    OwnedRef Handle_subtracted(HandleRef _this, HandleRef p) {
        return PAINTERPATH_HEAP_NEW(THIS->subtracted(QPAINTERPATH_VALUE(p)));
    }

    PolygonF::OwnedRef Handle_toFillPolygon(HandleRef _this, Transform::HandleRef matrix /* nullptr */) {
        return POLYGONF_HEAP_NEW(THIS->toFillPolygon(Transform::fromNullable(matrix)));
    }

    std::vector<PolygonF::OwnedRef> Handle_toFillPolygons(HandleRef _this, Transform::HandleRef matrix /* nullptr */) {
        const auto qListResult = THIS->toFillPolygons(Transform::fromNullable(matrix));
        return fromQList<QPolygonF,PolygonF::OwnedRef>(qListResult, [](auto poly) {
            return POLYGONF_HEAP_NEW(poly);
        });
    }

    OwnedRef Handle_toReversed(HandleRef _this) {
        return PAINTERPATH_HEAP_NEW(THIS->toReversed());
    }

    std::vector<PolygonF::OwnedRef> Handle_toSubpathPolygons(HandleRef _this, Transform::HandleRef matrix /* nullptr */) {
        const auto qListResult = THIS->toSubpathPolygons(Transform::fromNullable(matrix));
        return fromQList<QPolygonF,PolygonF::OwnedRef>(qListResult, [](auto poly) {
            return POLYGONF_HEAP_NEW(poly);
        });
    }

    void Handle_translate(HandleRef _this, double dx, double dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, PointF offset) {
        THIS->translate(toQPointF(offset));
    }

    OwnedRef Handle_translated(HandleRef _this, double dx, double dy) {
        return PAINTERPATH_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, PointF offset) {
        return PAINTERPATH_HEAP_NEW(THIS->translated(toQPointF(offset)));
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef p) {
        return PAINTERPATH_HEAP_NEW(THIS->united(QPAINTERPATH_VALUE(p)));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return PAINTERPATH_HEAP_NEW();
    }

    OwnedRef create(PointF startPoint) {
        return PAINTERPATH_HEAP_NEW(toQPointF(startPoint));
    }

    OwnedRef create(HandleRef path) {
        return PAINTERPATH_HEAP_NEW(QPAINTERPATH_VALUE(path));
    }
}
