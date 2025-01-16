#include "generated/StyleOptionViewItem.h"
#include "StyleOptionViewItemInternal.h"

#define THIS (AS_QSTYLEOPTIONVIEWITEM_PTR(_this))

namespace StyleOptionViewItem
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
