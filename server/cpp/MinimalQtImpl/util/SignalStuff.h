#pragma once

#include <QObject>
#include <map>

// enum SignalState {
//     Added,
//     Removed,
//     Unchanged
// };
//
// template <typename T>
// std::map<T, SignalState> getSignalChanges(int32_t oldMask, int32_t newMask, int signalCount) {
//     std::map<T, SignalState> result;
//     int32_t checkSignal = 1;
//     for (int i = 0; i< signalCount; i++, checkSignal <<= 1) {
//         auto lastState = ((oldMask & checkSignal) != 0);
//         auto thisState = ((newMask & checkSignal) != 0);
//         SignalState value;
//         if (thisState && !lastState) {
//             value = Added;
//         } else if (lastState && !thisState) {
//             value = Removed;
//         } else {
//             value = Unchanged;
//         }
//         result[(T)checkSignal] = value;
//     }
//     return result;
// }

template <typename T>
struct SignalMapItem {
    T flag;
    const char *signal;
    const char *slot;
};

template <typename T>
void processChanged_OLD(int32_t lastMask, int32_t newMask, std::vector<SignalMapItem<T>> mapItems, QObject* thisPtr) {
    // auto changes = getSignalChanges<T>(lastMask, newMask, (int)mapItems.size());
    for (auto item : mapItems) {
        if ((newMask & item.flag) != (lastMask & item.flag)) {
            // changed
            if (newMask & item.flag) {
                // added
                QObject::connect(thisPtr, item.signal, thisPtr, item.slot);
            } else {
                // removed
                QObject::disconnect(thisPtr, item.signal, thisPtr, item.slot);
            }
        }
        // auto change = changes[item.flag];
        // if (change == Added) {
        //     QObject::connect(thisPtr, item.signal, thisPtr, item.slot);
        // } else if (change == Removed) {
        //     QObject::disconnect(thisPtr, item.signal, thisPtr, item.slot);
        // }
    }
}

template <typename T>
void processChanges(int32_t lastMask, int32_t newMask, std::vector<SignalMapItem<T>> mapItems, QObject* sender, QObject* receiver) {
    for (auto item : mapItems) {
        if ((newMask & item.flag) != (lastMask & item.flag)) {
            // changed
            if (newMask & item.flag) {
                // added
                printf("Signal [%s] added!\n", item.signal);
                QObject::connect(sender, item.signal, receiver, item.slot);
            } else {
                // removed
                QObject::disconnect(sender, item.signal, receiver, item.slot);
            }
        }
    }
}

