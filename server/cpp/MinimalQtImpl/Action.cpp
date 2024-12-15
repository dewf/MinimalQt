#include "generated/Action.h"

#include <QObject>
#include <QAction>

#include "util/SignalStuff.h"

#include "IconInternal.h"
#include "KeySequenceInternal.h"

#include "signalmanagers/Action.h"

#define THIS ((ActionWithHandler*)_this)

namespace Action
{
    class ActionWithHandler : public QAction {
        Q_OBJECT
    private:
        ActionSignalManager signalManager;
    public:
        ActionWithHandler(QObject *parent, const std::shared_ptr<SignalHandler> &handler) : QAction(parent),
            signalManager(this, handler) {
        }
        void setSignalMask(SignalMask newMask) {
            signalManager.setSignalMask(newMask);
        }
    };

    void Handle_setAutoRepeat(HandleRef _this, bool state) {
        THIS->setAutoRepeat(state);
    }

    void Handle_setCheckable(HandleRef _this, bool state) {
        THIS->setCheckable(state);
    }

    void Handle_setChecked(HandleRef _this, bool state) {
        THIS->setChecked(state);
    }

    void Handle_setEnabled(HandleRef _this, bool state) {
        THIS->setEnabled(state);
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(ICON_VALUE(icon));
    }

    void Handle_setIconText(HandleRef _this, const std::string& text) {
        THIS->setIconText(QString::fromStdString(text));
    }

    void Handle_setIconVisibleInMenu(HandleRef _this, bool visible) {
        THIS->setIconVisibleInMenu(visible);
    }

    void Handle_setMenuRole(HandleRef _this, MenuRole role) {
        THIS->setMenuRole(static_cast<QAction::MenuRole>(role));
    }

    void Handle_setPriority(HandleRef _this, Priority priority) {
        THIS->setPriority(static_cast<QAction::Priority>(priority));
    }

    void Handle_setShortcut(HandleRef _this, const std::shared_ptr<Deferred::Base>& shortcut) {
        THIS->setShortcut(fromDeferred(shortcut));
    }

    void Handle_setShortcutContext(HandleRef _this, ShortcutContext context) {
        THIS->setShortcutContext(static_cast<Qt::ShortcutContext>(context));
    }

    void Handle_setShortcutVisibleInContextMenu(HandleRef _this, bool visible) {
        THIS->setShortcutVisibleInContextMenu(visible);
    }

    void Handle_setStatusTip(HandleRef _this, const std::string& tip) {
        THIS->setStatusTip(QString::fromStdString(tip));
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    void Handle_setToolTip(HandleRef _this, const std::string& tip) {
        THIS->setToolTip(QString::fromStdString(tip));
    }

    void Handle_setVisible(HandleRef _this, bool visible) {
        THIS->setVisible(visible);
    }

    void Handle_setWhatsThis(HandleRef _this, const std::string& text) {
        THIS->setWhatsThis(QString::fromStdString(text));
    }

    void Handle_setSeparator(HandleRef _this, bool state) {
        THIS->setSeparator(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef owner, const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ActionWithHandler(reinterpret_cast<QObject *>(owner), handler));
    }
}

#include "Action.moc"
