#pragma once

#include "generated/Action.h"
#include "ObjectInternal.h"

#include <QAction>

#include "util/SignalStuff.h"

namespace Action {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QAction *actual;
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
        QAction *getActual() const {
            return actual;
        }
        SignalWrapper(QAction *existing, const std::shared_ptr<SignalHandler>& handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
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
