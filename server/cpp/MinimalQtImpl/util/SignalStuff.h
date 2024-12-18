#pragma once

#include <QObject>
#include <map>

template <typename T>
struct SignalMapItem {
    T flag;
    const char *signal;
    const char *slot;
};

template <typename T>
void processChanges(int32_t lastMask, int32_t newMask, std::vector<SignalMapItem<T>> mapItems, QObject* sender, QObject* receiver) {
    for (auto item : mapItems) {
        if ((newMask & item.flag) != (lastMask & item.flag)) {
            // changed
            if (newMask & item.flag) {
                // added
                QObject::connect(sender, item.signal, receiver, item.slot);
            } else {
                // removed
                QObject::disconnect(sender, item.signal, receiver, item.slot);
            }
        }
    }
}

