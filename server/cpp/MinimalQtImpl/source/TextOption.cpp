#include "generated/TextOption.h"
#include "TextOptionInternal.h"

using namespace ::Enums;

#define THIS (AS_QTEXTOPTION_PTR(_this))

namespace TextOption
{
    Flags<Alignment> Handle_alignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    void Handle_setAlignment(HandleRef _this, Flags<Alignment> alignment) {
        THIS->setAlignment(Qt::Alignment::fromInt(alignment.value()));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return TEXTOPTION_HEAP_NEW();
    }

    OwnedRef create(Flags<Alignment> alignment) {
        return TEXTOPTION_HEAP_NEW(Qt::Alignment::fromInt(alignment.value()));
    }

    OwnedRef create(HandleRef other) {
        return TEXTOPTION_HEAP_NEW(QTEXTOPTION_VALUE(other));
    }
}
