#include "generated/StatusBar.h"
#include "StatusBarInternal.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QStatusBar*>(_this))

namespace StatusBar
{
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

    SignalConnectionRef Handle_connect_MessageChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QStatusBar::messageChanged, [handler](const QString& message) {
            handler->messageChanged(message.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QStatusBar());
    }
}
