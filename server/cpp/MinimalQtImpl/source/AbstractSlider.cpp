#include "generated/AbstractSlider.h"
#include "AbstractSliderInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Enums;

#define THIS (reinterpret_cast<QAbstractSlider*>(_this))

namespace AbstractSlider
{
    bool Handle_hasTracking(HandleRef _this) {
        return THIS->hasTracking();
    }

    bool Handle_invertedAppearance(HandleRef _this) {
        return THIS->invertedAppearance();
    }

    bool Handle_invertedControls(HandleRef _this) {
        return THIS->invertedControls();
    }

    bool Handle_isSliderDown(HandleRef _this) {
        return THIS->isSliderDown();
    }

    int32_t Handle_maximum(HandleRef _this) {
        return THIS->maximum();
    }

    int32_t Handle_minimum(HandleRef _this) {
        return THIS->minimum();
    }

    Orientation Handle_getOrientation(HandleRef _this) {
        return static_cast<Orientation>(THIS->orientation());
    }

    int32_t Handle_pageStep(HandleRef _this) {
        return THIS->pageStep();
    }

    void Handle_setInvertedAppearance(HandleRef _this, bool state) {
        THIS->setInvertedAppearance(state);
    }

    void Handle_setInvertedControls(HandleRef _this, bool state) {
        THIS->setInvertedControls(state);
    }

    void Handle_setMaximum(HandleRef _this, int32_t value) {
        THIS->setMaximum(value);
    }

    void Handle_setMinimum(HandleRef _this, int32_t value) {
        THIS->setMinimum(value);
    }

    void Handle_setPageStep(HandleRef _this, int32_t pageStep) {
        THIS->setPageStep(pageStep);
    }

    void Handle_setSingleStep(HandleRef _this, int32_t step) {
        THIS->setSingleStep(step);
    }

    void Handle_setSliderDown(HandleRef _this, bool state) {
        THIS->setSliderDown(state);
    }

    void Handle_setSliderPosition(HandleRef _this, int32_t pos) {
        THIS->setSliderPosition(pos);
    }

    void Handle_setTracking(HandleRef _this, bool value) {
        THIS->setTracking(value);
    }

    int32_t Handle_singleStep(HandleRef _this) {
        return THIS->singleStep();
    }

    int32_t Handle_sliderPosition(HandleRef _this) {
        return THIS->sliderPosition();
    }

    void Handle_triggerAction(HandleRef _this, SliderAction action) {
        return THIS->triggerAction(static_cast<QAbstractSlider::SliderAction>(action));
    }

    int32_t Handle_value(HandleRef _this) {
        return THIS->value();
    }

    void Handle_setOrientation(HandleRef _this, Orientation orient) {
        THIS->setOrientation(static_cast<Qt::Orientation>(orient));
    }

    void Handle_setRange(HandleRef _this, int32_t min, int32_t max) {
        THIS->setRange(min, max);
    }

    void Handle_setValue(HandleRef _this, int32_t value) {
        THIS->setValue(value);
    }

    SignalConnectionRef Handle_connect_ActionTriggered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::actionTriggered, [handler](int action) {
            handler->sig_actionTriggered(static_cast<SliderAction>(action));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RangeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::rangeChanged, [handler](int min, int max) {
            handler->sig_rangeChanged(min, max);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SliderMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::sliderMoved, [handler](int value) {
            handler->sig_sliderMoved(value);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SliderPressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::sliderPressed, [handler] {
            handler->sig_sliderPressed();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SliderReleased(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::sliderReleased, [handler] {
            handler->sig_sliderReleased();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ValueChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractSlider::valueChanged, [handler](int value) {
            handler->sig_valueChanged(value);
        });
        return new __SignalConnection { connection };
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto absSlider = AS_QABSTRACTSLIDER_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(absSlider);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(absSlider);
        }
        std::unreachable();
    }
}
