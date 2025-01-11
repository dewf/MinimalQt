#include "generated/CheckBox.h"
#include "CheckBoxInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QCheckBox*>(_this))

namespace CheckBox
{
    CheckState Handle_getCheckState(HandleRef _this) {
        return static_cast<CheckState>(THIS->checkState());
    }

    void Handle_setCheckState(HandleRef _this, CheckState value) {
        THIS->setCheckState(static_cast<Qt::CheckState>(value));
    }

    bool Handle_isTristate(HandleRef _this) {
        return THIS->isTristate();
    }

    void Handle_setTristate(HandleRef _this, bool value) {
        THIS->setTristate(value);
    }

    SignalConnectionRef Handle_connect_CheckStateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCheckBox::checkStateChanged, [handler](Qt::CheckState state) {
            handler->checkStateChanged(static_cast<CheckState>(state));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QCheckBox(Widget::fromOptionalHandle(parent)));
    }

    HandleRef create(const std::string& text, const std::optional<Widget::HandleRef>& parent) {
        return reinterpret_cast<HandleRef>(new QCheckBox(QString::fromStdString(text), Widget::fromOptionalHandle(parent)));
    }
}
