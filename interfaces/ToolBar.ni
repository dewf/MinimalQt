module ToolBar;

import Object;
import Size;
import Point;
import Enums;
import Widget;
import Action;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void actionTriggered(Action.Handle action);
    void allowedAreasChanged(ToolBarAreas allowed);
    void iconSizeChanged(Size.Owned size);
    void movableChanged(bool movable);
    void orientationChanged(Orientation value);
    void toolButtonStyleChanged(ToolButtonStyle style);
    void topLevelChanged(bool topLevel);
    void visibilityChanged(bool visible);
}

opaque Handle extends Widget.Handle {
    Action.Handle actionAt(Point.Handle p);
    Action.Handle actionAt(int x, int y);
    Action.Handle addSeparator();
    Action.Handle addWidget(Widget.Handle widget);
    ToolBarAreas allowedAreas();
    void clear();
    Size.Owned iconSize();
    Action.Handle insertSeparator(Action.Handle before);
    Action.Handle insertWidget(Action.Handle before, Widget.Handle widget);
    bool isAreaAllowed(ToolBarArea area);
    bool isFloatable();
    bool isFloating();
    bool isMovable();
    Orientation orientation();
    void setAllowedAreas(ToolBarAreas areas);
    void setFloatable(bool floatable);
    void setMovable(bool movable);
    void setOrientation(Orientation orientation);
    Action.Handle toggleViewAction();
    ToolButtonStyle getToolButtonStyle();
    Widget.Handle widgetForAction(Action.Handle action);

    void setIconSize(Size.Handle iconSize);
    void setToolButtonStyle(ToolButtonStyle toolButtonStyle);

    // signals ============================
    SignalConnection connect_ActionTriggered(SignalHandler handler);
    SignalConnection connect_AllowedAreasChanged(SignalHandler handler);
    SignalConnection connect_IconSizeChanged(SignalHandler handler);
    SignalConnection connect_MovableChanged(SignalHandler handler);
    SignalConnection connect_OrientationChanged(SignalHandler handler);
    SignalConnection connect_ToolButtonStyleChanged(SignalHandler handler);
    SignalConnection connect_TopLevelChanged(SignalHandler handler);
    SignalConnection connect_VisibilityChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string title, Widget.Handle parent = null);
