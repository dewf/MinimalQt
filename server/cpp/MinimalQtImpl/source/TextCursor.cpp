#include "generated/TextCursor.h"
#include "TextCursorInternal.h"

namespace TextCursor
{
#define THIS (reinterpret_cast<QTextCursor*>(_this))

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
