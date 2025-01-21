module CheckBox;

import Object;
import Widget;
import AbstractButton;
import Enums;

interface SignalHandler extends AbstractButton.SignalHandler {
    void checkStateChanged(CheckState state);
}

opaque Handle extends AbstractButton.Handle {
    // properties
    CheckState getCheckState();
    void setCheckState(CheckState value);

    bool isTristate();
    void setTristate(bool value);

    // signals
    SignalConnection connect_CheckStateChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string text, Widget.Handle parent = null);
