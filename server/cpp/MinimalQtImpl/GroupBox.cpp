#include "generated/GroupBox.h"
#include "GroupBoxInternal.h"

#define THIS (reinterpret_cast<QGroupBox*>(_this))

namespace GroupBox {
    Alignment Handle_getAlignment(HandleRef _this) {
        return THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(align);
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    bool Handle_isChecked(HandleRef _this) {
        return THIS->isChecked();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    bool Handle_isFlat(HandleRef _this) {
        return THIS->isFlat();
    }

    void Handle_setFlat(HandleRef _this, bool state) {
        THIS->setFlat(state);
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGroupBox::clicked, [handler](bool checked_) {
            handler->clicked(checked_);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Toggled(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGroupBox::toggled, [handler](bool state) {
            handler->toggled(state);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QGroupBox(qParent));
    }

    HandleRef create(const std::string& title, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        return reinterpret_cast<HandleRef>(new QGroupBox(QString::fromStdString(title), qParent));
    }
}
