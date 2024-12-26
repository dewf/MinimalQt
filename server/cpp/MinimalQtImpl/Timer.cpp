#include "generated/Timer.h"
#include "TimerInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TIMER_THIS (WRAPPER->getActual())

namespace Timer
{
    bool Handle_isActive(HandleRef _this) {
        return TIMER_THIS->isActive();
    }

    void Handle_setInterval(HandleRef _this, int32_t msec) {
        TIMER_THIS->setInterval(msec);
    }

    int32_t Handle_remainingTime(HandleRef _this) {
        return TIMER_THIS->remainingTime();
    }

    void Handle_setSingleShot(HandleRef _this, bool state) {
        TIMER_THIS->setSingleShot(state);
    }

    void Handle_setTimerType(HandleRef _this, TimerType type_) {
        TIMER_THIS->setTimerType(static_cast<Qt::TimerType>(type_));
    }

    void Handle_start(HandleRef _this, int32_t msec) {
        TIMER_THIS->start(msec);
    }

    void Handle_start(HandleRef _this) {
        TIMER_THIS->start();
    }

    void Handle_stop(HandleRef _this) {
        TIMER_THIS->stop();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QTimer(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
