#pragma once

#include "generated/Object.h"
#include "util/SignalStuff.h"

#include <map>
#include <QObject>

namespace Object {
    class SignalWrapper : public QObject { // for signal-related stuff, this is not a QObject subclass per se
        Q_OBJECT
    private:
        static std::map<QObject*, SignalWrapper*> objectToWrapperMap; // so we can easily fetch the wrapper when a Qt method returns its bare QObject-derived pointers
    protected:
        bool qtDestroyed = false;
    private:
        QObject *actual = nullptr;
        QMetaObject::Connection destroyedConnection;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // see note in ctor
            // { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) }
        };
    public:
        QObject *getActual() const {
            return actual;
        }
        SignalWrapper(QObject *existing, const std::shared_ptr<SignalHandler> &handler) : actual(existing), handler(handler) {
            // we MUST connect the 'Destroyed' signal, so we know when to self-delete
            // but handler mask will be manually checked in our slot before invoking the supplied handler
            destroyedConnection = connect(existing, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));

            // add the mapping so we can lookup wrappers by QObject*
            objectToWrapperMap[existing] = this;
        }
        ~SignalWrapper() override {
            // remove mapping ASAP, in case the 'destroyed' handler tries to do something silly?
            objectToWrapperMap.erase(actual);
            // etc
            if (!qtDestroyed) {
                // printf("C++ Object::SignalWrapper destroying contained QObject\n");
                // disconnect signal first, so we don't create a loop
                disconnect(destroyedConnection);
                delete actual;
                qtDestroyed = true; // just being extra cautious since this is getting hairy ...
                // but still fulfill our responsibilities to anybody who wanted it:
                if (lastMask & Destroyed) {
                    handler->destroyed(reinterpret_cast<HandleRef>(this));
                }
            } else {
                // printf("C++ Object::SignalWrapper - qt object was already destroyed\n");
            }
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
            // we always handle this signal, see note in ctor
            if (lastMask & Destroyed) {
                // but only pass along to handler if mask permits
                handler->destroyed(reinterpret_cast<HandleRef>(this));
            }
            qtDestroyed = true;
            // in the case the QObject gets deleted out from under us, no reason to continue to exist!
            // hopefully the client side is not confused about this!
            // printf("QObject::SignalWrapper - 'delete this'\n");
            delete this;
        }
        void onObjectNameChanged(const QString& name) const {
            handler->objectNameChanged(name.toStdString());
        }

    // friend funcs:
        friend SignalWrapper *wrapperForQObject(QObject *obj);
    };

    SignalWrapper *wrapperForQObject(QObject *obj);
}
