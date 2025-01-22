#include "generated/SafeReturn.h"
#include "SafeReturnInternal.h"

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

namespace SafeReturn
{
    void Handle_setModelIndex(HandleRef _this, ModelIndex::HandleRef index) {
        _this->modelIndex = index->value;
    }

    void Handle_setVariant(HandleRef _this, Variant::HandleRef variant) {
        _this->variant = variant->value;
    }
}
