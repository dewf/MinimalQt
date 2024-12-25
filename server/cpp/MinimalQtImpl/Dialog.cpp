#include "generated/Dialog.h"
#include "DialogInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define DIALOG_THIS (WRAPPER->getActual())

namespace Dialog
{
    void Handle_setModal(HandleRef _this, bool state) {
        DIALOG_THIS->setModal(state);
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        DIALOG_THIS->setSizeGripEnabled(enabled);
    }

    void Handle_setParentDialogFlags(HandleRef _this, Widget::HandleRef parent) {
        DIALOG_THIS->setParent(reinterpret_cast<QWidget *>(parent), Qt::Dialog);
    }

    void Handle_accept(HandleRef _this) {
        DIALOG_THIS->accept();
    }

    void Handle_reject(HandleRef _this) {
        DIALOG_THIS->reject();
    }

    int Handle_exec(HandleRef _this) {
        return DIALOG_THIS->exec();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        const auto parentWrapper = reinterpret_cast<Widget::SignalWrapper*>(parent);
        const auto dialog = new QDialog(parentWrapper->getActual());
        const auto wrapper = new SignalWrapper(dialog, handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}

#include "Dialog.moc"
