#pragma once
#include <QStringList>

#define AS_QSTRING_LIST_PTR(x) (reinterpret_cast<QStringList*>(x))
#define QSTRING_LIST_VALUE(x) (x != nullptr ? *AS_QSTRING_LIST_PTR(x) : QStringList())
#define STRING_LIST_HEAP_NEW(...) (reinterpret_cast<String::OwnedListRef>(new QStringList(__VA_ARGS__)))
