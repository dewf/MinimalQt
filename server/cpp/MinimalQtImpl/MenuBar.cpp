#include "generated/MenuBar.h"
#include "MenuBarInternal.h"

#include <QObject>
#include <QMenuBar>

#define THIS ((MenuBarWithHandler*)_this)

namespace MenuBar
{
    class MenuBarWithHandler : public QMenuBar {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit MenuBarWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    bool Handle_isDefaultUp(HandleRef _this) {
        return THIS->isDefaultUp();
    }

    void Handle_setDefaultUp(HandleRef _this, bool state) {
        THIS->setDefaultUp(state);
    }

    bool Handle_isNativeMenuBar(HandleRef _this) {
        return THIS->isNativeMenuBar();
    }

    void Handle_setNativeMenuBar(HandleRef _this, bool state) {
        THIS->setNativeMenuBar(state);
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_addMenu(HandleRef _this, Menu::HandleRef menu) {
        THIS->addMenu(reinterpret_cast<QMenu*>(menu));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new MenuBarWithHandler(handler));
    }
}

#include "MenuBar.moc"
