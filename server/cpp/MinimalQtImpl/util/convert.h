#pragma once

#include <QRect>
#include <QPoint>
#include <QList>

#include "../generated/Common.h"
using namespace Common;

#include "../generated/Enums.h"
using namespace Enums;

#define STRUCT_CAST(b,a) *((b*)&a)

inline QByteArray toQByteArray(const std::vector<uint8_t>& input) {
    const QByteArray qState(reinterpret_cast<const char *>(input.data()), static_cast<qsizetype>(input.size()));
    return qState;
}

inline std::vector<uint8_t> fromQByteArray(const QByteArray& bytes) {
    const auto data = bytes.data();
    return std::vector<uint8_t>(data, data + bytes.length());
}

template <typename T, typename U>
std::vector<U> fromQSpan(QSpan<T> input, const std::function<U(T)>& mapFunc) {
    std::vector<U> ret;
    for (auto i = input.begin(); i != input.end(); ++i) {
        ret.push_back(mapFunc(*i));
    }
    return ret;
}

template <typename T, typename U>
std::vector<U> vectorMap(const std::vector<T>& input, const std::function<U(T)>& mapFunc) {
    std::vector<U> result;
    for (auto &elem : input) {
        result.push_back(mapFunc(elem));
    }
    return result;
}

template <typename T, typename U>
std::optional<U> optionalMap(const std::optional<T>& input, const std::function<U(T)>& mapFunc) {
    if (input.has_value()) {
        return mapFunc(input.value());
    }
    return std::optional<U>();
}

template <typename T, typename U>
U optionOrDefaultStaticCast(const std::optional<T>& input, U defaultValue) {
    auto ret = defaultValue;
    if (input.has_value()) ret = static_cast<U>(input.value());
    return ret;
}

template <typename T>
T idFunc(T input) {
    return input;
}

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
}

inline QStringList toQStringList(const std::vector<std::string>& strings) {
    return toQList<std::string,QString>(strings, [](const std::string& str) { return QString::fromStdString(str); });
}

inline QMargins toQMargins(const Margins& margins) {
    return QMargins(margins.left, margins.top, margins.right, margins.bottom);
}

inline QMarginsF toQMarginsF(const MarginsF& margins) {
    return QMarginsF(margins.left, margins.top, margins.right, margins.bottom);
}

inline Margins toMargins(const QMargins& qm) {
    return Margins { qm.left(), qm.top(), qm.right(), qm.bottom() };
}

inline RectF toRectF(const QRectF& qRectF) {
    return { qRectF.left(), qRectF.top(), qRectF.width(), qRectF.height() };
}

inline QRectF toQRectF(const RectF& r) {
    return { r.x, r.y, r.width, r.height };
}
