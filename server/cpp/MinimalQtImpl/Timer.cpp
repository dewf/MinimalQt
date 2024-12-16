#include "generated/Timer.h"

#include <QTimer>
#include <QObject>
#include <utility>

#include "util/SignalStuff.h"

#define THIS ((TimerWithHandler*)_this)

#include "signalrelays/Timer.h"

namespace Timer
{
    class TimerWithHandler : public QTimer {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit TimerWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    bool Handle_isActive(HandleRef _this) {
        return THIS->isActive();
    }

    void Handle_setInterval(HandleRef _this, int32_t msec) {
        THIS->setInterval(msec);
    }

    int32_t Handle_remainingTime(HandleRef _this) {
        return THIS->remainingTime();
    }

    void Handle_setSingleShot(HandleRef _this, bool state) {
        THIS->setSingleShot(state);
    }

    void Handle_setTimerType(HandleRef _this, TimerType type_) {
        THIS->setTimerType(static_cast<Qt::TimerType>(type_));
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

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new TimerWithHandler(handler));
    }
}

#include "Timer.moc"
