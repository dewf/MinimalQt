module RadioButton;

import Object;
import Widget;
import AbstractButton;

@methodprefix("sig_")
interface SignalHandler extends AbstractButton.SignalHandler;
// none extra

opaque Handle extends AbstractButton.Handle;
// nothin'

Handle create(Widget.Handle parent = null);
Handle create(string text, Widget.Handle parent = null);
