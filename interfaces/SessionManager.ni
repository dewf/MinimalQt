module SessionManager;

import Object;

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler;
// no signals

enum RestartHint {
    RestartIfRunning,
    RestartAnyway,
    RestartImmediately,
    RestartNever
}

@nodispose
opaque Handle extends Object.Handle {
    bool allowsErrorInteraction();
    bool allowsInteraction();
    void cancel();
    Array<string> discardCommand();
    bool isPhase2();
    void release();
    void requestPhase2();
    Array<string> restartCommand();
    RestartHint getRestartHint();
    string sessionId();
    string sessionKey();
    void setDiscardCommand(Array<string> command);
    void setManagerProperty(string name, Array<string> value);
    void setManagerProperty(string name, string value);
    void setRestartCommand(Array<string> command);
    void setRestartHint(RestartHint hint);
}
