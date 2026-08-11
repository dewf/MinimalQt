#include "generated/TextOption.h"
#include "TextOptionInternal.h"

using namespace ::Enums;

#define THIS (AS_QTEXTOPTION_PTR(_this))

namespace TextOption
{
    Flags<Alignment> Handle_alignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
