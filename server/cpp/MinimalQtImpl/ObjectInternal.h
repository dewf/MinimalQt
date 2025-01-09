#pragma once

#include "generated/Object.h"
#include "util/SignalStuff.h"

#include <map>
#include <QObject>

namespace Object {
    struct __SignalConnection {
        QMetaObject::Connection qConnection;
    };

    inline QObject *fromOptionalHandle(const std::optional<HandleRef>& handle) {
        QObject *qParent = nullptr;
        if (handle.has_value()) {
            qParent = reinterpret_cast<QObject*>(handle.value());
        }
        return qParent;
    }

    // class SignalWrapper : public QObject { // for signal-related stuff, this is not a QObject subclass per se! don't confuse wrapper with 'actual'!!!
    //     Q_OBJECT
    // private:
    //     static std::map<QObject*, SignalWrapper*> objectToWrapperMap; // so we can easily fetch the wrapper when a Qt method returns its bare QObject-derived pointers
    // protected:
    //     bool qtDestroyed = false;
    // private:
    //     QObject *actual = nullptr;
    //     QMetaObject::Connection destroyedConnection;
    //     std::shared_ptr<SignalHandler> handler;
    //     SignalMask lastMask = 0;
    //     std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
    //         // see note in ctor
    //         // { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
    //         { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) }
    //     };
    // public:
    //     QObject *getActual() const {
    //         return actual;
    //     }
    //     SignalWrapper(QObject *existing, const std::shared_ptr<SignalHandler> &handler) : actual(existing), handler(handler) {
    //         // we MUST connect the 'Destroyed' signal, so we know when to self-delete
    //         // but handler mask will be manually checked in our slot before invoking the supplied handler
    //         destroyedConnection = connect(existing, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyed(QObject*)));
    //
    //         // add the mapping so we can lookup wrappers by QObject*
    //         objectToWrapperMap[existing] = this;
    //     }
    //     ~SignalWrapper() override {
    //         // always send conventional destroyed signal if requested
    //         // 'actual' should always still be live at this point ... I think
    //         if (lastMask & Destroyed) {
    //             const auto wrapper = wrapperForQObject(actual);
    //             handler->destroyed(reinterpret_cast<HandleRef>(wrapper));
    //         }
    //         objectToWrapperMap.erase(actual);
    //
    //         // depending on whether we got deleted, or Qt object was deleted:
    //         if (!qtDestroyed) {
    //             // disconnect signal first, so we don't create a loop
    //             disconnect(destroyedConnection);
    //             delete actual;
    //         } else {
    //             // dtor was called in response to Qt-initiated object destruction
    //             // (vs. client-invoked .Dispose() of signal wrapper)
    //             // so let's notify the client that this happened
    //             handler->destroyedByQt();
    //         }
    //     }
    //     // purposely NOT virtual:
    //     void setSignalMask(SignalMask newMask) {
    //         if (newMask != lastMask) {
    //             processChanges(lastMask, newMask, signalMap,  actual, this);
    //             lastMask = newMask;
    //         }
    //     }
    // public slots:
    //     // note, this indicates 'actual' got destroyed, not us (the wrapper). easy to get confused since we're also a QObject of necessaity (to connect signals at all)
    //     void onDestroyed(QObject *obj) {
    //         // we always handle this signal (unless disconnected in dtor), see note in ctor
    //         qtDestroyed = true;
    //         delete this;
    //     }
    //     void onObjectNameChanged(const QString& name) const {
    //         handler->objectNameChanged(name.toStdString());
    //     }
    //
    // // friend funcs:
    //     friend SignalWrapper *wrapperForQObject(QObject *obj);
    // };
}
