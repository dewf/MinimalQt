#pragma once

#include "generated/StandardItem.h"
#include <QStandardItem>

#define AS_QSTANDARDITEM_PTR(x) (reinterpret_cast<QStandardItem*>(x))

namespace StandardItem {
    inline QList<QStandardItem*> arrayToList(const std::vector<HandleRef>& input) {
        QList<QStandardItem*> ret;
        for (const auto item : input) {
            ret.append(reinterpret_cast<QStandardItem*>(item));
        }
        return ret;
    }

    inline std::vector<HandleRef> listToArray(const QList<QStandardItem*>& items) {
        std::vector<HandleRef> ret;
        for (const auto item : items) {
            ret.push_back(reinterpret_cast<HandleRef>(item));
        }
        return ret;
    }
}
