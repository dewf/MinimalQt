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

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto handle = AS_QSPLITTERHANDLE_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(handle);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(handle);
        }
        std::unreachable();
    }
}
