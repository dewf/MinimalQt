#pragma once

#include "generated/ProgressBar.h"
#include "WidgetInternal.h"

#include <QProgressBar>

namespace ProgressBar {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QProgressBar *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ValueChanged, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)) },
        };
    public:
        QProgressBar *getActual() const {
            return actual;
        }
        SignalWrapper(QProgressBar *existing, const std::shared_ptr<SignalHandler>& handler)
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
        void onValueChanged(int value) const {
            handler->valueChanged(value);
        }
    };
}
