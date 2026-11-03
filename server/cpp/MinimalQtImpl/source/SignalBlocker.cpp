#include "generated/SignalBlocker.h"
#include "SignalBlockerInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;

namespace SignalBlocker
{
#define THIS (AS_QSIGNALBLOCKER_PTR(_this))
    void Handle_dismiss(HandleRef _this) {
        THIS->dismiss();
    }

    void Handle_reblock(HandleRef _this) {
        THIS->reblock();
    }

    void Handle_unblock(HandleRef _this) {
        THIS->unblock();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create(Object::HandleRef obj) {
        return reinterpret_cast<OwnedRef>(new QSignalBlocker(AS_QOBJECT_PTR(obj)));
    }
}
