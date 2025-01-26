#include "generated/Action.h"
#include "ActionInternal.h"

#include "ObjectInternal.h"
#include "IconInternal.h"
#include "KeySequenceInternal.h"
#include "FontInternal.h"
#include "MenuInternal.h"
#include "VariantInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::KeySequence;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Font;
using namespace ::Variant;

#define THIS (reinterpret_cast<QAction*>(_this))

namespace Action
{
    void Handle_activate(HandleRef _this, ActionEvent event_) {
        THIS->activate(static_cast<QAction::ActionEvent>(event_));
    }

    std::vector<Object::HandleRef> Handle_associatedObjects(HandleRef _this) {
        const auto qList = THIS->associatedObjects();
        return fromQList<QObject*,Object::HandleRef>(qList, [](auto obj) { return reinterpret_cast<Object::HandleRef>(obj); });
    }

    bool Handle_autoRepeat(HandleRef _this) {
        return THIS->autoRepeat();
    }

    Variant::OwnedRef Handle_data(HandleRef _this) {
        return VARIANT_HEAP_NEW(THIS->data());
    }

    Font::OwnedRef Handle_font(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    std::string Handle_iconText(HandleRef _this) {
        return THIS->iconText().toStdString();
    }

    bool Handle_isCheckable(HandleRef _this) {
        return THIS->isCheckable();
    }

    bool Handle_isChecked(HandleRef _this) {
        return THIS->isChecked();
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    bool Handle_isIconVisibleInMenu(HandleRef _this) {
        return THIS->isIconVisibleInMenu();
    }

    bool Handle_isSeparator(HandleRef _this) {
        return THIS->isSeparator();
    }

    bool Handle_isShortcutVisibleInContextMenu(HandleRef _this) {
        return THIS->isShortcutVisibleInContextMenu();
    }

    bool Handle_isVisible(HandleRef _this) {
        return THIS->isVisible();
    }

    Menu_HandleRef Handle_menu(HandleRef _this) {
        return reinterpret_cast<Menu_HandleRef>(THIS->menu<>());
    }

    MenuRole Handle_getMenuRole(HandleRef _this) {
        return static_cast<MenuRole>(THIS->menuRole());
    }

    Priority Handle_getPriority(HandleRef _this) {
        return static_cast<Priority>(THIS->priority());
    }

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        THIS->setAutoRepeat(state);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    void Handle_setData(HandleRef _this, Variant::HandleRef data) {
        THIS->setData(QVARIANT_VALUE(data));
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    void Handle_setIconText(HandleRef _this, const std::string& text) {
        THIS->setIconText(QString::fromStdString(text));
    }

    void Handle_setIconVisibleInMenu(HandleRef _this, bool visible) {
        THIS->setIconVisibleInMenu(visible);
    }

    void Handle_setMenu(HandleRef _this, Menu_HandleRef menu) {
        THIS->setMenu(AS_QMENU_PTR(menu));
    }

    void Handle_setMenuRole(HandleRef _this, MenuRole role) {
        THIS->setMenuRole(static_cast<QAction::MenuRole>(role));
    }

    MenuRole Handle_menuRole(HandleRef _this) {
        return static_cast<MenuRole>(THIS->menuRole());
    }

    void Handle_setPriority(HandleRef _this, Priority priority) {
        THIS->setPriority(static_cast<QAction::Priority>(priority));
    }

    void Handle_setSeparator(HandleRef _this, bool state) {
        THIS->setSeparator(state);
    }

    void Handle_setShortcut(HandleRef _this, KeySequence::HandleRef shortcut) {
        THIS->setShortcut(QKEYSEQ_VALUE(shortcut));
    }

    void Handle_setShortcutContext(HandleRef _this, ShortcutContext context) {
        THIS->setShortcutContext(static_cast<Qt::ShortcutContext>(context));
    }

    void Handle_setShortcutVisibleInContextMenu(HandleRef _this, bool visible) {
        THIS->setShortcutVisibleInContextMenu(visible);
    }

    void Handle_setShortcuts(HandleRef _this, StandardKey key) {
        THIS->setShortcuts(static_cast<QKeySequence::StandardKey>(key));
    }

    void Handle_setShortcuts(HandleRef _this, const std::vector<KeySequence::HandleRef>& shortcuts) {
        const auto qList = toQList<KeySequence::HandleRef,QKeySequence>(shortcuts, [](auto sc) { return QKEYSEQ_VALUE(sc); });
        THIS->setShortcuts(qList);
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        THIS->setStatusTip(QString::fromStdString(tip));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        THIS->setToolTip(QString::fromStdString(tip));
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        THIS->setWhatsThis(QString::fromStdString(text));
    }

    KeySequence::OwnedRef Handle_shortcut(HandleRef _this) {
        return KEYSEQ_HEAP_NEW(THIS->shortcut());
    }

    ShortcutContext Handle_shortcutContext(HandleRef _this) {
        return static_cast<ShortcutContext>(THIS->shortcutContext());
    }

    std::vector<KeySequence::OwnedRef> Handle_shortcuts(HandleRef _this) {
        const auto qList = THIS->shortcuts();
        return fromQList<QKeySequence,KeySequence::OwnedRef>(qList, [](auto sc) { return KEYSEQ_HEAP_NEW(sc); });
    }

    bool Handle_showStatusText(HandleRef _this, Object::HandleRef obj /* nullptr */) {
        return THIS->showStatusText(AS_QOBJECT_PTR(obj));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
    }

    void Handle_hover(HandleRef _this) {
        THIS->hover();
    }

    void Handle_resetEnabled(HandleRef _this) {
        THIS->resetEnabled();
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    void Handle_setDisabled(HandleRef _this, bool state) {
        THIS->setDisabled(state);
    }

    void Handle_setEnabled(HandleRef _this, bool state) {
        THIS->setEnabled(state);
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    void Handle_toggle(HandleRef _this) {
        THIS->toggle();
    }

    void Handle_trigger(HandleRef _this) {
        THIS->trigger();
    }

    SignalConnectionRef Handle_connect_Changed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::changed, [handler] {
            handler->changed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CheckableChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::checkableChanged, [handler](bool checkable) {
            handler->checkableChanged(checkable);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_EnabledChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::enabledChanged, [handler](bool enabled) {
            handler->enabledChanged(enabled);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Hovered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::hovered, [handler] {
            handler->hovered();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Toggled(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::toggled, [handler](bool checked_) {
            handler->toggled(checked_);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Triggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::triggered, [handler](bool checked_) {
            handler->triggered(checked_);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAction::visibleChanged, [handler] {
            handler->visibleChanged();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QAction(AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(const std::string& text, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QAction(QString::fromStdString(text), AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(Icon::HandleRef icon, const std::string& text, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QAction(QICON_VALUE(icon), QString::fromStdString(text), AS_QOBJECT_PTR(parent)));
    }

}
