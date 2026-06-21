module AbstractButton;

import Object;
import Size;
import KeySequence;
import Widget;
import Icon;

interface SignalHandler extends Widget.SignalHandler {
    void clicked(bool checkState);
    void pressed();
    void released();
    void toggled(bool checkState);
}

@nodispose
opaque Handle extends Widget.Handle {
    bool autoExclusive();
    bool autoRepeat();
    int autoRepeatDelay();
    int autoRepeatInterval();

    // QButtonGroup * group() const

    Icon.Owned icon();
    Size.Owned iconSize();
    bool isCheckable();
    bool isChecked();
    bool isDown();
    void setAutoExclusive(bool state);
    void setAutoRepeat(bool state);
    void setAutoRepeatDelay(int delay);
    void setAutoRepeatInterval(int interval);
    void setCheckable(bool state);
    void setDown(bool state);
    void setIcon(Icon.Handle icon);
    void setShortcut(KeySequence.Handle key);
    void setText(string text);
    KeySequence.Owned shortcut();
    string text();

    void animateClick();
    void click();
    void setChecked(bool state);
    void setIconSize(Size.Handle size);
    void toggle();

    // signals ============================
    SignalConnection connect_Clicked(SignalHandler handler);
    SignalConnection connect_Pressed(SignalHandler handler);
    SignalConnection connect_Released(SignalHandler handler);
    SignalConnection connect_Toggled(SignalHandler handler);
}

// can't create directly
