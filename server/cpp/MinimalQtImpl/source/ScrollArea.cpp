#include "generated/ScrollArea.h"
#include "ScrollAreaInternal.h"

#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::AbstractScrollArea;

#define THIS (reinterpret_cast<QScrollArea*>(_this))

namespace ScrollArea
{
    Flags<Alignment> Handle_getAlignment(HandleRef _this) {
        return static_cast<Flags<Alignment>>(THIS->alignment());
    }

    void Handle_ensureVisible(HandleRef _this, int32_t x, int32_t y, int32_t xmargin /* 50 */, int32_t ymargin /* 50 */) {
        THIS->ensureVisible(x, y, xmargin, ymargin);
    }

    void Handle_ensureWidgetVisible(HandleRef _this, Widget::HandleRef childWidget, int32_t xmargin /* 50 */, int32_t ymargin /* 50 */) {
        THIS->ensureWidgetVisible(AS_QWIDGET_PTR(childWidget), xmargin, ymargin);
    }

    void Handle_setAlignment(HandleRef _this,  Flags<Alignment> align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align.value()));
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

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto area = AS_QSCROLLAREA_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(area);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(area);
        case Handle_CastTarget::Frame_Handle:
            return static_cast<QFrame*>(area);
        case Handle_CastTarget::AbstractScrollArea_Handle:
            return static_cast<QAbstractScrollArea*>(area);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QScrollArea(AS_QWIDGET_PTR(parent)));
    }
}
