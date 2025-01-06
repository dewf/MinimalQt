#pragma once

#include <QRect>
#include <QPoint>
#include <QList>

#include "../generated/Common.h"
using namespace Common;

#include "../generated/Enums.h"
using namespace Enums;

#define STRUCT_CAST(b,a) *((b*)&a)

template <typename T, typename U>
std::optional<U> optionalMap(const std::optional<T>& input, auto mapFunc) {
    if (input.has_value()) {
        return mapFunc(input.value());
    }
    return std::optional<U>();
}

template <typename T, typename U>
std::vector<U> fromQList(const QList<T>& source, auto func) { // const std::function<U(T)>&
    std::vector<U> result;
    for (auto &elem : source) {
        result.push_back(func(elem));
    }
    return result;
}

template <typename T, typename U>
QList<U> toQList(const std::vector<T>& source, auto func) { // const std::function<U(T)>&
    QList<U> result;
    for (auto &elem : source) {
        result.append(func(elem));
    }
    return result;
}

inline std::vector<std::string> toVectorStrings(const QStringList& qStrings) {
    return fromQList<QString,std::string>(qStrings, [](const QString& qStr) { return qStr.toStdString(); });
}

inline QStringList toQStringList(const std::vector<std::string>& strings) {
    return toQList<std::string,QString>(strings, [](const std::string& str) { return QString::fromStdString(str); });
}

inline QSize toQSize(const Size& sz) {
    return {sz.width, sz.height };
}

inline Size toSize(const QSize& sz) {
    return { sz.width(), sz.height() };
}

inline SizeF toSizeF(const QSizeF& sz) {
    return { sz.width(), sz.height() };
}

inline Point toPoint(const QPoint& qPoint) {
    return { qPoint.x(), qPoint.y() };
}

inline PointF toPointF(const QPointF& qPointF) {
    return { qPointF.x(), qPointF.y() };
}

inline QPoint toQPoint(const Point& p) {
    return {p.x, p.y};
}

inline QPointF toQPointF(const PointF& p) {
    return {p.x, p.y};
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
