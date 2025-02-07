#include "generated/SafeReturn.h"
#include "SafeReturnInternal.h"

#include "ModelIndexInternal.h"
#include "VariantInternal.h"
#include "Size2Internal.h"

using namespace ::ModelIndex;
using namespace ::Variant;
using namespace ::Size2;

namespace SafeReturn
{
    void ModelIndexReturn_setResult(ModelIndexReturnRef _this, ModelIndex::HandleRef value) {
        _this->result = QMODELINDEX_VALUE(value);
    }

    void VariantReturn_setResult(VariantReturnRef _this, Variant::HandleRef value) {
        _this->result = QVARIANT_VALUE(value);
    }

    void SizeReturn_setResult(SizeReturnRef _this, Size2::HandleRef value) {
        _this->result = QSIZE_VALUE(value);
    }
}
