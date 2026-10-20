#include "generated/TextCharFormat.h"
#include "TextCharFormatInternal.h"

using namespace ::TextFormat;

namespace TextCharFormat
{
#define THIS (reinterpret_cast<QTextCharFormat*>(_this))

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto tcf = AS_QTEXTCHARFORMAT_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::TextFormat_Handle:
            return static_cast<QTextFormat*>(tcf);
        }
        std::unreachable();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
