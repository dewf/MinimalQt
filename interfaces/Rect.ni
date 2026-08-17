module Rect;

import Point;
import Size;
import Margins;

@nodispose
opaque Handle {

    int hashCode();

    void adjust(int dx1, int dy1, int dx2, int dy2);
    Owned adjusted(int dx1, int dy1, int dx2, int dy2);
    int bottom();
    Point.Owned bottomLeft();
    Point.Owned bottomRight();
    Point.Owned center();
    bool contains(Point.Handle point, bool proper = false);
    bool contains(Handle rectangle, bool proper = false);
    bool contains(int x, int y);
    bool contains(int x, int y, bool proper);
    Tuple<int,int,int,int> getCoords();
    Tuple<int,int,int,int> getRect();
    int height();
    Owned intersected(Handle rectangle);
    bool intersects(Handle rectangle);
    bool isEmpty();
    bool isNull();
    bool isValid();
    int left();
    Owned marginsAdded(Margins.Handle margins);
    Owned marginsRemoved(Margins.Handle margins);
    void moveBottom(int y);
    void moveBottomLeft(Point.Handle position);
    void moveBottomRight(Point.Handle position);
    void moveCenter(Point.Handle position);
    void moveLeft(int x);
    void moveRight(int x);
    void moveTo(Point.Handle position);
    void moveTo(int x, int y);
    void moveTop(int y);
    void moveTopLeft(Point.Handle position);
    void moveTopRight(Point.Handle position);
    Owned normalized();
    int right();
    void setBottom(int y);
    void setBottomLeft(Point.Handle position);
    void setBottomRight(Point.Handle position);
    void setCoords(int x1, int y1, int x2, int y2);
    void setHeight(int height);
    void setLeft(int x);
    void setRect(int x, int y, int width, int height);
    void setRight(int x);
    void setSize(Size.Handle size);
    void setTop(int y);
    void setTopLeft(Point.Handle position);
    void setTopRight(Point.Handle position);
    void setWidth(int width);
    void setX(int x);
    void setY(int y);
    Size.Owned size();

    // CGRect toCGRect() const

    // moved to RectF.ni as extension method
    // RectF_Owned toRectF();

    int top();
    Point.Owned topLeft();
    Point.Owned topRight();
    void translate(int dx, int dy);
    void translate(Point.Handle offset);
    Owned translated(int dx, int dy);
    Owned translated(Point.Handle offset);
    Owned transposed();
    Owned united(Handle rectangle);
    int width();
    int x();
    int y();

    // QRect operator&(const QRect &rectangle) const
    // use 'intersected'

    Handle operator_intersectWith(Handle rectangle); // returns 'this'
    Handle operator_incrementBy(Margins.Handle margins); // returns 'this'
    Handle operator_decrementBy(Margins.Handle margins); // returns 'this'

    // QRect operator|(const QRect &rectangle) const
    // use 'united'

    Handle operator_uniteWith(Handle rectangle); // returns 'this'
}
opaque Owned extends Handle;

Owned create();
Owned create(Point.Handle topLeft, Point.Handle bottomRight);
Owned create(Point.Handle topLeft, Size.Handle size);
Owned create(int x, int y, int width, int height);

// static methods =========================

Owned span(Point.Handle p1, Point.Handle p2);

// operators ==============================

bool operator_notEqual(Handle lhs, Handle rhs);

// QRect operator+(const QMargins &margins, const QRect &rectangle)

Owned operator_add(Handle rectangle, Margins.Handle margins);
Owned operator_sub(Handle lhs, Margins.Handle rhs);

// QDataStream & operator<<(QDataStream &stream, const QRect &rectangle)

bool operator_equal(Handle lhs, Handle rhs);

// QDataStream & operator>>(QDataStream &stream, QRect &rectangle)
