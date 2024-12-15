#pragma once

#include <QObject>
#include "../generated/Object.h"
#include "../util/SignalStuff.h"

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
            // 'destroyed' signal requires special handling, because this signal manager won't be around to handle it normally!
            // { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) : relayFor(relayFor), handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                // special handling for 'destroyed'
                if ((newMask & Destroyed) != (lastMask & Destroyed)) {
                    if (newMask & Destroyed) {
                        // added
                        destroyedConnection =
                            connect(relayFor, &QObject::destroyed, [=] {
                                handler->destroyed(reinterpret_cast<HandleRef>(relayFor));
                            });
                    } else {
                        // removed
                        // note we're using a QMetaObject connection because (without reading the docs right now) I'm pessimistically assuming another lambda in this branch might not be considered "equal"? thus wouldn't disconnect? dunno
                        disconnect(destroyedConnection);
                    }
                }
                // normal processing
                processChanges(lastMask, newMask, signalMap,  relayFor, this);
                // done
                lastMask = newMask;
            }
        }
        // void onDestroyed(QObject *obj) const {
        //     handler->destroyed(reinterpret_cast<Object::HandleRef>(obj));
        // }
    public slots:
        void onObjectNameChanged(const QString& name) const {
            handler->objectNameChanged(name.toStdString());
        }
    };
}
