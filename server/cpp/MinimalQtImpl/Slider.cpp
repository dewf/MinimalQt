#include "generated/Slider.h"

#include <QSlider>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((SliderWithHandler*)_this)

namespace Slider
{
    class SliderWithHandler : public QSlider {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // AbstractSlider:
            { ActionTriggered, SIGNAL(actionTriggered(int)), SLOT(onActionTriggered(int)) },
            { RangeChanged, SIGNAL(rangeChanged(int, int)), SLOT(onRangeChanged(int,int)) },
            { SliderMoved, SIGNAL(sliderMoved(int)), SLOT(onSliderMoved(int)) },
            { SliderPressed, SIGNAL(sliderPressed()), SLOT(onSliderPressed()) },
            { SliderReleased, SIGNAL(sliderReleased()), SLOT(onSliderReleased()) },
            { ValueChanged, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)) },
            // Slider:
            // .... (none)
        };
    public:
        explicit SliderWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // AbstractSlider ==========
        void onActionTriggered(int action) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    actionTriggered(static_cast<AbstractSlider::SliderAction>(action));
        };
        void onRangeChanged(int min, int max) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    rangeChanged(min, max);
        }
        void onSliderMoved(int value) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    sliderMoved(value);
        }
        void onSliderPressed() const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    sliderPressed();
        }
        void onSliderReleased() const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    sliderReleased();
        }
        void onValueChanged(int value) const {
            handler->
                inherited_AbstractSlider_SignalHandler()->
                    valueChanged(value);
        }
        // Slider ==================
        // .... (none)
    };

    void Handle_setTickInterval(HandleRef _this, int32_t interval) {
        THIS->setTickInterval(interval);
    }

    void Handle_setTickPosition(HandleRef _this, TickPosition tpos) {
        THIS->setTickPosition(static_cast<QSlider::TickPosition>(tpos));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new SliderWithHandler(handler));
    }
}

#include "Slider.moc"
