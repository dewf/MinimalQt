#include "generated/Window.h"
#include "WindowInternal.h"

#include "ObjectInternal.h"
#include "CursorInternal.h"
#include "IconInternal.h"
#include "PointInternal.h"
#include "PointFInternal.h"
#include "RegionInternal.h"
#include "SizeInternal.h"
#include "RectInternal.h"
#include "MarginsInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Enums;
using namespace ::Screen;
using namespace ::Common;
using namespace ::Margins;
using namespace ::Point;
using namespace ::PointF;
using namespace ::Size;
using namespace ::Rect;
using namespace ::Cursor;
using namespace ::Icon;
using namespace ::Region;

#define THIS (reinterpret_cast<QWindow*>(_this))

namespace Window
{
    Size::OwnedRef Handle_baseSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->baseSize());
    }

    ScreenOrientation Handle_contentOrientation(HandleRef _this) {
        return static_cast<ScreenOrientation>(THIS->contentOrientation());
    }

    void Handle_create(HandleRef _this) {
        THIS->create();
    }

    Cursor::OwnedRef Handle_cursor(HandleRef _this) {
        return CURSOR_HEAP_NEW(THIS->cursor());
    }

    void Handle_destroy(HandleRef _this) {
        THIS->destroy();
    }

    double Handle_devicePixelRatio(HandleRef _this) {
        return THIS->devicePixelRatio();
    }

    std::string Handle_filePath(HandleRef _this) {
        return THIS->filePath().toStdString();
    }

    WindowFlags Handle_flags_(HandleRef _this) {
        return WindowFlags(THIS->flags());
    }

    Object::HandleRef Handle_focusObject(HandleRef _this) {
        return reinterpret_cast<Object::HandleRef>(THIS->focusObject());
    }

    Rect::OwnedRef Handle_frameGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->frameGeometry());
    }

    Margins::OwnedRef Handle_frameMargins(HandleRef _this) {
        return MARGINS_HEAP_NEW(THIS->frameMargins());
    }

    Point::OwnedRef Handle_framePosition(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->framePosition());
    }

    Rect::OwnedRef Handle_geometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->geometry());
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    Icon::OwnedRef Handle_icon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    bool Handle_isActive(HandleRef _this) {
        return THIS->isActive();
    }

    bool Handle_isAncestorOf(HandleRef _this, HandleRef child, AncestorMode mode /* AncestorMode::IncludeTransients */) {
        return THIS->isAncestorOf(reinterpret_cast<QWindow*>(child), static_cast<QWindow::AncestorMode>(mode));
    }

    bool Handle_isExposed(HandleRef _this) {
        return THIS->isExposed();
    }

    bool Handle_isModal(HandleRef _this) {
        return THIS->isModal();
    }

    bool Handle_isTopLevel(HandleRef _this) {
        return THIS->isTopLevel();
    }

    bool Handle_isVisible(HandleRef _this) {
        return THIS->isVisible();
    }

    PointF::OwnedRef Handle_mapFromGlobal(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapFromGlobal(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapFromGlobal(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapFromGlobal(QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapToGlobal(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapToGlobal(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapToGlobal(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapToGlobal(QPOINT_VALUE(pos)));
    }

    Region::OwnedRef Handle_mask(HandleRef _this) {
        return REGION_HEAP_NEW(THIS->mask());
    }

    int32_t Handle_maximumHeight(HandleRef _this) {
        return THIS->maximumHeight();
    }

    Size::OwnedRef Handle_maximumSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->maximumSize());
    }

    int32_t Handle_maximumWidth(HandleRef _this) {
        return THIS->maximumWidth();
    }

    int32_t Handle_minimumHeight(HandleRef _this) {
        return THIS->minimumHeight();
    }

    Size::OwnedRef Handle_minimumSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->minimumSize());
    }

    int32_t Handle_minimumWidth(HandleRef _this) {
        return THIS->minimumWidth();
    }

    WindowModality Handle_modality(HandleRef _this) {
        return static_cast<WindowModality>(THIS->modality());
    }

    double Handle_opacity(HandleRef _this) {
        return THIS->opacity();
    }

    HandleRef Handle_parent(HandleRef _this, AncestorMode mode /* AncestorMode::ExcludeTransients */) {
        return reinterpret_cast<HandleRef>(THIS->parent(static_cast<QWindow::AncestorMode>(mode)));
    }

    Point::OwnedRef Handle_position(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->position());
    }

    void Handle_reportContentOrientationChange(HandleRef _this, ScreenOrientation orientation) {
        THIS->reportContentOrientationChange(static_cast<Qt::ScreenOrientation>(orientation));
    }

    void Handle_resize(HandleRef _this, Size::HandleRef newSize) {
        THIS->resize(QSIZE_VALUE(newSize));
    }

    void Handle_resize(HandleRef _this, int32_t w, int32_t h) {
        THIS->resize(w, h);
    }

    Screen::HandleRef Handle_screen(HandleRef _this) {
        return reinterpret_cast<Screen::HandleRef>(THIS->screen());
    }

    void Handle_setBaseSize(HandleRef _this, Size::HandleRef size) {
        THIS->setBaseSize(QSIZE_VALUE(size));
    }

    void Handle_setCursor(HandleRef _this, Cursor::HandleRef cursor) {
        THIS->setCursor(QCURSOR_VALUE(cursor));
    }

    void Handle_setFilePath(HandleRef _this, const std::string& filePath) {
        THIS->setFilePath(QString::fromStdString(filePath));
    }

    void Handle_setFlag(HandleRef _this, WindowType flag, bool on /* true */) {
        THIS->setFlag(static_cast<Qt::WindowType>(flag), on);
    }

    void Handle_setFlags(HandleRef _this, WindowFlags flags_) {
        THIS->setFlags(static_cast<Qt::WindowFlags>(flags_.value));
    }

    void Handle_setFramePosition(HandleRef _this, Point::HandleRef point) {
        THIS->setFramePosition(QPOINT_VALUE(point));
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    bool Handle_setKeyboardGrabEnabled(HandleRef _this, bool grab) {
        return THIS->setKeyboardGrabEnabled(grab);
    }

    void Handle_setMask(HandleRef _this, Region::HandleRef region) {
        THIS->setMask(QREGION_VALUE(region));
    }

    void Handle_setMaximumSize(HandleRef _this, Size::HandleRef size) {
        THIS->setMaximumSize(QSIZE_VALUE(size));
    }

    void Handle_setMinimumSize(HandleRef _this, Size::HandleRef size) {
        THIS->setMinimumSize(QSIZE_VALUE(size));
    }

    void Handle_setModality(HandleRef _this, WindowModality modality) {
        THIS->setModality(static_cast<Qt::WindowModality>(modality));
    }

    bool Handle_setMouseGrabEnabled(HandleRef _this, bool grab) {
        return THIS->setMouseGrabEnabled(grab);
    }

    void Handle_setOpacity(HandleRef _this, double level) {
        THIS->setOpacity(level);
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        THIS->setParent(reinterpret_cast<QWindow*>(parent));
    }

    void Handle_setPosition(HandleRef _this, Point::HandleRef pt) {
        THIS->setPosition(QPOINT_VALUE(pt));
    }

    void Handle_setPosition(HandleRef _this, int32_t posx, int32_t posy) {
        THIS->setPosition(posx, posy);
    }

    void Handle_setScreen(HandleRef _this, Screen::HandleRef newScreen) {
        THIS->setScreen(reinterpret_cast<QScreen*>(newScreen));
    }

    void Handle_setSizeIncrement(HandleRef _this, Size::HandleRef size) {
        THIS->setSizeIncrement(QSIZE_VALUE(size));
    }

    void Handle_setTransientParent(HandleRef _this, HandleRef parent) {
        THIS->setTransientParent(reinterpret_cast<QWindow*>(parent));
    }

    void Handle_setVisibility(HandleRef _this, Visibility v) {
        THIS->setVisibility(static_cast<QWindow::Visibility>(v));
    }

    void Handle_setWindowState(HandleRef _this, WindowState state) {
        THIS->setWindowState(static_cast<Qt::WindowState>(state));
    }

    void Handle_setWindowStates(HandleRef _this, WindowStates states) {
        THIS->setWindowStates(static_cast<Qt::WindowStates>(states.value));
    }

    Size::OwnedRef Handle_sizeIncrement(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->sizeIncrement());
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    HandleRef Handle_transientParent(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->transientParent());
    }

    WindowType Handle_type(HandleRef _this) {
        return static_cast<WindowType>(THIS->type());
    }

    void Handle_unsetCursor(HandleRef _this) {
        THIS->unsetCursor();
    }

    Visibility Handle_getVisibility(HandleRef _this) {
        return static_cast<Visibility>(THIS->visibility());
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    WIN_ID Handle_winId(HandleRef _this) {
        return THIS->winId();
    }

    WindowState Handle_getWindowState(HandleRef _this) {
        return static_cast<WindowState>(THIS->windowState());
    }

    WindowStates Handle_getWindowStates(HandleRef _this) {
        return WindowStates(THIS->windowStates());
    }

    int32_t Handle_x(HandleRef _this) {
        return THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return THIS->y();
    }

    // slots ====================

    void Handle_alert(HandleRef _this, int32_t msec) {
        THIS->alert(msec);
    }

    bool Handle_close(HandleRef _this) {
        return THIS->close();
    }

    void Handle_hide(HandleRef _this) {
        THIS->hide();
    }

    void Handle_lower(HandleRef _this) {
        THIS->lower();
    }

    void Handle_raise(HandleRef _this) {
        THIS->raise();
    }

    void Handle_requestActivate(HandleRef _this) {
        THIS->requestActivate();
    }

    void Handle_requestUpdate(HandleRef _this) {
        THIS->requestUpdate();
    }

    void Handle_setGeometry(HandleRef _this, Rect::HandleRef rect) {
        THIS->setGeometry(QRECT_VALUE(rect));
    }

    void Handle_setGeometry(HandleRef _this, int32_t posx, int32_t posy, int32_t w, int32_t h) {
        THIS->setGeometry(posx, posy, w, h);
    }

    void Handle_setHeight(HandleRef _this, int32_t height) {
        THIS->setHeight(height);
    }

    void Handle_setMaximumHeight(HandleRef _this, int32_t height) {
        THIS->setMaximumHeight(height);
    }

    void Handle_setMaximumWidth(HandleRef _this, int32_t width) {
        THIS->setMaximumWidth(width);
    }

    void Handle_setMinimumHeight(HandleRef _this, int32_t height) {
        THIS->setMinimumHeight(height);
    }

    void Handle_setMinimumWidth(HandleRef _this, int32_t width) {
        THIS->setMinimumWidth(width);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    void Handle_setWidth(HandleRef _this, int32_t width) {
        THIS->setWidth(width);
    }

    void Handle_setX(HandleRef _this, int32_t x) {
        THIS->setX(x);
    }

    void Handle_setY(HandleRef _this, int32_t y) {
        THIS->setY(y);
    }

    void Handle_show(HandleRef _this) {
        THIS->show();
    }

    void Handle_showFullScreen(HandleRef _this) {
        THIS->showFullScreen();
    }

    void Handle_showMaximized(HandleRef _this) {
        THIS->showMaximized();
    }

    void Handle_showMinimized(HandleRef _this) {
        THIS->showMinimized();
    }

    void Handle_showNormal(HandleRef _this) {
        THIS->showNormal();
    }

    bool Handle_startSystemMove(HandleRef _this) {
        return THIS->startSystemMove();
    }

    bool Handle_startSystemResize(HandleRef _this, Edges edges) {
        return THIS->startSystemResize(static_cast<Qt::Edges>(edges.value));
    }

    SignalConnectionRef Handle_connect_ActiveChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::activeChanged, [handler] {
            handler->activeChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ContentOrientationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::contentOrientationChanged, [handler](Qt::ScreenOrientation orientation) {
            handler->contentOrientationChanged(static_cast<ScreenOrientation>(orientation));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_FocusObjectChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::focusObjectChanged, [handler](QObject *object) {
            handler->focusObjectChanged(reinterpret_cast<Object::HandleRef>(object));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_HeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::heightChanged, [handler](int arg) {
            handler->heightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MaximumHeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::maximumHeightChanged, [handler](int arg) {
            handler->maximumHeightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MaximumWidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::maximumWidthChanged, [handler](int arg) {
            handler->maximumWidthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MinimumHeightChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::minimumHeightChanged, [handler](int arg) {
            handler->minimumHeightChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_MinimumWidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::minimumWidthChanged, [handler](int arg) {
            handler->minimumWidthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModalityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::modalityChanged, [handler](Qt::WindowModality modality) {
            handler->modalityChanged(static_cast<WindowModality>(modality));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_OpacityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::opacityChanged, [handler](qreal opacity) {
            handler->opacityChanged(opacity);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ScreenChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::screenChanged, [handler](QScreen *screen) {
            handler->screenChanged(reinterpret_cast<Screen::HandleRef>(screen));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TransientParentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::transientParentChanged, [handler](QWindow *transientParent) {
            handler->transientParentChanged(reinterpret_cast<HandleRef>(transientParent));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibilityChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::visibilityChanged, [handler](QWindow::Visibility visibility) {
            handler->visibilityChanged(static_cast<Visibility>(visibility));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_VisibleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::visibleChanged, [handler](bool arg) {
            handler->visibleChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WidthChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::widthChanged, [handler](int arg) {
            handler->widthChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowStateChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::windowStateChanged, [handler](Qt::WindowState windowState) {
            handler->windowStateChanged(static_cast<WindowState>(windowState));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowTitleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::windowTitleChanged, [handler](const QString &title) {
            handler->windowTitleChanged(title.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_XChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::xChanged, [handler](int arg) {
            handler->xChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_YChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWindow::yChanged, [handler](int arg) {
            handler->yChanged(arg);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Screen::HandleRef targetScreen /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QWindow(reinterpret_cast<QScreen*>(targetScreen)));
    }

    HandleRef create(HandleRef parent) {
        return reinterpret_cast<HandleRef>(new QWindow(reinterpret_cast<QWindow*>(parent)));
    }

    // static methods ====================
    HandleRef fromWinId(WIN_ID id) {
        return reinterpret_cast<HandleRef>(QWindow::fromWinId(id));
    }
}
