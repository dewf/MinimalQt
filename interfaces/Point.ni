module Point;

@nodispose
opaque Handle {
    int hashCode();

    bool isNull();
    int manhattanLength();

    // int & rx()
    // int & ry()

    void setX(int x);
    void setY(int y);

    // CGPoint toCGPoint() const

    // moved to PointF.ni as extension method
    // PointF_Owned toPointF();

    Owned transposed();
    int x();
    int y();

    // the following return 'this':

    Handle operator_multiplyBy(double factor);
    Handle operator_multiplyBy(float factor);
    Handle operator_multiplyBy(int factor);
    Handle operator_incrementBy(Handle point);
    Handle operator_decrementBy(Handle point);
    Handle operator_divideBy(double divisor);
}
opaque Owned extends Handle;

Owned create();
Owned create(int xpos, int ypos);

// static methods ======================

int dotProduct(Handle p1, Handle p2);

// operators ===========================

bool operator_notEqual(Handle lhs, Handle rhs);
Owned operator_mul(Handle point, double factor);
Owned operator_mul(Handle point, float factor);
Owned operator_mul(Handle point, int factor);

// QPoint operator*(double factor, const QPoint &point)
// QPoint operator*(float factor, const QPoint &point)
// QPoint operator*(int factor, const QPoint &point)

// QPoint operator+(const QPoint &point)

Owned operator_add(Handle p1, Handle p2);
Owned operator_sub(Handle p1, Handle p2);
Owned operator_negate(Handle point);
Owned operator_div(Handle point, double divisor);

// QDataStream & operator<<(QDataStream &stream, const QPoint &point)

bool operator_equal(Handle lhs, Handle rhs);

// QDataStream & operator>>(QDataStream &stream, QPoint &point)
