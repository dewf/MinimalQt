#include "generated/Gradient.h"
#include "GradientInternal.h"

#include "ColorInternal.h"
#include "PointF2Internal.h"
#include "util/convert.h"

using namespace ::Color;
using namespace ::Common;
using namespace ::PointF2;

#define GRAD_THIS (AS_QGRADIENT_PTR(_this))

namespace Gradient
{
    CoordinateMode Handle_getCoordinateMode(HandleRef _this) {
        return static_cast<CoordinateMode>(GRAD_THIS->coordinateMode());
    }

    void Handle_setColorAt(HandleRef _this, double position, Color::HandleRef color) {
        GRAD_THIS->setColorAt(position, QCOLOR_VALUE(color));
    }

    void Handle_setCoordinateMode(HandleRef _this, CoordinateMode mode) {
        GRAD_THIS->setCoordinateMode(static_cast<QGradient::CoordinateMode>(mode));
    }

    void Handle_setSpread(HandleRef _this, Spread method) {
        GRAD_THIS->setSpread(static_cast<QGradient::Spread>(method));
    }

    void Handle_setStops(HandleRef _this, const std::vector<GradientStopInput>& stopPoints) {
        const auto qList = toQList<GradientStopInput,QPair<qreal,QColor>>(stopPoints, [](auto p) {
            return QPair<qreal,QColor>(p.pos, QCOLOR_VALUE(p.color));
        });
        GRAD_THIS->setStops(qList);
    }

    Spread Handle_getSpread(HandleRef _this) {
        return static_cast<Spread>(GRAD_THIS->spread());
    }

    std::vector<GradientStopOutput> Handle_stops(HandleRef _this) {
        return fromQList<QPair<qreal,QColor>,GradientStopOutput>(GRAD_THIS->stops(), [](auto stop) {
            GradientStopOutput ret;
            ret.pos = stop.first;
            ret.color = COLOR_HEAP_NEW(stop.second);
            return ret;
        });
    }

    Type Handle_getType2(HandleRef _this) {
        return static_cast<Type>(GRAD_THIS->type());
    }

    void Owned_dispose(OwnedRef _this) {
        delete GRAD_THIS;
    }

    OwnedRef create(Preset preset) {
        return GRADIENT_HEAP_NEW(static_cast<QGradient::Preset>(preset));
    }

    // conical ==================================================================
#define CONICAL_THIS (AS_QCONICALGRADIENT_PTR(_this))

    namespace Conical {
        double Handle_angle(HandleRef _this) {
            return CONICAL_THIS->angle();
        }

        PointF2::OwnedRef Handle_center(HandleRef _this) {
            return POINTF_HEAP_NEW(CONICAL_THIS->center());
        }

        void Handle_setAngle(HandleRef _this, double angle) {
            CONICAL_THIS->setAngle(angle);
        }

        void Handle_setCenter(HandleRef _this, PointF2::HandleRef center) {
            CONICAL_THIS->setCenter(QPOINTF_VALUE(center));
        }

        void Handle_setCenter(HandleRef _this, double x, double y) {
            CONICAL_THIS->setCenter(x, y);
        }

        void Owned_dispose(OwnedRef _this) {
            delete CONICAL_THIS;
        }

        OwnedRef create() {
            return CONICALGRADIENT_HEAP_NEW();
        }

        OwnedRef create(PointF2::HandleRef center, double angle) {
            return CONICALGRADIENT_HEAP_NEW(QPOINTF_VALUE(center), angle);
        }

        OwnedRef create(double cx, double cy, double angle) {
            return CONICALGRADIENT_HEAP_NEW(cx, cy, angle);
        }
    }

#define LINEAR_THIS (AS_QLINEARGRADIENT_PTR(_this))

    namespace Linear {
        PointF2::OwnedRef Handle_finalStop(HandleRef _this) {
            return POINTF_HEAP_NEW(LINEAR_THIS->finalStop());
        }

        void Handle_setFinalStop(HandleRef _this, PointF2::HandleRef stop) {
            LINEAR_THIS->setFinalStop(QPOINTF_VALUE(stop));
        }

        void Handle_setFinalStop(HandleRef _this, double x, double y) {
            LINEAR_THIS->setFinalStop(x, y);
        }

        void Handle_setStart(HandleRef _this, PointF2::HandleRef start) {
            LINEAR_THIS->setStart(QPOINTF_VALUE(start));
        }

        void Handle_setStart(HandleRef _this, double x, double y) {
            LINEAR_THIS->setStart(x, y);
        }

        PointF2::OwnedRef Handle_start(HandleRef _this) {
            return POINTF_HEAP_NEW(LINEAR_THIS->start());
        }

        void Owned_dispose(OwnedRef _this) {
            delete LINEAR_THIS;
        }

        OwnedRef create() {
            return LINEARGRADIENT_HEAP_NEW();
        }

        OwnedRef create(PointF2::HandleRef start, PointF2::HandleRef finalStop) {
            return LINEARGRADIENT_HEAP_NEW(QPOINTF_VALUE(start), QPOINTF_VALUE(finalStop));
        }

        OwnedRef create(double x1, double y1, double x2, double y2) {
            return LINEARGRADIENT_HEAP_NEW(x1, y1, x2, y2);
        }
    }

#define RADIAL_THIS (AS_QRADIALGRADIENT_PTR(_this))

    namespace Radial {
        PointF2::OwnedRef Handle_center(HandleRef _this) {
            return POINTF_HEAP_NEW(RADIAL_THIS->center());
        }

        double Handle_centerRadius(HandleRef _this) {
            return RADIAL_THIS->centerRadius();
        }

        PointF2::OwnedRef Handle_focalPoint(HandleRef _this) {
            return POINTF_HEAP_NEW(RADIAL_THIS->focalPoint());
        }

        double Handle_focalRadius(HandleRef _this) {
            return RADIAL_THIS->focalRadius();
        }

        double Handle_radius(HandleRef _this) {
            return RADIAL_THIS->radius();
        }

        void Handle_setCenter(HandleRef _this, PointF2::HandleRef center) {
            RADIAL_THIS->setCenter(QPOINTF_VALUE(center));
        }

        void Handle_setCenter(HandleRef _this, double x, double y) {
            RADIAL_THIS->setCenter(x, y);
        }

        void Handle_setCenterRadius(HandleRef _this, double radius) {
            RADIAL_THIS->setCenterRadius(radius);
        }

        void Handle_setFocalPoint(HandleRef _this, PointF2::HandleRef focalPoint) {
            RADIAL_THIS->setFocalPoint(QPOINTF_VALUE(focalPoint));
        }

        void Handle_setFocalPoint(HandleRef _this, double x, double y) {
            RADIAL_THIS->setFocalPoint(x, y);
        }

        void Handle_setFocalRadius(HandleRef _this, double radius) {
            RADIAL_THIS->setFocalRadius(radius);
        }

        void Handle_setRadius(HandleRef _this, double radius) {
            RADIAL_THIS->setRadius(radius);
        }

        void Owned_dispose(OwnedRef _this) {
            delete RADIAL_THIS;
        }

        OwnedRef create() {
            return RADIALGRADIENT_HEAP_NEW();
        }

        OwnedRef create(PointF2::HandleRef center, double radius) {
            return RADIALGRADIENT_HEAP_NEW(QPOINTF_VALUE(center), radius);
        }

        OwnedRef create(PointF2::HandleRef center, double radius, PointF2::HandleRef focalPoint) {
            return RADIALGRADIENT_HEAP_NEW(QPOINTF_VALUE(center), radius, QPOINTF_VALUE(focalPoint));
        }

        OwnedRef create(double cx, double cy, double radius) {
            return RADIALGRADIENT_HEAP_NEW(cx, cy, radius);
        }

        OwnedRef create(PointF2::HandleRef center, double centerRadius, PointF2::HandleRef focalPoint, double focalRadius) {
            return RADIALGRADIENT_HEAP_NEW(QPOINTF_VALUE(center), centerRadius, QPOINTF_VALUE(focalPoint), focalRadius);
        }

        OwnedRef create(double cx, double cy, double radius, double fx, double fy) {
            return RADIALGRADIENT_HEAP_NEW(cx, cy, radius, fx, fy);
        }

        OwnedRef create(double cx, double cy, double centerRadius, double fx, double fy, double focalRadius) {
            return RADIALGRADIENT_HEAP_NEW(cx, cy, centerRadius, fx, fy, focalRadius);
        }
    }
}
