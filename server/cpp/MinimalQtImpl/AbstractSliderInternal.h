#pragma once

#include "generated/AbstractSlider.h"
#include "WidgetInternal.h"

#include <QAbstractSlider>

namespace AbstractSlider {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractSlider *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { ActionTriggered, SIGNAL(actionTriggered(int)), SLOT(onActionTriggered(int)) },
            { RangeChanged, SIGNAL(rangeChanged(int, int)), SLOT(onRangeChanged(int,int)) },
            { SliderMoved, SIGNAL(sliderMoved(int)), SLOT(onSliderMoved(int)) },
            { SliderPressed, SIGNAL(sliderPressed()), SLOT(onSliderPressed()) },
            { SliderReleased, SIGNAL(sliderReleased()), SLOT(onSliderReleased()) },
            { ValueChanged, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)) },
        };
    public:
        QAbstractSlider *getActual() const {
            return actual;
        }
        SignalWrapper(QAbstractSlider *existing, const std::shared_ptr<SignalHandler> &handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onActionTriggered(int action) const {
            handler->actionTriggered(static_cast<SliderAction>(action));
        };
        void onRangeChanged(int min, int max) const {
            handler->rangeChanged(min, max);
        }
        void onSliderMoved(int value) const {
            handler->sliderMoved(value);
        }
        void onSliderPressed() const {
            handler->sliderPressed();
        }
        void onSliderReleased() const {
            handler->sliderReleased();
        }
        void onValueChanged(int value) const {
            handler->valueChanged(value);
        }
    };
}
