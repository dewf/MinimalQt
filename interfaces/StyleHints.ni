module StyleHints;

import Object;
import Enums;

// this actually has LOTS of signals, but right now we just want to be able to set color scheme

@nodispose // no ctors
opaque Handle extends Object.Handle {
    ColorScheme colorScheme();
    void setColorScheme(ColorScheme scheme);
    void unsetColorScheme();
}

// no ctors
