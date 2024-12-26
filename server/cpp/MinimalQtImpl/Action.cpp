#include "generated/Action.h"
#include "ActionInternal.h"

#include <QObject>
#include <QAction>

#include "IconInternal.h"
#include "KeySequenceInternal.h"
#include "FontInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ACTION_THIS (WRAPPER->getActual())

namespace Action
{
    // properties ==========================================

    bool Handle_autoRepeat(HandleRef _this) {
        return ACTION_THIS->autoRepeat();
    }

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        ACTION_THIS->setAutoRepeat(state);
    }

    bool Handle_isCheckable(HandleRef _this) {
        return ACTION_THIS->isCheckable();
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        ACTION_THIS->setCheckable(state);
    }

    bool Handle_isChecked(HandleRef _this) {
        return ACTION_THIS->isChecked();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        ACTION_THIS->setChecked(state);
    }

    bool Handle_isEnabled(HandleRef _this) {
        return ACTION_THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool state) {
        ACTION_THIS->setEnabled(state);
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(ACTION_THIS->font());
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        ACTION_THIS->setFont(QFONT_VALUE(font));
    }

    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(ACTION_THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        ACTION_THIS->setIcon(QICON_VALUE(icon));
    }

    std::string Handle_iconText(HandleRef _this) {
        return ACTION_THIS->iconText().toStdString();
    }

    void Handle_setIconText(HandleRef _this, const std::string& text) {
        ACTION_THIS->setIconText(QString::fromStdString(text));
    }

    bool Handle_isIconVisibleInMenu(HandleRef _this) {
        return ACTION_THIS->isIconVisibleInMenu();
    }

    void Handle_setIconVisibleInMenu(HandleRef _this, bool visible) {
        ACTION_THIS->setIconVisibleInMenu(visible);
    }

    MenuRole Handle_menuRole(HandleRef _this) {
        return static_cast<MenuRole>(ACTION_THIS->menuRole());
    }

    void Handle_setMenuRole(HandleRef _this, MenuRole role) {
        ACTION_THIS->setMenuRole(static_cast<QAction::MenuRole>(role));
    }

    Priority Handle_priority(HandleRef _this) {
        return static_cast<Priority>(ACTION_THIS->priority());
    }

    void Handle_setPriority(HandleRef _this, Priority priority) {
        ACTION_THIS->setPriority(static_cast<QAction::Priority>(priority));
    }

    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(ACTION_THIS->shortcut());
    }

    void Handle_setShortcut(HandleRef _this, const std::shared_ptr<KeySequence::Deferred::Base>& shortcut) {
        ACTION_THIS->setShortcut(fromDeferred(shortcut));
    }

    ShortcutContext Handle_shortcutContext(HandleRef _this) {
        return static_cast<ShortcutContext>(ACTION_THIS->shortcutContext());
    }

    void Handle_setShortcutContext(HandleRef _this, ShortcutContext context) {
        ACTION_THIS->setShortcutContext(static_cast<Qt::ShortcutContext>(context));
    }

    bool Handle_isShortcutVisibleInContextMenu(HandleRef _this) {
        return ACTION_THIS->isShortcutVisibleInContextMenu();
    }

    void Handle_setShortcutVisibleInContextMenu(HandleRef _this, bool visible) {
        ACTION_THIS->setShortcutVisibleInContextMenu(visible);
    }

    std::string Handle_statusTip(HandleRef _this) {
        return ACTION_THIS->statusTip().toStdString();
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        ACTION_THIS->setStatusTip(QString::fromStdString(tip));
    }

    std::string Handle_text(HandleRef _this) {
        return ACTION_THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        ACTION_THIS->setText(QString::fromStdString(text));
    }

    std::string Handle_toolTip(HandleRef _this) {
        return ACTION_THIS->toolTip().toStdString();
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        ACTION_THIS->setToolTip(QString::fromStdString(tip));
    }

    bool Handle_isVisible(HandleRef _this) {
        return ACTION_THIS->isVisible();
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        ACTION_THIS->setVisible(visible);
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return ACTION_THIS->whatsThis().toStdString();
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        ACTION_THIS->setWhatsThis(QString::fromStdString(text));
    }

    // methods ==================================================

    void Handle_setSeparator(HandleRef _this, bool state) {
        ACTION_THIS->setSeparator(state);
    }

    // signal mask ==============================================

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Object::HandleRef owner, const std::shared_ptr<SignalHandler>& handler) {
        const auto ownerWrapper = reinterpret_cast<Object::SignalWrapper*>(owner);
        const auto action = new QAction(ownerWrapper->getActual());
        const auto wrapper = new SignalWrapper(action, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
