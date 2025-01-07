#include "generated/MainWindow.h"

#include <qevent.h>

#include "DockWidgetInternal.h"
#include "MainWindowInternal.h"
#include "MenuBarInternal.h"
#include "MenuInternal.h"
#include "StatusBarInternal.h"
#include "ToolBarInternal.h"

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

    void Handle_addDockWidget(HandleRef _this, DockWidgetArea area, DockWidget::HandleRef dockWidget, const std::optional<Orientation>& orientation) {
        const auto dockWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockWidget);
        if (orientation.has_value()) {
            const auto qOrientation = static_cast<Qt::Orientation>(orientation.value());
            MAINWINDOW_THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), dockWrapper->getActual(), qOrientation);
        } else {
            MAINWINDOW_THIS->addDockWidget(static_cast<Qt::DockWidgetArea>(area), dockWrapper->getActual()); // weird that Qt has 2 different methods, vs. one with an optional param ...
        }
    }

    void Handle_addToolBar(HandleRef _this, ToolBarArea area, ToolBar::HandleRef toolbar) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        MAINWINDOW_THIS->addToolBar(static_cast<Qt::ToolBarArea>(area), wrapper->getActual());
    }

    void Handle_addToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        MAINWINDOW_THIS->addToolBar(wrapper->getActual());
    }

    ToolBar::HandleRef Handle_addToolBar(HandleRef _this, const std::string& title, const std::shared_ptr<ToolBar::SignalHandler>& handler) {
        const auto created = MAINWINDOW_THIS->addToolBar(QString::fromStdString(title));
        const auto wrapper = new ToolBar::SignalWrapper(created, handler);
        return reinterpret_cast<ToolBar::HandleRef>(wrapper);
    }

    void Handle_addToolBarBreak(HandleRef _this, const std::optional<ToolBarArea>& area) {
        const auto qArea = optionOrDefaultStaticCast(area, Qt::TopToolBarArea);
        MAINWINDOW_THIS->addToolBarBreak(qArea);
    }

    Widget::HandleRef Handle_centralWidget(HandleRef _this) {
        if (const auto widget = MAINWINDOW_THIS->centralWidget(); widget != nullptr) {
            // must have been set by us prior, so it will exist
            const auto wrapper = wrapperForQObject(widget);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    DockWidgetArea Handle_corner(HandleRef _this, Corner corner) {
        return static_cast<DockWidgetArea>(MAINWINDOW_THIS->corner(static_cast<Qt::Corner>(corner)));
    }

    std::shared_ptr<PopupMenuResult::Base> Handle_createPopupMenu(HandleRef _this) {
        if (const auto menu = MAINWINDOW_THIS->createPopupMenu(); menu != nullptr) {
            // does it have an existing wrapper?
            if (const auto wrapper = wrapperForQObject(menu); wrapper != nullptr) {
                // yes!
                return std::make_shared<PopupMenuResult::AlreadyExists>(reinterpret_cast<Menu::HandleRef>(wrapper));
            }
            // else it needs a wrapper, return a function capable of creating one
            const auto wrapperFunc = [menu](const std::shared_ptr<Menu::SignalHandler>& handler) {
                const auto wrapper = new Menu::SignalWrapper(menu, handler);
                return reinterpret_cast<Menu::HandleRef>(wrapper);
            };
            return std::make_shared<PopupMenuResult::NeedsWrapper>(wrapperFunc);
        }
        // else, no toolbars or dock widgets, no popup menu created for us
        return std::make_shared<PopupMenuResult::NotRequired>();
    }

    DockWidgetArea Handle_getDockWidgetArea(HandleRef _this, DockWidget::HandleRef dockwidget) {
        const auto wrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockwidget);
        return static_cast<DockWidgetArea>(MAINWINDOW_THIS->dockWidgetArea(wrapper->getActual()));
    }

    void Handle_insertToolBar(HandleRef _this, ToolBar::HandleRef before, ToolBar::HandleRef toolbar) {
        const auto beforeWrapper = reinterpret_cast<ToolBar::SignalWrapper*>(before);
        const auto toolbarWrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        MAINWINDOW_THIS->insertToolBar(beforeWrapper->getActual(), toolbarWrapper->getActual());
    }

    void Handle_insertToolBarBreak(HandleRef _this, ToolBar::HandleRef before) {
        const auto beforeWrapper = reinterpret_cast<ToolBar::SignalWrapper*>(before);
        MAINWINDOW_THIS->insertToolBarBreak(beforeWrapper->getActual());
    }

    std::shared_ptr<MenuBarResult::Base> Handle_menuBar(HandleRef _this) {
        const auto menubar = MAINWINDOW_THIS->menuBar(); // either creates one, or returns what we've assigned
        assert(menubar != nullptr);
        // do we already know about it?
        if (const auto wrapper = wrapperForQObject(menubar); wrapper != nullptr) {
            // yes
            return std::make_shared<MenuBarResult::AlreadyExists>(reinterpret_cast<MenuBar::HandleRef>(wrapper));
        }
        // else, need to create a wrapper
        const auto wrapperFunc = [menubar](const std::shared_ptr<MenuBar::SignalHandler>& handler) {
            const auto wrapper = new MenuBar::SignalWrapper(menubar, handler);
            return reinterpret_cast<MenuBar::HandleRef>(wrapper);
        };
        return std::make_shared<MenuBarResult::NeedsWrapper>(wrapperFunc);
    }

    Widget::HandleRef Handle_menuWidget(HandleRef _this) {
        if (const auto menubar = MAINWINDOW_THIS->menuBar(); menubar != nullptr) {
            // something we assigned previously
            const auto wrapper = wrapperForQObject(menubar);
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    void Handle_removeDockWidget(HandleRef _this, DockWidget::HandleRef dockwidget) {
        const auto wrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockwidget);
        return MAINWINDOW_THIS->removeDockWidget(wrapper->getActual());
    }

    void Handle_removeToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        return MAINWINDOW_THIS->removeToolBar(wrapper->getActual());
    }

    void Handle_removeToolBarBreak(HandleRef _this, ToolBar::HandleRef before) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(before);
        return MAINWINDOW_THIS->removeToolBarBreak(wrapper->getActual());
    }

    void Handle_resizeDocks(HandleRef _this, const std::vector<DockWidget::HandleRef>& docks, const std::vector<int32_t>& sizes, Orientation orientation) {
        const auto qDocks = toQList<DockWidget::HandleRef,QDockWidget*>(docks, [](auto d) {
            const auto wrapper = reinterpret_cast<DockWidget::SignalWrapper*>(d);
            return wrapper->getActual();
        });
        const auto qSizes = toQList<int32_t,int>(sizes, idFunc<int>);
        MAINWINDOW_THIS->resizeDocks(qDocks, qSizes, static_cast<Qt::Orientation>(orientation));
    }

    bool Handle_restoreDockWidget(HandleRef _this, DockWidget::HandleRef dockwidget) {
        const auto wrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockwidget);
        return MAINWINDOW_THIS->restoreDockWidget(wrapper->getActual());
    }

    bool Handle_restoreState(HandleRef _this, const std::vector<uint8_t>& state, const std::optional<int32_t>& version) {
        const QByteArray qState(reinterpret_cast<const char *>(state.data()), static_cast<qsizetype>(state.size()));
        return MAINWINDOW_THIS->restoreState(qState, version.value_or(0));
    }

    std::vector<uint8_t> Handle_saveState(HandleRef _this, const std::optional<int32_t>& version) {
        const auto bytes = MAINWINDOW_THIS->saveState(version.value_or(0));
        const auto data = bytes.data();
        return std::vector<uint8_t>(data, data + bytes.length());
    }

    void Handle_setCentralWidget(HandleRef _this, Widget::HandleRef widget) {
        const auto widgetWrapper = reinterpret_cast<Widget::SignalWrapper*>(widget);
        MAINWINDOW_THIS->setCentralWidget(widgetWrapper->getActual());
    }

    void Handle_setCorner(HandleRef _this, Corner corner, DockWidgetArea area) {
        MAINWINDOW_THIS->setCorner(static_cast<Qt::Corner>(corner), static_cast<Qt::DockWidgetArea>(area));
    }

    void Handle_setMenuBar(HandleRef _this, MenuBar::HandleRef menubar) {
        const auto wrapper = reinterpret_cast<MenuBar::SignalWrapper*>(menubar);
        MAINWINDOW_THIS->setMenuBar(wrapper->getActual());
    }

    void Handle_setMenuWidget(HandleRef _this, Widget::HandleRef menubar) {
        const auto wrapper = reinterpret_cast<Widget::SignalWrapper*>(menubar);
        MAINWINDOW_THIS->setMenuWidget(wrapper->getActual());
    }

    void Handle_setStatusBar(HandleRef _this, StatusBar::HandleRef statusbar) {
        const auto wrapper = reinterpret_cast<StatusBar::SignalWrapper*>(statusbar);
        MAINWINDOW_THIS->setStatusBar(wrapper->getActual());
    }

    void Handle_setTabPosition(HandleRef _this, DockWidgetAreas areas, TabPosition tabPosition) {
        MAINWINDOW_THIS->setTabPosition(static_cast<Qt::DockWidgetAreas>(areas), static_cast<QTabWidget::TabPosition>(tabPosition));
    }

    void Handle_splitDockWidget(HandleRef _this, DockWidget::HandleRef first, DockWidget::HandleRef second, Orientation orientation) {
        const auto firstWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(first);
        const auto secondWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(second);
        MAINWINDOW_THIS->splitDockWidget(firstWrapper->getActual(), secondWrapper->getActual(), static_cast<Qt::Orientation>(orientation));
    }

    std::shared_ptr<StatusBarResult::Base> Handle_statusBar(HandleRef _this) {
        const auto statusbar = MAINWINDOW_THIS->statusBar();
        assert(statusbar != nullptr); // created if it doesn't exist
        if (const auto wrapper = wrapperForQObject(statusbar); wrapper != nullptr) {
            // already have a wrapper for it
            return std::make_shared<StatusBarResult::AlreadyExists>(reinterpret_cast<StatusBar::HandleRef>(wrapper));
        }
        // else, need to create one
        const auto wrapperFunc = [statusbar](const std::shared_ptr<StatusBar::SignalHandler>& handler) {
            const auto wrapper = new StatusBar::SignalWrapper(statusbar, handler);
            return reinterpret_cast<StatusBar::HandleRef>(wrapper);
        };
        return std::make_shared<StatusBarResult::NeedsWrapper>(wrapperFunc);
    }

    TabPosition Handle_tabPosition(HandleRef _this, DockWidgetArea area) {
        return static_cast<TabPosition>(MAINWINDOW_THIS->tabPosition(static_cast<Qt::DockWidgetArea>(area)));
    }

    std::vector<DockWidget::HandleRef> Handle_tabifiedDockWidgets(HandleRef _this, DockWidget::HandleRef dockwidget) {
        const auto dockWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(dockwidget);
        const auto result = MAINWINDOW_THIS->tabifiedDockWidgets(dockWrapper->getActual());
        return fromQList<QDockWidget*,DockWidget::HandleRef>(result, [](auto dw) {
            const auto wrapper = wrapperForQObject(dw);
            assert(wrapper != nullptr); // must exist
            return reinterpret_cast<DockWidget::HandleRef>(wrapper);
        });
    }

    void Handle_tabifyDockWidget(HandleRef _this, DockWidget::HandleRef first, DockWidget::HandleRef second) {
        const auto firstWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(first);
        const auto secondWrapper = reinterpret_cast<DockWidget::SignalWrapper*>(second);
        MAINWINDOW_THIS->tabifyDockWidget(firstWrapper->getActual(), secondWrapper->getActual());
    }

    Widget::HandleRef Handle_takeCentralWidget(HandleRef _this) {
        const auto widget = MAINWINDOW_THIS->takeCentralWidget();
        if (widget != nullptr) {
            const auto wrapper = wrapperForQObject(widget);
            assert(wrapper != nullptr); // must exist
            return reinterpret_cast<Widget::HandleRef>(wrapper);
        }
        return nullptr;
    }

    ToolBarArea Handle_toolBarArea(HandleRef _this, ToolBar::HandleRef toolbar) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        return static_cast<ToolBarArea>(MAINWINDOW_THIS->toolBarArea(wrapper->getActual()));
    }

    bool Handle_toolBarBreak(HandleRef _this, ToolBar::HandleRef toolbar) {
        const auto wrapper = reinterpret_cast<ToolBar::SignalWrapper*>(toolbar);
        return MAINWINDOW_THIS->toolBarBreak(wrapper->getActual());
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler, const std::optional<Widget::HandleRef>& parent, const std::optional<WindowFlags>& flags_) {
        const auto qParent = fromOptionalHandle(parent);
        Qt::WindowFlags qFlags;
        if (flags_.has_value()) qFlags = static_cast<Qt::WindowFlags>(flags_.value());
        const auto wrapper = new SignalWrapper(new QMainWindow(qParent, qFlags), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    // delegated ================================================================================================================

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
