#include "generated/MainWindow.h"

#include <qevent.h>

#include "ObjectInternal.h"
#include "DockWidgetInternal.h"
#include "MainWindowInternal.h"
#include "MenuBarInternal.h"
#include "MenuInternal.h"
#include "StatusBarInternal.h"
#include "ToolBarInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::Enums;
using namespace ::Widget;
using namespace ::Layout;
using namespace ::Menu;
using namespace ::MenuBar;
using namespace ::Icon;
using namespace ::DockWidget;
using namespace ::ToolBar;
using namespace ::StatusBar;
using namespace ::TabWidget;

#define THIS (reinterpret_cast<QMainWindow*>(_this))

namespace MainWindow
{
    void Handle_addDockWidget(HandleRef _this, DockWidgetArea area, DockWidget::HandleRef dockwidget) {
        THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), AS_QDOCKWIDGET_PTR(dockwidget));
    }

    void Handle_addDockWidget(HandleRef _this, DockWidgetArea area, DockWidget::HandleRef dockwidget, Orientation orientation) {
        THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), AS_QDOCKWIDGET_PTR(dockwidget), static_cast<Qt::Orientation>(orientation));
    }

    void Handle_addToolBar(HandleRef _this, ToolBarArea area, ToolBar::HandleRef toolbar) {
        THIS->addToolBar(static_cast<Qt::ToolBarArea>(area), AS_QTOOLBAR_PTR(toolbar));
    }

    void Handle_addToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        THIS->addToolBar(AS_QTOOLBAR_PTR(toolbar));
    }

    ToolBar::HandleRef Handle_addToolBar(HandleRef _this, const std::string& title) {
        return reinterpret_cast<ToolBar::HandleRef>(THIS->addToolBar(QString::fromStdString(title)));
    }

    void Handle_addToolBarBreak(HandleRef _this, ToolBarArea area /* ToolBarArea::TopToolBarArea */) {
        THIS->addToolBarBreak(static_cast<Qt::ToolBarArea>(area));
    }

    Widget::HandleRef Handle_centralWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->centralWidget());
    }

    DockWidgetArea Handle_corner(HandleRef _this, Corner corner) {
        return static_cast<DockWidgetArea>(THIS->corner(static_cast<Qt::Corner>(corner)));
    }

    Menu::HandleRef Handle_createPopupMenu(HandleRef _this) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createPopupMenu());
    }

    DockOptions Handle_getDockOptions(HandleRef _this) {
        return DockOptions(THIS->dockOptions());
    }

    DockWidgetArea Handle_dockWidgetArea(HandleRef _this, DockWidget::HandleRef dockwidget) {
        return static_cast<DockWidgetArea>(THIS->dockWidgetArea(AS_QDOCKWIDGET_PTR(dockwidget)));
    }

    bool Handle_documentMode(HandleRef _this) {
        return THIS->documentMode();
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_insertToolBar(HandleRef _this, ToolBar::HandleRef before, ToolBar::HandleRef toolbar) {
        THIS->insertToolBar(AS_QTOOLBAR_PTR(before), AS_QTOOLBAR_PTR(toolbar));
    }

    void Handle_insertToolBarBreak(HandleRef _this, ToolBar::HandleRef before) {
        THIS->insertToolBarBreak(AS_QTOOLBAR_PTR(before));
    }

    bool Handle_isAnimated(HandleRef _this) {
        return THIS->isAnimated();
    }

    bool Handle_isDockNestingEnabled(HandleRef _this) {
        return THIS->isDockNestingEnabled();
    }

    MenuBar::HandleRef Handle_menuBar(HandleRef _this) {
        return reinterpret_cast<MenuBar::HandleRef>(THIS->menuBar());
    }

    Widget::HandleRef Handle_menuWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->menuWidget());
    }

    void Handle_removeDockWidget(HandleRef _this, DockWidget::HandleRef dockwidget) {
        THIS->removeDockWidget(AS_QDOCKWIDGET_PTR(dockwidget));
    }

    void Handle_removeToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        THIS->removeToolBar(AS_QTOOLBAR_PTR(toolbar));
    }

    void Handle_removeToolBarBreak(HandleRef _this, ToolBar::HandleRef before) {
        THIS->removeToolBarBreak(AS_QTOOLBAR_PTR(before));
    }

    void Handle_resizeDocks(HandleRef _this, const std::vector<DockWidget::HandleRef>& docks, const std::vector<int32_t>& sizes, Orientation orientation) {
        const auto qDocks = toQList<DockWidget::HandleRef,QDockWidget*>(docks, [](auto d) {
            return AS_QDOCKWIDGET_PTR(d);
        });
        const auto qSizes = toQList<int32_t,int>(sizes, idFunc<int>);
        THIS->resizeDocks(qDocks, qSizes, static_cast<Qt::Orientation>(orientation));
    }

    bool Handle_restoreDockWidget(HandleRef _this, DockWidget::HandleRef dockwidget) {
        return THIS->restoreDockWidget(AS_QDOCKWIDGET_PTR(dockwidget));
    }

    bool Handle_restoreState(HandleRef _this, const std::vector<uint8_t>& state, int32_t version /* 0 */) {
        return THIS->restoreState(toQByteArray(state), version);
    }

    std::vector<uint8_t> Handle_saveState(HandleRef _this, int32_t version /* 0 */) {
        return fromQByteArray(THIS->saveState(version));
    }

    void Handle_setCentralWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setCentralWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setCorner(HandleRef _this, Corner corner, DockWidgetArea area) {
        THIS->setCorner(static_cast<Qt::Corner>(corner), static_cast<Qt::DockWidgetArea>(area));
    }

    void Handle_setDockOptions(HandleRef _this, DockOptions options_) {
        THIS->setDockOptions(static_cast<QMainWindow::DockOptions>(options_.value));
    }

    void Handle_setDocumentMode(HandleRef _this, bool enabled) {
        THIS->setDocumentMode(enabled);
    }

    void Handle_setIconSize(HandleRef _this, Size iconSize) {
        THIS->setIconSize(toQSize(iconSize));
    }

    void Handle_setMenuBar(HandleRef _this, MenuBar::HandleRef menuBar) {
        THIS->setMenuBar(reinterpret_cast<QMenuBar*>(menuBar));
    }

    void Handle_setMenuWidget(HandleRef _this, Widget::HandleRef menuBar) {
        THIS->setMenuWidget(AS_QWIDGET_PTR(menuBar));
    }

    void Handle_setStatusBar(HandleRef _this, StatusBar::HandleRef statusbar) {
        THIS->setStatusBar(reinterpret_cast<QStatusBar*>(statusbar));
    }

    void Handle_setTabPosition(HandleRef _this, DockWidgetAreas areas, TabPosition tabPosition) {
        THIS->setTabPosition(static_cast<Qt::DockWidgetAreas>(areas.value), static_cast<QTabWidget::TabPosition>(tabPosition));
    }

    void Handle_setTabShape(HandleRef _this, TabShape tabShape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(tabShape));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle toolButtonStyle) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(toolButtonStyle));
    }

    void Handle_splitDockWidget(HandleRef _this, DockWidget::HandleRef first, DockWidget::HandleRef second, Orientation orientation) {
        THIS->splitDockWidget(AS_QDOCKWIDGET_PTR(first), AS_QDOCKWIDGET_PTR(second), static_cast<Qt::Orientation>(orientation));
    }

    StatusBar::HandleRef Handle_statusBar(HandleRef _this) {
        return reinterpret_cast<StatusBar::HandleRef>(THIS->statusBar());
    }

    TabPosition Handle_tabPosition(HandleRef _this, DockWidgetArea area) {
        return static_cast<TabPosition>(THIS->tabPosition(static_cast<Qt::DockWidgetArea>(area)));
    }

    TabShape Handle_tabShape(HandleRef _this) {
        return static_cast<TabShape>(THIS->tabShape());
    }

    std::vector<DockWidget::HandleRef> Handle_tabifiedDockWidgets(HandleRef _this, DockWidget::HandleRef dockwidget) {
        const auto result = THIS->tabifiedDockWidgets(AS_QDOCKWIDGET_PTR(dockwidget));
        return fromQList<QDockWidget*,DockWidget::HandleRef>(result, [](auto dw) {
            return reinterpret_cast<DockWidget::HandleRef>(dw);
        });
    }

    void Handle_tabifyDockWidget(HandleRef _this, DockWidget::HandleRef first, DockWidget::HandleRef second) {
        THIS->tabifyDockWidget(AS_QDOCKWIDGET_PTR(first), AS_QDOCKWIDGET_PTR(second));
    }

    Widget::HandleRef Handle_takeCentralWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->takeCentralWidget());
    }

    ToolBarArea Handle_getToolBarArea(HandleRef _this, ToolBar::HandleRef toolbar) {
        return static_cast<ToolBarArea>(THIS->toolBarArea(AS_QTOOLBAR_PTR(toolbar)));
    }

    bool Handle_toolBarBreak(HandleRef _this, ToolBar::HandleRef toolbar) {
        return THIS->toolBarBreak(AS_QTOOLBAR_PTR(toolbar));
    }

    ToolButtonStyle Handle_toolButtonStyle(HandleRef _this) {
        return static_cast<ToolButtonStyle>(THIS->toolButtonStyle());
    }

    bool Handle_unifiedTitleAndToolBarOnMac(HandleRef _this) {
        return THIS->unifiedTitleAndToolBarOnMac();
    }

    void Handle_setAnimated(HandleRef _this, bool enabled) {
        THIS->setAnimated(enabled);
    }

    void Handle_setDockNestingEnabled(HandleRef _this, bool enabled) {
        THIS->setDockNestingEnabled(enabled);
    }

    void Handle_setUnifiedTitleAndToolBarOnMac(HandleRef _this, bool set) {
        THIS->setUnifiedTitleAndToolBarOnMac(set);
    }

    SignalConnectionRef Handle_connect_IconSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMainWindow::iconSizeChanged, [handler](const QSize& size) {
            handler->iconSizeChanged(toSize(size));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabifiedDockWidgetActivated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMainWindow::tabifiedDockWidgetActivated, [handler](QDockWidget* dockWidget) {
            handler->tabifiedDockWidgetActivated(reinterpret_cast<DockWidget::HandleRef>(dockWidget));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ToolButtonStyleChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QMainWindow::toolButtonStyleChanged, [handler](Qt::ToolButtonStyle style) {
            handler->toolButtonStyleChanged(static_cast<ToolButtonStyle>(style));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<HandleRef>(new QMainWindow(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value)));
    }

    // delegated ================================================================================================================

#define DELEGATED_THIS (reinterpret_cast<Delegated*>(_this))

    class Delegated : public QMainWindow {
        std::shared_ptr<DelegatedMethods> methods;
        DelegatedMethodMask mask = 0;
    public:
        Delegated(QWidget *parent, const Qt::WindowFlags &flags, const std::shared_ptr<DelegatedMethods> &methods,
            DelegatedMethodMask mask)
            : QMainWindow(parent, flags),
              methods(methods),
              mask(mask) {}
    protected:
        void closeEvent(QCloseEvent *event) override {
            bool canClose = true;
            if (mask & CanClose) {
                canClose = methods->canClose();
            }
            if (canClose) {
                // definitely going to close
                if (mask & Closed) {
                    methods->closed();
                }
            } else {
                // ignore close event
                event->ignore();
            }
        }
    };

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated(const std::shared_ptr<DelegatedMethods>& methods, DelegatedMethodMask mask, Widget::HandleRef parent /* nullptr */, WindowFlags flags_ /* 0 */) {
        return reinterpret_cast<DelegatedRef>(new Delegated(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(flags_.value), methods, mask));
    }
}
