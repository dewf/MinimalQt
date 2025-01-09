#pragma once

#include "generated/Object.h"

#include <QObject>

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
