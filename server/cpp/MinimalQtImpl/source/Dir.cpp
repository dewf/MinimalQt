#include "generated/Dir.h"
#include "DirInternal.h"

#define THIS (AS_QDIR_PTR(_this))

namespace Dir
{
    std::string Handle_toAbsoluteInternal(HandleRef _this) {
        return THIS->absolutePath().toStdString();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef createFromAbsolute(const std::string& absoluteDir) {
        return DIR_HEAP_NEW(QString::fromStdString(absoluteDir));
    }
}
