#include "generated/GroupBox.h"
#include "GroupBoxInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define GROUPBOX_THIS (WRAPPER->getActual())

namespace GroupBox {
    Alignment Handle_getAlignment(HandleRef _this) {
        return GROUPBOX_THIS->alignment();
    }

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        GROUPBOX_THIS->setAlignment(align);
    }

    bool Handle_isCheckable(HandleRef _this) {
        return GROUPBOX_THIS->isCheckable();
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        GROUPBOX_THIS->setCheckable(state);
    }

    bool Handle_isChecked(HandleRef _this) {
        return GROUPBOX_THIS->isChecked();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        GROUPBOX_THIS->setChecked(state);
    }

    bool Handle_isFlat(HandleRef _this) {
        return GROUPBOX_THIS->isFlat();
    }

    void Handle_setFlat(HandleRef _this, bool state) {
        GROUPBOX_THIS->setFlat(state);
    }

    std::string Handle_title(HandleRef _this) {
        return GROUPBOX_THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        GROUPBOX_THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QGroupBox(qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(const std::string& title, const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent) {
        const auto qParent = Widget::fromOptionalHandle(parent);
        const auto wrapper = new SignalWrapper(new QGroupBox(QString::fromStdString(title), qParent), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
