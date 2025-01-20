module Application;

import GuiApplication;
import Object;
import Widget;

interface SignalHandler extends GuiApplication.SignalHandler {
    void focusChanged(Widget.Handle old, Widget.Handle new_);
}

opaque Handle extends GuiApplication.Handle {
    SignalConnection connect_FocusChanged(SignalHandler handler);
}

Handle create(Array<string> args);

// static methods ===============
void setStyle(string name);
int exec();
void quit();

// convenience (fake) ===========
Array<string> availableStyles();

delegate void MainThreadFunc();
void executeOnMainThread(MainThreadFunc func);
