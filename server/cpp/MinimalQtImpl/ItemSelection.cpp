#include "generated/ItemSelection.h"
#include "ItemSelectionInternal.h"

#include "ModelIndexInternal.h"
#include "util/convert.h"

using namespace ::ModelIndex;
using namespace ::ItemSelectionCommon;

#define THIS (AS_QITEMSELECTION_PTR(_this))

namespace ItemSelection {
    bool Handle_contains(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->contains(QMODELINDEX_VALUE(index));
    }

    OwnedListRef Handle_indexes(HandleRef _this) {
        return MODELINDEX_LIST_HEAP_NEW(THIS->indexes());
    }

    void Handle_merge(HandleRef _this, HandleRef other, SelectionFlags command) {
        THIS->merge(QITEMSELECTION_VALUE(other), static_cast<QItemSelectionModel::SelectionFlags>(command.value));
    }

    void Handle_select(HandleRef _this, ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
        THIS->select(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return ITEMSELECTION_HEAP_NEW();
    }

    OwnedRef create(ModelIndex::HandleRef topLeft, ModelIndex::HandleRef bottomRight) {
        return ITEMSELECTION_HEAP_NEW(QMODELINDEX_VALUE(topLeft), QMODELINDEX_VALUE(bottomRight));
    }
}
