#include "generated/StatusBar.h"

#include <QStatusBar>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((StatusBarWithHandler*)_this)

namespace StatusBar
{
    class StatusBarWithHandler : public QStatusBar {
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
            // StatusBar:
            { MessageChanged, SIGNAL(messageChanged(QString)), SLOT(onMessageChanged(QString)) },
        };
    public:
        explicit StatusBarWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object ==================
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
        // StatusBar ===============
        void onMessageChanged(const QString& message) const {
            handler->messageChanged(message.toStdString());
        };
    };

    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return THIS->isSizeGripEnabled();
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        THIS->setSizeGripEnabled(enabled);
    }

    void Handle_clearMessage(HandleRef _this) {
        THIS->clearMessage();
    }

    void Handle_showMessage(HandleRef _this, const std::string& message, int32_t timeout) {
        THIS->showMessage(QString::fromStdString(message), timeout);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new StatusBarWithHandler(handler));
    }
}

#include "StatusBar.moc"
