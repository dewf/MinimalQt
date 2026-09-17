#include "generated/Polygon.h"

#include "PointInternal.h"
#include "PolygonInternal.h"
#include "PolygonFInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Point;
using namespace ::Rect;
using namespace ::Enums;

#define THIS (AS_QPOLYGON_PTR(_this))

namespace Polygon
{
    static std::vector<int> pointsToIntVector(const std::vector<Point::HandleRef>& points) {
        std::vector<int> ret;
        for (const auto handle : points) {
            const auto qPoint = QPOINT_VALUE(handle);
            ret.push_back(qPoint.x());
            ret.push_back(qPoint.y());
        }
        return ret;
    }

    Rect::OwnedRef Handle_boundingRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->boundingRect());
    }

    bool Handle_containsPoint(HandleRef _this, Point::HandleRef point, FillRule fillRule) {
        return THIS->containsPoint(QPOINT_VALUE(point), static_cast<Qt::FillRule>(fillRule));
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef r) {
        return POLYGON_HEAP_NEW(THIS->intersected(QPOLYGON_VALUE(r)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef p) {
        return THIS->intersects(QPOLYGON_VALUE(p));
    }

    std::tuple<int32_t,int32_t> Handle_pointXY(HandleRef _this, int32_t index) {
        int x, y;
        THIS->point(index, &x, &y);
        return { x, y };
    }

    Point::OwnedRef Handle_point(HandleRef _this, int32_t index) {
        return POINT_HEAP_NEW(THIS->point(index));
    }

    void Handle_putPoints(HandleRef _this, int32_t index, const std::vector<Point::HandleRef>& points) {
        const auto vec = pointsToIntVector(points);
        THIS->putPoints(index, static_cast<int>(points.size()), vec.data());
    }

    void Handle_putPoints(HandleRef _this, int32_t index, int32_t nPoints, HandleRef fromPolygon, int32_t fromIndex /* 0 */) {
        THIS->putPoints(index, nPoints, QPOLYGON_VALUE(fromPolygon), fromIndex);
    }

    void Handle_setPoint(HandleRef _this, int32_t index, int32_t x, int32_t y) {
        THIS->setPoint(index, x, y);
    }

    void Handle_setPoint(HandleRef _this, int32_t index, Point::HandleRef point) {
        THIS->setPoint(index, QPOINT_VALUE(point));
    }

    void Handle_setPoints(HandleRef _this, const std::vector<int32_t>& points) {
        THIS->setPoints(static_cast<int>(points.size()), points.data());
    }

    void Handle_setPoints(HandleRef _this, const std::vector<Point::HandleRef>& points) {
        const auto vec = pointsToIntVector(points);
        THIS->setPoints(static_cast<int>(points.size()), vec.data());
    }

    OwnedRef Handle_subtracted(HandleRef _this, HandleRef r) {
        return POLYGON_HEAP_NEW(THIS->subtracted(QPOLYGON_VALUE(r)));
    }

    void Handle_translate(HandleRef _this, int32_t dx, int32_t dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, Point::HandleRef offset) {
        THIS->translate(QPOINT_VALUE(offset));
    }

    OwnedRef Handle_translated(HandleRef _this, int32_t dx, int32_t dy) {
        return POLYGON_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, Point::HandleRef offset) {
        return POLYGON_HEAP_NEW(THIS->translated(QPOINT_VALUE(offset)));
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef r) {
        return POLYGON_HEAP_NEW(THIS->united(QPOLYGON_VALUE(r)));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return POLYGON_HEAP_NEW();
    }

    OwnedRef create(const std::vector<Point::HandleRef>& points) {
        const auto qPoints = toQList<Point::HandleRef,QPoint>(points, [](auto p) { return QPOINT_VALUE(p); });
        return POLYGON_HEAP_NEW(qPoints);
    }

    OwnedRef create(Rect::HandleRef rect, bool closed /* false */) {
        return POLYGON_HEAP_NEW(QRECT_VALUE(rect), closed);
    }
}
