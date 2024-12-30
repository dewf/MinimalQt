#include "generated/ItemSelection.h"
#include "ItemSelectionInternal.h"

#include "ModelIndexInternal.h"

#define THIS (AS_QITEMSELECTION_PTR(_this))

namespace ItemSelection {
    bool Handle_contains(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->contains(QMODELINDEX_VALUE(index));
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
        THIS->select(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
