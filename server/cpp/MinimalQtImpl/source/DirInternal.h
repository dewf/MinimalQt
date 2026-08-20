#pragma once

#include "generated/Dir.h"
#include <QDir>

#define AS_QDIR_PTR(x) (reinterpret_cast<QDir*>(x))
#define QDIR_VALUE(x) (*AS_QDIR_PTR(x))
#define DIR_HEAP_NEW(...) (reinterpret_cast<Dir::OwnedRef>(new QDir(__VA_ARGS__)))

namespace Dir {
}
