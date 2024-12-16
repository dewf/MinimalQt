#include "generated/StatusBar.h"

#include <QStatusBar>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((StatusBarWithHandler*)_this)

#include "signalrelays/StatusBar.h"

namespace StatusBar
{
    class StatusBarWithHandler : public QStatusBar {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit StatusBarWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return THIS->isSizeGripEnabled();
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        THIS->setSizeGripEnabled(enabled);
    }

    void Handle_clearMessage(HandleRef _this) {
        THIS->clearMessage();
    }

    void Handle_showMessage(HandleRef _this, const std::string& message, int32_t timeout) {
        THIS->showMessage(QString::fromStdString(message), timeout);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new StatusBarWithHandler(handler));
    }
}

#include "StatusBar.moc"
