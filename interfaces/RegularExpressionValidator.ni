module RegularExpressionValidator;

import Object;
import Validator;
import RegularExpression;

@methodprefix("sig_")
interface SignalHandler extends Validator.SignalHandler {
    void regularExpressionChanged(RegularExpression.Handle re);
}

opaque Handle extends Validator.Handle {
    RegularExpression.Owned regularExpression();
    void setRegularExpression(RegularExpression.Handle re);

    SignalConnection connect_RegularExpressionChanged(SignalHandler handler);
}

Handle create(Object.Handle parent = null);
Handle create(RegularExpression.Handle re, Object.Handle parent = null);
