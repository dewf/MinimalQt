#include "generated/ItemSelection.h"
#include "ItemSelectionInternal.h"

#include "ModelIndexInternal.h"

#define THIS (AS_QITEMSELECTION_PTR(_this))

namespace ItemSelection {
    bool Handle_contains(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->contains(index->value);
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
        THIS->select(topLeft->value, bottomRight->value);
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }
}
