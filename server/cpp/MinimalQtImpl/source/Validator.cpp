#include "generated/Validator.h"
#include "ValidatorInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;

#define THIS (reinterpret_cast<QValidator*>(_this))

namespace Validator
{
    // const methods ====================================
    std::string ConstHandle_fixup(ConstHandleRef _this, const std::string& input) {
        auto qInput = QString::fromStdString(input);
        THIS->fixup(qInput);
        return qInput.toStdString();
    }

    ValidateResult ConstHandle_validate(ConstHandleRef _this, const std::string& input, int32_t pos) {
        auto qInput = QString::fromStdString(input);
        const auto qState = THIS->validate(qInput, pos);
        return ValidateResult { static_cast<State>(qState), qInput.toStdString(), pos };
    }

    SignalConnectionRef ConstHandle_connect_Changed(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QValidator::changed, [handler] {
            handler->sig_changed();
        });
        return new __SignalConnection { connection };
    }

    void* ConstHandle_staticCast(ConstHandleRef obj, ConstHandle_CastTarget target) {
        auto validator = AS_QVALIDATOR_PTR(obj);
        switch (target)
        {
        case ConstHandle_CastTarget::Object_Handle:
            return static_cast<QObject*>(validator);
        }
        std::unreachable();
    }

    // normal non-const methods =========================

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto validator = AS_QVALIDATOR_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(validator);
        case Handle_CastTarget::ConstHandle:
            // same
            return validator;
        }
        std::unreachable();
    }
}
