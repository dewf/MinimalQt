#include "generated/MessageBox.h"

#include <QMessageBox>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((MessageBoxWithHandler*)_this)

namespace MessageBox
{
    class MessageBoxWithHandler : public QMessageBox {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // Dialog:
            { SignalMaskFlags::Accepted, SIGNAL(accepted()), SLOT(onAccepted()) },
            { Finished, SIGNAL(finished(int)), SLOT(onFinished(int)) },
            { SignalMaskFlags::Rejected, SIGNAL(rejected()), SLOT(onRejected()) },
            // MessageBox:
            { ButtonClicked, SIGNAL(buttonClicked(QAbstractButton)), SLOT(onButtonClicked(QAbstractButton)) }
        };
    public:
        MessageBoxWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : QMessageBox(parent), handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget =================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((::Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Dialog_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Dialog =================
        void onAccepted() const {
            handler->
                inherited_Dialog_SignalHandler()->
                    accepted();
        }
        void onFinished(int result) const {
            handler->
                inherited_Dialog_SignalHandler()->
                    finished(result);
        }
        void onRejected() const {
            handler->
                inherited_Dialog_SignalHandler()->
                    rejected();
        }
        // MessageBox ==============
        void onButtonClicked(QAbstractButton *button) const {
            handler->buttonClicked((AbstractButton::HandleRef)button);
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
