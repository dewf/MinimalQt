#include "generated/SizePolicy.h"

#include <QSizePolicy>
#include "SizePolicyInternal.h"

#define THIS ((QSizePolicy*)_this)

namespace SizePolicy
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
