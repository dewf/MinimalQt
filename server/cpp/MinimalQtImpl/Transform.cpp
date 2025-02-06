#include "generated/Transform.h"
#include "TransformInternal.h"

#include "PainterPathInternal.h"
#include "PolygonFInternal.h"
#include "PolygonInternal.h"
#include "RegionInternal.h"

// #include <functional>
#include "PointInternal.h"
#include "util/convert.h"

using namespace ::Common;
using namespace ::Point;
using namespace ::Polygon;
using namespace ::PolygonF;
using namespace ::Region;
using namespace ::Enums;

#define THIS (AS_QTRANSFORM_PTR(_this))

namespace Transform
{
    double Handle_m11(HandleRef _this) {
        return THIS->m11();
    }

    double Handle_m12(HandleRef _this) {
        return THIS->m12();
    }

    double Handle_m13(HandleRef _this) {
        return THIS->m13();
    }

    double Handle_m21(HandleRef _this) {
        return THIS->m21();
    }

    double Handle_m22(HandleRef _this) {
        return THIS->m22();
    }

    double Handle_m23(HandleRef _this) {
        return THIS->m23();
    }

    double Handle_m31(HandleRef _this) {
        return THIS->m31();
    }

    double Handle_m32(HandleRef _this) {
        return THIS->m32();
    }

    double Handle_m33(HandleRef _this) {
        return THIS->m33();
    }

    OwnedRef Handle_adjoint(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->adjoint());
    }

    double Handle_determinant(HandleRef _this) {
        return THIS->determinant();
    }

    double Handle_dx(HandleRef _this) {
        return THIS->dx();
    }

    double Handle_dy(HandleRef _this) {
        return THIS->dy();
    }

    std::optional<OwnedRef> Handle_inverted(HandleRef _this) {
        std::optional<OwnedRef> result;
        bool invertible = false;
        const auto qTransform = THIS->inverted(&invertible);
        if (invertible) {
            result = TRANSFORM_HEAP_NEW(qTransform);
        }
        return result;
    }

    bool Handle_isAffine(HandleRef _this) {
        return THIS->isAffine();
    }

    bool Handle_isIdentity(HandleRef _this) {
        return THIS->isIdentity();
    }

    bool Handle_isInvertible(HandleRef _this) {
        return THIS->isInvertible();
    }

    bool Handle_isRotating(HandleRef _this) {
        return THIS->isRotating();
    }

    bool Handle_isScaling(HandleRef _this) {
        return THIS->isScaling();
    }

    bool Handle_isTranslating(HandleRef _this) {
        return THIS->isTranslating();
    }

    std::tuple<double,double> Handle_map(HandleRef _this, double x, double y) {
        double tx, ty;
        THIS->map(x, y, &tx, &ty);
        return { tx, ty };
    }

    PainterPath_OwnedRef Handle_map(HandleRef _this, PainterPath_HandleRef path) {
        const auto result = PAINTERPATH_HEAP_NEW(THIS->map(QPAINTERPATH_VALUE(path)));
        return reinterpret_cast<PainterPath_OwnedRef>(result);
    }

    Point::OwnedRef Handle_map(HandleRef _this, Point::HandleRef point) {
        return POINT_HEAP_NEW(THIS->map(QPOINT_VALUE(point)));
    }

    PointF Handle_map(HandleRef _this, PointF p) {
        return toPointF(THIS->map(toQPointF(p)));
    }

    Polygon::OwnedRef Handle_map(HandleRef _this, Polygon::HandleRef polygon) {
        return POLYGON_HEAP_NEW(THIS->map(QPOLYGON_VALUE(polygon)));
    }

    PolygonF::OwnedRef Handle_map(HandleRef _this, PolygonF::HandleRef polygon) {
        return POLYGONF_HEAP_NEW(THIS->map(QPOLYGONF_VALUE(polygon)));
    }

    Region::OwnedRef Handle_map(HandleRef _this, Region::HandleRef region) {
        return REGION_HEAP_NEW(THIS->map(QREGION_VALUE(region)));
    }

    std::tuple<int32_t,int32_t> Handle_map(HandleRef _this, int32_t x, int32_t y) {
        int tx, ty;
        THIS->map(x, y, &tx, &ty);
        return { tx, ty };
    }

    RectF Handle_mapRect(HandleRef _this, RectF rectangle) {
        return toRectF(THIS->mapRect(toQRectF(rectangle)));
    }

    Rect Handle_mapRect(HandleRef _this, Rect rectangle) {
        return toRect(THIS->mapRect(toQRect(rectangle)));
    }

    Polygon::OwnedRef Handle_mapToPolygon(HandleRef _this, Rect rectangle) {
        return POLYGON_HEAP_NEW(THIS->mapToPolygon(toQRect(rectangle)));
    }

    void Handle_reset(HandleRef _this) {
        THIS->reset();
    }

    OwnedRef Handle_rotate(HandleRef _this, double a, Axis axis, double distanceToPlane) {
        return TRANSFORM_HEAP_NEW(THIS->rotate(a, static_cast<Qt::Axis>(axis), distanceToPlane));
    }

    OwnedRef Handle_rotate(HandleRef _this, double a, Axis axis /* Axis::ZAxis */) {
        return TRANSFORM_HEAP_NEW(THIS->rotate(a, static_cast<Qt::Axis>(axis)));
    }

    OwnedRef Handle_rotateRadians(HandleRef _this, double a, Axis axis, double distanceToPlane) {
        return TRANSFORM_HEAP_NEW(THIS->rotateRadians(a, static_cast<Qt::Axis>(axis), distanceToPlane));
    }

    OwnedRef Handle_rotateRadians(HandleRef _this, double a, Axis axis /* Axis::ZAxis */) {
        return TRANSFORM_HEAP_NEW(THIS->rotateRadians(a, static_cast<Qt::Axis>(axis)));
    }

    OwnedRef Handle_scale(HandleRef _this, double sx, double sy) {
        return TRANSFORM_HEAP_NEW(THIS->scale(sx, sy));
    }

    void Handle_setMatrix(HandleRef _this, double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33) {
        THIS->setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);
    }

    OwnedRef Handle_shear(HandleRef _this, double sh, double sv) {
        return TRANSFORM_HEAP_NEW(THIS->shear(sh, sv));
    }

    OwnedRef Handle_translate(HandleRef _this, double dx, double dy) {
        return TRANSFORM_HEAP_NEW(THIS->translate(dx, dy));
    }

    OwnedRef Handle_transposed(HandleRef _this) {
        return TRANSFORM_HEAP_NEW(THIS->transposed());
    }

    TransformationType Handle_type(HandleRef _this) {
        return static_cast<TransformationType>(THIS->type());
    }

    // operator overloads ================================================

    bool Handle_operator_equal(HandleRef _this, HandleRef other) {
        return QTRANSFORM_VALUE(_this) == QTRANSFORM_VALUE(other);
    }

    int32_t Handle_hashCode(HandleRef _this) {
        return static_cast<int32_t>(qHash(QTRANSFORM_VALUE(_this)));
    }

    OwnedRef Handle_operator_mul(HandleRef _this, HandleRef matrix) {
        return TRANSFORM_HEAP_NEW(QTRANSFORM_VALUE(_this) * QTRANSFORM_VALUE(matrix));
    }

    OwnedRef Handle_operator_mul(HandleRef _this, double scalar) {
        return TRANSFORM_HEAP_NEW(QTRANSFORM_VALUE(_this) * scalar);
    }

    OwnedRef Handle_operator_plus(HandleRef _this, double scalar) {
        return TRANSFORM_HEAP_NEW(QTRANSFORM_VALUE(_this) + scalar);
    }

    OwnedRef Handle_operator_minus(HandleRef _this, double scalar) {
        return TRANSFORM_HEAP_NEW(QTRANSFORM_VALUE(_this) - scalar);
    }

    OwnedRef Handle_operator_div(HandleRef _this, double scalar) {
        return TRANSFORM_HEAP_NEW(QTRANSFORM_VALUE(_this) / scalar);
    }

    // disposal ===========================================================

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    // ctors and static methods ===========================================

    OwnedRef create() {
        return TRANSFORM_HEAP_NEW();
    }

    OwnedRef create(double m11, double m12, double m21, double m22, double dx, double dy) {
        return TRANSFORM_HEAP_NEW(m11, m12, m21, m22, dx, dy);
    }

    OwnedRef create(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33) {
        return TRANSFORM_HEAP_NEW(m11, m12, m13, m21, m22, m23, m31, m32, m33);
    }

    OwnedRef fromScale(double sx, double sy) {
        return TRANSFORM_HEAP_NEW(QTransform::fromScale(sx, sy));
    }

    OwnedRef fromTranslate(double dx, double dy) {
        return TRANSFORM_HEAP_NEW(QTransform::fromTranslate(dx, dy));
    }

    std::optional<OwnedRef> quadToQuad(PolygonF::HandleRef one, PolygonF::HandleRef two) {
        std::optional<OwnedRef> ret;
        if (QTransform result; QTransform::quadToQuad(QPOLYGONF_VALUE(one), QPOLYGONF_VALUE(two), result)) {
            ret = TRANSFORM_HEAP_NEW(result);
        }
        return ret;
    }

    std::optional<OwnedRef> quadToSquare(PolygonF::HandleRef quad) {
        std::optional<OwnedRef> ret;
        if (QTransform result; QTransform::quadToSquare(QPOLYGONF_VALUE(quad), result)) {
            ret = TRANSFORM_HEAP_NEW(result);
        }
        return ret;
    }

    std::optional<OwnedRef> squareToQuad(PolygonF::HandleRef quad) {
        std::optional<OwnedRef> ret;
        if (QTransform result; QTransform::squareToQuad(QPOLYGONF_VALUE(quad), result)) {
            ret = TRANSFORM_HEAP_NEW(result);
        }
        return ret;
    }
}
