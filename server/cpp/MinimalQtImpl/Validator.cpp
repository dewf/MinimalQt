#include "generated/Validator.h"
#include "ValidatorInternal.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QValidator*>(_this))

namespace Validator
{
    SignalConnectionRef ConstHandle_connect_Changed(ConstHandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QValidator::changed, [handler] {
            handler->changed();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }
}
