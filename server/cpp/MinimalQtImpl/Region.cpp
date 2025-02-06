#include "generated/Region.h"

#include "PointInternal.h"
#include "RegionInternal.h"

#include "PolygonInternal.h"

#include "util/convert.h"

using namespace ::Common;
using namespace ::Point;
using namespace ::Polygon;
using namespace ::Enums;

#define THIS (AS_QREGION_PTR(_this))

namespace Region
{
    Rect Handle_boundingRect(HandleRef _this) {
        return toRect(THIS->boundingRect());
    }

    bool Handle_contains(HandleRef _this, Point::HandleRef p) {
        return THIS->contains(QPOINT_VALUE(p));
    }

    bool Handle_contains(HandleRef _this, Rect r) {
        return THIS->contains(toQRect(r));
    }

    OwnedRef Handle_intersected(HandleRef _this, Rect rect) {
        return REGION_HEAP_NEW(THIS->intersected(toQRect(rect)));
    }

    OwnedRef Handle_intersected(HandleRef _this, HandleRef r) {
        return REGION_HEAP_NEW(THIS->intersected(QREGION_VALUE(r)));
    }

    bool Handle_intersects(HandleRef _this, Rect rect) {
        return THIS->intersects(toQRect(rect));
    }

    bool Handle_intersects(HandleRef _this, HandleRef region) {
        return THIS->intersects(QREGION_VALUE(region));
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    int32_t Handle_rectCount(HandleRef _this) {
        return THIS->rectCount();
    }

    std::vector<Rect> Handle_rects(HandleRef _this) {
        return fromQSpan<const QRect,Rect>(THIS->rects(), toRect);
    }

    void Handle_setRects(HandleRef _this, const std::vector<Rect>& rects) {
        const auto qVec = vectorMap<Rect,QRect>(rects, toQRect);
        THIS->setRects(qVec);
    }

    OwnedRef Handle_subtracted(HandleRef _this, HandleRef r) {
        return REGION_HEAP_NEW(THIS->subtracted(QREGION_VALUE(r)));
    }

    void Handle_translate(HandleRef _this, int32_t dx, int32_t dy) {
        THIS->translate(dx, dy);
    }

    void Handle_translate(HandleRef _this, Point::HandleRef point) {
        THIS->translate(QPOINT_VALUE(point));
    }

    OwnedRef Handle_translated(HandleRef _this, int32_t dx, int32_t dy) {
        return REGION_HEAP_NEW(THIS->translated(dx, dy));
    }

    OwnedRef Handle_translated(HandleRef _this, Point::HandleRef p) {
        return REGION_HEAP_NEW(THIS->translated(QPOINT_VALUE(p)));
    }

    OwnedRef Handle_united(HandleRef _this, Rect rect) {
        return REGION_HEAP_NEW(THIS->united(toQRect(rect)));
    }

    OwnedRef Handle_united(HandleRef _this, HandleRef r) {
        return REGION_HEAP_NEW(THIS->united(QREGION_VALUE(r)));
    }

    OwnedRef Handle_xored(HandleRef _this, HandleRef r) {
        return REGION_HEAP_NEW(THIS->xored(QREGION_VALUE(r)));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return REGION_HEAP_NEW();
    }

    OwnedRef create(Polygon::HandleRef a, FillRule fillRule /* FillRule::OddEvenFill */) {
        return REGION_HEAP_NEW(QPOLYGON_VALUE(a), static_cast<Qt::FillRule>(fillRule));
    }

    OwnedRef create(int32_t x, int32_t y, int32_t w, int32_t h, RegionType t /* RegionType::Rectangle */) {
        return REGION_HEAP_NEW(x, y, w, h, static_cast<QRegion::RegionType>(t));
    }

    OwnedRef create(Rect r, RegionType t /* RegionType::Rectangle */) {
        return REGION_HEAP_NEW(toQRect(r), static_cast<QRegion::RegionType>(t));
    }

    OwnedRef create(HandleRef other) {
        return REGION_HEAP_NEW(QREGION_VALUE(other));
    }
}
