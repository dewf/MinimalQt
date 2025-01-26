module AbstractSpinBox;

import Widget;
import Object;
import Enums;
import Validator;

interface SignalHandler extends Widget.SignalHandler {
    void editingFinished();
}

enum ButtonSymbols { UpDownArrows, PlusMinus, NoButtons }
enum CorrectionMode  { CorrectToPreviousValue, CorrectToNearestValue }

// the naming on these seems backwards, but we're just copying Qt
@withflags(StepEnabled)
enum StepEnabledFlag {
    StepNone = 0x00,
    StepUpEnabled = 0x01,
    StepDownEnabled = 0x02
}

enum StepType {
    DefaultStepType,
    AdaptiveDecimalStepType
}

@nodispose
opaque Handle extends Widget.Handle {
    Alignment getAlignment();
    ButtonSymbols getButtonSymbols();
    CorrectionMode getCorrectionMode();
    
    string fixup(string input); // 'input' is actually a string ref, and function returns void

    bool hasAcceptableInput();
    bool hasFrame();
    void interpretText();
    bool isAccelerated();
    bool isGroupSeparatorShown();
    bool isReadOnly();
    bool keyboardTracking();
    void setAccelerated(bool on);
    void setAlignment(Alignment flag);
    void setButtonSymbols(ButtonSymbols bs);
    void setCorrectionMode(CorrectionMode cm);
    void setFrame(bool hasFrame);
    void setGroupSeparatorShown(bool shown);
    void setKeyboardTracking(bool kt);
    void setReadOnly(bool r);
    void setSpecialValueText(string text);
    void setWrapping(bool w);
    string specialValueText();
    void stepBy(int steps);
    string text();

    Validator.ValidateResult validate(string input, int pos); // 'input' and 'pos' are both ref params, and return value is simple Validate.State - we're approximating this with a struct return

    bool wrapping();

    void clear();
    void selectAll();
    void stepDown();
    void stepUp();

    // signals ===================
    SignalConnection connect_EditingFinished(SignalHandler handler);
}
