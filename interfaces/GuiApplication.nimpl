module GuiApplication;

import Object;
import CoreApplication;
import Enums;
import SessionManager;
import Screen;
import Window;

interface SignalHandler extends CoreApplication.SignalHandler {
    void applicationDisplayNameChanged();
    void applicationStateChanged(ApplicationState state);
    void commitDataRequest(SessionManager.Handle manager);
    void focusObjectChanged(Object.Handle focusObject);
    void focusWindowChanged(Window.Handle focusWindow);
    void fontDatabaseChanged();
    void lastWindowClosed();
    void layoutDirectionChanged(LayoutDirection direction);
    void primaryScreenChanged(Screen.Handle screen);
    void saveStateRequest(SessionManager.Handle manager);
    void screenAdded(Screen.Handle screen);
    void screenRemoved(Screen.Handle screen);
}

@nodispose
opaque Handle extends CoreApplication.Handle {

    // signals ==============================
    SignalConnection connect_ApplicationDisplayNameChanged(SignalHandler handler);
    SignalConnection connect_ApplicationStateChanged(SignalHandler handler);
    SignalConnection connect_CommitDataRequest(SignalHandler handler);
    SignalConnection connect_FocusObjectChanged(SignalHandler handler);
    SignalConnection connect_FocusWindowChanged(SignalHandler handler);
    SignalConnection connect_FontDatabaseChanged(SignalHandler handler);
    SignalConnection connect_LastWindowClosed(SignalHandler handler);
    SignalConnection connect_LayoutDirectionChanged(SignalHandler handler);
    SignalConnection connect_PrimaryScreenChanged(SignalHandler handler);
    SignalConnection connect_SaveStateRequest(SignalHandler handler);
    SignalConnection connect_ScreenAdded(SignalHandler handler);
    SignalConnection connect_ScreenRemoved(SignalHandler handler);
}

void setQuitOnLastWindowClosed(bool state);
