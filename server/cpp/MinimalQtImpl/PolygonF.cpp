#include "generated/PolygonF.h"
#include "PolygonFInternal.h"

#include "PolygonInternal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Enums;

#define THIS (AS_QPOLYGONF_PTR(_this))

namespace PolygonF
{
    RectF Handle_boundingRect(HandleRef _this) {
        return toRectF(THIS->boundingRect());
    }

    bool Handle_containsPoint(HandleRef _this, PointF point, FillRule fillRule) {
        return THIS->containsPoint(toQPointF(point), static_cast<Qt::FillRule>(fillRule));
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef r) {
        return POLYGONF_HEAP_NEW(THIS->intersected(QPOLYGONF_VALUE(r)));
    }

    bool Handle_intersects(HandleRef _this, HandleRef p) {
        return THIS->intersects(QPOLYGONF_VALUE(p));
    }

    bool Handle_isClosed(HandleRef _this) {
        return THIS->isClosed();
    }

    OwnedRef Handle_subtracted(HandleRef _this, HandleRef r) {
        return POLYGONF_HEAP_NEW(THIS->subtracted(QPOLYGONF_VALUE(r)));
    }

    Polygon_OwnedRef Handle_toPolygon(HandleRef _this) {
        const auto actual = POLYGON_HEAP_NEW(THIS->toPolygon());
        return reinterpret_cast<Polygon_OwnedRef>(actual);
    }

    void Handle_translate(HandleRef _this, PointF offset) {
        THIS->translate(toQPointF(offset));
    }

    void Handle_translate(HandleRef _this, double dx, double dy) {
        THIS->translate(dx, dy);
    }

    OwnedRef Handle_translated(HandleRef _this, PointF offset) {
        return POLYGONF_HEAP_NEW(THIS->translated(toQPointF(offset)));
    }

    OwnedRef Handle_translated(HandleRef _this, double dx, double dy) {
        return POLYGONF_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef r) {
        return POLYGONF_HEAP_NEW(THIS->united(QPOLYGONF_VALUE(r)));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return POLYGONF_HEAP_NEW();
    }

    OwnedRef create(const std::vector<PointF>& points) {
        const auto qPoints = toQList<PointF,QPointF>(points, toQPointF);
        return POLYGONF_HEAP_NEW(qPoints);
    }

    OwnedRef create(Polygon_HandleRef polygon) {
        return POLYGONF_HEAP_NEW(QPOLYGON_VALUE(polygon));
    }

    OwnedRef create(RectF rectangle) {
        return POLYGONF_HEAP_NEW(toQRectF(rectangle));
    }
}
