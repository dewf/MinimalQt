#include "generated/Dialog.h"
#include "DialogInternal.h"

#include "ObjectInternal.h"

#define THIS (reinterpret_cast<QDialog*>(_this))

namespace Dialog
{
    void Handle_setModal(HandleRef _this, bool state) {
        THIS->setModal(state);
    }

    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return THIS->isSizeGripEnabled();
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        THIS->setSizeGripEnabled(enabled);
    }

    void Handle_setParentDialogFlags(HandleRef _this, Widget::HandleRef parent) {
        THIS->setParent(AS_QWIDGET_PTR(parent), Qt::Dialog);
    }

    int32_t Handle_result(HandleRef _this) {
        return THIS->result();
    }

    void Handle_setResult(HandleRef _this, int32_t result) {
        THIS->setResult(result);
    }

    void Handle_accept(HandleRef _this) {
        THIS->accept();
    }

    void Handle_done(HandleRef _this, int32_t result) {
        THIS->done(result);
    }

    void Handle_reject(HandleRef _this) {
        THIS->reject();
    }

    int Handle_exec(HandleRef _this) {
        return THIS->exec();
    }

    SignalConnectionRef Handle_connect_Accepted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::accepted, [handler] {
            handler->accepted();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Finished(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::finished, [handler](int result) {
            handler->finished(result);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Rejected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::rejected, [handler] {
            handler->rejected();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent) {
        return reinterpret_cast<HandleRef>(AS_QWIDGET_PTR(parent));
    }
}
