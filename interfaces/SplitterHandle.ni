module SplitterHandle;

import Object;
import Widget;
import Enums;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler;
// no extra signals

opaque Handle extends Widget.Handle {
    bool opaqueResize();
    Orientation orientation();
    void setOrientation(Orientation orientation);

    // moved to Splitter.ni extension method
    // Splitter_Handle splitter();
}

// no ctor, we don't create these currently
