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

    // normal non-const methods =========================
    // TODO:
}
