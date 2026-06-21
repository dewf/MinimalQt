module AbstractSlider;

import Object;
import Widget;
import Enums;

enum SliderAction {
    SliderNoAction,
    SliderSingleStepAdd,
    SliderSingleStepSub,
    SliderPageStepAdd,
    SliderPageStepSub,
    SliderToMinimum,
    SliderToMaximum,
    SliderMove
}

interface SignalHandler extends Widget.SignalHandler {
    void actionTriggered(SliderAction action);
    void rangeChanged(int min, int max);
    void sliderMoved(int value);
    void sliderPressed();
    void sliderReleased();
    void valueChanged(int value);
}

@nodispose
opaque Handle extends Widget.Handle {
    bool hasTracking();
    bool invertedAppearance();
    bool invertedControls();
    bool isSliderDown();
    int maximum();
    int minimum();
    Orientation getOrientation();
    int pageStep();
    void setInvertedAppearance(bool state);
    void setInvertedControls(bool state);
    void setMaximum(int value);
    void setMinimum(int value);
    void setPageStep(int pageStep);
    void setSingleStep(int step);
    void setSliderDown(bool state);
    void setSliderPosition(int pos);
    void setTracking(bool value);
    int singleStep();
    int sliderPosition();
    void triggerAction(SliderAction action);
    int value();

    void setOrientation(Orientation orient);
    void setRange(int min, int max);
    void setValue(int value);

    // signals ============================
    SignalConnection connect_ActionTriggered(SignalHandler handler);
    SignalConnection connect_RangeChanged(SignalHandler handler);
    SignalConnection connect_SliderMoved(SignalHandler handler);
    SignalConnection connect_SliderPressed(SignalHandler handler);
    SignalConnection connect_SliderReleased(SignalHandler handler);
    SignalConnection connect_ValueChanged(SignalHandler handler);
}

// no direct creation, inherited by eg QSlider
