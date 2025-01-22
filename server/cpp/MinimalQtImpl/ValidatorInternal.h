#pragma once

#include "generated/Validator.h"
#include <QValidator>

#define AS_QVALIDATOR_CONSTPTR(x) (reinterpret_cast<const QValidator*>(x))
#define AS_VALIDATOR_CONSTHANDLE(x) (reinterpret_cast<Validator::ConstHandleRef>(const_cast<QValidator*>(x)))

namespace Validator {
}
