#include "generated/RadioButton.h"
#include "RadioButtonInternal.h"

#include <QRadioButton>
#include "util/convert.h"

#define THIS ((RadioButtonWithHandler*)_this)

namespace RadioButton
{
    class RadioButtonWithHandler : public QRadioButton {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit RadioButtonWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new RadioButtonWithHandler(handler));
    }
}

#include "RadioButton.moc"
