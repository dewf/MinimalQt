#include "generated/ToolBar.h"
#include "ToolBarInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TOOLBAR_THIS (WRAPPER->getActual())

namespace ToolBar
{
    void Handle_setAllowedAreas(HandleRef _this, Enums::ToolBarAreas allowed) {
        TOOLBAR_THIS->setAllowedAreas(static_cast<Qt::ToolBarAreas>(allowed));
    }

    void Handle_setFloatable(HandleRef _this, bool floatable) {
        TOOLBAR_THIS->setFloatable(floatable);
    }

    bool Handle_isFloating(HandleRef _this) {
        return TOOLBAR_THIS->isFloating();
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        TOOLBAR_THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        TOOLBAR_THIS->setMovable(value);
    }

    void Handle_setOrientation(HandleRef _this, Orientation value) {
        TOOLBAR_THIS->setOrientation(static_cast<Qt::Orientation>(value));
    }

    void Handle_setToolButtonStyle(HandleRef _this, ToolButtonStyle style) {
        TOOLBAR_THIS->setToolButtonStyle(static_cast<Qt::ToolButtonStyle>(style));
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this) {
        return reinterpret_cast<Action::HandleRef>(TOOLBAR_THIS->addSeparator());
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        TOOLBAR_THIS->addWidget(reinterpret_cast<QWidget *>(widget));
    }

    void Handle_clear(HandleRef _this) {
        TOOLBAR_THIS->clear();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QToolBar(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
