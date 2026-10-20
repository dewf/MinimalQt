#pragma once

#include "generated/RegularExpressionValidator.h"
#include <QRegularExpressionValidator>

#define AS_QREGEX_VALIDATOR_PTR(x) (reinterpret_cast<QRegularExpressionValidator*>(x))

namespace RegularExpressionValidator {
}
