#include "generated/Polygon.h"
#include "PolygonInternal.h"

#include "PolygonFInternal.h"
#include "util/convert.h"

#define THIS (AS_QPOLYGON_PTR(_this))

namespace Polygon
{
    static std::vector<int> pointsToIntVector(const std::vector<Point>& points) {
        std::vector<int> ret;
        for (auto &p : points) {
            ret.push_back(p.x);
            ret.push_back(p.y);
        }
        return ret;
    }

    Rect Handle_boundingRect(HandleRef _this) {
        return toRect(THIS->boundingRect());
    }

    bool Handle_containsPoint(HandleRef _this, Point point, FillRule fillRule) {
        return THIS->containsPoint(toQPoint(point), static_cast<Qt::FillRule>(fillRule));
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef r) {
        return POLYGON_HEAP_NEW(THIS->intersected(QPOLYGON_VALUE(r)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef p) {
        return THIS->intersects(QPOLYGON_VALUE(p));
    }

    Point Handle_point(HandleRef _this, int32_t index) {
        return toPoint(THIS->point(index));
    }

    void Handle_putPoints(HandleRef _this, int32_t index, const std::vector<Point>& points) {
        const auto vec = pointsToIntVector(points);
        THIS->putPoints(index, static_cast<int>(points.size()), vec.data());
    }

    void Handle_putPoints(HandleRef _this, int32_t index, int32_t nPoints, HandleRef fromPolygon, int32_t fromIndex /* 0 */) {
        THIS->putPoints(index, nPoints, QPOLYGON_VALUE(fromPolygon), fromIndex);
    }

    void Handle_setPoint(HandleRef _this, int32_t index, int32_t x, int32_t y) {
        THIS->setPoint(index, x, y);
    }

    void Handle_setPoint(HandleRef _this, int32_t index, Point point) {
        THIS->setPoint(index, toQPoint(point));
    }

    void Handle_setPoints(HandleRef _this, const std::vector<Point>& points) {
        const auto vec = pointsToIntVector(points);
        THIS->setPoints(static_cast<int>(points.size()), vec.data());
    }

    OwnedRef Handle_subtracted(HandleRef _this, HandleRef r) {
        return POLYGON_HEAP_NEW(THIS->subtracted(QPOLYGON_VALUE(r)));
    }

    PolygonF_OwnedRef Handle_toPolygonF(HandleRef _this) {
        const auto actual = POLYGONF_HEAP_NEW(THIS->toPolygonF());
        return reinterpret_cast<PolygonF_OwnedRef>(actual);
    }

    void Handle_translate(HandleRef _this, int32_t dx, int32_t dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, Point offset) {
        THIS->translate(toQPoint(offset));
    }

    OwnedRef Handle_translated(HandleRef _this, int32_t dx, int32_t dy) {
        return POLYGON_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, Point offset) {
        return POLYGON_HEAP_NEW(THIS->translated(toQPoint(offset)));
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

    OwnedRef create(const std::vector<Point>& points) {
        const auto qPoints = toQList<Point,QPoint>(points, toQPoint);
        return POLYGON_HEAP_NEW(qPoints);
    }

    OwnedRef create(Rect rect, bool closed /* false */) {
        return POLYGON_HEAP_NEW(toQRect(rect), closed);
    }
}
