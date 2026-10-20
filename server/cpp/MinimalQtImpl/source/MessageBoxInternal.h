#pragma once

#include "generated/MessageBox.h"

#include <QMessageBox>

#define AS_QMESSAGEBOX_PTR(x) (reinterpret_cast<QMessageBox*>(x))

namespace MessageBox {
}

