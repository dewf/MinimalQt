#pragma once

#include "generated/StyleOption.h"
#include <QStyleOption>

// Base
#define AS_QSTYLEOPTION_PTR(x) (reinterpret_cast<QStyleOption*>(x))
#define QSTYLEOPTION_VALUE(x) (x != nullptr ? *AS_QSTYLEOPTION_PTR(x) : QStyleOption())
#define STYLEOPTION_HEAP_NEW(...) (reinterpret_cast<StyleOption::OwnedRef>(new QStyleOption(__VA_ARGS__)))

// ViewItem
#define AS_QSTYLEOPTIONVIEWITEM_PTR(x) (reinterpret_cast<QStyleOptionViewItem*>(x))
#define QSTYLEOPTIONVIEWITEM_VALUE(x) (x != nullptr ? *AS_QSTYLEOPTIONVIEWITEM_PTR(x) : QStyleOptionViewItem())
#define STYLEOPTIONVIEWITEM_HEAP_NEW(...) (reinterpret_cast<StyleOption::ViewItem::OwnedRef>(new QStyleOptionViewItem(__VA_ARGS__)))

namespace StyleOption
{
}
