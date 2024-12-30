#include "generated/ItemSelectionModel.h"
#include "ItemSelectionModelInternal.h"

#define WRAPPER (reinterpret_cast<ItemSelectionModel::SignalWrapper*>(_this))

namespace ItemSelectionModel
{
    void Handle_setSignalMask(HandleRef _this, SignalMask signalMask) {
        WRAPPER->setSignalMask(signalMask);
    }
    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }
}
