module BoxLayout;

import Widget;
import Layout;
import Enums;
import Object;
import LayoutItem;

interface SignalHandler extends Layout.SignalHandler;

enum Direction {
    LeftToRight,
    RightToLeft,
    TopToBottom,
    BottomToTop
}

@dlang_withoverloads(Layout.Handle, addWidget)
opaque Handle extends Layout.Handle {
    void addLayout(Layout.Handle layout, int stretch = 0);

    // void addSpacerItem(QSpacerItem *spacerItem)

    void addSpacing(int size);
    void addStretch(int stretch = 0);
    void addStrut(int size);
    void addWidget(Widget.Handle widget, int stretch = 0, Alignment alignment = 0);
    Direction getDirection();
    void insertItem(int index, LayoutItem.Handle item);
    void insertLayout(int index, Layout.Handle layout, int stretch = 0);

    // void insertSpacerItem(int index, QSpacerItem *spacerItem)

    void insertSpacing(int index, int size);
    void insertStretch(int index, int stretch = 0);
    void insertWidget(int index, Widget.Handle widget, int stretch = 0, Alignment alignment = 0);
    void setDirection(Direction direction);
    void setStretch(int index, int stretch);
    bool setStretchFactor(Widget.Handle widget, int stretch);
    bool setStretchFactor(Layout.Handle layout, int stretch);
    int stretch(int index);
}

Handle create(Direction dir, Widget.Handle parent = null);
