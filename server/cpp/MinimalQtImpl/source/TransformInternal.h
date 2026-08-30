#pragma once

#include "generated/Transform.h"
#include <QTransform>

#define AS_QTRANSFORM_PTR(x) (reinterpret_cast<QTransform*>(x))
#define QTRANSFORM_VALUE(x) (x != nullptr ? *AS_QTRANSFORM_PTR(x) : QTransform())
#define TRANSFORM_HEAP_NEW(...) (reinterpret_cast<Transform::OwnedRef>(new QTransform(__VA_ARGS__)))

namespace Transform {
    inline QTransform fromNullable(HandleRef value) {
        QTransform ret;
        if (value != nullptr) ret = QTRANSFORM_VALUE(value);
        return ret;
    }
    // inline QTransform fromOptional(const std::optional<Transform::HandleRef>& x) {
    //     QTransform ret;
    //     if (x.has_value()) ret = QTRANSFORM_VALUE(x.value());
    //     return ret;
    // }
}
