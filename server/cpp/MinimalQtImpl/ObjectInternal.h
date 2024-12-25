#pragma once

#include "generated/Object.h"
#include "util/SignalStuff.h"

#include <QObject>

namespace Object {
    class SignalWrapper : public QObject { // for signal-related stuff, this is not a QObject subclass per se
        Q_OBJECT
    protected:
        bool qtDestroyed = false;
    private:
        QObject *actual = nullptr;
        QMetaObject::Connection destroyedConnection;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) }
        };
    public:
        ~SignalWrapper() override {
            if (!qtDestroyed) {
                printf("C++ Object::SignalWrapper destroying QObject\n");
                delete actual;
                qtDestroyed = true;
            } else {
                printf("C++ Object::SignalWrapper - qt object was already destroyed\n");
            }
        }
        QObject *getActual() const {
            return actual;
        }
        // wrap existing:
        SignalWrapper(QObject *existing, const std::shared_ptr<SignalHandler> &handler) : actual(existing), handler(handler) {
            // we MUST connect the 'Destroyed' signal, so we know when to self-delete
            // but it will be manually checked in the handler before invoking the handler
        }
        // purposely NOT virtual:
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap,  actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onDestroyed(QObject *obj) {
            handler->destroyed((HandleRef)this);
            qtDestroyed = true;
            // in the case the QObject gets deleted out from under us, no reason to continue to exist!
            // hopefully the client side is not confused about this!
            printf("QObject::SignalWrapper - 'delete this'\n");
            delete this;
        }
        void onObjectNameChanged(const QString& name) const {
            handler->objectNameChanged(name.toStdString());
        }
    };
}
