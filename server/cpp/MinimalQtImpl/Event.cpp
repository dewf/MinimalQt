#include "generated/Event.h"
#include "EventInternal.h"

#define THIS (AS_QEVENT_PTR(_this))

namespace Event
{
    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    namespace HelpEvent {
#define HELPEVENT_THIS (AS_QHELPEVENT_PTR(_this))

        void Owned_dispose(OwnedRef _this) {
            delete HELPEVENT_THIS;
        }
    }
}
