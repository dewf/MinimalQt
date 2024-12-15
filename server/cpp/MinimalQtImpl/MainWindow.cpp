#include "generated/MainWindow.h"

#include <QMainWindow>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"

#include "IconInternal.h"

#define THIS ((MainWindowWithHandler*)_this)

namespace MainWindow
{
    class MainWindowWithHandler : public QMainWindow {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject*)), SLOT(onDestroyed(QObject*)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // MainWindow:
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { TabifiedDockWidgetActivated, SIGNAL(tabifiedDockWidgetActivated(QDockWidget)), SLOT(onTabifiedDockWidgetActivated(QDockWidget)) },
            { ToolButtonStyleChanged, SIGNAL(toolButtonStyleChanged(Qt::ToolButtonStyle)), SLOT(onToolButtonStyleChanged(Qt::ToolButtonStyle)) },
            // MainWindow custom:
            { WindowClosed, SIGNAL(windowClosed()), SLOT(onWindowClosed()) }
        };
    public:
        explicit MainWindowWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}

        // could we just put a lambda in the ctor (capturing the handler only) which connects to Destroyed?
        // seems like that would be potentially safer/more correct than emitting it ourselves

        // ~MainWindowWithHandler() override {
        //     // we have to 'manually' invoke this ourselves, because it's not emitted until this derived class is torn down,
        //     // but by then our signal handler is gone
        //     if (lastMask & SignalMaskFlags::Destroyed) {
        //         printf("\"manual\" MainWindow destroyed signal\n");
        //         handler->destroyed(reinterpret_cast<Object::HandleRef>(this));
        //     }
        // }

        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    signals:
        void windowClosed();
    protected:
        // something we're implementing ourselves since it's not a stock signal
        void closeEvent(QCloseEvent *event) override {
            QWidget::closeEvent(event);
            emit windowClosed();
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            // this isn't firing, and I think it's because our subclass is torn down before the base dtor runs,
            // which means our 'handler' is non-existent (I guess Qt's MOC stuff is smart enough to disconnect the signal when a subclass is destructed? else why don't we crash when a connection exists?)
            // anyway, I don't think it's possible to listen to this signal internally. is that going to be a problem?
            // could we explicitly connect it with a lambda that referecnes the shared_ptr to keep the handler alive?
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // MainWindow ===============
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onTabifiedDockWidgetActivated(QDockWidget* dockWidget) const {
            handler->tabifiedDockWidgetActivated((DockWidget::HandleRef)dockWidget);
        }
        void onToolButtonStyleChanged(Qt::ToolButtonStyle style) const {
            handler->toolButtonStyleChanged((Enums::ToolButtonStyle)style);
        }
        // MainWindow (custom) ======
        void onWindowClosed() const {
            handler->windowClosed();
        }
    };

    void Handle_setAnimated(HandleRef _this, bool state) {
        THIS->setAnimated(state);
    }

    void Handle_setDockNestingEnabled(HandleRef _this, bool state) {
        THIS->setDockNestingEnabled(state);
    }

    void Handle_setDockOptions(HandleRef _this, DockOptions dockOptions) {
        THIS->setDockOptions(static_cast<QMainWindow::DockOptions>(dockOptions));
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        THIS->setDocumentMode(state);
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setTabShape(HandleRef _this, TabShape tabShape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(tabShape));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    void Handle_setUnifiedTitleAndToolBarOnMac(HandleRef _this, bool state) {
        THIS->setUnifiedTitleAndToolBarOnMac(state);
    }

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
