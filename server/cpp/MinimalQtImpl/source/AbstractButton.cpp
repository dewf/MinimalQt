#include "generated/AbstractButton.h"
#include "AbstractButtonInternal.h"

#include "ObjectInternal.h"
#include "IconInternal.h"
#include "KeySequenceInternal.h"
#include "SizeInternal.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::KeySequence;
using namespace ::Widget;
using namespace ::Icon;

#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractButton*>(_this))

namespace AbstractButton
{
    bool Handle_autoExclusive(HandleRef _this) {
        return THIS->autoExclusive();
    }

    bool Handle_autoRepeat(HandleRef _this) {
        return THIS->autoRepeat();
    }

    int32_t Handle_autoRepeatDelay(HandleRef _this) {
        return THIS->autoRepeatDelay();
    }

    int32_t Handle_autoRepeatInterval(HandleRef _this) {
        return THIS->autoRepeatInterval();
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    Size::OwnedRef Handle_iconSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->iconSize());
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    bool Handle_isChecked(HandleRef _this) {
        return THIS->isChecked();
    }

    bool Handle_isDown(HandleRef _this) {
        return THIS->isDown();
    }

    void Handle_setAutoExclusive(HandleRef _this, bool state) {
        THIS->setAutoExclusive(state);
    }

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        THIS->setAutoRepeat(state);
    }

    void Handle_setAutoRepeatDelay(HandleRef _this, int32_t delay) {
        THIS->setAutoRepeatDelay(delay);
    }

    void Handle_setAutoRepeatInterval(HandleRef _this, int32_t interval) {
        THIS->setAutoRepeatInterval(interval);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    void Handle_setDown(HandleRef _this, bool state) {
        THIS->setDown(state);
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    void Handle_setShortcut(HandleRef _this, KeySequence::HandleRef seq) {
        THIS->setShortcut(QKEYSEQ_VALUE(seq));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(THIS->shortcut());
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_animateClick(HandleRef _this) {
        THIS->animateClick();
    }

    void Handle_click(HandleRef _this) {
        THIS->click();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    void Handle_setIconSize(HandleRef _this, Size::HandleRef size) {
        THIS->setIconSize(QSIZE_VALUE(size));
    }

    void Handle_toggle(HandleRef _this) {
        THIS->toggle();
    }

    // ============

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::clicked, [handler](const bool checkState) {
            handler->sig_clicked(checkState);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Pressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::pressed, [handler] {
            handler->sig_pressed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Released(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::released, [handler] {
            handler->sig_released();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Toggled(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractButton::toggled, [handler](const bool checkState) {
            handler->sig_toggled(checkState);
        });
        return new __SignalConnection { connection };
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto button = AS_QABSTRACTBUTTON_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(button);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(button);
        }
        std::unreachable();
    }
}
