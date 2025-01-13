#pragma once

#include "generated/Object.h"

#include <QObject>

#define AS_QOBJECT_PTR(x) (reinterpret_cast<QObject*>(x))

namespace Object {
    struct __SignalConnection {
        QMetaObject::Connection qConnection;
    };

    inline QObject *fromOptionalHandle(const std::optional<HandleRef>& handle) {
        QObject *qParent = nullptr;
        if (handle.has_value()) {
            qParent = reinterpret_cast<QObject*>(handle.value());
        }
        return qParent;
    }
}
