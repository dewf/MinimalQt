module Pen;

import Enums;
import Brush;
import Color;

@nodispose
opaque Handle {
    Brush.Owned brush();
    PenCapStyle capStyle();
    Color.Owned color();
    double dashOffset();
    Array<double> dashPattern();
    bool isCosmetic();
    bool isSolid();
    PenJoinStyle joinStyle();
    double miterLimit();
    void setBrush(Brush.Handle brush);
    void setCapStyle(PenCapStyle style);
    void setColor(Color.Handle color);
    void setCosmetic(bool cosmetic);
    void setDashOffset(double offset);
    void setDashPattern(Array<double> pattern);
    void setJoinStyle(PenJoinStyle style);
    void setMiterLimit(double limit);
    void setStyle(PenStyle style);
    void setWidth(int width);
    void setWidthF(double width);
    PenStyle style();
    int width();
    double widthF();
}

opaque Owned extends Handle;

Owned create();
Owned create(PenStyle style);
Owned create(Color.Handle color);
Owned create(Brush.Handle brush, double width, PenStyle style = SolidLine, PenCapStyle cap = SquareCap, PenJoinStyle join = BevelJoin);
Owned create(Handle other);
