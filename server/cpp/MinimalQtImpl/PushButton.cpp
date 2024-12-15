#include "generated/PushButton.h"

#include <QPushButton>
#include "util/SignalStuff.h"
#include "util/convert.h"

#include "signalmanagers/PushButtonSignalManager.h"

#define THIS ((PushButtonWithHandler*)_this)

namespace PushButton
{
    class PushButtonWithHandler : public QPushButton {
        Q_OBJECT
    private:
        PushButtonSignalManager signalManager;
    public:
        explicit PushButtonWithHandler(const std::shared_ptr<SignalHandler>& handler) : signalManager(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            signalManager.setSignalMask(newMask);
        }
    };

    void Handle_setAutoDefault(HandleRef _this, bool value) {
        THIS->setAutoDefault(value);
    }

    void Handle_setDefault(HandleRef _this, bool value) {
        THIS->setDefault(value);
    }

    void Handle_setFlat(HandleRef _this, bool value) {
        THIS->setFlat(value);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new PushButtonWithHandler(handler));
    }
}

#include "PushButton.moc"
