#include "generated/MenuBar.h"

#include <QObject>
#include <QMenuBar>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((MenuBarWithHandler*)_this)

namespace MenuBar
{
    class MenuBarWithHandler : public QMenuBar {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // MenuBar:
            { Hovered, SIGNAL(hovered(QAction*)), SLOT(onHovered(QAction*)) },
            { Triggered, SIGNAL(triggered(QAction*)), SLOT(onTriggered(QAction*))}
        };
    public:
        explicit MenuBarWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
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
        // MenuBar =================
        void onHovered(QAction* action) const {
            handler->hovered(reinterpret_cast<Action::HandleRef>(action));
        }
        void onTriggered(QAction* action) const {
            handler->triggered(reinterpret_cast<Action::HandleRef>(action));
        }
    };

    void Handle_setDefaultUp(HandleRef _this, bool state) {
        THIS->setDefaultUp(state);
    }

    void Handle_setNativeMenuBar(HandleRef _this, bool state) {
        THIS->setNativeMenuBar(state);
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_addMenu(HandleRef _this, Menu::HandleRef menu) {
        THIS->addMenu(reinterpret_cast<QMenu *>(menu));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MenuBarWithHandler(handler));
    }
}

#include "MenuBar.moc"
