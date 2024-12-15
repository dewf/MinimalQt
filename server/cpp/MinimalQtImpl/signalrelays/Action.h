#pragma once

#include "../util/SignalStuff.h"

#include "../generated/Action.h"
#include "Object.h"

namespace Action {
    class SignalRelay : public Object::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Changed, SIGNAL(changed()), SLOT(onChanged) },
            { CheckableChanged, SIGNAL(checkableChanged(bool)), SLOT(onCheckableChanged(bool)) },
            { EnabledChanged, SIGNAL(enabledChanged(bool)), SLOT(onEnabledChanged(bool) )},
            { Hovered, SIGNAL(hovered()), SLOT(onHovered()) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) },
            { Triggered, SIGNAL(triggered(bool)), SLOT(onTriggered(bool)) },
            { VisibleChanged, SIGNAL(visibleChanged()), SLOT(onVisibleChanged()) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Object::SignalRelay(relayFor, SignalHandler::as_Object_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onChanged() const {
            handler->changed();
        }
        void onCheckableChanged(bool checkable) const {
            handler->checkableChanged(checkable);
        }
        void onEnabledChanged(bool enabled) const {
            handler->enabledChanged(enabled);
        }
        void onHovered() const {
            handler->hovered();
        }
        void onToggled(bool checked_) const {
            handler->toggled(checked_);
        }
        void onTriggered(bool checked_) const {
            handler->triggered(checked_);
        }
        void onVisibleChanged() const {
            handler->visibleChanged();
        }
    };
}
