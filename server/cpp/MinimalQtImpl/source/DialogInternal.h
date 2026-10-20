#pragma once

#include "generated/Dialog.h"
#include "WidgetInternal.h"

#include <QDialog>

#define AS_QDIALOG_PTR(x) (reinterpret_cast<QDialog*>(x))

namespace Dialog {
}
