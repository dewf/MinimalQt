module Window;

import Object;
import Enums;
import Screen;
import Margins;
import Point;
import PointF;
import Size;
import Rect;
import Cursor;
import Icon;
import Region;

enum Visibility {
    Hidden = 0,
    AutomaticVisibility,
    Windowed,
    Minimized,
    Maximized,
    FullScreen
}

enum AncestorMode {
    ExcludeTransients,
    IncludeTransients
}

interface SignalHandler extends Object.SignalHandler {
    void activeChanged();
    void contentOrientationChanged(ScreenOrientation orientation);
    void focusObjectChanged(Object.Handle obj);
    void heightChanged(int arg);
    void maximumHeightChanged(int arg);
    void maximumWidthChanged(int arg);
    void minimumHeightChanged(int arg);
    void minimumWidthChanged(int arg);
    void modalityChanged(WindowModality modality);
    void opacityChanged(double opacity);
    void screenChanged(Screen.Handle screen);
    void transientParentChanged(Handle transientParent);
    void visibilityChanged(Visibility visibility);
    void visibleChanged(bool arg);
    void widthChanged(int arg);
    void windowStateChanged(WindowState windowState);
    void windowTitleChanged(string title);
    void xChanged(int arg);
    void yChanged(int arg);
}

opaque Handle extends Object.Handle {
    Size.Owned baseSize();
    ScreenOrientation contentOrientation();
    void create();
    Cursor.Owned cursor();
    void destroy();
    double devicePixelRatio();
    string filePath();
    WindowFlags flags_();
    Object.Handle focusObject();
    Rect.Owned frameGeometry();
    Margins.Owned frameMargins();
    Point.Owned framePosition();
    Rect.Owned geometry();
    int height();
    Icon.Owned icon();
    bool isActive();
    bool isAncestorOf(Window.Handle child, AncestorMode mode = IncludeTransients);
    bool isExposed();
    bool isModal();
    bool isTopLevel();
    bool isVisible();
    PointF.Owned mapFromGlobal(PointF.Handle pos);
    Point.Owned mapFromGlobal(Point.Handle pos);
    PointF.Owned mapToGlobal(PointF.Handle pos);
    Point.Owned mapToGlobal(Point.Handle pos);
    Region.Owned mask();
    int maximumHeight();
    Size.Owned maximumSize();
    int maximumWidth();
    int minimumHeight();
    Size.Owned minimumSize();
    int minimumWidth();
    WindowModality modality();
    double opacity();
    Window.Handle parent(AncestorMode mode = ExcludeTransients);
    Point.Owned position();
    void reportContentOrientationChange(ScreenOrientation orientation);

    // QSurfaceFormat requestedFormat() const
    // TODO

    void resize(Size.Handle newSize);
    void resize(int w, int h);
    Screen.Handle screen();
    void setBaseSize(Size.Handle size);
    void setCursor(Cursor.Handle cursor);
    void setFilePath(string filePath);
    void setFlag(WindowType flag, bool on = true);
    void setFlags(WindowFlags flags_);

    // void setFormat(const QSurfaceFormat &format)
    // TODO

    void setFramePosition(Point.Handle point);
    void setIcon(Icon.Handle icon);
    bool setKeyboardGrabEnabled(bool grab);
    void setMask(Region.Handle region);
    void setMaximumSize(Size.Handle size);
    void setMinimumSize(Size.Handle size);
    void setModality(WindowModality modality);
    bool setMouseGrabEnabled(bool grab);
    void setOpacity(double level);
    void setParent(Window.Handle parent);
    void setPosition(Point.Handle pt);
    void setPosition(int posx, int posy);
    void setScreen(Screen.Handle newScreen);
    void setSizeIncrement(Size.Handle size);

    // void setSurfaceType(QSurface::SurfaceType surfaceType)
    // TODO

    void setTransientParent(Window.Handle parent);
    void setVisibility(Visibility v);

    // void setVulkanInstance(QVulkanInstance *instance)
    // TODO

    void setWindowState(WindowState state);
    void setWindowStates(WindowStates states);
    Size.Owned sizeIncrement();
    string title();
    Window.Handle transientParent();
    WindowType type();
    void unsetCursor();
    Visibility getVisibility();

    // QVulkanInstance * vulkanInstance() const
    // TODO

    int width();
    WIN_ID winId();
    WindowState getWindowState();
    WindowStates getWindowStates();
    int x();
    int y();

    // slots ==================================

    void alert(int msec);
    bool close();
    void hide();
    void lower();
    void raise();
    void requestActivate();
    void requestUpdate();
    void setGeometry(Rect.Handle rect);
    void setGeometry(int posx, int posy, int w, int h);
    void setHeight(int height);
    void setMaximumHeight(int height);
    void setMaximumWidth(int width);
    void setMinimumHeight(int height);
    void setMinimumWidth(int width);
    void setTitle(string title);
    void setVisible(bool visible);
    void setWidth(int width);
    void setX(int x);
    void setY(int y);
    void show();
    void showFullScreen();
    void showMaximized();
    void showMinimized();
    void showNormal();
    bool startSystemMove();
    bool startSystemResize(Edges edges);

    // signals ================================
    SignalConnection connect_ActiveChanged(SignalHandler handler);
    SignalConnection connect_ContentOrientationChanged(SignalHandler handler);
    SignalConnection connect_FocusObjectChanged(SignalHandler handler);
    SignalConnection connect_HeightChanged(SignalHandler handler);
    SignalConnection connect_MaximumHeightChanged(SignalHandler handler);
    SignalConnection connect_MaximumWidthChanged(SignalHandler handler);
    SignalConnection connect_MinimumHeightChanged(SignalHandler handler);
    SignalConnection connect_MinimumWidthChanged(SignalHandler handler);
    SignalConnection connect_ModalityChanged(SignalHandler handler);
    SignalConnection connect_OpacityChanged(SignalHandler handler);
    SignalConnection connect_ScreenChanged(SignalHandler handler);
    SignalConnection connect_TransientParentChanged(SignalHandler handler);
    SignalConnection connect_VisibilityChanged(SignalHandler handler);
    SignalConnection connect_VisibleChanged(SignalHandler handler);
    SignalConnection connect_WidthChanged(SignalHandler handler);
    SignalConnection connect_WindowStateChanged(SignalHandler handler);
    SignalConnection connect_WindowTitleChanged(SignalHandler handler);
    SignalConnection connect_XChanged(SignalHandler handler);
    SignalConnection connect_YChanged(SignalHandler handler);
}

Handle create(Screen.Handle targetScreen = null);
Handle create(Handle parent);

// static methods ==============================
Handle fromWinId(WIN_ID id);
