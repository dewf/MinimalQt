#include "generated/LayoutItem.h"
#include "LayoutItemInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QLayoutItem*>(_this))

namespace LayoutItem
{
    Alignment Handle_alignment(HandleRef _this) {
        return static_cast<Alignment>(THIS->alignment());
    }

    ControlTypes Handle_controlTypes(HandleRef _this) {
        return ControlTypes(THIS->controlTypes());
    }

    Orientations Handle_expandingDirections(HandleRef _this) {
        return Orientations(THIS->expandingDirections());
    }

    Rect Handle_geometry(HandleRef _this) {
        return toRect(THIS->geometry());
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

    LayoutHandleRef Handle_layout(HandleRef _this) {
        return reinterpret_cast<LayoutHandleRef>(THIS->layout());
    }

    Size Handle_maximumSize(HandleRef _this) {
        return toSize(THIS->maximumSize());
    }

    int32_t Handle_minimumHeightForWidth(HandleRef _this, int32_t width) {
        return THIS->minimumHeightForWidth(width);
    }

    Size Handle_minimumSize(HandleRef _this) {
        return toSize(THIS->minimumSize());
    }

    void Handle_setAlignment(HandleRef _this, Alignment alignment) {
        THIS->setAlignment(static_cast<Qt::Alignment>(alignment.value));
    }

    void Handle_setGeometry(HandleRef _this, Rect r) {
        THIS->setGeometry(toQRect(r));
    }

    Size Handle_sizeHint(HandleRef _this) {
        return toSize(THIS->sizeHint());
    }

    WidgetHandleRef Handle_widget(HandleRef _this) {
        return reinterpret_cast<WidgetHandleRef>(THIS->widget());
    }
}
