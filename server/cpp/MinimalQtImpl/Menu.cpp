#include "generated/Menu.h"
#include "MenuInternal.h"

// #include <QObject>

#include "util/convert.h"
#include "IconInternal.h"

#include "ActionInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MENU_THIS (WRAPPER->getActual())

namespace Menu
{
    Icon::OwnedRef Handle_getIcon(HandleRef _this) {
        return ICON_HEAP_NEW(MENU_THIS->icon());
    }

    void Handle_setIcon(HandleRef _this, Icon::HandleRef icon) {
        MENU_THIS->setIcon(QICON_VALUE(icon));
    }

    bool Handle_separatorsCollasible(HandleRef _this) {
        return MENU_THIS->separatorsCollapsible();
    }

    void Handle_setSeparatorsCollapsible(HandleRef _this, bool state) {
        MENU_THIS->setSeparatorsCollapsible(state);
    }

    bool Handle_isTearOffEnabled(HandleRef _this) {
        return MENU_THIS->isTearOffEnabled();
    }

    void Handle_setTearOffEnabled(HandleRef _this, bool state) {
        MENU_THIS->setTearOffEnabled(state);
    }

    std::string Handle_title(HandleRef _this) {
        return MENU_THIS->title().toStdString();
    }

    void Handle_setTitle(HandleRef _this, const std::string& title) {
        MENU_THIS->setTitle(QString::fromStdString(title));
    }

    bool Handle_toolTipsVisible(HandleRef _this) {
        return MENU_THIS->toolTipsVisible();
    }

    void Handle_setToolTipsVisible(HandleRef _this, bool visible) {
        MENU_THIS->setToolTipsVisible(visible);
    }

    void Handle_clear(HandleRef _this) {
        MENU_THIS->clear();
    }

    Action::HandleRef Handle_addSeparator(HandleRef _this, const std::shared_ptr<Action::SignalHandler>& handler) {
        const auto wrapper = new Action::SignalWrapper(MENU_THIS->addSeparator(), handler);
        return reinterpret_cast<Action::HandleRef>(wrapper);
    }

    void Handle_popup(HandleRef _this, Point p) {
        MENU_THIS->popup(toQPoint(p));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QMenu(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
