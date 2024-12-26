#pragma once

#include "generated/ScrollArea.h"
#include "AbstractScrollAreaInternal.h"

#include <QSCrollArea>

namespace ScrollArea {
    class SignalWrapper : public AbstractScrollArea::SignalWrapper {
        Q_OBJECT
    private:
        QScrollArea *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QScrollArea *getActual() const {
            return actual;
        }
        SignalWrapper(QScrollArea *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractScrollArea::SignalWrapper(existing, SignalHandler::as_AbstractScrollArea_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractScrollArea::SignalWrapper::setSignalMask(newMask);
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
