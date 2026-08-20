#pragma once

#include "generated/Action.h"
#include <QAction>

#define AS_QACTION_PTR(x) (reinterpret_cast<QAction*>(x))

namespace Action {
    inline QAction *fromOptionalHandle(const std::optional<HandleRef>& handle) {
        QAction *action = nullptr;
        if (handle.has_value()) {
            action = AS_QACTION_PTR(handle.value());
        }
        return action;
    }
}
