#include "generated/StyleOption.h"
#include "StyleOptionInternal.h"

#include "WidgetInternal.h"

#include "LoggingInternal.h"
using namespace ::Logging;

#define THIS (AS_QSTYLEOPTION_PTR(_this))

namespace StyleOption
{
    void Handle_initFrom(HandleRef _this, Widget::HandleRef widget) {
        THIS->initFrom(AS_QWIDGET_PTR(widget));
    }

    void Owned_dispose(OwnedRef _this) {
        clientLog(LogLevel::Warning, "backend: StyleOption disposed() - forget why we originally wanted to warn on this...");
        delete THIS;
    }

    OwnedRef create(int32_t version /* static_cast<int32_t>(StyleOptionVersion::Version) */, int32_t type_ /* static_cast<int32_t>(OptionType::SO_Default) */) {
        return STYLEOPTION_HEAP_NEW(version, type_);
    }

    OwnedRef create(HandleRef other) {
        return STYLEOPTION_HEAP_NEW(QSTYLEOPTION_VALUE(other));
    }

    // StyleOptionViewItem =========================================================
#define VIEWITEM_THIS (AS_QSTYLEOPTIONVIEWITEM_PTR(_this))

    namespace ViewItem {
        void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
            auto viewitem = AS_QSTYLEOPTIONVIEWITEM_PTR(obj);
            switch (target)
            {
            case Handle_CastTarget::StyleOption_Handle:
                return static_cast<QStyleOption*>(viewitem);
            }
            std::unreachable();
        }

        void Owned_dispose(OwnedRef _this) {
            delete VIEWITEM_THIS;
        }

        OwnedRef create() {
            return STYLEOPTIONVIEWITEM_HEAP_NEW();
        }

        OwnedRef create(HandleRef other) {
            return STYLEOPTIONVIEWITEM_HEAP_NEW(*AS_QSTYLEOPTIONVIEWITEM_PTR(other));
        }
    }

}
