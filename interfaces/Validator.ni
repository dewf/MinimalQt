module Validator;

import Object;

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void changed();
}

enum State { Invalid, Intermediate, Acceptable }

struct ValidateResult {
    State state;
    string output;
    int outPos;
}

@nodispose
opaque ConstHandle extends Object.Handle {
    string fixup(string input);                         // potentially modifies the string, but not necessarily

    // QLocale	locale() const

    ValidateResult validate(string input, int pos);

    // signals ======================
    SignalConnection connect_Changed(SignalHandler handler);
}

// non-const methods:
@nodispose
opaque Handle extends ConstHandle {
    // void setLocale(const QLocale &locale)
}

// QValidator is abstract, no constructors
