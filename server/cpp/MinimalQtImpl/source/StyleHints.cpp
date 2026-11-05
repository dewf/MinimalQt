#include "generated/StyleHints.h"
#include "StyleHintsInternal.h"

using namespace ::Object;
using namespace ::Enums;

#define THIS (AS_QSTYLEHINTS_PTR(_this))

namespace StyleHints
{
    ColorScheme Handle_colorScheme(HandleRef _this) {
        return static_cast<ColorScheme>(THIS->colorScheme());
    }

    void Handle_setColorScheme(HandleRef _this, ColorScheme scheme) {
        THIS->setColorScheme(static_cast<Qt::ColorScheme>(scheme));
    }

    void Handle_unsetColorScheme(HandleRef _this) {
        THIS->unsetColorScheme();
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto styleHints = AS_QSTYLEHINTS_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(styleHints);
        }
        std::unreachable();
    }
}
