#include "generated/ScrollArea.h"
#include "ScrollAreaInternal.h"

#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QScrollArea*>(_this))

namespace ScrollArea
{
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setWidgetResizable(HandleRef _this, bool resizable) {
        THIS->setWidgetResizable(resizable);
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QScrollArea());
    }
}
