module Action;

import Object;
import KeySequence;
import Icon;
import Enums;
import Font;
import Variant;

interface SignalHandler extends Object.SignalHandler {
    void changed();
    void checkableChanged(bool checkable);
    void enabledChanged(bool enabled);
    void hovered();
    void toggled(bool checked_);
    void triggered(bool checked_);
    void visibleChanged();
}

enum ActionEvent { Trigger, Hover }

enum MenuRole {
    NoRole = 0,
    TextHeuristicRole,
    ApplicationSpecificRole,
    AboutQtRole,
    AboutRole,
    PreferencesRole,
    QuitRole
}

enum Priority {
    LowPriority = 0,
    NormalPriority = 128,
    HighPriority = 256
}

opaque Handle extends Object.Handle {

    // QActionGroup * actionGroup() const
    // TODO

    void activate(ActionEvent event_);
    Array<Object.Handle> associatedObjects();
    bool autoRepeat();
    Variant.Owned data();
    Font.Owned font();
    Icon.Owned icon();
    string iconText();
    bool isCheckable();
    bool isChecked();
    bool isEnabled();
    bool isIconVisibleInMenu();
    bool isSeparator();
    bool isShortcutVisibleInContextMenu();
    bool isVisible();

    // now an extension method in Menu.ni:
    // Menu_Handle menu();

    MenuRole getMenuRole();
    Priority getPriority();

    // void setActionGroup(QActionGroup *group)
    // TODO

    void setAutoRepeat(bool state);
    void setCheckable(bool state);
    void setData(Variant.Handle data);
    void setFont(Font.Handle font);
    void setIcon(Icon.Handle icon);
    void setIconText(string text);
    void setIconVisibleInMenu(bool visible);

    // now an extension method in Menu.ni:
    // void setMenu(Menu_Handle menu);

    void setMenuRole(MenuRole menuRole);
    void setPriority(Priority priority);
    void setSeparator(bool b);
    void setShortcut(KeySequence.Handle shortcut);
    void setShortcutContext(ShortcutContext context);
    void setShortcutVisibleInContextMenu(bool show);
    void setShortcuts(KeySequence.StandardKey key);
    void setShortcuts(Array<KeySequence.Handle> shortcuts);
    void setStatusTip(string statusTip);
    void setText(string text);
    void setToolTip(string tip);
    void setWhatsThis(string what);
    KeySequence.Owned shortcut();
    ShortcutContext shortcutContext();
    Array<KeySequence.Owned> shortcuts();
    bool showStatusText(Object.Handle obj = null);
    string statusTip();
    string text();
    string toolTip();
    string whatsThis();

    void hover();
    void resetEnabled();
    void setChecked(bool state);
    void setDisabled(bool state);
    void setEnabled(bool state);
    void setVisible(bool state);
    void toggle();
    void trigger();

    // signals ============================
    SignalConnection connect_Changed(SignalHandler handler);
    SignalConnection connect_CheckableChanged(SignalHandler handler);
    SignalConnection connect_EnabledChanged(SignalHandler handler);
    SignalConnection connect_Hovered(SignalHandler handler);
    SignalConnection connect_Toggled(SignalHandler handler);
    SignalConnection connect_Triggered(SignalHandler handler);
    SignalConnection connect_VisibleChanged(SignalHandler handler);
}

Handle create(Object.Handle parent = null);
Handle create(string text, Object.Handle parent = null);
Handle create(Icon.Handle icon, string text, Object.Handle parent = null);
