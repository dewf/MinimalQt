#include "generated/Dialog.h"

#include <QObject>
#include <QDialog>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((DialogWithHandler*)_this)

#include "DialogInternal.h"

namespace Dialog
{
    class DialogWithHandler : public QDialog {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        DialogWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : QDialog(parent), relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setModal(HandleRef _this, bool state) {
        THIS->setModal(state);
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        THIS->setSizeGripEnabled(enabled);
    }

    void Handle_setParentDialogFlags(HandleRef _this, Widget::HandleRef parent) {
        THIS->setParent(reinterpret_cast<QWidget *>(parent), Qt::Dialog);
    }

    void Handle_accept(HandleRef _this) {
        THIS->accept();
    }

    void Handle_reject(HandleRef _this) {
        THIS->reject();
    }

    int Handle_exec(HandleRef _this) {
        return THIS->exec();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new DialogWithHandler(reinterpret_cast<QWidget *>(parent), handler));
    }
}

#include "Dialog.moc"
