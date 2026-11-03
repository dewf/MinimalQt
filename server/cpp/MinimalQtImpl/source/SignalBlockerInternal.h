#pragma once
#include <QSignalBlocker>

#define AS_QSIGNALBLOCKER_PTR(x) (reinterpret_cast<QSignalBlocker*>(x))

namespace SignalBlocker
{
    // for some reason, trying to use this just locked everything up,
    // even after it was destroyed
    // TODO, maybe!

    // class RecursiveSignalBlocker
    // {
    // private:
    //     std::vector<QSignalBlocker> blockers;
    // public:
    //     explicit RecursiveSignalBlocker(QObject *root) {
    //         if (root != nullptr) {
    //             blockers.emplace_back(root);
    //             // findChildren actually works recursively, doing our work for us:
    //             for (auto child : root->findChildren<QObject*>()) {
    //                 blockers.emplace_back(child);
    //             }
    //         }
    //     }
    // };
}
