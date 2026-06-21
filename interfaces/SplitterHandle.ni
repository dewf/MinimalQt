module SplitterHandle;

import Object;
import Widget;
import Enums;

interface SignalHandler extends Widget.SignalHandler;
// no extra signals

fwdopaque Splitter_Handle = Splitter.Handle; // potential for confusion here (vs. this module name)

opaque Handle extends Widget.Handle {
    bool opaqueResize();
    Orientation orientation();
    void setOrientation(Orientation orientation);
    Splitter_Handle splitter();
}

// no ctor, we don't create these currently
