#pragma once

#include "generated/GroupBox.h"
#include "WidgetInternal.h"

#include <QGroupBox>

namespace GroupBox {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QGroupBox *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Clicked, SIGNAL(clicked(bool)), SLOT(onClicked(bool)) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) }
        };
    public:
        QGroupBox *getActual() const {
            return actual;
        }
        SignalWrapper(QGroupBox *existing, const std::shared_ptr<SignalHandler>& handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onClicked(bool checked_) const {
            handler->clicked(checked_);
        }
        void onToggled(bool state) const {
            handler->toggled(state);
        }
    };
}
