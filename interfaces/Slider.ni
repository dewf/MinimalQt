module Slider;

import Object;
import Widget;
import Enums;
import AbstractSlider;

@methodprefix("sig_")
interface SignalHandler extends AbstractSlider.SignalHandler;

enum TickPosition {
    NoTicks = 0,
    TicksAbove = 1,
    TicksLeft = TicksAbove,
    TicksBelow = 2,
    TicksRight = TicksBelow,
    TicksBothSides = 3
}

opaque Handle extends AbstractSlider.Handle {
    void setTickInterval(int interval);
    void setTickPosition(TickPosition tpos);
    int tickInterval();
    TickPosition tickPosition();
}

Handle create(Widget.Handle parent = null);
Handle create(Orientation orientation, Widget.Handle parent = null);
