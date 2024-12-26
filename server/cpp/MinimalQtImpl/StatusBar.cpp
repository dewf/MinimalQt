#include "generated/StatusBar.h"
#include "StatusBarInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define STATUSBAR_THIS (WRAPPER->getActual())

namespace StatusBar
{
    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return STATUSBAR_THIS->isSizeGripEnabled();
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        STATUSBAR_THIS->setSizeGripEnabled(enabled);
    }

    void Handle_clearMessage(HandleRef _this) {
        STATUSBAR_THIS->clearMessage();
    }

    void Handle_showMessage(HandleRef _this, const std::string& message, int32_t timeout) {
        STATUSBAR_THIS->showMessage(QString::fromStdString(message), timeout);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QStatusBar(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
