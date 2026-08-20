#include "generated/Pen.h"
#include "PenInternal.h"

#include "BrushInternal.h"
#include "ColorInternal.h"

#include "util/convert.h"

using namespace ::Enums;
using namespace ::Brush;
using namespace ::Color;

#define THIS (AS_QPEN_PTR(_this))

namespace Pen
{
    Brush::OwnedRef Handle_brush(HandleRef _this) {
        return BRUSH_HEAP_NEW(THIS->brush());
    }

    PenCapStyle Handle_capStyle(HandleRef _this) {
        return static_cast<PenCapStyle>(THIS->capStyle());
    }

    Color::OwnedRef Handle_color(HandleRef _this) {
        return COLOR_HEAP_NEW(THIS->color());
    }

    double Handle_dashOffset(HandleRef _this) {
        return THIS->dashOffset();
    }

    std::vector<double> Handle_dashPattern(HandleRef _this) {
        return fromQList<qreal,double>(THIS->dashPattern(), idFunc<double>);
    }

    bool Handle_isCosmetic(HandleRef _this) {
        return THIS->isCosmetic();
    }

    bool Handle_isSolid(HandleRef _this) {
        return THIS->isSolid();
    }

    PenJoinStyle Handle_joinStyle(HandleRef _this) {
        return PenJoinStyle::MiterJoin;
    }

    double Handle_miterLimit(HandleRef _this) {
        return THIS->miterLimit();
    }

    void Handle_setBrush(HandleRef _this, Brush::HandleRef brush) {
        THIS->setBrush(QBRUSH_VALUE(brush));
    }

    void Handle_setCapStyle(HandleRef _this, PenCapStyle style) {
        THIS->setCapStyle(static_cast<Qt::PenCapStyle>(style));
    }

    void Handle_setColor(HandleRef _this, Color::HandleRef color) {
        THIS->setColor(QCOLOR_VALUE(color));
    }

    void Handle_setCosmetic(HandleRef _this, bool cosmetic) {
        THIS->setCosmetic(cosmetic);
    }

    void Handle_setDashOffset(HandleRef _this, double offset) {
        THIS->setDashOffset(offset);
    }

    void Handle_setDashPattern(HandleRef _this, const std::vector<double>& pattern) {
        const auto qPattern = toQList<double,qreal>(pattern, idFunc<double>);
        THIS->setDashPattern(qPattern);
    }

    void Handle_setJoinStyle(HandleRef _this, PenJoinStyle style) {
        THIS->setJoinStyle(static_cast<Qt::PenJoinStyle>(style));
    }

    void Handle_setMiterLimit(HandleRef _this, double limit) {
        THIS->setMiterLimit(limit);
    }

    void Handle_setStyle(HandleRef _this, PenStyle style) {
        THIS->setStyle(static_cast<Qt::PenStyle>(style));
    }

    void Handle_setWidth(HandleRef _this, int32_t width) {
        THIS->setWidth(width);
    }

    void Handle_setWidthF(HandleRef _this, double width) {
        THIS->setWidthF(width);
    }

    PenStyle Handle_style(HandleRef _this) {
        return static_cast<PenStyle>(THIS->style());
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    double Handle_widthF(HandleRef _this) {
        return THIS->widthF();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return PEN_HEAP_NEW();
    }

    OwnedRef create(PenStyle style) {
        return PEN_HEAP_NEW(static_cast<Qt::PenStyle>(style));
    }

    OwnedRef create(Color::HandleRef color) {
        return PEN_HEAP_NEW(QCOLOR_VALUE(color));
    }

    OwnedRef create(Brush::HandleRef brush, double width, PenStyle style /* PenStyle::SolidLine */, PenCapStyle cap /* PenCapStyle::SquareCap */, PenJoinStyle join /* PenJoinStyle::BevelJoin */) {
        return PEN_HEAP_NEW(QBRUSH_VALUE(brush), width, static_cast<Qt::PenStyle>(style), static_cast<Qt::PenCapStyle>(cap), static_cast<Qt::PenJoinStyle>(join));
    }

    OwnedRef create(HandleRef other) {
        return PEN_HEAP_NEW(QPEN_VALUE(other));
    }
}
