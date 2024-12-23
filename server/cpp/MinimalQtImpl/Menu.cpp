#include "generated/Menu.h"
#include "MenuInternal.h"

#include <QObject>
#include <QMenu>

#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((MenuWithHandler*)_this)

namespace Menu
{
    class MenuWithHandler : public QMenu {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit MenuWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        THIS->setIcon(QICON_VALUE(icon));
    }

    bool Handle_separatorsCollasible(HandleRef _this) {
        return THIS->separatorsCollapsible();
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool state) {
        THIS->setSeparatorsCollapsible(state);
    }

    bool Handle_isTearOffEnabled(HandleRef _this) {
        return THIS->isTearOffEnabled();
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool state) {
        THIS->setTearOffEnabled(state);
    }

    std::string Handle_title(HandleRef _this) {
        return THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        THIS->setTitle(QString::fromStdString(title));
    }

    bool Handle_toolTipsVisible(HandleRef _this) {
        return THIS->toolTipsVisible();
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        THIS->setToolTipsVisible(visible);
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        // Menu has ownership, hence Handle (vs. Owned)
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_popup(HandleRef _this, Point p) {
        THIS->popup(toQPoint(p));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MenuWithHandler(handler));
    }
}

#include "Menu.moc"
