#include "generated/SafeReturn.h"
#include "SafeReturnInternal.h"

#include "ModelIndexInternal.h"
#include "VariantInternal.h"

namespace SafeReturn
{
    void ModelIndexReturn_setResult(ModelIndexReturnRef _this, ModelIndex::HandleRef value) {
        _this->result = value->value;
    }

    void VariantReturn_setResult(VariantReturnRef _this, Variant::HandleRef value) {
        _this->result = value->value;
    }
}
