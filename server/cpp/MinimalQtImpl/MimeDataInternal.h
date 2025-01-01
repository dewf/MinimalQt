#pragma once

#include "generated/MimeData.h"
#include "ObjectInternal.h"

#include <QMimeData>

#define AS_QMIMEDATA_PTR(x) (reinterpret_cast<QMimeData*>(x))

namespace MimeData {
    // class SignalWrapper : public Object::SignalWrapper {
    //     Q_OBJECT
    // private:
    //     QMimeData *actual;
    //     std::shared_ptr<SignalHandler> handler;
    //     SignalMask lastMask = 0;
    //     std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
    //         // none extra
    //     };
    // public:
    //     QMimeData *getActual() const {
    //         return actual;
    //     }
    //     SignalWrapper(QMimeData *existing, const std::shared_ptr<SignalHandler>& handler)
    //         : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
    //           actual(existing),
    //           handler(handler) {}
    //     void setSignalMask(SignalMask newMask) {
    //         // update inherited signals
    //         Object::SignalWrapper::setSignalMask(newMask);
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
