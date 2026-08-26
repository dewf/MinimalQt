module MessageBox;

import Object;
import Icon;
import Enums;
import Dialog;
import AbstractButton;
import PushButton;
import CheckBox;
import Widget;
import Pixmap;

@methodprefix("sig_")
interface SignalHandler extends Dialog.SignalHandler {
    void buttonClicked(AbstractButton.Handle button);
}

enum ButtonRole {
    // keep this in sync with QDialogButtonBox::ButtonRole and QPlatformDialogHelper::ButtonRole
    InvalidRole = -1,
    AcceptRole,
    RejectRole,
    DestructiveRole,
    ActionRole,
    HelpRole,
    YesRole,
    NoRole,
    ResetRole,
    ApplyRole,

    NRoles
}

@withflags(StandardButtons)
enum StandardButton {
    NoButton           = 0x00000000,
    Ok                 = 0x00000400,
    Save               = 0x00000800,
    SaveAll            = 0x00001000,
    Open               = 0x00002000,
    Yes                = 0x00004000,
    YesToAll           = 0x00008000,
    No                 = 0x00010000,
    NoToAll            = 0x00020000,
    Abort              = 0x00040000,
    Retry              = 0x00080000,
    Ignore             = 0x00100000,
    Close              = 0x00200000,
    Cancel             = 0x00400000,
    Discard            = 0x00800000,
    Help               = 0x01000000,
    Apply              = 0x02000000,
    Reset              = 0x04000000,
    RestoreDefaults    = 0x08000000
}

enum Icon {
    NoIcon = 0,
    Information = 1,
    Warning = 2,
    Critical = 3,
    Question = 4
}

@withflags(OptionEnumSet)
enum OptionEnum {
    DontUseNativeDialog = 0x00000001
}

opaque Handle extends Dialog.Handle {
    void addButton(AbstractButton.Handle button, ButtonRole role);
    PushButton.Handle addButton(StandardButton button);
    PushButton.Handle addButton(string text, ButtonRole role);
    AbstractButton.Handle button(StandardButton which);
    ButtonRole getButtonRole(AbstractButton.Handle button);
    Array<AbstractButton.Handle> buttons();
    CheckBox.Handle checkBox();
    AbstractButton.Handle clickedButton();
    PushButton.Handle defaultButton();
    string detailedText();
    AbstractButton.Handle escapeButton();
    Icon getIcon();
    Pixmap.Owned iconPixmap();
    string informativeText();

    // void open(QObject *receiver, const char *member)
    // hmmmm

    OptionEnumSet getOptions();
    void removeButton(AbstractButton.Handle button);
    void setCheckBox(CheckBox.Handle cb);
    void setDefaultButton(StandardButton button);
    void setDefaultButton(PushButton.Handle button);
    void setDetailedText(string text);
    void setEscapeButton(AbstractButton.Handle button);
    void setEscapeButton(StandardButton button);
    void setIcon(Icon icon);
    void setIconPixmap(Pixmap.Handle pixmap);
    void setInformativeText(string text);
    void setOption(OptionEnum option, bool on = true);
    void setOptions(OptionEnumSet options_);
    void setStandardButtons(StandardButtons buttons);
    void setText(string text);
    void setTextFormat(TextFormatEnum format);
    void setTextInteractionFlags(TextInteractionFlags flags_);

    @shadows
    void setWindowModality(WindowModality windowModality);

    @shadows
    void setWindowTitle(string title);

    StandardButton getStandardButton(AbstractButton.Handle button);
    StandardButtons getStandardButtons();
    bool testOption(OptionEnum option);
    string text();
    TextFormatEnum textFormat();
    TextInteractionFlags textInteractionFlags();

    // exec() defined by Dialog.Handle

    // signals ========================================
    SignalConnection connect_ButtonClicked(SignalHandler handler);
}

// ctors:
Handle create(Widget.Handle parent = null);
Handle create(Icon icon, string title, string text, StandardButtons buttons = NoButton, Widget.Handle parent = null, WindowFlags flags_ = Dialog | MSWindowsFixedSizeDialogHint);

// static methods:
void about(Widget.Handle parent, string title, string text);
void aboutQt(Widget.Handle parent, Option<string> title);
StandardButton critical(Widget.Handle parent, string title, string text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
StandardButton information(Widget.Handle parent, string title, string text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
StandardButton question(Widget.Handle parent, string title, string text, StandardButtons buttons = Yes | No, StandardButton defaultButton = NoButton);
StandardButton warning(Widget.Handle parent, string title, string text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton);
