#include "generated/AbstractButton.h"
#include "AbstractButtonInternal.h"

#include <QAbstractButton>

#include "IconInternal.h"
#include "KeySequenceInternal.h"
#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSBUTTON_THIS (WRAPPER->getActual())

namespace AbstractButton
{
    bool Handle_autoExclusive(HandleRef _this) {
        return ABSBUTTON_THIS->autoExclusive();
    }
    void Handle_setAutoExclusive(HandleRef _this, bool state) {
        ABSBUTTON_THIS->setAutoExclusive(state);
    }
    bool Handle_autoRepeat(HandleRef _this) {
        return ABSBUTTON_THIS->autoRepeat();
    }
    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        ABSBUTTON_THIS->setAutoRepeat(state);
    }
    int32_t Handle_autoRepeatDelay(HandleRef _this) {
        return ABSBUTTON_THIS->autoRepeatDelay();
    }
    void Handle_setAutoRepeatDelay(HandleRef _this, int32_t delay) {
        ABSBUTTON_THIS->setAutoRepeatDelay(delay);
    }
    int32_t Handle_autoRepeatInterval(HandleRef _this) {
        return ABSBUTTON_THIS->autoRepeatInterval();
    }
    void Handle_setAutoRepeatInterval(HandleRef _this, int32_t interval) {
        ABSBUTTON_THIS->setAutoRepeatInterval(interval);
    }
    bool Handle_isCheckable(HandleRef _this) {
        return ABSBUTTON_THIS->isCheckable();
    }
    void Handle_setCheckable(HandleRef _this, bool state) {
        ABSBUTTON_THIS->setCheckable(state);
    }
    bool Handle_isChecked(HandleRef _this) {
        return ABSBUTTON_THIS->isChecked();
    }
    void Handle_setChecked(HandleRef _this, bool state) {
        ABSBUTTON_THIS->setChecked(state);
    }
    bool Handle_isDown(HandleRef _this) {
        return ABSBUTTON_THIS->isDown();
    }
    void Handle_setDown(HandleRef _this, bool state) {
        ABSBUTTON_THIS->setDown(state);
    }
    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(ABSBUTTON_THIS->icon());
    }
    void Handle_setIcon(HandleRef _this, const std::shared_ptr<Icon::Deferred::Base>& icon) {
        ABSBUTTON_THIS->setIcon(Icon::fromDeferred(icon));
    }
    Size Handle_iconSize(HandleRef _this) {
        return toSize(ABSBUTTON_THIS->iconSize());
    }
    void Handle_setIconSize(HandleRef _this, Size size) {
        ABSBUTTON_THIS->setIconSize(toQSize(size));
    }
    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(ABSBUTTON_THIS->shortcut());
    }
    void Handle_setShortcut(HandleRef _this, const std::shared_ptr<KeySequence::Deferred::Base>& seq) {
        ABSBUTTON_THIS->setShortcut(KeySequence::fromDeferred(seq));
    }
    std::string Handle_text(HandleRef _this) {
        return ABSBUTTON_THIS->text().toStdString();
    }
    void Handle_setText(HandleRef _this, const std::string& text) {
        ABSBUTTON_THIS->setText(QString::fromStdString(text));
    }
}
