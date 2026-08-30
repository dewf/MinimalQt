#pragma once

#include "generated/StyleOptionViewItem.h"
#include <QStyleOptionViewItem>

#define AS_QSTYLEOPTIONVIEWITEM_PTR(x) (reinterpret_cast<QStyleOptionViewItem*>(x))
#define QSTYLEOPTIONVIEWITEM_VALUE(x) (x != nullptr ? *AS_QSTYLEOPTIONVIEWITEM_PTR(x) : QStyleOptionViewItem())
#define STYLEOPTIONVIEWITEM_HEAP_NEW(...) (reinterpret_cast<StyleOptionViewItem::OwnedRef>(new QStyleOptionViewItem(__VA_ARGS__)))

namespace StyleOptionViewItem {
}
