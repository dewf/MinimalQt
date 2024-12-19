#pragma once

#include "generated/Object.h"
#include "util/SignalStuff.h"

#include <QObject>

namespace Object {
    class SignalRelay : public QObject {
        Q_OBJECT
    protected:
        QObject *relayFor;
    private:
        QMetaObject::Connection destroyedConnection;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // 'destroyed' signal requires manual handling, because this signal manager won't be around to handle it normally! (this torn down prior to <relayFor>'s QObject destructor being called)
            // { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) : relayFor(relayFor), handler(handler) {}
        ~SignalRelay() override {
            // manual sending of 'Destroyed' signal, see note in signalMap above
            if (lastMask & Destroyed) {
                handler->destroyed(reinterpret_cast<HandleRef>(relayFor));
            }
        }
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap,  relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onObjectNameChanged(const QString& name) const {
            handler->objectNameChanged(name.toStdString());
        }
    };
}
