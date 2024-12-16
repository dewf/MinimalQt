#pragma once

#include "../generated/AbstractSlider.h"
#include "Widget.h"

namespace AbstractSlider {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
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
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalRelay(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
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
