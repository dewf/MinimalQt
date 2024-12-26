#pragma once

#include "generated/Slider.h"
#include "AbstractSliderInternal.h"

#include <QSlider>

namespace Slider {
    class SignalWrapper : public AbstractSlider::SignalWrapper {
        Q_OBJECT
    private:
        QSlider *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // none
        };
    public:
        QSlider *getActual() const {
            return actual;
        }
        SignalWrapper(QSlider *existing, const std::shared_ptr<SignalHandler> &handler)
            : AbstractSlider::SignalWrapper(existing, SignalHandler::as_AbstractSlider_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractSlider::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        // none
    };
}
