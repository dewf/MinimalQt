module ScrollBar;

import AbstractSlider;
import Widget;
import Enums;

interface SignalHandler extends AbstractSlider.SignalHandler;
// no extra signals

opaque Handle extends AbstractSlider.Handle;
// no methods

Handle create(Widget.Handle parent = null);
Handle create(Orientation orientation, Widget.Handle parent = null);
