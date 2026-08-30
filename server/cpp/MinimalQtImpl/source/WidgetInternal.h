#pragma once

#include "generated/Widget.h"
#include <QWidget>

#define AS_QWIDGET_PTR(x) (reinterpret_cast<QWidget*>(x))

namespace Widget {
    // inline QWidget *fromOptionalHandle(const std::optional<HandleRef>& handle) {
    //     QWidget *qParent = nullptr;
    //     if (handle.has_value()) {
    //         qParent = reinterpret_cast<QWidget*>(handle.value());
    //     }
    //     return qParent;
    // }
}
