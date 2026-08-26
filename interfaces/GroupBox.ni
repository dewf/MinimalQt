module GroupBox;

import Object;
import Icon;
import Enums;
import Widget;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void clicked(bool checked_);
    void toggled(bool state);
}

opaque Handle extends Widget.Handle {

    Alignment alignment();
    bool isCheckable();
    bool isChecked();
    bool isFlat();
    void setAlignment(int alignment);
    void setCheckable(bool checkable);
    void setFlat(bool flat);
    void setTitle(string title);
    string title();

    void setChecked(bool checked_);

    // signals ============================
    SignalConnection connect_Clicked(SignalHandler handler);
    SignalConnection connect_Toggled(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string title, Widget.Handle parent = null);
