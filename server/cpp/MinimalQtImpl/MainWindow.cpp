#include "generated/MainWindow.h"
#include "MainWindowInternal.h"

#include <QMainWindow>
#include <utility>

#include "util/convert.h"

#define THIS ((MainWindowWithHandler*)_this)

namespace MainWindow
{
    class MainWindowWithHandler : public QMainWindow {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit MainWindowWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    signals:
        void windowClosed();
    protected:
        // something we're implementing ourselves since it's not a stock signal
        void closeEvent(QCloseEvent *event) override {
            QWidget::closeEvent(event);
            emit windowClosed();
        }
    };

    // properties ==============================

    bool Handle_isAnimated(HandleRef _this) {
        return THIS->isAnimated();
    }

    void Handle_setAnimated(HandleRef _this, bool state) {
        THIS->setAnimated(state);
    }

    bool Handle_isDockNestingEnabled(HandleRef _this) {
        return THIS->isDockNestingEnabled();
    }

    void Handle_setDockNestingEnabled(HandleRef _this, bool state) {
        THIS->setDockNestingEnabled(state);
    }

    DockOptions Handle_getDockOptions(HandleRef _this) {
        return THIS->dockOptions();
    }

    void Handle_setDockOptions(HandleRef _this, DockOptions dockOptions) {
        THIS->setDockOptions(static_cast<QMainWindow::DockOptions>(dockOptions));
    }

    bool Handle_documentMode(HandleRef _this) {
        return THIS->documentMode();
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        THIS->setDocumentMode(state);
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    TabShape Handle_getTabShape(HandleRef _this) {
        return static_cast<TabShape>(THIS->tabShape());
    }

    void Handle_setTabShape(HandleRef _this, TabShape tabShape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(tabShape));
    }

    ToolButtonStyle Handle_getToolButtonStyle(HandleRef _this) {
        return static_cast<ToolButtonStyle>(THIS->toolButtonStyle());
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    bool Handle_unifiedTitleAndToolBarOnMac(HandleRef _this) {
        return THIS->unifiedTitleAndToolBarOnMac();
    }

    void Handle_setUnifiedTitleAndToolBarOnMac(HandleRef _this, bool state) {
        THIS->setUnifiedTitleAndToolBarOnMac(state);
    }

    // methods =================================

    void Handle_setCentralWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setCentralWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_setMenuBar(HandleRef _this, MenuBar::HandleRef menubar) {
        THIS->setMenuBar(reinterpret_cast<QMenuBar *>(menubar));
    }

    void Handle_setStatusBar(HandleRef _this, StatusBar::HandleRef statusbar) {
        THIS->setStatusBar(reinterpret_cast<QStatusBar *>(statusbar));
    }

    void Handle_addToolBar(HandleRef _this, ToolBar::HandleRef toolbar) {
        THIS->addToolBar(reinterpret_cast<QToolBar *>(toolbar));
    }

    void Handle_addToolBar(HandleRef _this, ToolBarArea area, ToolBar::HandleRef toolbar) {
        THIS->addToolBar(static_cast<Qt::ToolBarArea>(area), reinterpret_cast<QToolBar*>(toolbar));
    }

    // etc =====================================

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MainWindowWithHandler(handler));
    }
}

#include "MainWindow.moc"
