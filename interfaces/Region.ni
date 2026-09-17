module Region;

import Point;
import Rect;
import Polygon;
import Enums;

enum RegionType { Rectangle, Ellipse }

@nodispose
opaque Handle {
    Rect.Owned boundingRect();
    bool contains(Point.Handle p);
    bool contains(Rect.Handle r);
    Owned intersected(Rect.Handle rect);
    Owned intersected(Handle r);
    bool intersects(Rect.Handle rect);
    bool intersects(Handle region);
    bool isEmpty();
    bool isNull();
    int rectCount();
    Array<Rect.Owned> rects(); // TODO: Rect.OwnedList?
    void setRects(Array<Rect.Handle> rects);
    Owned subtracted(Handle r);
    void swap(Handle other);

    // (since 6.0) HRGN toHRGN() const

    void translate(int dx, int dy);
    void translate(Point.Handle point);
    Owned translated(int dx, int dy);
    Owned translated(Point.Handle p);
    Owned united(Rect.Handle rect);
    Owned united(Handle r);
    Owned xored(Handle r);
}
opaque Owned extends Handle;

Owned create();

// might be difficult to enable this because this triggers some grisly circular dependencies
// (and not sure if an extension method on Bitmap could be used via `new` in Dlang)
// QRegion(const QBitmap &bm)

Owned create(Polygon.Handle a, FillRule fillRule = OddEvenFill);
Owned create(int x, int y, int w, int h, RegionType t = Rectangle);
Owned create(Rect.Handle r, RegionType t = Rectangle);
Owned create(Handle other);
