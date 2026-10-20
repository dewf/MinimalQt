#pragma once

#include "generated/Event.h"
#include <QEvent>
#include <QHelpEvent>
#include <QDragMoveEvent>
#include <QKeyEvent>
#include <QInputEvent>

#define AS_QEVENT_PTR(x) (reinterpret_cast<QEvent*>(x))

#define AS_QRESIZEEVENT_PTR(x) (reinterpret_cast<QResizeEvent*>(x))

#define AS_QHELPEVENT_PTR(x) (reinterpret_cast<QHelpEvent*>(x))

#define AS_QDROPEVENT_PTR(x) (reinterpret_cast<QDropEvent*>(x))

#define AS_QINPUTEVENT_PTR(x) (reinterpret_cast<QInputEvent*>(x))

#define AS_QFOCUSEVENT_PTR(x) (reinterpret_cast<QFocusEvent*>(x))

#define AS_QSHOWEVENT_PTR(x) (reinterpret_cast<QShowEvent*>(x))

#define AS_QPAINTEVENT_PTR(x) (reinterpret_cast<QPaintEvent*>(x))

#define AS_QDRAGLEAVEEVENT_PTR(x) (reinterpret_cast<QDragLeaveEvent*>(x))

#define AS_QCONTEXTMENUEVENT_PTR(x) (reinterpret_cast<QContextMenuEvent*>(x))

#define AS_QDRAGMOVEEVENT_PTR(x) (reinterpret_cast<QDragMoveEvent*>(x))

#define AS_QKEYEVENT_PTR(x) (reinterpret_cast<QKeyEvent*>(x))

#define AS_QPOINTEREVENT_PTR(x) (reinterpret_cast<QPointerEvent*>(x))

#define AS_QDRAGENTEREVENT_PTR(x) (reinterpret_cast<QDragEnterEvent*>(x))

#define AS_QSINGLEPOINTEVENT_PTR(x) (reinterpret_cast<QSinglePointEvent*>(x))

#define AS_QENTEREVENT_PTR(x) (reinterpret_cast<QEnterEvent*>(x))

#define AS_QMOUSEEVENT_PTR(x) (reinterpret_cast<QMouseEvent*>(x))

#define AS_QWHEELEVENT_PTR(x) (reinterpret_cast<QWheelEvent*>(x))

namespace Event {
}
