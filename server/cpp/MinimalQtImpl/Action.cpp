#include "generated/Action.h"
#include "ActionInternal.h"

#include <QObject>
#include <QAction>

#include "IconInternal.h"
#include "KeySequenceInternal.h"
#include "FontInternal.h"

#define THIS ((ActionWithHandler*)_this)

namespace Action
{
    class ActionWithHandler : public QAction {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        ActionWithHandler(QObject *parent, const std::shared_ptr<SignalHandler> &handler) : QAction(parent),
            relay(this, handler) {
        }
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    // properties ==========================================

    bool Handle_autoRepeat(HandleRef _this) {
        return THIS->autoRepeat();
    }

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        THIS->setAutoRepeat(state);
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

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool state) {
        THIS->setEnabled(state);
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    std::string Handle_iconText(HandleRef _this) {
        return THIS->iconText().toStdString();
    }

    void Handle_setIconText(HandleRef _this, const std::string& text) {
        THIS->setIconText(QString::fromStdString(text));
    }

    bool Handle_isIconVisibleInMenu(HandleRef _this) {
        return THIS->isIconVisibleInMenu();
    }

    void Handle_setIconVisibleInMenu(HandleRef _this, bool visible) {
        THIS->setIconVisibleInMenu(visible);
    }

    MenuRole Handle_menuRole(HandleRef _this) {
        return static_cast<MenuRole>(THIS->menuRole());
    }

    void Handle_setMenuRole(HandleRef _this, MenuRole role) {
        THIS->setMenuRole(static_cast<QAction::MenuRole>(role));
    }

    Priority Handle_priority(HandleRef _this) {
        return static_cast<Priority>(THIS->priority());
    }

    void Handle_setPriority(HandleRef _this, Priority priority) {
        THIS->setPriority(static_cast<QAction::Priority>(priority));
    }

    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(THIS->shortcut());
    }

    void Handle_setShortcut(HandleRef _this, const std::shared_ptr<KeySequence::Deferred::Base>& shortcut) {
        THIS->setShortcut(fromDeferred(shortcut));
    }

    ShortcutContext Handle_shortcutContext(HandleRef _this) {
        return static_cast<ShortcutContext>(THIS->shortcutContext());
    }

    void Handle_setShortcutContext(HandleRef _this, ShortcutContext context) {
        THIS->setShortcutContext(static_cast<Qt::ShortcutContext>(context));
    }

    bool Handle_isShortcutVisibleInContextMenu(HandleRef _this) {
        return THIS->isShortcutVisibleInContextMenu();
    }

    void Handle_setShortcutVisibleInContextMenu(HandleRef _this, bool visible) {
        THIS->setShortcutVisibleInContextMenu(visible);
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        THIS->setStatusTip(QString::fromStdString(tip));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        THIS->setToolTip(QString::fromStdString(tip));
    }

    bool Handle_isVisible(HandleRef _this) {
        return THIS->isVisible();
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        THIS->setWhatsThis(QString::fromStdString(text));
    }

    // methods ==================================================

    void Handle_setSeparator(HandleRef _this, bool state) {
        THIS->setSeparator(state);
    }

    // signal mask ==============================================

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef owner, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ActionWithHandler(reinterpret_cast<QObject *>(owner), handler));
    }
}

#include "Action.moc"
