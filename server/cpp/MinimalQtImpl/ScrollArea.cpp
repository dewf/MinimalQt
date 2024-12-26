#include "generated/ScrollArea.h"
#include "ScrollAreaInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define SCROLLAREA_THIS (WRAPPER->getActual())

namespace ScrollArea
{
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        SCROLLAREA_THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setWidgetResizable(HandleRef _this, bool resizable) {
        SCROLLAREA_THIS->setWidgetResizable(resizable);
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        SCROLLAREA_THIS->setWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QScrollArea(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
