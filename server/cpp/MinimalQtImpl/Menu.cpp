#include "generated/Menu.h"

#include <QObject>
#include <QMenu>

#include "util/convert.h"
#include "util/SignalStuff.h"
#include "IconInternal.h"

#define THIS ((MenuWithHandler*)_this)

namespace Menu
{
    class MenuWithHandler : public QMenu {
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
            // Menu:
            { AboutToHide, SIGNAL(aboutToHide()), SLOT(onAboutToHide()) },
            { AboutToShow, SIGNAL(aboutToShow()), SLOT(onAboutToShow()) },
            { Hovered, SIGNAL(hovered(QAction*)), SLOT(onHovered(QAction*)) },
            { Triggered, SIGNAL(triggered(QAction*)), SLOT(onTriggered(QAction*)) }
        };
    public:
        explicit MenuWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
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
        // Menu ====================
        void onAboutToHide() const {
            handler->aboutToHide();
        }
        void onAboutToShow() const {
            handler->aboutToShow();
        }
        void onHovered(QAction *action) const {
            handler->hovered(reinterpret_cast<Action::HandleRef>(action));
        }
        void onTriggered(QAction *action) const {
            handler->triggered(reinterpret_cast<Action::HandleRef>(action));
        }
    };

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(ICON_VALUE(icon));
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool state) {
        THIS->setSeparatorsCollapsible(state);
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool state) {
        THIS->setTearOffEnabled(state);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        THIS->setToolTipsVisible(visible);
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        // should we be concerned about ownership here? I presume the Menu owns it (as parent), and we're probably not going to do anything else with it ...
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_popup(HandleRef _this, Point p) {
        THIS->popup(toQPoint(p));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MenuWithHandler(handler));
    }
}

#include "Menu.moc"
