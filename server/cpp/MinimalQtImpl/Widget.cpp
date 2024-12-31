#include "generated/Widget.h"
#include "WidgetInternal.h"

#include <QObject>
#include <QWidget>

#include <QPainter>
#include <QPaintEvent>

#include <QMimeData>
#include <QDrag>
#include <utility>

#include "ActionInternal.h"
#include "FontInternal.h"
#include "util/convert.h"
#include "IconInternal.h"
#include "SizePolicyInternal.h"
#include "CursorInternal.h"
#include "LayoutInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define WIDGET_THIS (WRAPPER->getActual())

namespace Widget
{
    const int32_t WIDGET_SIZE_MAX = QWIDGETSIZE_MAX;

    bool Handle_acceptDrops(HandleRef _this) {
        return WIDGET_THIS->acceptDrops();
    }

    void Handle_setAcceptDrops(HandleRef _this, bool state) {
        WIDGET_THIS->setAcceptDrops(state);
    }

    std::string Handle_accessibleDescription(HandleRef _this) {
        return WIDGET_THIS->accessibleDescription().toStdString();
    }

    void Handle_setAccessibleDescription(HandleRef _this, const std::string& desc) {
        WIDGET_THIS->setAccessibleDescription(QString::fromStdString(desc));
    }

    std::string Handle_accessibleName(HandleRef _this) {
        return WIDGET_THIS->accessibleName().toStdString();
    }

    void Handle_setAccessibleName(HandleRef _this, const std::string& name) {
        WIDGET_THIS->setAccessibleName(QString::fromStdString(name));
    }

    bool Handle_autoFillBackground(HandleRef _this) {
        return WIDGET_THIS->autoFillBackground();
    }

    void Handle_setAutoFillBackground(HandleRef _this, bool state) {
        WIDGET_THIS->setAutoFillBackground(state);
    }

    Size Handle_baseSize(HandleRef _this) {
        return toSize(WIDGET_THIS->baseSize());
    }

    void Handle_setBaseSize(HandleRef _this, Size size) {
        WIDGET_THIS->setBaseSize(toQSize(size));
    }

    Rect Handle_childrenRect(HandleRef _this) {
        return toRect(WIDGET_THIS->childrenRect());
    }

    Region::OwnedRef Handle_childrenRegion(HandleRef _this) {
        auto ret = WIDGET_THIS->childrenRegion();
        return reinterpret_cast<Region::OwnedRef>(new QRegion(ret));
    }

    ContextMenuPolicy Handle_contextMenuPolicy(HandleRef _this) {
        return static_cast<ContextMenuPolicy>(WIDGET_THIS->contextMenuPolicy());
    }

    void Handle_setContextMenuPolicy(HandleRef _this, ContextMenuPolicy policy) {
        WIDGET_THIS->setContextMenuPolicy(static_cast<Qt::ContextMenuPolicy>(policy));
    }

    Cursor::OwnedRef Handle_getCursor(HandleRef _this) {
        return CURSOR_HEAP_NEW(WIDGET_THIS->cursor());
    }

    void Handle_setCursor(HandleRef _this, Cursor::HandleRef cursor) {
        WIDGET_THIS->setCursor(QCURSOR_VALUE(cursor));
    }

    bool Handle_isEnabled(HandleRef _this) {
        return WIDGET_THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        WIDGET_THIS->setEnabled(enabled);
    }

    bool Handle_hasFocus(HandleRef _this) {
        return WIDGET_THIS->hasFocus();
    }

    FocusPolicy Handle_getFocusPolicy(HandleRef _this) {
        return WIDGET_THIS->focusPolicy();
    }

    void Handle_setFocusPolicy(HandleRef _this, FocusPolicy policy) {
        WIDGET_THIS->setFocusPolicy(static_cast<Qt::FocusPolicy>(policy));
    }

    Font::OwnedRef Handle_getFont(HandleRef _this) {
        return FONT_HEAP_NEW(WIDGET_THIS->font());
    }

    void Handle_setFont(HandleRef _this, Font::HandleRef font) {
        WIDGET_THIS->setFont(QFONT_VALUE(font));
    }

    Rect Handle_frameGeometry(HandleRef _this) {
        return toRect(WIDGET_THIS->frameGeometry());
    }

    Size Handle_frameSize(HandleRef _this) {
        return toSize(WIDGET_THIS->frameSize());
    }

    bool Handle_isFullscreen(HandleRef _this) {
        return WIDGET_THIS->isFullScreen();
    }

    Rect Handle_geometry(HandleRef _this) {
        return toRect(WIDGET_THIS->geometry());
    }

    void Handle_setGeometry(HandleRef _this, Rect rect) {
        WIDGET_THIS->setGeometry(toQRect(rect));
    }

    void Handle_setGeometry(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        WIDGET_THIS->setGeometry(x, y, width, height);
    }

    int32_t Handle_height(HandleRef _this) {
        return WIDGET_THIS->height();
    }

    InputMethodHints Handle_getInputMethodHints(HandleRef _this) {
        return WIDGET_THIS->inputMethodHints();
    }

    void Handle_setInputMethodHints(HandleRef _this, InputMethodHints hints) {
        WIDGET_THIS->setInputMethodHints(static_cast<Qt::InputMethodHints>(hints));
    }

    bool Handle_isActiveWindow(HandleRef _this) {
        return WIDGET_THIS->isActiveWindow();
    }

    LayoutDirection Handle_getLayoutDirection(HandleRef _this) {
        return static_cast<LayoutDirection>(WIDGET_THIS->layoutDirection());
    }

    void Handle_setLayoutDirection(HandleRef _this, LayoutDirection direction) {
        WIDGET_THIS->setLayoutDirection(static_cast<Qt::LayoutDirection>(direction));
    }

    bool Handle_isMaximized(HandleRef _this) {
        return WIDGET_THIS->isMaximized();
    }

    int32_t Handle_maximumHeight(HandleRef _this) {
        return WIDGET_THIS->maximumHeight();
    }

    void Handle_setMaximumHeight(HandleRef _this, int32_t height) {
        WIDGET_THIS->setMaximumHeight(height);
    }

    Size Handle_maximumSize(HandleRef _this) {
        return toSize(WIDGET_THIS->maximumSize());
    }

    void Handle_setMaximumSize(HandleRef _this, Size size) {
        WIDGET_THIS->setMaximumSize(toQSize(size));
    }

    int32_t Handle_maximumWidth(HandleRef _this) {
        return WIDGET_THIS->maximumWidth();
    }

    void Handle_setMaximumWidth(HandleRef _this, int32_t width) {
        WIDGET_THIS->setMaximumWidth(width);
    }

    bool Handle_isMinimized(HandleRef _this) {
        return WIDGET_THIS->isMinimized();
    }

    int32_t Handle_minimumHeight(HandleRef _this) {
        return WIDGET_THIS->minimumHeight();
    }

    void Handle_setMinimumHeight(HandleRef _this, int32_t height) {
        WIDGET_THIS->setMinimumHeight(height);
    }

    Size Handle_minimumSize(HandleRef _this) {
        return toSize(WIDGET_THIS->minimumSize());
    }

    void Handle_setMinimumSize(HandleRef _this, Size size) {
        WIDGET_THIS->setMinimumSize(toQSize(size));
    }

    Size Handle_minimumSizeHint(HandleRef _this) {
        return toSize(WIDGET_THIS->minimumSizeHint());
    }

    int32_t Handle_minimumWidth(HandleRef _this) {
        return WIDGET_THIS->minimumWidth();
    }

    void Handle_setMinimumWidth(HandleRef _this, int32_t width) {
        WIDGET_THIS->setMinimumWidth(width);
    }

    bool Handle_isModal(HandleRef _this) {
        return WIDGET_THIS->isModal();
    }

    bool Handle_hasMouseTracking(HandleRef _this) {
        return WIDGET_THIS->hasMouseTracking();
    }

    void Handle_setMouseTracking(HandleRef _this, bool state) {
        WIDGET_THIS->setMouseTracking(state);
    }

    Rect Handle_normalGeometry(HandleRef _this) {
        return toRect(WIDGET_THIS->normalGeometry());
    }

    Point Handle_pos(HandleRef _this) {
        return toPoint(WIDGET_THIS->pos());
    }

    void Handle_move(HandleRef _this, Point p) {
        WIDGET_THIS->move(toQPoint(p));
    }

    void Handle_move(HandleRef _this, int32_t x, int32_t y) {
        WIDGET_THIS->move(x, y);
    }

    Rect Handle_rect(HandleRef _this) {
        return toRect(WIDGET_THIS->rect());
    }

    Size Handle_getSize(HandleRef _this) {
        return toSize(WIDGET_THIS->size());
    }

    void Handle_resize(HandleRef _this, Size size) {
        WIDGET_THIS->resize(toQSize(size));
    }

    void Handle_resize(HandleRef _this, int32_t width, int32_t height) {
        WIDGET_THIS->resize(width, height);
    }

    Size Handle_sizeHint(HandleRef _this) {
        return toSize(WIDGET_THIS->sizeHint());
    }

    Size Handle_sizeIncrement(HandleRef _this) {
        return toSize(WIDGET_THIS->sizeIncrement());
    }

    void Handle_setSizeIncrement(HandleRef _this, Common::Size size) {
        WIDGET_THIS->setSizeIncrement(toQSize(size));
    }

    void Handle_setSizeIncrement(HandleRef _this, int32_t w, int32_t h) {
        WIDGET_THIS->setSizeIncrement(w, h);
    }

    SizePolicy::OwnedRef Handle_getSizePolicy(HandleRef _this) {
        return SIZEPOLICY_HEAP_NEW(WIDGET_THIS->sizePolicy());
    }

    void Handle_setSizePolicy(HandleRef _this, SizePolicy::HandleRef policy) {
        WIDGET_THIS->setSizePolicy(QSIZEPOLICY_VALUE(policy));
    }

    void Handle_setSizePolicy(HandleRef _this, Policy hPolicy, Policy vPolicy) {
        WIDGET_THIS->setSizePolicy(static_cast<QSizePolicy::Policy>(hPolicy), static_cast<QSizePolicy::Policy>(vPolicy));
    }

    std::string Handle_statusTip(HandleRef _this) {
        return WIDGET_THIS->statusTip().toStdString();
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        WIDGET_THIS->setStatusTip(QString::fromStdString(tip));
    }

    std::string Handle_styleSheet(HandleRef _this) {
        return WIDGET_THIS->styleSheet().toStdString();
    }

    void Handle_setStyleSheet(HandleRef _this, const std::string& styles) {
        WIDGET_THIS->setStyleSheet(QString::fromStdString(styles));
    }

    bool Handle_hasTabletTracking(HandleRef _this) {
        return WIDGET_THIS->hasTabletTracking();
    }

    void Handle_setTabletTracking(HandleRef _this, bool state) {
        WIDGET_THIS->setTabletTracking(state);
    }

    std::string Handle_toolTip(HandleRef _this) {
        return WIDGET_THIS->toolTip().toStdString();
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        WIDGET_THIS->setToolTip(QString::fromStdString(tip));
    }

    int32_t Handle_toolTipDuration(HandleRef _this) {
        return WIDGET_THIS->toolTipDuration();
    }

    void Handle_setToolTipDuration(HandleRef _this, int32_t duration) {
        WIDGET_THIS->setToolTipDuration(duration);
    }

    bool Handle_updatesEnabled(HandleRef _this) {
        return WIDGET_THIS->updatesEnabled();
    }

    void Handle_setUpdatesEnabled(HandleRef _this, bool enabled) {
        WIDGET_THIS->setUpdatesEnabled(enabled);
    }

    bool Handle_isVisible(HandleRef _this) {
        return WIDGET_THIS->isVisible();
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        WIDGET_THIS->setVisible(visible);
    }

    std::string Handle_whatsThis(HandleRef _this) {
        return WIDGET_THIS->whatsThis().toStdString();
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        WIDGET_THIS->setWhatsThis(QString::fromStdString(text));
    }

    int32_t Handle_width(HandleRef _this) {
        return WIDGET_THIS->width();
    }

    std::string Handle_windowFilePath(HandleRef _this) {
        return WIDGET_THIS->windowFilePath().toStdString();
    }

    void Handle_setWindowFilePath(HandleRef _this, const std::string& path) {
        WIDGET_THIS->setWindowFilePath(QString::fromStdString(path));
    }

    WindowFlags Handle_getWindowFlags(HandleRef _this) {
        return WIDGET_THIS->windowFlags();
    }

    void Handle_setWindowFlags(HandleRef _this, WindowFlags flags_) {
        WIDGET_THIS->setWindowFlags(static_cast<Qt::WindowFlags>(flags_));
    }

    Icon::OwnedRef Handle_windowIcon(HandleRef _this) {
        return ICON_HEAP_NEW(WIDGET_THIS->windowIcon());
    }

    void Handle_setWindowIcon(HandleRef _this, Icon::HandleRef icon) {
        WIDGET_THIS->setWindowIcon(QICON_VALUE(icon));
    }

    WindowModality Handle_getWindowModality(HandleRef _this) {
        return static_cast<WindowModality>(WIDGET_THIS->windowModality());
    }

    void Handle_setWindowModality(HandleRef _this, WindowModality modality) {
        WIDGET_THIS->setWindowModality(static_cast<Qt::WindowModality>(modality));
    }

    bool Handle_isWindowModified(HandleRef _this) {
        return WIDGET_THIS->isWindowModified();
    }

    void Handle_setWindowModified(HandleRef _this, bool modified) {
        WIDGET_THIS->setWindowModified(modified);
    }

    double Handle_windowOpacity(HandleRef _this) {
        return WIDGET_THIS->windowOpacity();
    }

    void Handle_setWindowOpacity(HandleRef _this, double opacity) {
        WIDGET_THIS->setWindowOpacity(opacity);
    }

    std::string Handle_windowTitle(HandleRef _this) {
        return WIDGET_THIS->windowTitle().toStdString();
    }

    void Handle_setWindowTitle(HandleRef _this, const std::string& title) {
        WIDGET_THIS->setWindowTitle(QString::fromStdString(title));
    }

    int32_t Handle_x(HandleRef _this) {
        return WIDGET_THIS->x();
    }

    int32_t Handle_y(HandleRef _this) {
        return WIDGET_THIS->y();
    }

    // methods ====================================================

    void Handle_addAction(HandleRef _this, Action::HandleRef action) {
        const auto actionWrapper = reinterpret_cast<Action::SignalWrapper*>(action);
        WIDGET_THIS->addAction(actionWrapper->getActual());
    }

    HandleRef Handle_getWindow(HandleRef _this) {
        const auto wrapper = wrapperForQObject(WIDGET_THIS->window());
        return reinterpret_cast<HandleRef>(wrapper);
    }

    void Handle_updateGeometry(HandleRef _this) {
        WIDGET_THIS->updateGeometry();
    }

    void Handle_adjustSize(HandleRef _this) {
        WIDGET_THIS->adjustSize();
    }

    void Handle_setFixedWidth(HandleRef _this, int32_t width) {
        WIDGET_THIS->setFixedWidth(width);
    }

    void Handle_setFixedHeight(HandleRef _this, int32_t height) {
        WIDGET_THIS->setFixedHeight(height);
    }

    void Handle_setFixedSize(HandleRef _this, Size size) {
        WIDGET_THIS->setFixedSize(toQSize(size));
    }

    void Handle_setFixedSize(HandleRef _this, int32_t width, int32_t height) {
        WIDGET_THIS->setFixedSize(width, height);
    }

    void Handle_show(HandleRef _this) {
        WIDGET_THIS->show();
    }

    void Handle_hide(HandleRef _this) {
        WIDGET_THIS->hide();
    }

    void Handle_update(HandleRef _this) {
        WIDGET_THIS->update();
    }

    void Handle_update(HandleRef _this, int32_t x, int32_t y, int32_t width, int32_t height) {
        WIDGET_THIS->update(x, y, width, height);
    }

    void Handle_update(HandleRef _this, Rect rect) {
        WIDGET_THIS->update(toQRect(rect));
    }

    void Handle_setLayout(HandleRef _this, Layout::HandleRef layout) {
        const auto layoutWrapper = reinterpret_cast<Layout::SignalWrapper*>(layout);
        WIDGET_THIS->setLayout(layoutWrapper->getActual());
    }

    std::shared_ptr<LayoutResult::Base> Handle_getLayout(HandleRef _this) {
        if (const auto layout = WIDGET_THIS->layout(); layout != nullptr) {
            // check for existing wrapper (ie, did we originally set the layout ourselves?)
            if (const auto existing = wrapperForQObject(layout); existing != nullptr) {
                const auto handleRef = reinterpret_cast<Layout::HandleRef>(existing);
                return std::make_shared<LayoutResult::AlreadyExists>(handleRef);
            }
            // else, unknown (Qt-supplied) default, need to create a new wrapper
            // return a function which can create one on-demand
            const auto func = [layout](const std::shared_ptr<Layout::SignalHandler>& handler) {
                const auto wrapper = new Layout::SignalWrapper(layout, handler);
                return reinterpret_cast<Layout::HandleRef>(wrapper);
            };
            return std::make_shared<LayoutResult::NeedsWrapper>(func);
        }
        // else
        return std::make_shared<LayoutResult::NoLayout>();
    }

    Point Handle_mapToGlobal(HandleRef _this, Point p) {
        auto p2 = WIDGET_THIS->mapToGlobal(toQPoint(p));
        return toPoint(p2);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QWidget(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    class NullWidgetSignalHandler : public ServerObject, public SignalHandler, public Object::SignalHandler { // don't think it even needs to be a ServerObject since it's never going anywhere, but whatever
    public:
        void destroyedByQt() override {}
        void destroyed(Object::HandleRef obj) override {}
        void objectNameChanged(const std::string &objectName) override {}
        Object::SignalHandler * inherited_Object_SignalHandler() override { return this; }
        void customContextMenuRequested(Point pos) override {}
        void windowIconChanged(Icon::HandleRef icon) override {}
        void windowTitleChanged(const std::string &title) override {}
    };

    HandleRef createNoHandler() {
        const auto wrapper = new SignalWrapper(new QWidget(), std::make_shared<NullWidgetSignalHandler>());
        return reinterpret_cast<HandleRef>(wrapper);
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

    class DelegatedWidget : public QWidget {
    private:
        std::shared_ptr<DelegateMethods> methods;
        MethodMask methodMask = 0;
    public:
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

    void Delegated_setDelegate(DelegatedRef _this, const std::shared_ptr<DelegateMethods>& methods, MethodMask methodMask) {
        if (const auto delegated = dynamic_cast<DelegatedWidget*>(WIDGET_THIS); delegated != nullptr) {
            delegated->setDelegate(methods, methodMask);
        } else {
            printf("Widget::Delegated_setDelegate: dynamic cast failed, could not set delegate\n");
        }
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete WRAPPER;
    }

    DelegatedRef createDelegated(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new DelegatedWidget(), handler);
        return reinterpret_cast<DelegatedRef>(wrapper);
    }
}
