#pragma once

#include "generated/Gradient.h"
#include <QGradient>

#include <QConicalGradient>
#include <QLinearGradient>
#include <QRadialGradient>

#define AS_QGRADIENT_PTR(x) (reinterpret_cast<QGradient*>(x))
#define QGRADIENT_VALUE(x) (x != nullptr? *AS_QGRADIENT_PTR(x) : QGradient())
#define GRADIENT_HEAP_NEW(...) (reinterpret_cast<Gradient::OwnedRef>(new QGradient(__VA_ARGS__)))

#define AS_QCONICALGRADIENT_PTR(x) (reinterpret_cast<QConicalGradient*>(x))
#define QCONICALGRADIENT_VALUE(x) (x != nullptr ? *AS_QCONICALGRADIENT_PTR(x) : QConicalGradient())
#define CONICALGRADIENT_HEAP_NEW(...) (reinterpret_cast<Gradient::Conical::OwnedRef>(new QConicalGradient(__VA_ARGS__)))

#define AS_QLINEARGRADIENT_PTR(x) (reinterpret_cast<QLinearGradient*>(x))
#define QLINEARGRADIENT_VALUE(x) (x != nullptr ? *AS_QLINEARGRADIENT_PTR(x) : QLinearGradient())
#define LINEARGRADIENT_HEAP_NEW(...) (reinterpret_cast<Gradient::Linear::OwnedRef>(new QLinearGradient(__VA_ARGS__)))

#define AS_QRADIALGRADIENT_PTR(x) (reinterpret_cast<QRadialGradient*>(x))
#define QRADIALGRADIENT_VALUE(x) (x != nullptr ? *AS_QRADIALGRADIENT_PTR(x) : QRadialGradient())
#define RADIALGRADIENT_HEAP_NEW(...) (reinterpret_cast<Gradient::Radial::OwnedRef>(new QRadialGradient(__VA_ARGS__)))

namespace Gradient {
}
