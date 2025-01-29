#include "generated/Color.h"
#include "ColorInternal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

#define THIS (AS_QCOLOR_PTR(_this))

namespace Color
{
    QColor fromConstant(const Constant name) {
        switch (name) {
            case Constant::Black:
                return QColorConstants::Black;
            case Constant::White:
                return QColorConstants::White;
            case Constant::DarkGray:
                return QColorConstants::DarkGray;
            case Constant::Gray:
                return QColorConstants::Gray;
            case Constant::LightGray:
                return QColorConstants::LightGray;
            case Constant::Red:
                return QColorConstants::Red;
            case Constant::Green:
                return QColorConstants::Green;
            case Constant::Blue:
                return QColorConstants::Blue;
            case Constant::Cyan:
                return QColorConstants::Cyan;
            case Constant::Magenta:
                return QColorConstants::Magenta;
            case Constant::Yellow:
                return QColorConstants::Yellow;
            case Constant::DarkRed:
                return QColorConstants::DarkRed;
            case Constant::DarkGreen:
                return QColorConstants::DarkGreen;
            case Constant::DarkBlue:
                return QColorConstants::DarkBlue;
            case Constant::DarkCyan:
                return QColorConstants::DarkCyan;
            case Constant::DarkMagenta:
                return QColorConstants::DarkMagenta;
            case Constant::DarkYellow:
                return QColorConstants::DarkYellow;
            case Constant::Transparent:
                return QColorConstants::Transparent;
            default:
                clientLog(LogLevel::Warning, "Painter.cpp Color::fromConstant - unhandled value");
        }
        return QColorConstants::Black;
    }

    void Handle_setAlpha(HandleRef _this, int32_t alpha) {
        THIS->setAlpha(alpha);
    }

    void Handle_setAlphaF(HandleRef _this, float alpha) {
        THIS->setAlphaF(alpha);
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return COLOR_HEAP_NEW();
    }
    OwnedRef create(Constant name) {
        return COLOR_HEAP_NEW(fromConstant(name));
    }
    OwnedRef create(int32_t r, int32_t g, int32_t b) {
        return COLOR_HEAP_NEW(r, g, b);
    }
    OwnedRef create(int32_t r, int32_t g, int32_t b, int32_t a) {
        return COLOR_HEAP_NEW(r, g, b, a);
    }
    OwnedRef create(float r, float g, float b) {
        return COLOR_HEAP_NEW(QColor::fromRgbF(r, g, b));
    }
    OwnedRef create(float r, float g, float b, float a) {
        return COLOR_HEAP_NEW(QColor::fromRgbF(r, g, b, a));
    }
    OwnedRef create(HandleRef other) {
        return COLOR_HEAP_NEW(QCOLOR_VALUE(other));
    }
}
