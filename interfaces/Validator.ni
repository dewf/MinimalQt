module Validator;

import Object;

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
    ValidateResult validate(string input, int pos);

    // signals ======================
    SignalConnection connect_Changed(SignalHandler handler);
}

// non-const methods:
opaque Handle extends ConstHandle {

    // QLocale locale() const
    // void setLocale(const QLocale &locale)

}
