module SpinBox;

import Object;
import AbstractSpinBox;
import Widget;

@methodprefix("sig_")
interface SignalHandler extends AbstractSpinBox.SignalHandler {
    void textChanged(string text);
    void valueChanged(int value);
}

opaque Handle extends AbstractSpinBox.Handle {

    string cleanText();
    int displayIntegerBase();
    int maximum();
    int minimum();
    string prefix();
    void setDisplayIntegerBase(int base_); // reserved word in C#
    void setMaximum(int max);
    void setMinimum(int min);
    void setPrefix(string prefix);
    void setRange(int minimum, int maximum);
    void setSingleStep(int val);
    void setStepType(StepType stepType);
    void setSuffix(string suffix);
    int singleStep();
    StepType stepType();
    string suffix();
    int value();

    void setValue(int val);

    // signals ===============
    SignalConnection connect_TextChanged(SignalHandler handler);
    SignalConnection connect_ValueChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
