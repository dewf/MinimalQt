#include "generated/MainWindow.h"

#include <qevent.h>

#include "DockWidgetInternal.h"
#include "MainWindowInternal.h"
#include "MenuBarInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MAINWINDOW_THIS (WRAPPER->getActual())

namespace MainWindow
{
    bool Handle_isAnimated(HandleRef _this) {
        return MAINWINDOW_THIS->isAnimated();
    }

    void Handle_setAnimated(HandleRef _this, bool state) {
        MAINWINDOW_THIS->setAnimated(state);
    }

    bool Handle_isDockNestingEnabled(HandleRef _this) {
        return MAINWINDOW_THIS->isDockNestingEnabled();
    }

    void Handle_setDockNestingEnabled(HandleRef _this, bool state) {
        MAINWINDOW_THIS->setDockNestingEnabled(state);
    }

    DockOptions Handle_getDockOptions(HandleRef _this) {
        return MAINWINDOW_THIS->dockOptions();
    }

    void Handle_setDockOptions(HandleRef _this, DockOptions dockOptions) {
        MAINWINDOW_THIS->setDockOptions(static_cast<QMainWindow::DockOptions>(dockOptions));
    }

    bool Handle_documentMode(HandleRef _this) {
        return MAINWINDOW_THIS->documentMode();
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        MAINWINDOW_THIS->setDocumentMode(state);
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(MAINWINDOW_THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        MAINWINDOW_THIS->setIconSize(toQSize(size));
    }

    TabShape Handle_getTabShape(HandleRef _this) {
        return static_cast<TabShape>(MAINWINDOW_THIS->tabShape());
    }

    void Handle_setTabShape(HandleRef _this, TabShape tabShape) {
        MAINWINDOW_THIS->setTabShape(static_cast<QTabWidget::TabShape>(tabShape));
    }

    ToolButtonStyle Handle_getToolButtonStyle(HandleRef _this) {
        return static_cast<ToolButtonStyle>(MAINWINDOW_THIS->toolButtonStyle());
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        MAINWINDOW_THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    bool Handle_unifiedTitleAndToolBarOnMac(HandleRef _this) {
        return MAINWINDOW_THIS->unifiedTitleAndToolBarOnMac();
    }

    void Handle_setUnifiedTitleAndToolBarOnMac(HandleRef _this, bool state) {
        MAINWINDOW_THIS->setUnifiedTitleAndToolBarOnMac(state);
    }

    // methods =================================

    void Handle_addDockWidget(HandleRef _this, DockWidgetArea area, DockWidget::HandleRef dockWidget, const std::optional<Orientation>& orientation) {
        const auto dockWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockWidget);
        if (orientation.has_value()) {
            const auto qOrientation = static_cast<Qt::Orientation>(orientation.value());
            MAINWINDOW_THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), dockWrapper->getActual(), qOrientation);
        } else {
            MAINWINDOW_THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), dockWrapper->getActual()); // weird that Qt has 2 different methods, vs. one with an optional param ...
        }
    }

    void Handle_setCentralWidget(HandleRef _this, Widget::HandleRef widget) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        MAINWINDOW_THIS->setCentralWidget(widgetWrapper->getActual());
    }

    void Handle_setMenuBar(HandleRef _this, MenuBar::HandleRef menubar) {
        const auto menuBarWrapper = reinterpret_cast<MenuBar::SignalWrapper*>(menubar);
        MAINWINDOW_THIS->setMenuBar(menuBarWrapper->getActual());
    }

    void Handle_setStatusBar(HandleRef _this, StatusBar::HandleRef statusbar) {
        MAINWINDOW_THIS->setStatusBar(reinterpret_cast<QStatusBar *>(statusbar));
    }

    void Handle_addToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        MAINWINDOW_THIS->addToolBar(reinterpret_cast<QToolBar *>(toolbar));
    }

    void Handle_addToolBar(HandleRef _this, ToolBarArea area, ToolBar::HandleRef toolbar) {
        MAINWINDOW_THIS->addToolBar(static_cast<Qt::ToolBarArea>(area), reinterpret_cast<QToolBar*>(toolbar));
    }

    // etc =====================================

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QMainWindow(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    // delegated =============================================
    class Delegated : public QMainWindow {
    private:
        std::shared_ptr<DelegatedMethods> methods;
        DelegatedMethodMask mask = 0;
    public:
        void setDelegate(const std::shared_ptr<DelegatedMethods>& methods, DelegatedMethodMask mask) {
            this->methods = methods;
            this->mask = mask;
        }
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

    void Delegated_setDelegate(DelegatedRef _this, const std::shared_ptr<DelegatedMethods>& methods, DelegatedMethodMask mask) {
        if (const auto delegated = dynamic_cast<Delegated*>(WRAPPER->getActual()); delegated != nullptr) {
            delegated->setDelegate(methods, mask);
        } else {
            printf("warning: MainWindow::Delegated_setDelegate: dynamic cast failed\n");
        }
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete WRAPPER;
    }

    DelegatedRef createDelegated(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new Delegated(), handler);
        return reinterpret_cast<DelegatedRef>(wrapper);
    }
}
