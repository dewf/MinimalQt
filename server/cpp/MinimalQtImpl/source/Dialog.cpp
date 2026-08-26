#include "generated/Dialog.h"
#include "DialogInternal.h"

#include "ObjectInternal.h"

using namespace ::Object;
using namespace ::Icon;
using namespace ::Widget;
using namespace ::Enums;

#define THIS (reinterpret_cast<QDialog*>(_this))

namespace Dialog
{
    // don't remember what exactly this was for, back in the F# days
    // void Handle_setParentDialogFlags(HandleRef _this, Widget::HandleRef parent) {
    //     THIS->setParent(AS_QWIDGET_PTR(parent), Qt::Dialog);
    // }

    bool Handle_isSizeGripEnabled(HandleRef _this) {
        return THIS->isSizeGripEnabled();
    }

    int32_t Handle_result(HandleRef _this) {
        return THIS->result();
    }

    void Handle_setModal(HandleRef _this, bool modal) {
        THIS->setModal(modal);
    }

    void Handle_setResult(HandleRef _this, int32_t i) {
        THIS->setResult(i);
    }

    void Handle_setSizeGripEnabled(HandleRef _this, bool enabled) {
        THIS->setSizeGripEnabled(enabled);
    }

    void Handle_accept(HandleRef _this) {
        THIS->accept();
    }

    void Handle_done(HandleRef _this, int32_t r) {
        THIS->done(r);
    }

    int32_t Handle_exec(HandleRef _this) {
        return THIS->exec();
    }

    void Handle_open(HandleRef _this) {
        THIS->open();
    }

    void Handle_reject(HandleRef _this) {
        THIS->reject();
    }

    SignalConnectionRef Handle_connect_Accepted(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::accepted, [handler] {
            handler->sig_accepted();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Finished(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::finished, [handler](int result) {
            handler->sig_finished(result);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Rejected(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QDialog::rejected, [handler] {
            handler->sig_rejected();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */, Flags<WindowFlags> f /* 0 */) {
        auto intFlags = std::bit_cast<int>(f.value()); // Qt flags silliness
        return reinterpret_cast<HandleRef>(new QDialog(AS_QWIDGET_PTR(parent), static_cast<Qt::WindowFlags>(intFlags)));
    }
}
