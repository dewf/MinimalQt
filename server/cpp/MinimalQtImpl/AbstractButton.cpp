#include "generated/AbstractButton.h"
#include "AbstractButtonInternal.h"

#include "ObjectInternal.h"
#include "IconInternal.h"
#include "KeySequenceInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractButton*>(_this))

namespace AbstractButton
{
    bool Handle_autoExclusive(HandleRef _this) {
        return THIS->autoExclusive();
    }

    void Handle_setAutoExclusive(HandleRef _this, bool state) {
        THIS->setAutoExclusive(state);
    }

    bool Handle_autoRepeat(HandleRef _this) {
        return THIS->autoRepeat();
    }

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        THIS->setAutoRepeat(state);
    }

    int32_t Handle_autoRepeatDelay(HandleRef _this) {
        return THIS->autoRepeatDelay();
    }

    void Handle_setAutoRepeatDelay(HandleRef _this, int32_t delay) {
        THIS->setAutoRepeatDelay(delay);
    }

    int32_t Handle_autoRepeatInterval(HandleRef _this) {
        return THIS->autoRepeatInterval();
    }

    void Handle_setAutoRepeatInterval(HandleRef _this, int32_t interval) {
        THIS->setAutoRepeatInterval(interval);
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

    bool Handle_isDown(HandleRef _this) {
        return THIS->isDown();
    }

    void Handle_setDown(HandleRef _this, bool state) {
        THIS->setDown(state);
    }

    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(THIS->shortcut());
    }

    void Handle_setShortcut(HandleRef _this, KeySequence::HandleRef seq) {
        THIS->setShortcut(QKEYSEQ_VALUE(seq));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::clicked, [handler](const bool checkState) {
            handler->clicked(checkState);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Pressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::pressed, [handler] {
            handler->pressed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Released(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::released, [handler] {
            handler->released();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Toggled(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::toggled, [handler](const bool checkState) {
            handler->toggled(checkState);
        });
        return new __SignalConnection { connection };
    }
}
