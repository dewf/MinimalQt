#include "generated/GraphicsEffect.h"
#include "GraphicsEffectInternal.h"

#include "ObjectInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QGraphicsEffect*>(_this))

namespace GraphicsEffect
{
    RectF Handle_boundingRect(HandleRef _this) {
        return toRectF(THIS->boundingRect());
    }

    RectF Handle_boundingRectFor(HandleRef _this, RectF rect) {
        return toRectF(THIS->boundingRectFor(toQRectF(rect)));
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
