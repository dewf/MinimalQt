module Transform;

import Point;
import PointF;
import Rect;
import RectF;
import Polygon;
import PolygonF;
import Region;
import Enums;

enum TransformationType {
    TxNone      = 0x00,
    TxTranslate = 0x01,
    TxScale     = 0x02,
    TxRotate    = 0x04,
    TxShear     = 0x08,
    TxProject   = 0x10
}

struct InvertResult {
    Owned transform;
    bool invertible;
}

@nodispose
opaque Handle {

    int hashCode();

    double m11();
    double m12();
    double m13();
    double m21();
    double m22();
    double m23();
    double m31();
    double m32();
    double m33();
    Owned adjoint();
    double determinant();
    double dx();
    double dy();

    // QTransform QTransform::inverted(bool *invertible = nullptr) const
    // actual signature takes an 'out' parameter bool, but internally we'll always ask for that and return it as part of the result
    // then the idiomatic wrapper can make it match the C++ API
    // (since we still don't support out/ref parameters in NativeImpl)
    InvertResult inverted();

    bool isAffine();
    bool isIdentity();
    bool isInvertible();
    bool isRotating();
    bool isScaling();
    bool isTranslating();
    Tuple<double,double> map(double x, double y);

    // QLine map(const QLine &l) const
    // QLineF map(const QLineF &line) const

    // moved to extension method in PainterPath.ni
    // PainterPath_Owned map(PainterPath_Handle path);

    Point.Owned map(Point.Handle point);
    PointF.Owned map(PointF.Handle p);
    Polygon.Owned map(Polygon.Handle polygon);
    PolygonF.Owned map(PolygonF.Handle polygon);
    Region.Owned map(Region.Handle region);
    Tuple<int,int> map(int x, int y);
    RectF.Owned mapRect(RectF.Handle rectangle);
    Rect.Owned mapRect(Rect.Handle rectangle);
    Polygon.Owned mapToPolygon(Rect.Handle rectangle);
    void reset();
    Owned rotate(double a, Axis axis, double distanceToPlane);
    Owned rotate(double a, Axis axis = ZAxis);
    Owned rotateRadians(double a, Axis axis, double distanceToPlane);
    Owned rotateRadians(double a, Axis axis = ZAxis);
    Owned scale(double sx, double sy);
    void setMatrix(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);
    Owned shear(double sh, double sv);
    Owned translate(double dx, double dy);
    Owned transposed();
    TransformationType type();

    // operators ====================================

    // QVariant operator QVariant() const
    // we'll just use a convenience (fake) constructor on Variant

    bool operator_notEqual(Handle matrix);
    Owned operator_mul(Handle matrix);

    Handle operator_multiplyBy(Handle matrix); // returns 'this'
    Handle operator_multiplyBy(double scalar); // returns 'this'
    Handle operator_incrementBy(double scalar); // returns 'this'
    Handle operator_decrementBy(double scalar); // returns 'this'
    Handle operator_divideBy(double scalar); // returns 'this'
    Handle operator_assign(Handle matrix); // returns 'this'
    bool operator_equal(Handle matrix);
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(double m11, double m12, double m21, double m22, double dx, double dy);
Owned create(double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33);

// static methods ===============

Owned fromScale(double sx, double sy);
Owned fromTranslate(double dx, double dy);
bool quadToQuad(PolygonF.Handle one, PolygonF.Handle two, Transform.Handle trans);
bool quadToSquare(PolygonF.Handle quad, Transform.Handle trans);
bool squareToQuad(PolygonF.Handle quad, Transform.Handle trans);

bool fuzzyCompare(Handle t1, Handle t2);

// size_t qHash(const QTransform &key, size_t seed = 0)
// see hashCode() method

// operators ====================

// QLine operator*(const QLine &line, const QTransform &matrix)
// QLineF operator*(const QLineF &line, const QTransform &matrix)

// moved to PainterPath.ni
// PainterPath_Owned operator_mul(PainterPath_Handle path, Handle matrix);

Point.Owned operator_mul(Point.Handle point, Handle matrix);
PointF.Owned operator_mul(PointF.Handle point, Handle matrix);
Polygon.Owned operator_mul(Polygon.Handle polygon, Handle matrix);
PolygonF.Owned operator_mul(PolygonF.Handle polygon, Handle matrix);
Region.Owned operator_mul(Region.Handle region, Handle matrix);

// QDataStream & operator<<(QDataStream &stream, const QTransform &matrix)
// QDataStream & operator>>(QDataStream &stream, QTransform &matrix)
