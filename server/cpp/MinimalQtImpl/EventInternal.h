#pragma once

#include "generated/Event.h"
#include <QEvent>
#include <QHelpEvent>
#include <QDragMoveEvent>

#define AS_QEVENT_PTR(x) (reinterpret_cast<QEvent*>(x))
// #define QEVENT_VALUE(x) (*AS_QEVENT_PTR(x))
// #define EVENT_HEAP_NEW(...) (reinterpret_cast<Event::OwnedRef>(new QEvent(__VA_ARGS__)))

#define AS_QHELPEVENT_PTR(x) (reinterpret_cast<QHelpEvent*>(x))

#define AS_QDRAGMOVEEVENT_PTR(x) (reinterpret_cast<QDragMoveEvent*>(_this))

namespace Event {
}
