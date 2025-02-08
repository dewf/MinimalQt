#include "generated/GraphicsEffect.h"
#include "GraphicsEffectInternal.h"

#include "ObjectInternal.h"
#include "RectF2Internal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Common;
using namespace ::RectF2;

#define THIS (reinterpret_cast<QGraphicsEffect*>(_this))

namespace GraphicsEffect
{
    OwnedRef Handle_boundingRect(HandleRef _this) {
        return RECTF_HEAP_NEW(THIS->boundingRect());
    }

    OwnedRef Handle_boundingRectFor(HandleRef _this, RectF2::HandleRef rect) {
        return RECTF_HEAP_NEW(THIS->boundingRectFor(QRECTF_VALUE(rect)));
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enable) {
        THIS->setEnabled(enable);
    }

    void Handle_update(HandleRef _this) {
        THIS->update();
    }

    SignalConnectionRef Handle_connect_EnabledChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QGraphicsEffect::enabledChanged, [handler](bool enabled) {
            handler->enabledChanged(enabled);
        });
        return new __SignalConnection { connection };
    }
}
