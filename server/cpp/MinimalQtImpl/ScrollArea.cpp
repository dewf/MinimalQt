#include "generated/ScrollArea.h"

#include <QScrollArea>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((ScrollAreaWithHandler*)_this)

#include "signalrelays/ScrollArea.h"

namespace ScrollArea
{
    class ScrollAreaWithHandler : public QScrollArea {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit ScrollAreaWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setWidgetResizable(HandleRef _this, bool resizable) {
        THIS->setWidgetResizable(resizable);
    }

    void Handle_setWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ScrollAreaWithHandler(handler));
    }
}

#include "ScrollArea.moc"
