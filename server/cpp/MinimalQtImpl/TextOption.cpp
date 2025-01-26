#include "generated/TextOption.h"
#include "TextOptionInternal.h"

using namespace ::Enums;

#define THIS (AS_QTEXTOPTION_PTR(_this))

namespace TextOption
{
    Alignment Handle_alignment(HandleRef _this) {
        return Alignment(THIS->alignment());
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
