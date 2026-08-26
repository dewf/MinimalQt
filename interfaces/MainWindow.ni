module MainWindow;

import Object;
import Size;
import Enums;
import Widget;
import Layout;
import Menu;
import MenuBar;
import Icon;
import DockWidget;
import ToolBar;
import StatusBar;
import TabWidget;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void iconSizeChanged(Size.Owned iconSize);
    void tabifiedDockWidgetActivated(DockWidget.Handle dockWidget);
    void toolButtonStyleChanged(ToolButtonStyle style);
}

@withflags(DockOptions)
enum DockOption {
    AnimatedDocks = 0x01,
    AllowNestedDocks = 0x02,
    AllowTabbedDocks = 0x04,
    ForceTabbedDocks = 0x08,  // implies AllowTabbedDocks, !AllowNestedDocks
    VerticalTabs = 0x10,      // implies AllowTabbedDocks
    GroupedDragging = 0x20    // implies AllowTabbedDocks
}

opaque Handle extends Widget.Handle {
    void addDockWidget(DockWidgetArea area, DockWidget.Handle dockwidget);
    void addDockWidget(DockWidgetArea area, DockWidget.Handle dockwidget, Orientation orientation);
    void addToolBar(ToolBarArea area, ToolBar.Handle toolbar);
    void addToolBar(ToolBar.Handle toolbar);
    ToolBar.Handle addToolBar(string title);
    void addToolBarBreak(ToolBarArea area = TopToolBarArea);
    Widget.Handle centralWidget();
    DockWidgetArea corner(Corner corner);
    Menu.Handle createPopupMenu();
    DockOptions getDockOptions();
    DockWidgetArea dockWidgetArea(DockWidget.Handle dockwidget);
    bool documentMode();
    Size.Owned iconSize();
    void insertToolBar(ToolBar.Handle before, ToolBar.Handle toolbar);
    void insertToolBarBreak(ToolBar.Handle before);
    bool isAnimated();
    bool isDockNestingEnabled();
    MenuBar.Handle menuBar();
    Widget.Handle menuWidget();
    void removeDockWidget(DockWidget.Handle dockwidget);
    void removeToolBar(ToolBar.Handle toolbar);
    void removeToolBarBreak(ToolBar.Handle before);
    void resizeDocks(Array<DockWidget.Handle> docks, Array<int> sizes, Orientation orientation);
    bool restoreDockWidget(DockWidget.Handle dockwidget);
    bool restoreState(Array<byte> state, int version = 0);
    Array<byte> saveState(int version = 0);
    void setCentralWidget(Widget.Handle widget);
    void setCorner(Corner corner, DockWidgetArea area);
    void setDockOptions(DockOptions options_);
    void setDocumentMode(bool enabled);
    void setIconSize(Size.Handle iconSize);
    void setMenuBar(MenuBar.Handle menuBar);
    void setMenuWidget(Widget.Handle menuBar);
    void setStatusBar(StatusBar.Handle statusbar);
    void setTabPosition(DockWidgetAreas areas, TabPosition tabPosition);
    void setTabShape(TabShape tabShape);
    void setToolButtonStyle(ToolButtonStyle toolButtonStyle);
    void splitDockWidget(DockWidget.Handle first, DockWidget.Handle second, Orientation orientation);
    StatusBar.Handle statusBar();
    TabPosition tabPosition(DockWidgetArea area);
    TabShape tabShape();
    Array<DockWidget.Handle> tabifiedDockWidgets(DockWidget.Handle dockwidget);
    void tabifyDockWidget(DockWidget.Handle first, DockWidget.Handle second);
    Widget.Handle takeCentralWidget();
    ToolBarArea getToolBarArea(ToolBar.Handle toolbar);
    bool toolBarBreak(ToolBar.Handle toolbar);
    ToolButtonStyle toolButtonStyle();
    bool unifiedTitleAndToolBarOnMac();
    void setAnimated(bool enabled);
    void setDockNestingEnabled(bool enabled);
    void setUnifiedTitleAndToolBarOnMac(bool set);

    // signals =========================================
    SignalConnection connect_IconSizeChanged(SignalHandler handler);
    SignalConnection connect_TabifiedDockWidgetActivated(SignalHandler handler);
    SignalConnection connect_ToolButtonStyleChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null, WindowFlags flags_ = 0);

// delegated ==========================================================

namedbits DelegatedMethodMask {
    CanClose,
    Closed,
    Resized
    // TODO: CreatePopupMenu
}

interface DelegatedMethods {
    bool canClose();
    void closed();
    void resized(Size.Owned oldSize, Size.Owned newSize);
}

opaque Delegated extends Handle;
// no protected/interior methods yet

Delegated createDelegated(DelegatedMethods methods, DelegatedMethodMask mask, Widget.Handle parent = null, WindowFlags flags_ = 0);
