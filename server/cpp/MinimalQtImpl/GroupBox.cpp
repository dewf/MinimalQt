#include "generated/GroupBox.h"
#include "GroupBoxInternal.h"

#include <QGroupBox>
#include "util/convert.h"

#define THIS ((GroupBoxWithHandler*)_this)

namespace GroupBox {
    class GroupBoxWithHandler : public QGroupBox {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit GroupBoxWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAlignment(HandleRef _this, Alignment align) {
        THIS->setAlignment(align);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    void Handle_setFlat(HandleRef _this, bool state) {
        THIS->setFlat(state);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new GroupBoxWithHandler(handler));
    }
}

#include "GroupBox.moc"
