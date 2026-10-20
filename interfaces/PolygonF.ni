module PolygonF;

import Polygon;
import PointF;
import RectF;
import Enums;

@nodispose
opaque Handle {
    RectF.Owned boundingRect();
    bool containsPoint(PointF.Handle point, FillRule fillRule);
    Owned intersected(Handle r);
    bool intersects(Handle p);
    bool isClosed();
    Owned subtracted(Handle r);
    Polygon.Owned toPolygon();
    void translate(PointF.Handle offset);
    void translate(double dx, double dy);
    Owned translated(PointF.Handle offset);
    Owned translated(double dx, double dy);
    Owned united(Handle r);
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(Array<PointF.Handle> points);
Owned create(Polygon.Handle polygon);
Owned create(RectF.Handle rectangle);

// to break circular dependency:
Owned ext_Polygon_toPolygonF(Polygon.Handle this_);
