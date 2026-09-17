module ScrollBar;

import AbstractSlider;
import Widget;
import Enums;
import Menu;
import Point;

@methodprefix("sig_")
interface SignalHandler extends AbstractSlider.SignalHandler;
// no extra signals

opaque Handle extends AbstractSlider.Handle {
    Menu.Handle createStandardContextMenu(Point.Handle position);
}

Handle create(Widget.Handle parent = null);
Handle create(Orientation orientation, Widget.Handle parent = null);
