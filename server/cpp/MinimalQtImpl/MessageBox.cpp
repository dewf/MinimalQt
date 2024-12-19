#include "generated/MessageBox.h"

#include <QMessageBox>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((MessageBoxWithHandler*)_this)

#include "MessageBoxInternal.h"

namespace MessageBox
{
    class MessageBoxWithHandler : public QMessageBox {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        MessageBoxWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : QMessageBox(parent), relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setDetailedText(HandleRef _this, const std::string& text) {
        THIS->setDetailedText(QString::fromStdString(text));
    }

    void Handle_setIcon(HandleRef _this, MessageBoxIcon icon) {
        THIS->setIcon(static_cast<QMessageBox::Icon>(icon));
    }

    void Handle_setInformativeText(HandleRef _this, const std::string& text) {
        THIS->setInformativeText(QString::fromStdString(text));
    }

    void Handle_setOptions(HandleRef _this, Options opts) {
        THIS->setOptions(static_cast<QMessageBox::Options>(opts));
    }

    void Handle_setStandardButtons(HandleRef _this, StandardButtonSet buttons) {
        THIS->setStandardButtons(static_cast<QMessageBox::StandardButtons>(buttons));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setTextFormat(HandleRef _this, TextFormat format) {
        THIS->setTextFormat(static_cast<Qt::TextFormat>(format));
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    void Handle_setDefaultButton(HandleRef _this, StandardButton button) {
        THIS->setDefaultButton(static_cast<QMessageBox::StandardButton>(button));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MessageBoxWithHandler(reinterpret_cast<QWidget *>(parent), handler));
    }
}

#include "MessageBox.moc"
