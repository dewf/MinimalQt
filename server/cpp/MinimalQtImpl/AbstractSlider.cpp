#include "generated/AbstractSlider.h"
#include "AbstractSliderInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSLIDER_THIS (WRAPPER->getActual())

namespace AbstractSlider
{
    void Handle_setInvertedAppearance(HandleRef _this, bool state) {
        ABSLIDER_THIS->setInvertedAppearance(state);
    }

    void Handle_setInvertedControls(HandleRef _this, bool state) {
        ABSLIDER_THIS->setInvertedControls(state);
    }

    void Handle_setMaximum(HandleRef _this, int32_t value) {
        ABSLIDER_THIS->setMaximum(value);
    }

    void Handle_setMinimum(HandleRef _this, int32_t value) {
        ABSLIDER_THIS->setMinimum(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation orient) {
        ABSLIDER_THIS->setOrientation((Qt::Orientation)orient);
    }

    void Handle_setPageStep(HandleRef _this, int32_t pageStep) {
        ABSLIDER_THIS->setPageStep(pageStep);
    }

    void Handle_setSingleStep(HandleRef _this, int32_t step) {
        ABSLIDER_THIS->setSingleStep(step);
    }

    void Handle_setSliderDown(HandleRef _this, bool state) {
        ABSLIDER_THIS->setSliderDown(state);
    }

    void Handle_setSliderPosition(HandleRef _this, int32_t pos) {
        ABSLIDER_THIS->setSliderPosition(pos);
    }

    void Handle_setTracking(HandleRef _this, bool value) {
        ABSLIDER_THIS->setTracking(value);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        ABSLIDER_THIS->setValue(value);
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        ABSLIDER_THIS->setRange(min, max);
    }
}
