#include "generated/ScrollBar.h"
#include "ScrollBarInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QScrollBar*>(_this))

namespace ScrollBar
{
    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QScrollBar(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Orientation orientation, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QScrollBar(static_cast<Qt::Orientation>(orientation), AS_QWIDGET_PTR(parent)));
    }
}
