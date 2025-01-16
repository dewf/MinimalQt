#pragma once

#include "generated/Event.h"
#include <QEvent>
#include <QHelpEvent>

#define AS_QEVENT_PTR(x) (reinterpret_cast<QEvent*>(x))
// #define QEVENT_VALUE(x) (*AS_QEVENT_PTR(x))
// #define EVENT_HEAP_NEW(...) (reinterpret_cast<Event::OwnedRef>(new QEvent(__VA_ARGS__)))

#define AS_QHELPEVENT_PTR(x) (reinterpret_cast<QHelpEvent*>(x))

namespace Event {
}
