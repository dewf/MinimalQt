#include "generated/SplitterHandle.h"
#include "SplitterHandleInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Enums;

#define THIS (reinterpret_cast<QSplitterHandle*>(_this))

namespace SplitterHandle
{
    bool Handle_opaqueResize(HandleRef _this) {
        return THIS->opaqueResize();
    }

    Orientation Handle_orientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    void Handle_setOrientation(HandleRef _this, Orientation orientation) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orientation));
    }

    Splitter_HandleRef Handle_splitter(HandleRef _this) {
        return reinterpret_cast<Splitter_HandleRef>(THIS->splitter());
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }
}
