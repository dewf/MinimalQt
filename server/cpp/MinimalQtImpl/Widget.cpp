#include "generated/Widget.h"
#include "WidgetInternal.h"

#include <QObject>
#include <QWidget>
#include <QLayout>

#include <QPainter>
#include <QPaintEvent>

#include <QMimeData>
#include <QDrag>
#include <utility>

#include "FontInternal.h"
#include "util/convert.h"
#include "IconInternal.h"
#include "SizePolicyInternal.h"
#include "CursorInternal.h"

#define THIS ((WidgetWithHandler*)_this)

namespace Widget
{
    class WidgetWithHandler : public QWidget {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit WidgetWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    const int32_t WIDGET_SIZE_MAX = QWIDGETSIZE_MAX;

    bool Handle_acceptDrops(HandleRef _this) {
        return THIS->acceptDrops();
    }

    void Handle_setAcceptDrops(HandleRef _this, bool state) {
        THIS->setAcceptDrops(state);
    }

    std::string Handle_accessibleDescription(HandleRef _this) {
        return THIS->accessibleDescription().toStdString();
    }

    void Handle_setAccessibleDescription(HandleRef _this, const std::string& desc) {
        THIS->setAccessibleDescription(QString::fromStdString(desc));
    }

    std::string Handle_accessibleName(HandleRef _this) {
        return THIS->accessibleName().toStdString();
    }

    void Handle_setAccessibleName(HandleRef _this, const std::string& name) {
        THIS->setAccessibleName(QString::fromStdString(name));
    }

    bool Handle_autoFillBackground(HandleRef _this) {
        return THIS->autoFillBackground();
    }

    void Handle_setAutoFillBackground(HandleRef _this, bool state) {
        THIS->setAutoFillBackground(state);
    }

    Size Handle_baseSize(HandleRef _this) {
        return toSize(THIS->baseSize());
    }

    void Handle_setBaseSize(HandleRef _this, Size size) {
        THIS->setBaseSize(toQSize(size));
    }

    Rect Handle_childrenRect(HandleRef _this) {
        return toRect(THIS->childrenRect());
    }

    Region::OwnedRef Handle_childrenRegion(HandleRef _this) {
        auto ret = THIS->childrenRegion();
        return reinterpret_cast<Region::OwnedRef>(new QRegion(ret));
    }

    ContextMenuPolicy Handle_contextMenuPolicy(HandleRef _this) {
        return static_cast<ContextMenuPolicy>(THIS->contextMenuPolicy());
    }

    void Handle_setContextMenuPolicy(HandleRef _this, ContextMenuPolicy policy) {
        THIS->setContextMenuPolicy(static_cast<Qt::ContextMenuPolicy>(policy));
    }

    Cursor::OwnedRef Handle_getCursor(HandleRef _this) {
        return CURSOR_HEAP_NEW(THIS->cursor());
    }

    void Handle_setCursor(HandleRef _this, Cursor::HandleRef cursor) {
        THIS->setCursor(QCURSOR_VALUE(cursor));
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    bool Handle_hasFocus(HandleRef _this) {
        return THIS->hasFocus();
    }

    FocusPolicy Handle_getFocusPolicy(HandleRef _this) {
        return THIS->focusPolicy();
    }

    void Handle_setFocusPolicy(HandleRef _this, FocusPolicy policy) {
        THIS->setFocusPolicy(static_cast<Qt::FocusPolicy>(policy));
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(THIS->font());
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        THIS->setFont(QFONT_VALUE(font));
    }

    Rect Handle_frameGeometry(HandleRef _this) {
        return toRect(THIS->frameGeometry());
    }

    Size Handle_frameSize(HandleRef _this) {
        return toSize(THIS->frameSize());
    }

    bool Handle_isFullscreen(HandleRef _this) {
        return THIS->isFullScreen();
    }

    Rect Handle_geometry(HandleRef _this) {
        return toRect(THIS->geometry());
    }

    void Handle_setGeometry(HandleRef _this, Rect rect) {
        THIS->setGeometry(toQRect(rect));
    }

    void Handle_setGeometry(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->setGeometry(x, y, width, height);
    }

    int32_t Handle_height(HandleRef _this) {
        return THIS->height();
    }

    InputMethodHints Handle_getInputMethodHints(HandleRef _this) {
        return THIS->inputMethodHints();
    }

    void Handle_setInputMethodHints(HandleRef _this, InputMethodHints hints) {
        THIS->setInputMethodHints(static_cast<Qt::InputMethodHints>(hints));
    }

    bool Handle_isActiveWindow(HandleRef _this) {
        return THIS->isActiveWindow();
    }

    LayoutDirection Handle_getLayoutDirection(HandleRef _this) {
        return static_cast<LayoutDirection>(THIS->layoutDirection());
    }

    void Handle_setLayoutDirection(HandleRef _this, LayoutDirection direction) {
        THIS->setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
    }

    bool Handle_isMaximized(HandleRef _this) {
        return THIS->isMaximized();
    }

    int32_t Handle_maximumHeight(HandleRef _this) {
        return THIS->maximumHeight();
    }

    void Handle_setMaximumHeight(HandleRef _this, int32_t height) {
        THIS->setMaximumHeight(height);
    }

    Size Handle_maximumSize(HandleRef _this) {
        return toSize(THIS->maximumSize());
    }

    void Handle_setMaximumSize(HandleRef _this, Size size) {
        THIS->setMaximumSize(toQSize(size));
    }

    int32_t Handle_maximumWidth(HandleRef _this) {
        return THIS->maximumWidth();
    }

    void Handle_setMaximumWidth(HandleRef _this, int32_t width) {
        THIS->setMaximumWidth(width);
    }

    bool Handle_isMinimized(HandleRef _this) {
        return THIS->isMinimized();
    }

    int32_t Handle_minimumHeight(HandleRef _this) {
        return THIS->minimumHeight();
    }

    void Handle_setMinimumHeight(HandleRef _this, int32_t height) {
        THIS->setMinimumHeight(height);
    }

    Size Handle_minimumSize(HandleRef _this) {
        return toSize(THIS->minimumSize());
    }

    void Handle_setMinimumSize(HandleRef _this, Size size) {
        THIS->setMinimumSize(toQSize(size));
    }

    Size Handle_minimumSizeHint(HandleRef _this) {
        return toSize(THIS->minimumSizeHint());
    }

    int32_t Handle_minimumWidth(HandleRef _this) {
        return THIS->minimumWidth();
    }

    void Handle_setMinimumWidth(HandleRef _this, int32_t width) {
        THIS->setMinimumWidth(width);
    }

    bool Handle_isModal(HandleRef _this) {
        return THIS->isModal();
    }

    bool Handle_hasMouseTracking(HandleRef _this) {
        return THIS->hasMouseTracking();
    }

    void Handle_setMouseTracking(HandleRef _this, bool state) {
        THIS->setMouseTracking(state);
    }

    Rect Handle_normalGeometry(HandleRef _this) {
        return toRect(THIS->normalGeometry());
    }

    Point Handle_pos(HandleRef _this) {
        return toPoint(THIS->pos());
    }

    void Handle_move(HandleRef _this, Point p) {
        THIS->move(toQPoint(p));
    }

    void Handle_move(HandleRef _this, int32_t x, int32_t y) {
        THIS->move(x, y);
    }

    Rect Handle_rect(HandleRef _this) {
        return toRect(THIS->rect());
    }

    Size Handle_getSize(HandleRef _this) {
        return toSize(THIS->size());
    }

    void Handle_resize(HandleRef _this, Size size) {
        THIS->resize(toQSize(size));
    }

    void Handle_resize(HandleRef _this, int32_t width, int32_t height) {
        THIS->resize(width, height);
    }

    Size Handle_sizeHint(HandleRef _this) {
        return toSize(THIS->sizeHint());
    }

    Size Handle_sizeIncrement(HandleRef _this) {
        return toSize(THIS->sizeIncrement());
    }

    void Handle_setSizeIncrement(HandleRef _this, Common::Size size) {
        THIS->setSizeIncrement(toQSize(size));
    }

    void Handle_setSizeIncrement(HandleRef _this, int32_t w, int32_t h) {
        THIS->setSizeIncrement(w, h);
    }

    SizePolicy::OwnedRef Handle_getSizePolicy(HandleRef _this) {
        return SIZEPOLICY_HEAP_NEW(THIS->sizePolicy());
    }

    void Handle_setSizePolicy(HandleRef _this, SizePolicy::HandleRef policy) {
        THIS->setSizePolicy(QSIZEPOLICY_VALUE(policy));
    }

    void Handle_setSizePolicy(HandleRef _this, Policy hPolicy, Policy vPolicy) {
        THIS->setSizePolicy(static_cast<QSizePolicy::Policy>(hPolicy), static_cast<QSizePolicy::Policy>(vPolicy));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return THIS->statusTip().toStdString();
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        THIS->setStatusTip(QString::fromStdString(tip));
    }

    std::string Handle_styleSheet(HandleRef _this) {
        return THIS->styleSheet().toStdString();
    }

    void Handle_setStyleSheet(HandleRef _this, const std::string& styles) {
        THIS->setStyleSheet(QString::fromStdString(styles));
    }

    bool Handle_hasTabletTracking(HandleRef _this) {
        return THIS->hasTabletTracking();
    }

    void Handle_setTabletTracking(HandleRef _this, bool state) {
        THIS->setTabletTracking(state);
    }

    std::string Handle_toolTip(HandleRef _this) {
        return THIS->toolTip().toStdString();
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        THIS->setToolTip(QString::fromStdString(tip));
    }

    int32_t Handle_toolTipDuration(HandleRef _this) {
        return THIS->toolTipDuration();
    }

    void Handle_setToolTipDuration(HandleRef _this, int32_t duration) {
        THIS->setToolTipDuration(duration);
    }

    bool Handle_updatesEnabled(HandleRef _this) {
        return THIS->updatesEnabled();
    }

    void Handle_setUpdatesEnabled(HandleRef _this, bool enabled) {
        THIS->setUpdatesEnabled(enabled);
    }

    bool Handle_isVisible(HandleRef _this) {
        return THIS->isVisible();
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return THIS->whatsThis().toStdString();
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        THIS->setWhatsThis(QString::fromStdString(text));
    }

    int32_t Handle_width(HandleRef _this) {
        return THIS->width();
    }

    std::string Handle_windowFilePath(HandleRef _this) {
        return THIS->windowFilePath().toStdString();
    }

    void Handle_setWindowFilePath(HandleRef _this, const std::string& path) {
        THIS->setWindowFilePath(QString::fromStdString(path));
    }

    WindowFlags Handle_getWindowFlags(HandleRef _this) {
        return THIS->windowFlags();
    }

    void Handle_setWindowFlags(HandleRef _this, WindowFlags flags_) {
        THIS->setWindowFlags(static_cast<Qt::WindowFlags>(flags_));
    }

    Icon::OwnedRef Handle_windowIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->windowIcon());
    }

    void Handle_setWindowIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setWindowIcon(QICON_VALUE(icon));
    }

    WindowModality Handle_getWindowModality(HandleRef _this) {
        return static_cast<WindowModality>(THIS->windowModality());
    }

    void Handle_setWindowModality(HandleRef _this, WindowModality modality) {
        THIS->setWindowModality(static_cast<Qt::WindowModality>(modality));
    }

    bool Handle_isWindowModified(HandleRef _this) {
        return THIS->isWindowModified();
    }

    void Handle_setWindowModified(HandleRef _this, bool modified) {
        THIS->setWindowModified(modified);
    }

    double Handle_windowOpacity(HandleRef _this) {
        return THIS->windowOpacity();
    }

    void Handle_setWindowOpacity(HandleRef _this, double opacity) {
        THIS->setWindowOpacity(opacity);
    }

    std::string Handle_windowTitle(HandleRef _this) {
        return THIS->windowTitle().toStdString();
    }

    void Handle_setWindowTitle(HandleRef _this, const std::string& title) {
        THIS->setWindowTitle(QString::fromStdString(title));
    }

    int32_t Handle_x(HandleRef _this) {
        return THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return THIS->y();
    }

    // methods ====================================================

    void Handle_addAction(HandleRef _this, Action::HandleRef action) {
        THIS->addAction(reinterpret_cast<QAction *>(action));
    }

    HandleRef Handle_getWindow(HandleRef _this) {
        return reinterpret_cast<HandleRef>(THIS->window());
    }

    void Handle_updateGeometry(HandleRef _this) {
        THIS->updateGeometry();
    }

    void Handle_adjustSize(HandleRef _this) {
        THIS->adjustSize();
    }

    void Handle_setFixedWidth(HandleRef _this, int32_t width) {
        THIS->setFixedWidth(width);
    }

    void Handle_setFixedHeight(HandleRef _this, int32_t height) {
        THIS->setFixedHeight(height);
    }

    void Handle_setFixedSize(HandleRef _this, Size size) {
        THIS->setFixedSize(toQSize(size));
    }

    void Handle_setFixedSize(HandleRef _this, int32_t width, int32_t height) {
        THIS->setFixedSize(width, height);
    }

    void Handle_show(HandleRef _this) {
        THIS->show();
    }

    void Handle_hide(HandleRef _this) {
        THIS->hide();
    }

    void Handle_update(HandleRef _this) {
        THIS->update();
    }

    void Handle_update(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        THIS->update(x, y, width, height);
    }

    void Handle_update(HandleRef _this, Rect rect) {
        THIS->update(toQRect(rect));
    }

    void Handle_setLayout(HandleRef _this, Layout::HandleRef layout) {
        THIS->setLayout(reinterpret_cast<QLayout *>(layout));
    }

    Layout::HandleRef Handle_getLayout(HandleRef _this) {
        return reinterpret_cast<Layout::HandleRef>(THIS->layout());
    }

    Point Handle_mapToGlobal(HandleRef _this, Point p) {
        auto p2 = THIS->mapToGlobal(toQPoint(p));
        return toPoint(p2);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new WidgetWithHandler(handler));
    }

    HandleRef createNoHandler() {
        return reinterpret_cast<HandleRef>(new QWidget());
    }

    // =========================================================================

#define EVENTTHIS ((QEvent*)_this)

    void Event_accept(EventRef _this) {
        EVENTTHIS->accept();
    }

    void Event_ignore(EventRef _this) {
        EVENTTHIS->ignore();
    }

//    void Event_dispose(EventRef _this) {
//        // not owned, do nothing
//    }

#define MIMETHIS ((QMimeData*)_this)

    std::vector<std::string> MimeData_formats(MimeDataRef _this) {
        std::vector<std::string> result;
        for (auto & fmt : MIMETHIS->formats()) {
            result.push_back(fmt.toStdString());
        }
        return result;
    }

    bool MimeData_hasFormat(MimeDataRef _this, const std::string& mimeType) {
        return MIMETHIS->hasFormat(QString::fromStdString(mimeType));
    }

    std::string MimeData_text(MimeDataRef _this) {
        return MIMETHIS->text().toStdString();
    }

    void MimeData_setText(MimeDataRef _this, const std::string& text) {
        MIMETHIS->setText(QString::fromStdString(text));
    }

    std::vector<std::string> MimeData_urls(MimeDataRef _this) {
        std::vector<std::string> result;
        for (auto & url : MIMETHIS->urls()) {
            result.push_back(url.toString().toStdString());
        }
        return result;
    }

    void MimeData_setUrls(MimeDataRef _this, const std::vector<std::string>& urls) {
        QList<QUrl> qUrls;
        for (auto & url : urls) {
            qUrls.append(QUrl(QString::fromStdString(url)));
        }
        MIMETHIS->setUrls(qUrls);
    }

//    void MimeData_dispose(MimeDataRef _this) {
//        // if it was created on a drop, we're not responsible for it
//        // if we created it for a drag, we're also not responsible for releasing it
//    }

    MimeDataRef createMimeData() {
        return reinterpret_cast<MimeDataRef>(new QMimeData());
    }

#define DRAGTHIS ((QDrag*)_this)

    void Drag_setMimeData(DragRef _this, MimeDataRef data) {
        DRAGTHIS->setMimeData(reinterpret_cast<QMimeData *>(data));
    }

    DropAction Drag_exec(DragRef _this, DropActionSet supportedActions, DropAction defaultAction) {
        auto qDefault = static_cast<Qt::DropAction>(defaultAction);
        auto qSupported = QFlags<Qt::DropAction>(supportedActions);
        return static_cast<DropAction>(DRAGTHIS->exec(qSupported, qDefault));
    }

//    void Drag_dispose(DragRef _this) {
//        // we're not responsible for deleting these (if they are exec'ed)
//    }

    DragRef createDrag(HandleRef parent) {
        return reinterpret_cast<DragRef>(new QDrag(reinterpret_cast<QObject *>(parent)));
    }

#define DRAGMOVETHIS ((QDragMoveEvent*)_this)

    DropAction DragMoveEvent_proposedAction(DragMoveEventRef _this) {
        return static_cast<DropAction>(DRAGMOVETHIS->proposedAction());
    }

    void DragMoveEvent_acceptProposedAction(DragMoveEventRef _this) {
        DRAGMOVETHIS->acceptProposedAction();
    }

    DropActionSet DragMoveEvent_possibleActions(DragMoveEventRef _this) {
        return (DropActionSet) DRAGMOVETHIS->possibleActions();
    }

    void DragMoveEvent_acceptDropAction(DragMoveEventRef _this, DropAction action) {
        auto qtAction = static_cast<Qt::DropAction>(action);
        if (qtAction == DRAGMOVETHIS->proposedAction()) {
            DRAGMOVETHIS->acceptProposedAction();
        } else {
            if (DRAGMOVETHIS->possibleActions().testFlag(qtAction)) {
                DRAGMOVETHIS->setDropAction(qtAction);
                DRAGMOVETHIS->accept();
            } else {
                printf("DragMoveEvent_acceptDropAction: specified action was not in allowed set\n");
            }
        }
    }

//    void DragMoveEvent_dispose(DragMoveEventRef _this) {
//        // not owned
//    }

    // subclass/delegated stuff ==========================================================

    class DelegatedWidget : public WidgetWithHandler {
    private:
        std::shared_ptr<DelegateMethods> methods;
        MethodMask methodMask = 0;
    public:
        explicit DelegatedWidget(const std::shared_ptr<SignalHandler>& handler) : WidgetWithHandler(handler) {}
        void setDelegate(const std::shared_ptr<DelegateMethods>& methods, const MethodMask methodMask) {
            this->methods = methods;
            this->methodMask = methodMask;
        }
    protected:
        void showEvent(QShowEvent *event) override {
            if (methodMask & ShowEvent) {
                methods->showEvent(event->spontaneous());
                event->accept();
            } else {
                QWidget::showEvent(event);
            }
        }

        void paintEvent(QPaintEvent *event) override {
            if (methodMask & PaintEvent) {
                QPainter painter(this);
                methods->paintEvent(reinterpret_cast<Painter::HandleRef>(&painter), toRect(event->rect()));
                // prevent it from propagating:
                // do we allow this from the method delegate somehow?
                event->accept();
            } else {
                QWidget::paintEvent(event);
            }
        }

        void mousePressEvent(QMouseEvent *event) override {
            if (methodMask & MousePressEvent) {
                auto pos = toPoint(event->pos());
                auto button = static_cast<MouseButton>(event->button());
                auto modifiers = event->modifiers();
                methods->mousePressEvent(pos, button, modifiers);
                // prevent from propagating, see notes above
                event->accept();
            } else {
                QWidget::mousePressEvent(event);
            }
        }

        void mouseMoveEvent(QMouseEvent *event) override {
            if (methodMask & MouseMoveEvent) {
                auto pos = toPoint(event->pos());
                auto buttons = event->buttons();
                auto modifiers = event->modifiers();
                methods->mouseMoveEvent(pos, buttons, modifiers);
                // prevent from propagating, see notes above
                event->accept();
            } else {
                QWidget::mouseMoveEvent(event);
            }
        }

        void mouseReleaseEvent(QMouseEvent *event) override {
            if (methodMask & MouseReleaseEvent) {
                auto pos = toPoint(event->pos());
                auto button = static_cast<MouseButton>(event->button());
                auto modifiers = event->modifiers();
                methods->mouseReleaseEvent(pos, button, modifiers);
                event->accept();
            } else {
                QWidget::mouseReleaseEvent(event);
            }
        }

        void enterEvent(QEnterEvent *event) override {
            if (methodMask & EnterEvent) {
                auto pos = toPoint(event->position().toPoint());
                methods->enterEvent(pos);
                event->accept();
            } else {
                QWidget::enterEvent(event);
            }
        }

        void leaveEvent(QEvent *event) override {
            if (methodMask & LeaveEvent) {
                methods->leaveEvent();
                event->accept();
            } else {
                QWidget::leaveEvent(event);
            }
        }

        void resizeEvent(QResizeEvent *event) override {
            if (methodMask & ResizeEvent) {
                methods->resizeEvent(toSize(event->oldSize()), toSize(event->size()));
                event->accept();
            } else {
                QWidget::resizeEvent(event);
            }
        }

        void dragEnterEvent(QDragEnterEvent *event) override {
            if (methodMask & DropEvents) {
                auto pos = toPoint(event->position().toPoint());
                auto modifiers = event->modifiers();
                auto mimeOpaque = MimeDataRef(event->mimeData());
                auto moveEvent = reinterpret_cast<DragMoveEventRef>(event);
                methods->dragMoveEvent(pos, modifiers, mimeOpaque, moveEvent, true);
                // other side needs to call acceptProposedAction if it's OK, otherwise ... .ignore?
            } else {
                QWidget::dragEnterEvent(event);
            }
        }

        void dragMoveEvent(QDragMoveEvent *event) override {
            if (methodMask & DropEvents) {
                auto pos = toPoint(event->position().toPoint());
                auto modifiers = event->modifiers();
                auto mimeOpaque = (MimeDataRef)event->mimeData();
                auto moveEvent = reinterpret_cast<DragMoveEventRef>(event);
                methods->dragMoveEvent(pos, modifiers, mimeOpaque, moveEvent, false);
                // other side needs to call acceptProposedAction if it's OK, otherwise ... .ignore?
            } else {
                QWidget::dragMoveEvent(event);
            }
        }

        void dragLeaveEvent(QDragLeaveEvent *event) override {
            if (methodMask & DropEvents) {
                methods->dragLeaveEvent();
                event->accept();
            } else {
                QWidget::dragLeaveEvent(event);
            }
        }

        void dropEvent(QDropEvent *event) override {
            if (methodMask & DropEvents) {
                auto pos = toPoint(event->position().toPoint());
                auto modifiers = event->modifiers();
                auto mimeOpaque = (MimeDataRef)event->mimeData();
                auto action = static_cast<DropAction>(event->proposedAction());
                methods->dropEvent(pos, modifiers, mimeOpaque, action);
                event->acceptProposedAction();
            } else {
                QWidget::dropEvent(event);
            }
        }

    public:
        [[nodiscard]] QSize sizeHint() const override {
            if (methodMask & SizeHint) {
                auto size = methods->sizeHint();
                return toQSize(size);
            } else {
                return QWidget::sizeHint();
            }
        }
    };

#define DELEGATED_THIS (reinterpret_cast<DelegatedWidget*>(_this))

    void Delegated_setDelegate(DelegatedRef _this, const std::shared_ptr<DelegateMethods>& methods, MethodMask methodMask) {
        DELEGATED_THIS->setDelegate(methods, methodMask);
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<DelegatedRef>(new DelegatedWidget(handler));
    }
}

#include "Widget.moc"
