#include "generated/LayoutItem.h"
#include "LayoutItemInternal.h"

#include "SizeInternal.h"
#include "RectInternal.h"

#include "util/convert.h"

using namespace ::Enums;
using namespace ::Size;
using namespace ::Rect;
using namespace ::SizePolicy;

#define THIS (reinterpret_cast<QLayoutItem*>(_this))

namespace LayoutItem
{
    Flags<Alignment> Handle_alignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

     Flags<ControlTypes> Handle_controlTypes(HandleRef _this) {
        return static_cast<Flags<ControlTypes>>(THIS->controlTypes());
    }

    Flags<Orientations> Handle_expandingDirections(HandleRef _this) {
        return static_cast<Flags<Orientations>>(THIS->expandingDirections());
    }

    Rect::OwnedRef Handle_geometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->geometry());
    }

    bool Handle_hasHeightForWidth(HandleRef _this) {
        return THIS->hasHeightForWidth();
    }

    int32_t Handle_heightForWidth(HandleRef _this, int32_t width) {
        return THIS->heightForWidth(width);
    }

    void Handle_invalidate(HandleRef _this) {
        THIS->invalidate();
    }

    bool Handle_isEmpty(HandleRef _this) {
        return THIS->isEmpty();
    }

    Size::OwnedRef Handle_maximumSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->maximumSize());
    }

    int32_t Handle_minimumHeightForWidth(HandleRef _this, int32_t width) {
        return THIS->minimumHeightForWidth(width);
    }

    Size::OwnedRef Handle_minimumSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->minimumSize());
    }

    void Handle_setAlignment(HandleRef _this, Flags<Alignment> alignment) {
        THIS->setAlignment(static_cast<Qt::Alignment>(alignment.value()));
    }

    void Handle_setGeometry(HandleRef _this, Rect::HandleRef r) {
        THIS->setGeometry(QRECT_VALUE(r));
    }

    Size::OwnedRef Handle_sizeHint(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->sizeHint());
    }

    Widget::HandleRef Handle_widget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget());
    }
}
