module TabBar;

import Object;
import Size;
import Point;
import Rect;
import Icon;
import Widget;
import Enums;
import Variant;
import Color;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void currentChanged(int index);
    void tabBarClicked(int index);
    void tabBarDoubleClicked(int index);
    void tabCloseRequested(int index);
    void tabMoved(int fromIndex, int toIndex);
}

enum ButtonPosition {
    LeftSide,
    RightSide
}

enum SelectionBehavior {
    SelectLeftTab,
    SelectRightTab,
    SelectPreviousTab
}

enum Shape {
    RoundedNorth,
    RoundedSouth,
    RoundedWest,
    RoundedEast,
    TriangularNorth,
    TriangularSouth,
    TriangularWest,
    TriangularEast
}

opaque Handle extends Widget.Handle {

    string accessibleTabName(int index);
    int addTab(string text);
    int addTab(Icon.Handle icon, string text);
    bool autoHide();
    bool changeCurrentOnDrag();
    int count();
    int currentIndex();
    bool documentMode();
    bool drawBase();
    TextElideMode elideMode();
    bool expanding();
    Size.Owned iconSize();
    int insertTab(int index, string text);
    int insertTab(int index, Icon.Handle icon, string text);
    bool isMovable();
    bool isTabEnabled(int index);
    bool isTabVisible(int index);
    void moveTab(int from, int to);
    void removeTab(int index);
    SelectionBehavior selectionBehaviorOnRemove();
    void setAccessibleTabName(int index, string name);
    void setAutoHide(bool hide);
    void setChangeCurrentOnDrag(bool change);
    void setDocumentMode(bool set);
    void setDrawBase(bool drawTheBase);
    void setElideMode(TextElideMode mode);
    void setExpanding(bool enabled);
    void setIconSize(Size.Handle size);
    void setMovable(bool movable);
    void setSelectionBehaviorOnRemove(SelectionBehavior behavior);
    void setShape(Shape shape);
    void setTabButton(int index, ButtonPosition position, Widget.Handle widget);
    void setTabData(int index, Variant.Handle data);
    void setTabEnabled(int index, bool enabled);
    void setTabIcon(int index, Icon.Handle icon);
    void setTabText(int index, string text);
    void setTabTextColor(int index, Color.Handle color);
    void setTabToolTip(int index, string tip);
    void setTabVisible(int index, bool visible);
    void setTabWhatsThis(int index, string text);
    void setTabsClosable(bool closable);
    void setUsesScrollButtons(bool useButtons);
    Shape getShape();
    int tabAt(Point.Handle position);
    Widget.Handle tabButton(int index, ButtonPosition position);
    Variant.Owned tabData(int index);
    Icon.Owned tabIcon(int index);
    Rect.Owned tabRect(int index);
    string tabText(int index);
    Color.Owned tabTextColor(int index);
    string tabToolTip(int index);
    string tabWhatsThis(int index);
    bool tabsClosable();
    bool usesScrollButtons();

    void setCurrentIndex(int index);

    // signals ============================
    SignalConnection connect_CurrentChanged(SignalHandler handler);
    SignalConnection connect_TabBarClicked(SignalHandler handler);
    SignalConnection connect_TabBarDoubleClicked(SignalHandler handler);
    SignalConnection connect_TabCloseRequested(SignalHandler handler);
    SignalConnection connect_TabMoved(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
