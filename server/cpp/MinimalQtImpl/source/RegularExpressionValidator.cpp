#include "generated/RegularExpressionValidator.h"
#include "RegularExpressionValidatorInternal.h"

#include "ObjectInternal.h"
#include "RegularExpressionInternal.h"

using namespace ::Object;
using namespace ::Validator;
using namespace ::RegularExpression;

#define THIS (reinterpret_cast<QRegularExpressionValidator*>(_this))

namespace RegularExpressionValidator
{
    OwnedRef Handle_regularExpression(HandleRef _this) {
        return REGEX_HEAP_NEW(THIS->regularExpression());
    }

    void Handle_setRegularExpression(HandleRef _this, RegularExpression::HandleRef re) {
        THIS->setRegularExpression(QREGEX_VALUE(re));
    }

    SignalConnectionRef Handle_connect_RegularExpressionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QRegularExpressionValidator::regularExpressionChanged, [handler](const QRegularExpression &re) {
            QRegularExpression safeCopy(re); // copy for (non-)const purposes
            handler->sig_regularExpressionChanged(reinterpret_cast<RegularExpression::HandleRef>(&safeCopy));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto regex_validator = AS_QREGEX_VALIDATOR_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(regex_validator);
        case Handle_CastTarget::Validator_ConstHandle:
        case Handle_CastTarget::Validator_Handle:
            return static_cast<QValidator*>(regex_validator);
        }
        std::unreachable();
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRegularExpressionValidator(AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(RegularExpression::HandleRef re, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QRegularExpressionValidator(QREGEX_VALUE(re), AS_QOBJECT_PTR(parent)));
    }
}
