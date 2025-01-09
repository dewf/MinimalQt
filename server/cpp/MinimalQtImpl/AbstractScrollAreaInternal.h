#pragma once

#include "generated/AbstractScrollArea.h"
#include "FrameInternal.h"

#include <QAbstractScrollArea>

namespace AbstractScrollArea {
    // class SignalWrapper : public Frame::SignalWrapper {
    //     Q_OBJECT
    // private:
    //     QAbstractScrollArea *actual;
    //     std::shared_ptr<SignalHandler> handler;
    //     SignalMask lastMask = 0;
    //     std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
    //         // none
    //     };
    // public:
    //     QAbstractScrollArea *getActual() const {
    //         return actual;
    //     }
    //     SignalWrapper(QAbstractScrollArea *existing, const std::shared_ptr<SignalHandler>& handler)
    //         : Frame::SignalWrapper(existing, SignalHandler::as_Frame_SignalHandler(handler)),
    //           actual(existing),
    //           handler(handler) {}
    //     void setSignalMask(SignalMask newMask) {
    //         // update inherited signals
    //         Frame::SignalWrapper::setSignalMask(newMask);
    //         // ours:
    //         if (newMask != lastMask) {
    //             processChanges(lastMask, newMask, signalMap, actual, this);
    //             lastMask = newMask;
    //         }
    //     }
    // public slots:
    //     // none
    // };
}
