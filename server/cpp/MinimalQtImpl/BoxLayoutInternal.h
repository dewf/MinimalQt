#pragma once

#include "generated/BoxLayout.h"
#include "LayoutInternal.h"

#include <QBoxLayout>

namespace BoxLayout {
    class SignalWrapper : public Layout::SignalWrapper {
        Q_OBJECT
    private:
        QBoxLayout *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QBoxLayout *getActual() const {
            return actual;
        }
        SignalWrapper(QBoxLayout *existing, const std::shared_ptr<SignalHandler>& handler)
            : Layout::SignalWrapper(existing, SignalHandler::as_Layout_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Layout::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
