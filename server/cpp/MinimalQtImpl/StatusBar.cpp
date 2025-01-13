#include "generated/StatusBar.h"
#include "StatusBarInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QStatusBar*>(_this))

namespace StatusBar
{
    void Handle_addPermanentWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch /* 0 */) {
        THIS->addPermanentWidget(AS_QWIDGET_PTR(widget), stretch);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch /* 0 */) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), stretch);
    }

    std::string Handle_currentMessage(HandleRef _this) {
        return THIS->currentMessage().toStdString();
    }

    int32_t Handle_insertPermanentWidget(HandleRef _this, int32_t index, Widget::HandleRef widget, int32_t stretch /* 0 */) {
        return THIS->insertPermanentWidget(index, AS_QWIDGET_PTR(widget), stretch);
    }

    int32_t Handle_insertWidget(HandleRef _this, int32_t index, Widget::HandleRef widget, int32_t stretch /* 0 */) {
        return THIS->insertWidget(index, AS_QWIDGET_PTR(widget), stretch);
    }

    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return THIS->isSizeGripEnabled();
    }

    void Handle_removeWidget(HandleRef _this, Widget::HandleRef widget) {
        return THIS->removeWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enable) {
        THIS->setSizeGripEnabled(enable);
    }

    void Handle_clearMessage(HandleRef _this) {
        THIS->clearMessage();
    }

    void Handle_showMessage(HandleRef _this, const std::string& message, int32_t timeout /* 0 */) {
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(AS_QWIDGET_PTR(parent));
    }
}
