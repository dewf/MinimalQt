#include "generated/ToolBar.h"

#include <QToolBar>
#include <utility>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((ToolBarWithHandler*)_this)

#include "signalrelays/ToolBar.h"

namespace ToolBar
{
    class ToolBarWithHandler : public QToolBar {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit ToolBarWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAllowedAreas(HandleRef _this, Enums::ToolBarAreas allowed) {
        THIS->setAllowedAreas(static_cast<Qt::ToolBarAreas>(allowed));
    }

    void Handle_setFloatable(HandleRef _this, bool floatable) {
        THIS->setFloatable(floatable);
    }

    bool Handle_isFloating(HandleRef _this) {
        return THIS->isFloating();
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        THIS->setMovable(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation value) {
        THIS->setOrientation(static_cast<Qt::Orientation>(value));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(THIS->addSeparator());
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ToolBarWithHandler(handler));
    }
}

#include "ToolBar.moc"
