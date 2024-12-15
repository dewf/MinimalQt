#include "generated/Action.h"

#include <QObject>
#include <QAction>

#include "util/SignalStuff.h"

#include "IconInternal.h"
#include "KeySequenceInternal.h"

#define THIS ((ActionWithHandler*)_this)

namespace Action
{
    class ActionWithHandler : public QAction {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Action:
            { Changed, SIGNAL(changed()), SLOT(onChanged) },
            { CheckableChanged, SIGNAL(checkableChanged(bool)), SLOT(onCheckableChanged(bool)) },
            { EnabledChanged, SIGNAL(enabledChanged(bool)), SLOT(onEnabledChanged(bool) )},
            { Hovered, SIGNAL(hovered()), SLOT(onHovered()) },
            { Toggled, SIGNAL(toggled(bool)), SLOT(onToggled(bool)) },
            { Triggered, SIGNAL(triggered(bool)), SLOT(onTriggered(bool)) },
            { VisibleChanged, SIGNAL(visibleChanged()), SLOT(onVisibleChanged()) }
        };
    public:
        ActionWithHandler(QObject *parent, const std::shared_ptr<SignalHandler> &handler) : QAction(parent), handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Action =================
        void onChanged() const {
            handler->changed();
        }
        void onCheckableChanged(bool checkable) const {
            handler->checkableChanged(checkable);
        }
        void onEnabledChanged(bool enabled) const {
            handler->enabledChanged(enabled);
        }
        void onHovered() const {
            handler->hovered();
        }
        void onToggled(bool checked_) const {
            handler->toggled(checked_);
        }
        void onTriggered(bool checked_) const {
            handler->triggered(checked_);
        }
        void onVisibleChanged() const {
            handler->visibleChanged();
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
        THIS->setMenuRole((QAction::MenuRole)role);
    }

    void Handle_setPriority(HandleRef _this, Priority priority) {
        THIS->setPriority((QAction::Priority)priority);
    }

    void Handle_setShortcut(HandleRef _this, const std::shared_ptr<Deferred::Base>& shortcut) {
        THIS->setShortcut(fromDeferred(shortcut));
    }

    void Handle_setShortcutContext(HandleRef _this, ShortcutContext context) {
        THIS->setShortcutContext((Qt::ShortcutContext)context);
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
        return reinterpret_cast<HandleRef>(new ActionWithHandler((QObject *) owner, handler));
    }
}

#include "Action.moc"
