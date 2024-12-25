#include "generated/GroupBox.h"
#include "GroupBoxInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define GROUPBOX_THIS (WRAPPER->getActual())

namespace GroupBox {
    void Handle_setAlignment(HandleRef _this, Alignment align) {
        GROUPBOX_THIS->setAlignment(align);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        GROUPBOX_THIS->setCheckable(state);
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        GROUPBOX_THIS->setChecked(state);
    }

    void Handle_setFlat(HandleRef _this, bool state) {
        GROUPBOX_THIS->setFlat(state);
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        GROUPBOX_THIS->setTitle(QString::fromStdString(title));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QGroupBox(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}

#include "GroupBox.moc"
