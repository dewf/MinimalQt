module MarginsF;

import Margins;

@nodispose
opaque Handle {

    double bottom();
    bool isNull();
    double left();
    double right();
    void setBottom(double abottom);
    void setLeft(double aleft);
    void setRight(double aright);
    void setTop(double atop);
    Margins.Owned toMargins();
    double top();

    Handle operator_mul(double factor);
    Handle operator_add(Handle margins);
    Handle operator_add(double addend);
    Handle operator_sub(Handle margins);
    Handle operator_sub(double subtrahend);
    Handle operator_div(double divisor);
}
opaque Owned extends Handle;

Owned create();
Owned create(Margins.Handle margins);
Owned create(double left, double top, double right, double bottom);

// static methods =======================

bool fuzzyCompare(Handle lhs, Handle rhs);
bool fuzzyIsNull(Handle margins);

// operators ============================

bool operator_notEqual(Handle lhs, Handle rhs);
Owned operator_mul(Handle lhs, double rhs);

// QMarginsF operator*(qreal lhs, const QMarginsF &rhs)
// see above

// QMarginsF operator+(const QMarginsF &margins)
// no-op

Owned operator_add(Handle lhs, Handle rhs);
Owned operator_add(Handle lhs, double rhs);

// QMarginsF operator+(qreal lhs, const QMarginsF &rhs)
// see above

Owned operator_negate(Handle margins);
Owned operator_sub(Handle lhs, Handle rhs);
Owned operator_sub(Handle lhs, double rhs);
Owned operator_div(Handle lhs, double rhs);

// QDataStream & operator<<(QDataStream &stream, const QMarginsF &m)

bool operator_equal(Handle lhs, Handle rhs);

// QDataStream & operator>>(QDataStream &stream, QMarginsF &m)

Owned operator_or(Handle m1, Handle m2);
