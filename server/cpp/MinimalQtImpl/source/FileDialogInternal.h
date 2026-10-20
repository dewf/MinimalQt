#pragma once

#include "generated/FileDialog.h"
#include "DialogInternal.h"

#include <QFileDialog>

#define AS_QFILEDIALOG_PTR(x) (reinterpret_cast<QFileDialog*>(x))

namespace FileDialog {
}
