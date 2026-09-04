module AbstractScrollArea;

import Object;
import Size;
import Icon;
import Frame;
import Enums;
import ScrollBar;
import Widget;

@methodprefix("sig_")
interface SignalHandler extends Frame.SignalHandler;
// no extra signals

enum SizeAdjustPolicy {
    AdjustIgnored,
    AdjustToContentsOnFirstShow,
    AdjustToContents
}

@nodispose
opaque Handle extends Frame.Handle {
    void addScrollBarWidget(Widget.Handle widget, Alignment alignment);
    Widget.Handle cornerWidget();
    ScrollBar.Handle horizontalScrollBar();
    ScrollBarPolicy horizontalScrollBarPolicy();
    Size.Owned maximumViewportSize();
    Array<Widget.Handle> scrollBarWidgets(Alignment alignment);
    void setCornerWidget(Widget.Handle widget);
    void setHorizontalScrollBar(ScrollBar.Handle scrollBar);
    void setHorizontalScrollBarPolicy(ScrollBarPolicy policy);
    void setSizeAdjustPolicy(SizeAdjustPolicy policy);
    void setVerticalScrollBar(ScrollBar.Handle scrollBar);
    void setVerticalScrollBarPolicy(ScrollBarPolicy policy);
    void setViewport(Widget.Handle widget);
    void setupViewport(Widget.Handle viewport);
    SizeAdjustPolicy getSizeAdjustPolicy(); // 'get' otherwise it conflicts with the enum in C#
    ScrollBar.Handle verticalScrollBar();
    ScrollBarPolicy verticalScrollBarPolicy();
    Widget.Handle viewport();
}

// no create
