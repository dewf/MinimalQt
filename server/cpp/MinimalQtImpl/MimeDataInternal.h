#pragma once

#include "generated/MimeData.h"

#include <QMimeData>

#define AS_QMIMEDATA_PTR(x) (reinterpret_cast<QMimeData*>(x))

namespace MimeData {
}
