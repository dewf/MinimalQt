#include "generated/Timer.h"
#include "TimerInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::Enums;

#define THIS (reinterpret_cast<QTimer*>(_this))

namespace Timer
{
    TimerId Handle_id(HandleRef _this) {
        return static_cast<TimerId>(THIS->id());
    }

    int32_t Handle_interval(HandleRef _this) {
        return THIS->interval();
    }

    bool Handle_isActive(HandleRef _this) {
        return THIS->isActive();
    }

    bool Handle_isSingleShot(HandleRef _this) {
        return THIS->isSingleShot();
    }

    int32_t Handle_remainingTime(HandleRef _this) {
        return THIS->remainingTime();
    }

    void Handle_setInterval(HandleRef _this, int32_t msec) {
        THIS->setInterval(msec);
    }

    void Handle_setSingleShot(HandleRef _this, bool state) {
        THIS->setSingleShot(state);
    }

    void Handle_setTimerType(HandleRef _this, TimerType type_) {
        THIS->setTimerType(static_cast<Qt::TimerType>(type_));
    }

    int32_t Handle_timerId(HandleRef _this) {
        return THIS->timerId();
    }

    TimerType Handle_getTimerType(HandleRef _this) {
        return static_cast<TimerType>(THIS->timerType());
    }

    void Handle_start(HandleRef _this, int32_t msec) {
        THIS->start(msec);
    }

    void Handle_start(HandleRef _this) {
        THIS->start();
    }

    void Handle_stop(HandleRef _this) {
        THIS->stop();
    }

    SignalConnectionRef Handle_connect_Timeout(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTimer::timeout, [handler] {
            handler->timeout();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTimer(AS_QOBJECT_PTR(parent)));
    }
}
