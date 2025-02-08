#include "generated/Widget.h"
#include "WidgetInternal.h"

#include "PainterInternal.h"
#include "ObjectInternal.h"
#include "ActionInternal.h"
#include "FontInternal.h"
#include "IconInternal.h"
#include "SizePolicyInternal.h"
#include "CursorInternal.h"
#include "KeySequenceInternal.h"
#include "LayoutInternal.h"
#include "MimeDataInternal.h"
#include "PixmapInternal.h"
#include "RegionInternal.h"
#include "ScreenInternal.h"
#include "VariantInternal.h"
#include "PointFInternal.h"
#include "PointInternal.h"
#include "SizeInternal.h"
#include "SafeReturnInternal.h"
#include "RectInternal.h"
#include "Margins2Internal.h"

#include <QPaintEvent>

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Margins2;
using namespace ::Point;
using namespace ::PointF;
using namespace ::Size;
using namespace ::Rect;
using namespace ::Layout;
using namespace ::Painter;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::Action;
using namespace ::Region;
using namespace ::Cursor;
using namespace ::SizePolicy;
using namespace ::Font;
using namespace ::MimeData;
using namespace ::KeySequence;
using namespace ::Pixmap;
using namespace ::GraphicsEffect;
using namespace ::PaintDevice;
using namespace ::Variant;
using namespace ::Event;
using namespace ::Window;
using namespace ::Screen;
using namespace ::SafeReturn;

#define THIS (reinterpret_cast<QWidget*>(_this))

namespace Widget
{
    const int32_t WIDGET_SIZE_MAX = QWIDGETSIZE_MAX;

    PaintDevice::HandleRef Handle_asPaintDevice(HandleRef _this) {
        return reinterpret_cast<PaintDevice::HandleRef>(_this);
    }

    bool Handle_acceptDrops(HandleRef _this) {
        return THIS->acceptDrops();
    }

    std::string Handle_accessibleDescription(HandleRef _this) {
        return THIS->accessibleDescription().toStdString();
    }

    std::string Handle_accessibleName(HandleRef _this) {
        return THIS->accessibleName().toStdString();
    }

    std::vector<Action::HandleRef> Handle_actions(HandleRef _this) {
        return fromQList<QAction*,Action::HandleRef>(THIS->actions(), [](auto action) {
            return reinterpret_cast<Action::HandleRef>(action);
        });
    }

    void Handle_activateWindow(HandleRef _this) {
        THIS->activateWindow();
    }

    void Handle_addAction(HandleRef _this, Action::HandleRef action) {
        THIS->addAction(AS_QACTION_PTR(action));
    }

    Action::HandleRef Handle_addAction(HandleRef _this, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->addAction(QString::fromStdString(text)));
    }

    Action::HandleRef Handle_addAction(HandleRef _this, Icon::HandleRef icon, const std::string& text) {
        return reinterpret_cast<Action::HandleRef>(THIS->addAction(QICON_VALUE(icon), QString::fromStdString(text)));
    }

    Action::HandleRef Handle_addAction(HandleRef _this, const std::string& text, KeySequence::HandleRef shortcut) {
        return reinterpret_cast<Action::HandleRef>(THIS->addAction(QString::fromStdString(text), QKEYSEQ_VALUE(shortcut)));
    }

    Action::HandleRef Handle_addAction(HandleRef _this, Icon::HandleRef icon, const std::string& text, KeySequence::HandleRef shortcut) {
        return reinterpret_cast<Action::HandleRef>(THIS->addAction(QICON_VALUE(icon), QString::fromStdString(text), QKEYSEQ_VALUE(shortcut)));
    }

    void Handle_addActions(HandleRef _this, const std::vector<Action::HandleRef>& actions) {
        const auto qActions = toQList<Action::HandleRef,QAction*>(actions, [](auto action) {
            return AS_QACTION_PTR(action);
        });
        THIS->addActions(qActions);
    }

    void Handle_adjustSize(HandleRef _this) {
        THIS->adjustSize();
    }

    bool Handle_autoFillBackground(HandleRef _this) {
        return THIS->autoFillBackground();
    }

    Size::OwnedRef Handle_baseSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->baseSize());
    }

    HandleRef Handle_childAt(HandleRef _this, int32_t x, int32_t y) {
        return reinterpret_cast<HandleRef>(THIS->childAt(x, y));
    }

    HandleRef Handle_childAt(HandleRef _this, Point::HandleRef p) {
        return reinterpret_cast<HandleRef>(THIS->childAt(QPOINT_VALUE(p)));
    }

    HandleRef Handle_childAt(HandleRef _this, PointF::HandleRef p) {
        return reinterpret_cast<HandleRef>(THIS->childAt(QPOINTF_VALUE(p)));
    }

    Rect::OwnedRef Handle_childrenRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->childrenRect());
    }

    Region::OwnedRef Handle_childrenRegion(HandleRef _this) {
        return REGION_HEAP_NEW(THIS->childrenRegion());
    }

    void Handle_clearFocus(HandleRef _this) {
        THIS->clearFocus();
    }

    void Handle_clearMask(HandleRef _this) {
        THIS->clearMask();
    }

    Margins2::OwnedRef Handle_contentsMargins(HandleRef _this) {
        return MARGINS_HEAP_NEW(THIS->contentsMargins());
    }

    Rect::OwnedRef Handle_contentsRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->contentsRect());
    }

    ContextMenuPolicy Handle_contextMenuPolicy(HandleRef _this) {
        return static_cast<ContextMenuPolicy>(THIS->contextMenuPolicy());
    }

    Cursor::OwnedRef Handle_cursor(HandleRef _this) {
        return CURSOR_HEAP_NEW(THIS->cursor());
    }

    WIN_ID Handle_effectiveWinId(HandleRef _this) {
        return THIS->effectiveWinId();
    }

    void Handle_ensurePolished(HandleRef _this) {
        THIS->ensurePolished();
    }

    FocusPolicy Handle_focusPolicy(HandleRef _this) {
        return THIS->focusPolicy();
    }

    HandleRef Handle_focusProxy(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->focusProxy());
    }

    HandleRef Handle_focusWidget(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->focusWidget());
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    Rect::OwnedRef Handle_frameGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->frameGeometry());
    }

    Size::OwnedRef Handle_frameSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->frameSize());
    }

    Rect::OwnedRef Handle_geometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->geometry());
    }

    Pixmap::OwnedRef Handle_grab(HandleRef _this, const std::optional<Rect::HandleRef>& rectangle) {
        auto qRect = QRect(QPoint(0, 0), QSize(-1, -1));
        if (rectangle.has_value()) qRect = QRECT_VALUE(rectangle.value());
        return PIXMAP_HEAP_NEW(THIS->grab(qRect));
    }

    void Handle_grabGesture(HandleRef _this, GestureType gesture, GestureFlags flags_ /* 0 */) {
        THIS->grabGesture(static_cast<Qt::GestureType>(gesture), static_cast<Qt::GestureFlags>(flags_.value));
    }

    void Handle_grabKeyboard(HandleRef _this) {
        THIS->grabKeyboard();
    }

    void Handle_grabMouse(HandleRef _this) {
        THIS->grabMouse();
    }

    void Handle_grabMouse(HandleRef _this, Cursor::HandleRef cursor) {
        THIS->grabMouse(QCURSOR_VALUE(cursor));
    }

    int32_t Handle_grabShortcut(HandleRef _this, KeySequence::HandleRef key, ShortcutContext context /* ShortcutContext::WindowShortcut */) {
        return THIS->grabShortcut(QKEYSEQ_VALUE(key), static_cast<Qt::ShortcutContext>(context));
    }

    GraphicsEffect::HandleRef Handle_graphicsEffect(HandleRef _this) {
        return reinterpret_cast<GraphicsEffect::HandleRef>(THIS->graphicsEffect());
    }

    // only for embedded linux:
    // bool Handle_hasEditFocus(HandleRef _this) {
    //     return false;
    // }

    bool Handle_hasFocus(HandleRef _this) {
        return THIS->hasFocus();
    }

    bool Handle_hasHeightForWidth(HandleRef _this) {
        return THIS->hasHeightForWidth();
    }

    bool Handle_hasMouseTracking(HandleRef _this) {
        return THIS->hasMouseTracking();
    }

    bool Handle_hasTabletTracking(HandleRef _this) {
        return THIS->hasTabletTracking();
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    int32_t Handle_heightForWidth(HandleRef _this, int32_t w) {
        return THIS->heightForWidth(w);
    }

    InputMethodHints Handle_inputMethodHints(HandleRef _this) {
        return InputMethodHints(THIS->inputMethodHints());
    }

    Variant::OwnedRef Handle_inputMethodQuery(HandleRef _this, InputMethodQuery query) {
        return VARIANT_HEAP_NEW(THIS->inputMethodQuery(static_cast<Qt::InputMethodQuery>(query)));
    }

    void Handle_insertAction(HandleRef _this, Action::HandleRef before, Action::HandleRef action) {
        THIS->insertAction(AS_QACTION_PTR(before), AS_QACTION_PTR(action));
    }

    void Handle_insertActions(HandleRef _this, Action::HandleRef before, const std::vector<Action::HandleRef>& actions) {
        const auto qActions = toQList<Action::HandleRef,QAction*>(actions, [](auto action) {
            return AS_QACTION_PTR(action);
        });
        THIS->insertActions(AS_QACTION_PTR(before), qActions);
    }

    bool Handle_isActiveWindow(HandleRef _this) {
        return THIS->isActiveWindow();
    }

    bool Handle_isAncestorOf(HandleRef _this, HandleRef child) {
        return THIS->isAncestorOf(AS_QWIDGET_PTR(child));
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    bool Handle_isEnabledTo(HandleRef _this, HandleRef ancestor) {
        return THIS->isEnabledTo(AS_QWIDGET_PTR(ancestor));
    }

    bool Handle_isFullScreen(HandleRef _this) {
        return THIS->isFullScreen();
    }

    bool Handle_isHidden(HandleRef _this) {
        return THIS->isHidden();
    }

    bool Handle_isMaximized(HandleRef _this) {
        return THIS->isMaximized();
    }

    bool Handle_isMinimized(HandleRef _this) {
        return THIS->isMinimized();
    }

    bool Handle_isModal(HandleRef _this) {
        return THIS->isModal();
    }

    bool Handle_isVisible(HandleRef _this) {
        return THIS->isVisible();
    }

    bool Handle_isVisibleTo(HandleRef _this, HandleRef ancestor) {
        return THIS->isVisibleTo(AS_QWIDGET_PTR(ancestor));
    }

    bool Handle_isWindow(HandleRef _this) {
        return THIS->isWindow();
    }

    bool Handle_isWindowModified(HandleRef _this) {
        return THIS->isWindowModified();
    }

    Layout::HandleRef Handle_layout(HandleRef _this) {
        return reinterpret_cast<Layout::HandleRef>(THIS->layout());
    }

    LayoutDirection Handle_layoutDirection(HandleRef _this) {
        return static_cast<LayoutDirection>(THIS->layoutDirection());
    }

    PointF::OwnedRef Handle_mapFrom(HandleRef _this, HandleRef parent, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapFrom(AS_QWIDGET_PTR(parent), QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapFrom(HandleRef _this, HandleRef parent, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapFrom(AS_QWIDGET_PTR(parent), QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapFromGlobal(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapFromGlobal(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapFromGlobal(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapFromGlobal(QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapFromParent(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapFromParent(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapFromParent(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapFromParent(QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapTo(HandleRef _this, HandleRef parent, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapTo(AS_QWIDGET_PTR(parent), QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapTo(HandleRef _this, HandleRef parent, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapTo(AS_QWIDGET_PTR(parent), QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapToGlobal(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapToGlobal(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapToGlobal(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapToGlobal(QPOINT_VALUE(pos)));
    }

    PointF::OwnedRef Handle_mapToParent(HandleRef _this, PointF::HandleRef pos) {
        return POINTF_HEAP_NEW(THIS->mapToParent(QPOINTF_VALUE(pos)));
    }

    Point::OwnedRef Handle_mapToParent(HandleRef _this, Point::HandleRef pos) {
        return POINT_HEAP_NEW(THIS->mapToParent(QPOINT_VALUE(pos)));
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

    Size::OwnedRef Handle_minimumSizeHint(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->minimumSizeHint());
    }

    int32_t Handle_minimumWidth(HandleRef _this) {
        return THIS->minimumWidth();
    }

    void Handle_move(HandleRef _this, Point::HandleRef p) {
        THIS->move(QPOINT_VALUE(p));
    }

    void Handle_move(HandleRef _this, int32_t x, int32_t y) {
        THIS->move(x, y);
    }

    HandleRef Handle_nativeParentWidget(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->nativeParentWidget());
    }

    HandleRef Handle_nextInFocusChain(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->nextInFocusChain());
    }

    Rect::OwnedRef Handle_normalGeometry(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->normalGeometry());
    }

    void Handle_overrideWindowFlags(HandleRef _this, WindowFlags flags_) {
        THIS->overrideWindowFlags(static_cast<Qt::WindowFlags>(flags_.value));
    }

    HandleRef Handle_parentWidget(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->parentWidget());
    }

    Point::OwnedRef Handle_pos(HandleRef _this) {
        return POINT_HEAP_NEW(THIS->pos());
    }

    HandleRef Handle_previousInFocusChain(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->previousInFocusChain());
    }

    Rect::OwnedRef Handle_rect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->rect());
    }

    void Handle_releaseKeyboard(HandleRef _this) {
        THIS->releaseKeyboard();
    }

    void Handle_releaseMouse(HandleRef _this) {
        THIS->releaseMouse();
    }

    void Handle_releaseShortcut(HandleRef _this, int32_t id) {
        THIS->releaseShortcut(id);
    }

    void Handle_removeAction(HandleRef _this, Action::HandleRef action) {
        THIS->removeAction(AS_QACTION_PTR(action));
    }

    void Handle_render(HandleRef _this, PaintDevice::HandleRef target, const std::optional<Point::HandleRef>& targetOffset, const std::optional<Region::HandleRef>& sourceRegion, RenderFlags renderFlags /* RenderFlags::DrawWindowBackground | RenderFlags::DrawChildren */) {
        QPoint qTargetOffset;
        if (targetOffset.has_value()) qTargetOffset = QPOINT_VALUE(targetOffset.value());
        QRegion qSourceRegion;
        if (sourceRegion.has_value()) qSourceRegion = QREGION_VALUE(sourceRegion.value());
        THIS->render(reinterpret_cast<QPaintDevice*>(target), qTargetOffset, qSourceRegion, static_cast<QWidget::RenderFlags>(renderFlags.value));
    }

    void Handle_render(HandleRef _this, Painter::HandleRef painter, const std::optional<Point::HandleRef>& targetOffset, const std::optional<Region::HandleRef>& sourceRegion, RenderFlags renderFlags /* RenderFlags::DrawWindowBackground | RenderFlags::DrawChildren */) {
        QPoint qTargetOffset;
        if (targetOffset.has_value()) qTargetOffset = QPOINT_VALUE(targetOffset.value());
        QRegion qSourceRegion;
        if (sourceRegion.has_value()) qSourceRegion = QREGION_VALUE(sourceRegion.value());
        THIS->render(reinterpret_cast<QPainter*>(painter), qTargetOffset, qSourceRegion, static_cast<QWidget::RenderFlags>(renderFlags.value));
    }

    void Handle_repaint(HandleRef _this, Rect::HandleRef rect) {
        THIS->repaint(QRECT_VALUE(rect));
    }

    void Handle_repaint(HandleRef _this, Region::HandleRef rgn) {
        THIS->repaint(QREGION_VALUE(rgn));
    }

    void Handle_repaint(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h) {
        THIS->repaint(x, y, w, h);
    }

    void Handle_resize(HandleRef _this, Size::HandleRef size) {
        THIS->resize(QSIZE_VALUE(size));
    }

    void Handle_resize(HandleRef _this, int32_t w, int32_t h) {
        THIS->resize(w, h);
    }

    bool Handle_restoreGeometry(HandleRef _this, const std::vector<uint8_t>& geometry) {
        const QByteArray qBytes(reinterpret_cast<const char *>(geometry.data()), static_cast<qsizetype>(geometry.size()));
        return THIS->restoreGeometry(qBytes);
    }

    std::vector<uint8_t> Handle_saveGeometry(HandleRef _this) {
        const auto qBytes = THIS->saveGeometry();
        const auto data = qBytes.data();
        return std::vector<uint8_t>(data, data + qBytes.length());
    }

    Screen::HandleRef Handle_screen(HandleRef _this) {
        return reinterpret_cast<Screen::HandleRef>(THIS->screen());
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy) {
        THIS->scroll(dx, dy);
    }

    void Handle_scroll(HandleRef _this, int32_t dx, int32_t dy, Rect::HandleRef r) {
        THIS->scroll(dx, dy, QRECT_VALUE(r));
    }

    void Handle_setAcceptDrops(HandleRef _this, bool on) {
        THIS->setAcceptDrops(on);
    }

    void Handle_setAccessibleDescription(HandleRef _this, const std::string& description) {
        THIS->setAccessibleDescription(QString::fromStdString(description));
    }

    void Handle_setAccessibleName(HandleRef _this, const std::string& name) {
        THIS->setAccessibleName(QString::fromStdString(name));
    }

    void Handle_setAttribute(HandleRef _this, WidgetAttribute attribute, bool on /* true */) {
        THIS->setAttribute(static_cast<Qt::WidgetAttribute>(attribute), on);
    }

    void Handle_setAutoFillBackground(HandleRef _this, bool enabled) {
        THIS->setAutoFillBackground(enabled);
    }

    void Handle_setBaseSize(HandleRef _this, Size::HandleRef size) {
        THIS->setBaseSize(QSIZE_VALUE(size));
    }

    void Handle_setBaseSize(HandleRef _this, int32_t basew, int32_t baseh) {
        THIS->setBaseSize(basew, baseh);
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_setContentsMargins(HandleRef _this, Margins2::HandleRef margins) {
        THIS->setContentsMargins(QMARGINS_VALUE(margins));
    }

    void Handle_setContextMenuPolicy(HandleRef _this, ContextMenuPolicy policy) {
        THIS->setContextMenuPolicy(static_cast<Qt::ContextMenuPolicy>(policy));
    }

    void Handle_setCursor(HandleRef _this, Cursor::HandleRef cursor) {
        THIS->setCursor(QCURSOR_VALUE(cursor));
    }

    // void Handle_setEditFocus(HandleRef _this, bool enable) {
    //     // embedded linux only
    // }

    void Handle_setFixedHeight(HandleRef _this, int32_t h) {
        THIS->setFixedHeight(h);
    }

    void Handle_setFixedSize(HandleRef _this, Size::HandleRef s) {
        THIS->setFixedSize(QSIZE_VALUE(s));
    }

    void Handle_setFixedSize(HandleRef _this, int32_t w, int32_t h) {
        THIS->setFixedSize(w, h);
    }

    void Handle_setFixedWidth(HandleRef _this, int32_t w) {
        THIS->setFixedWidth(w);
    }

    void Handle_setFocus(HandleRef _this, FocusReason reason) {
        THIS->setFocus(static_cast<Qt::FocusReason>(reason));
    }

    void Handle_setFocusPolicy(HandleRef _this, FocusPolicy policy) {
        THIS->setFocusPolicy(static_cast<Qt::FocusPolicy>(policy.value));
    }

    void Handle_setFocusProxy(HandleRef _this, HandleRef w) {
        THIS->setFocusProxy(AS_QWIDGET_PTR(w));
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    void Handle_setGeometry(HandleRef _this, Rect::HandleRef r) {
        THIS->setGeometry(QRECT_VALUE(r));
    }

    void Handle_setGeometry(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h) {
        THIS->setGeometry(x, y, w, h);
    }

    void Handle_setGraphicsEffect(HandleRef _this, GraphicsEffect::HandleRef effect) {
        THIS->setGraphicsEffect(reinterpret_cast<QGraphicsEffect*>(effect));
    }

    void Handle_setInputMethodHints(HandleRef _this, InputMethodHints hints) {
        THIS->setInputMethodHints(static_cast<Qt::InputMethodHints>(hints.value));
    }

    void Handle_setLayout(HandleRef _this, Layout::HandleRef layout) {
        THIS->setLayout(AS_QLAYOUT_PTR(layout));
    }

    void Handle_setLayoutDirection(HandleRef _this, LayoutDirection direction) {
        THIS->setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
    }

    void Handle_setMask(HandleRef _this, Region::HandleRef region) {
        THIS->setMask(QREGION_VALUE(region));
    }

    void Handle_setMaximumHeight(HandleRef _this, int32_t maxh) {
        THIS->setMaximumHeight(maxh);
    }

    void Handle_setMaximumSize(HandleRef _this, Size::HandleRef size) {
        THIS->setMaximumSize(QSIZE_VALUE(size));
    }

    void Handle_setMaximumSize(HandleRef _this, int32_t maxw, int32_t maxh) {
        THIS->setMaximumSize(maxw, maxh);
    }

    void Handle_setMaximumWidth(HandleRef _this, int32_t maxw) {
        THIS->setMaximumWidth(maxw);
    }

    void Handle_setMinimumHeight(HandleRef _this, int32_t minh) {
        THIS->setMinimumHeight(minh);
    }

    void Handle_setMinimumSize(HandleRef _this, Size::HandleRef size) {
        THIS->setMinimumSize(QSIZE_VALUE(size));
    }

    void Handle_setMinimumSize(HandleRef _this, int32_t minw, int32_t minh) {
        THIS->setMinimumSize(minw, minh);
    }

    void Handle_setMinimumWidth(HandleRef _this, int32_t minw) {
        THIS->setMinimumWidth(minw);
    }

    void Handle_setMouseTracking(HandleRef _this, bool enable) {
        THIS->setMouseTracking(enable);
    }

    void Handle_setParent(HandleRef _this, HandleRef parent) {
        THIS->setParent(AS_QWIDGET_PTR(parent));
    }

    void Handle_setParent(HandleRef _this, HandleRef parent, WindowFlags f) {
        THIS->setParent(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(f.value));
    }

    void Handle_setScreen(HandleRef _this, Screen::HandleRef screen) {
        THIS->setScreen(AS_QSCREEN_PTR(screen));
    }

    void Handle_setShortcutAutoRepeat(HandleRef _this, int32_t id, bool enable /* true */) {
        THIS->setShortcutAutoRepeat(id, enable);
    }

    void Handle_setShortcutEnabled(HandleRef _this, int32_t id, bool enable /* true */) {
        THIS->setShortcutEnabled(id, enable);
    }

    void Handle_setSizeIncrement(HandleRef _this, Size::HandleRef size) {
        THIS->setSizeIncrement(QSIZE_VALUE(size));
    }

    void Handle_setSizeIncrement(HandleRef _this, int32_t w, int32_t h) {
        THIS->setSizeIncrement(w, h);
    }

    void Handle_setSizePolicy(HandleRef _this, SizePolicy::HandleRef policy) {
        THIS->setSizePolicy(QSIZEPOLICY_VALUE(policy));
    }

    void Handle_setSizePolicy(HandleRef _this, Policy horizontal, Policy vertical) {
        THIS->setSizePolicy(static_cast<QSizePolicy::Policy>(horizontal.value), static_cast<QSizePolicy::Policy>(vertical.value));
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        THIS->setStatusTip(QString::fromStdString(tip));
    }

    void Handle_setTabletTracking(HandleRef _this, bool enable) {
        THIS->setTabletTracking(enable);
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        THIS->setToolTip(QString::fromStdString(tip));
    }

    void Handle_setToolTipDuration(HandleRef _this, int32_t msec) {
        THIS->setToolTipDuration(msec);
    }

    void Handle_setUpdatesEnabled(HandleRef _this, bool enable) {
        THIS->setUpdatesEnabled(enable);
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        THIS->setWhatsThis(QString::fromStdString(text));
    }

    void Handle_setWindowFilePath(HandleRef _this, const std::string& filePath) {
        THIS->setWindowFilePath(QString::fromStdString(filePath));
    }

    void Handle_setWindowFlag(HandleRef _this, WindowType flag, bool on /* true */) {
        THIS->setWindowFlag(static_cast<Qt::WindowType>(flag), on);
    }

    void Handle_setWindowFlags(HandleRef _this, WindowFlags type_) {
        THIS->setWindowFlags(static_cast<Qt::WindowFlags>(type_.value));
    }

    void Handle_setWindowIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setWindowIcon(QICON_VALUE(icon));
    }

    void Handle_setWindowModality(HandleRef _this, WindowModality windowModality) {
        THIS->setWindowModality(static_cast<Qt::WindowModality>(windowModality));
    }

    void Handle_setWindowOpacity(HandleRef _this, double level) {
        THIS->setWindowOpacity(level);
    }

    void Handle_setWindowRole(HandleRef _this, const std::string& role) {
        THIS->setWindowRole(QString::fromStdString(role));
    }

    void Handle_setWindowState(HandleRef _this, WindowStates windowState) {
        THIS->setWindowState(static_cast<Qt::WindowStates>(windowState.value));
    }

    // void Handle_setupUi(HandleRef _this, HandleRef widget) {
    //     // only for UI-designed widgets
    // }

    Size::OwnedRef Handle_size(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->size());
    }

    Size::OwnedRef Handle_sizeHint(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->sizeHint());
    }

    Size::OwnedRef Handle_sizeIncrement(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->sizeIncrement());
    }

    SizePolicy::OwnedRef Handle_sizePolicy(HandleRef _this) {
        return SIZEPOLICY_HEAP_NEW(THIS->sizePolicy());
    }

    void Handle_stackUnder(HandleRef _this, HandleRef w) {
        THIS->stackUnder(AS_QWIDGET_PTR(w));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    std::string Handle_styleSheet(HandleRef _this) {
        return THIS->styleSheet().toStdString();
    }

    bool Handle_testAttribute(HandleRef _this, WidgetAttribute attribute) {
        return THIS->testAttribute(static_cast<Qt::WidgetAttribute>(attribute));
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    int32_t Handle_toolTipDuration(HandleRef _this) {
        return THIS->toolTipDuration();
    }

    bool Handle_underMouse(HandleRef _this) {
        return THIS->underMouse();
    }

    void Handle_ungrabGesture(HandleRef _this, GestureType gesture) {
        THIS->ungrabGesture(static_cast<Qt::GestureType>(gesture));
    }

    void Handle_unsetCursor(HandleRef _this) {
        THIS->unsetCursor();
    }

    void Handle_unsetLayoutDirection(HandleRef _this) {
        THIS->unsetLayoutDirection();
    }

    void Handle_unsetLocale(HandleRef _this) {
        THIS->unsetLocale();
    }

    void Handle_update(HandleRef _this, Rect::HandleRef rect) {
        THIS->update(QRECT_VALUE(rect));
    }

    void Handle_update(HandleRef _this, Region::HandleRef rgn) {
        THIS->update(QREGION_VALUE(rgn));
    }

    void Handle_update(HandleRef _this, int32_t x, int32_t y, int32_t w, int32_t h) {
        THIS->update(x, y, w, h);
    }

    void Handle_updateGeometry(HandleRef _this) {
        THIS->updateGeometry();
    }

    bool Handle_updatesEnabled(HandleRef _this) {
        return THIS->updatesEnabled();
    }

    Region::OwnedRef Handle_visibleRegion(HandleRef _this) {
        return REGION_HEAP_NEW(THIS->visibleRegion());
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    WIN_ID Handle_winId(HandleRef _this) {
        return THIS->winId();
    }

    HandleRef Handle_window(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->window());
    }

    std::string Handle_windowFilePath(HandleRef _this) {
        return THIS->windowFilePath().toStdString();
    }

    WindowFlags Handle_getWindowFlags(HandleRef _this) {
        return WindowFlags(THIS->windowFlags());
    }

    Window::HandleRef Handle_windowHandle(HandleRef _this) {
        return reinterpret_cast<Window::HandleRef>(THIS->windowHandle());
    }

    Icon::OwnedRef Handle_windowIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->windowIcon());
    }

    WindowModality Handle_getWindowModality(HandleRef _this) {
        return static_cast<WindowModality>(THIS->windowModality());
    }

    double Handle_windowOpacity(HandleRef _this) {
        return THIS->windowOpacity();
    }

    std::string Handle_windowRole(HandleRef _this) {
        return THIS->windowRole().toStdString();
    }

    WindowStates Handle_windowState(HandleRef _this) {
        return WindowStates(THIS->windowState());
    }

    std::string Handle_windowTitle(HandleRef _this) {
        return THIS->windowTitle().toStdString();
    }

    WindowType Handle_getWindowType(HandleRef _this) {
        return static_cast<WindowType>(THIS->windowType());
    }

    int32_t Handle_x(HandleRef _this) {
        return THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return THIS->y();
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

    void Handle_repaint(HandleRef _this) {
        THIS->repaint();
    }

    void Handle_setDisabled(HandleRef _this, bool disable) {
        THIS->setDisabled(disable);
    }

    void Handle_setEnabled(HandleRef _this, bool enable) {
        THIS->setEnabled(enable);
    }

    void Handle_setFocus(HandleRef _this) {
        THIS->setFocus();
    }

    void Handle_setHidden(HandleRef _this, bool hidden) {
        THIS->setHidden(hidden);
    }

    void Handle_setStyleSheet(HandleRef _this, const std::string& styleSheet) {
        THIS->setStyleSheet(QString::fromStdString(styleSheet));
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    void Handle_setWindowModified(HandleRef _this, bool modified) {
        THIS->setWindowModified(modified);
    }

    void Handle_setWindowTitle(HandleRef _this, const std::string& title) {
        THIS->setWindowTitle(QString::fromStdString(title));
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

    void Handle_update(HandleRef _this) {
        THIS->update();
    }

    SignalConnectionRef Handle_connect_CustomContextMenuRequested(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWidget::customContextMenuRequested, [handler](const QPoint& pos) {
            handler->customContextMenuRequested((Point::HandleRef)&pos);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowIconChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWidget::windowIconChanged, [handler](const QIcon& icon) {
            handler->windowIconChanged((Icon::HandleRef)&icon);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_WindowTitleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QWidget::windowTitleChanged, [handler](const QString& title) {
            handler->windowTitleChanged(title.toStdString());
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<HandleRef>(new QWidget(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value)));
    }

    // subclass/delegated stuff ==========================================================

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(_this))

    class Delegated : public QWidget {
        std::shared_ptr<DelegateMethods> methods;
        MethodMask methodMask = 0;
    public:
        Delegated(QWidget *parent, const Qt::WindowFlags &f, const std::shared_ptr<DelegateMethods> &methods, const MethodMask method_mask)
            : QWidget(parent, f),
              methods(methods),
              methodMask(method_mask) {}

    // public virtual overrides:
        [[nodiscard]] QSize sizeHint() const override {
            if (methodMask & SizeHint) {
                __SizeReturn ret;
                methods->sizeHint(&ret);
                return ret.result;
            } else {
                return QWidget::sizeHint();
            }
        }
    protected:
        void contextMenuEvent(QContextMenuEvent *event) override {
            if (methodMask & ContextMenuEvent) {
                methods->contextMenuEvent(reinterpret_cast<ContextMenuEventRef>(event));
                event->accept();
            } else {
                return QWidget::contextMenuEvent(event);
            }
        }

        void dragEnterEvent(QDragEnterEvent *event) override {
            if (methodMask & DragEnterEvent) {
                methods->dragEnterEvent(reinterpret_cast<DragEnterEventRef>(event));
                // other side needs to call acceptProposedAction if it's OK, otherwise ... .ignore?
                event->accept();
            } else {
                QWidget::dragEnterEvent(event);
            }
        }

        void dragLeaveEvent(QDragLeaveEvent *event) override {
            if (methodMask & DragLeaveEvent) {
                methods->dragLeaveEvent(reinterpret_cast<DragLeaveEventRef>(event));
                event->accept();
            } else {
                QWidget::dragLeaveEvent(event);
            }
        }

        void dragMoveEvent(QDragMoveEvent *event) override {
            if (methodMask & DragMoveEvent) {
                methods->dragMoveEvent(reinterpret_cast<DragMoveEventRef>(event));
                // other side needs to call acceptProposedAction if it's OK, otherwise ... .ignore?
                event->accept();
            } else {
                QWidget::dragMoveEvent(event);
            }
        }

        void dropEvent(QDropEvent *event) override {
            if (methodMask & DropEvent) {
                methods->dropEvent(reinterpret_cast<DropEventRef>(event));
                // ?? forget why this was being called originally, seemes like the implementer's responsibility:
                // event->acceptProposedAction();
                event->accept();
            } else {
                QWidget::dropEvent(event);
            }
        }

        void enterEvent(QEnterEvent *event) override {
            if (methodMask & EnterEvent) {
                methods->enterEvent(reinterpret_cast<EnterEventRef>(event));
                event->accept();
            } else {
                QWidget::enterEvent(event);
            }
        }

        void focusInEvent(QFocusEvent *event) override {
            if (methodMask & FocusInEvent) {
                methods->focusInEvent(reinterpret_cast<FocusEventRef>(event));
                event->accept();
            } else {
                QWidget::focusInEvent(event);
            }
        }

        void focusOutEvent(QFocusEvent *event) override {
            if (methodMask & FocusOutEvent) {
                methods->focusOutEvent(reinterpret_cast<FocusEventRef>(event));
                event->accept();
            } else {
                QWidget::focusOutEvent(event);
            }
        }

        void keyPressEvent(QKeyEvent *event) override {
            if (methodMask & KeyPressEvent) {
                methods->keyPressEvent(reinterpret_cast<KeyEventRef>(event));
                // don't need to accept() per docs
            } else {
                QWidget::keyPressEvent(event);
            }
        }

        void keyReleaseEvent(QKeyEvent *event) override {
            if (methodMask & KeyReleaseEvent) {
                methods->keyReleaseEvent(reinterpret_cast<KeyEventRef>(event));
                // don't need to accept() per docs
            } else {
                QWidget::keyReleaseEvent(event);
            }
        }

        void leaveEvent(QEvent *event) override {
            if (methodMask & LeaveEvent) {
                methods->leaveEvent(reinterpret_cast<Event::HandleRef>(event));
                event->accept();
            } else {
                QWidget::leaveEvent(event);
            }
        }

        void mouseDoubleClickEvent(QMouseEvent *event) override {
            if (methodMask & MouseDoubleClickEvent) {
                methods->mouseDoubleClickEvent(reinterpret_cast<MouseEventRef>(event));
                event->accept();
            } else {
                QWidget::mouseDoubleClickEvent(event);
            }
        }

        void mouseMoveEvent(QMouseEvent *event) override {
            if (methodMask & MouseMoveEvent) {
                methods->mouseMoveEvent(reinterpret_cast<MouseEventRef>(event));
                // prevent from propagating, see notes above
                event->accept();
            } else {
                QWidget::mouseMoveEvent(event);
            }
        }

        void mousePressEvent(QMouseEvent *event) override {
            if (methodMask & MousePressEvent) {
                methods->mousePressEvent(reinterpret_cast<MouseEventRef>(event));
                // prevent from propagating, see notes above
                event->accept();
            } else {
                QWidget::mousePressEvent(event);
            }
        }

        void mouseReleaseEvent(QMouseEvent *event) override {
            if (methodMask & MouseReleaseEvent) {
                methods->mouseReleaseEvent(reinterpret_cast<MouseEventRef>(event));
                event->accept();
            } else {
                QWidget::mouseReleaseEvent(event);
            }
        }

        void paintEvent(QPaintEvent *event) override {
            if (methodMask & PaintEvent) {
                QPainter painter(this);
                methods->paintEvent(reinterpret_cast<Painter::HandleRef>(&painter), reinterpret_cast<PaintEventRef>(event));
                // prevent it from propagating:
                // do we allow this from the method delegate somehow?
                event->accept();
            } else {
                QWidget::paintEvent(event);
            }
        }

        void resizeEvent(QResizeEvent *event) override {
            if (methodMask & ResizeEvent) {
                methods->resizeEvent(reinterpret_cast<ResizeEventRef>(event));
                event->accept();
            } else {
                QWidget::resizeEvent(event);
            }
        }

        void showEvent(QShowEvent *event) override {
            if (methodMask & ShowEvent) {
                methods->showEvent(reinterpret_cast<ShowEventRef>(event));
                event->accept();
            } else {
                QWidget::showEvent(event);
            }
        }

        void wheelEvent(QWheelEvent *event) override {
            if (methodMask & WheelEvent) {
                methods->wheelEvent(reinterpret_cast<WheelEventRef>(event));
                event->accept();
            } else {
                QWidget::wheelEvent(event);
            }
        }
    };

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated(const std::shared_ptr<DelegateMethods>& methods, MethodMask methodMask, HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<DelegatedRef>(new Delegated(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value), methods, methodMask));
    }
}
