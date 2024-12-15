#include "generated/Dialog.h"

#include <QObject>
#include <QDialog>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((DialogWithHandler*)_this)

namespace Dialog
{
    class DialogWithHandler : public QDialog {
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
        };
    public:
        DialogWithHandler(QWidget *parent, const std::shared_ptr<SignalHandler> &handler) : handler(handler), QDialog(parent) {}
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
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget =================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Dialog =================
        void onAccepted() const {
            handler->accepted();
        }
        void onFinished(int result) const {
            handler->finished(result);
        }
        void onRejected() const {
            handler->rejected();
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
