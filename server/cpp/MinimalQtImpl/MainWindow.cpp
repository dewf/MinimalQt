#include "generated/MainWindow.h"
#include "MainWindowInternal.h"

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

    void Handle_setCentralWidget(HandleRef _this, Widget::HandleRef widget) {
        MAINWINDOW_THIS->setCentralWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_setMenuBar(HandleRef _this, MenuBar::HandleRef menubar) {
        MAINWINDOW_THIS->setMenuBar(reinterpret_cast<QMenuBar *>(menubar));
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
}
