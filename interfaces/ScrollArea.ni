module ScrollArea;

import Object;
import Widget;
import Enums;
import AbstractScrollArea;

@methodprefix("sig_")
interface SignalHandler extends AbstractScrollArea.SignalHandler;
// none extra

opaque Handle extends AbstractScrollArea.Handle {
    Alignment getAlignment();
    void ensureVisible(int x, int y, int xmargin = 50, int ymargin = 50);
    void ensureWidgetVisible(Widget.Handle childWidget, int xmargin = 50, int ymargin = 50);
    void setAlignment(Alignment align);
    void setWidget(Widget.Handle widget);
    void setWidgetResizable(bool resizable);
    Widget.Handle takeWidget();
    Widget.Handle widget();
    bool widgetResizable();
}

Handle create(Widget.Handle parent = null);
