module Splitter;

import Object;
import Widget;
import Frame;
import Enums;
import SplitterHandle;

interface SignalHandler extends Frame.SignalHandler {
    void splitterMoved(int pos, int index);
}

struct RangeResult {
    int min;
    int max;
}

opaque Handle extends Frame.Handle {
    void addWidget(Widget.Handle widget);
    bool childrenCollapsible();
    int count();
    RangeResult getRange(int index);
    SplitterHandle.Handle getHandle(int index);
    int handleWidth();
    int indexOf(Widget.Handle widget);
    void insertWidget(int index, Widget.Handle widget);
    bool isCollapsible(int index);
    bool opaqueResize();
    Orientation orientation();
    void refresh();
    Widget.Handle replaceWidget(int index, Widget.Handle widget);
    bool restoreState(Array<byte> state);
    Array<byte> saveState();
    void setChildrenCollapsible(bool value);
    void setCollapsible(int index, bool collapse);
    void setHandleWidth(int width);
    void setOpaqueResize(bool opaque_ = true);
    void setOrientation(Orientation orientation);
    void setSizes(Array<int> list);
    void setStretchFactor(int index, int stretch);
    Array<int> sizes();
    Widget.Handle widget(int index);

    // signals ==================================
    SignalConnection connect_SplitterMoved(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(Orientation orientation, Widget.Handle parent = null);

// to break circular dependency
// also: holy confusing!
extmethods SplitterHandle.Handle {
    Handle splitter();
}
