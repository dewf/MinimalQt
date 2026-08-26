module Dialog;

import Object;
import Icon;
import Widget;
import Enums;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void accepted();
    void finished(int result);
    void rejected();
}

enum DialogCode {
    Accepted = 1,
    Rejected = 0
}

opaque Handle extends Widget.Handle {

    bool isSizeGripEnabled();
    int result();
    void setModal(bool modal);
    void setResult(int i);
    void setSizeGripEnabled(bool enabled);

    void accept();
    void done(int r);
    int exec();
    void open();
    void reject();

    // signals ============================
    SignalConnection connect_Accepted(SignalHandler handler);
    SignalConnection connect_Finished(SignalHandler handler);
    SignalConnection connect_Rejected(SignalHandler handler);
}

Handle create(Widget.Handle parent = null, WindowFlags f = 0);
