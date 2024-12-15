#include "generated/RadioButton.h"

#include <QRadioButton>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((RadioButtonWithHandler*)_this)

namespace RadioButton
{
    class RadioButtonWithHandler : public QRadioButton {
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
            // AbstractButton:
            { Clicked, SIGNAL(clicked(bool)), SLOT(onClicked(bool)) },
            { Pressed, SIGNAL(pressed()), SLOT(onPressed()) },
            { Released, SIGNAL(released()), SLOT(onReleased()) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) }
            // RadioButton:
            // .... (none)
        };
    public:
        explicit RadioButtonWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget =================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // AbstractButton =========
        void onClicked(bool checkState) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                    clicked(checkState);
        }
        void onPressed() const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                    pressed();
        }
        void onReleased() const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                    released();
        }
        void onToggled(bool checkState) const {
            handler->
                inherited_AbstractButton_SignalHandler()->
                    toggled(checkState);
        }
        // RadioButton =============
        // .... (none)
    };

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new RadioButtonWithHandler(handler));
    }
}

#include "RadioButton.moc"
