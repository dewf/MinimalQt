#include "generated/ScrollArea.h"
#include "ScrollAreaInternal.h"

#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QScrollArea*>(_this))

namespace ScrollArea
{
    Alignment Handle_getAlignment(HandleRef _this) {
        return THIS->alignment();
    }

    void Handle_ensureVisible(HandleRef _this, int32_t x, int32_t y, const std::optional<int32_t>& xmargin, const std::optional<int32_t>& ymargin) {
        THIS->ensureVisible(x, y, xmargin.value_or(50), ymargin.value_or(50));
    }

    void Handle_ensureWidgetVisible(HandleRef _this, Widget::HandleRef childWidget, const std::optional<int32_t>& xmargin, const std::optional<int32_t>& ymargin) {
        THIS->ensureWidgetVisible(AS_QWIDGET_PTR(childWidget), xmargin.value_or(50), ymargin.value_or(50));
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setWidgetResizable(HandleRef _this, bool resizable) {
        THIS->setWidgetResizable(resizable);
    }

    Widget::HandleRef Handle_takeWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->takeWidget());
    }

    Widget::HandleRef Handle_widget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->takeWidget());
    }

    bool Handle_widgetResizable(HandleRef _this) {
        return THIS->widgetResizable();
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QScrollArea(Widget::fromOptionalHandle(parent)));
    }
}
