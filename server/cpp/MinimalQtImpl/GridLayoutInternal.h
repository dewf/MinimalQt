#pragma once

#include "generated/GridLayout.h"
#include "LayoutInternal.h"

#include <QGridLayout>

namespace GridLayout {
    class SignalWrapper : public Layout::SignalWrapper {
        Q_OBJECT
    private:
        QGridLayout *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QGridLayout *getActual() const {
            return actual;
        }
        SignalWrapper(QGridLayout *existing, const std::shared_ptr<SignalHandler> &handler)
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
