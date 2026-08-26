module Timer;

import Object;
import Enums;

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void timeout();
}

opaque Handle extends Object.Handle {

    TimerId id();
    int interval();

    // std::chrono::milliseconds intervalAsDuration() const

    bool isActive();
    bool isSingleShot();
    int remainingTime();

    // std::chrono::milliseconds remainingTimeAsDuration() const

    void setInterval(int msec);

    // void setInterval(std::chrono::milliseconds value)

    void setSingleShot(bool singleShot);

    void setTimerType(TimerType atype);

    // void start(std::chrono::milliseconds msec)

    int timerId();

    TimerType getTimerType();

    void start(int msec);
    void start();
    void stop();

    // signals ============================
    SignalConnection connect_Timeout(SignalHandler handler);
}

Handle create(Object.Handle parent = null);
