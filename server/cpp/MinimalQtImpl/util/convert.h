#pragma once

#include <QRect>
#include <QKeySequence>
#include <QStringList>

#include "../generated/Common.h"
using namespace Common;
#include "../generated/Enums.h"
using namespace Enums;

#define STRUCT_CAST(b,a) *((b*)&a)

template <typename T, typename U>
std::vector<U> fromQList(const QList<T>& source, const std::function<U(T)>& func) {
    std::vector<U> result;
    for (auto &elem : source) {
        result.push_back(func(elem));
    }
    return result;
}

template <typename T, typename U>
QList<U> toQList(const std::vector<T>& source, const std::function<U(T)>& func) {
    QList<U> result;
    for (auto &elem : source) {
        result.append(func(elem));
    }
    return result;
}

inline std::vector<std::string> toVectorStrings(const QStringList& qStrings) {
    return fromQList<QString,std::string>(qStrings, [](const QString& qStr) { return qStr.toStdString(); });
    // std::vector<std::string> ret;
    // for (auto & qStr : qStrings) {
    //     ret.push_back(qStr.toStdString());
    // }
    // return ret;
}

inline QStringList toQStringList(const std::vector<std::string>& strings) {
    return toQList<std::string,QString>(strings, [](const std::string& str) { return QString::fromStdString(str); });
    // QStringList ret;
    // for (auto & str : strings) {
    //     ret.append(QString::fromStdString(str));
    // }
    // return ret;
}

inline QSize toQSize(const Size& sz) {
    return {sz.width, sz.height };
}

inline Size toSize(const QSize& sz) {
    return { sz.width(), sz.height() };
}

inline Point toPoint(const QPoint& qPoint) {
    return { qPoint.x(), qPoint.y() };
}

inline PointF toPointF(const QPointF& qPointF) {
    return { qPointF.x(), qPointF.y() };
}

inline QPoint toQPoint(const Point& p) {
    return QPoint(p.x, p.y);
}

inline QPointF toQPointF(const PointF& p) {
    return QPointF(p.x, p.y);
}

inline Rect toRect(const QRect& qRect) {
    return { qRect.left(), qRect.top(), qRect.width(), qRect.height() };
}

inline QRect toQRect(const Rect& r) {
    return {r.x, r.y, r.width, r.height};
}

inline QRectF toQRectF(const RectF& r) {
    return { r.x, r.y, r.width, r.height };
}
