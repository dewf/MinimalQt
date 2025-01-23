#include "generated/PushButton.h"

#include "IconInternal.h"
#include "MenuInternal.h"
#include "PushButtonInternal.h"
#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QPushButton*>(_this))

namespace PushButton
{
    bool Handle_autoDefault(HandleRef _this) {
        return THIS->autoDefault();
    }

    bool Handle_isDefault(HandleRef _this) {
        return THIS->isDefault();
    }

    bool Handle_isFlat(HandleRef _this) {
        return THIS->isFlat();
    }

    Menu::HandleRef Handle_getMenu(HandleRef _this) {
        return reinterpret_cast<Menu::HandleRef>(THIS->menu());
    }

    void Handle_setAutoDefault(HandleRef _this, bool value) {
        THIS->setAutoDefault(value);
    }

    void Handle_setDefault(HandleRef _this, bool value) {
        THIS->setDefault(value);
    }

    void Handle_setFlat(HandleRef _this, bool value) {
        THIS->setFlat(value);
    }

    void Handle_setMenu(HandleRef _this, Menu::HandleRef menu) {
        THIS->setMenu(AS_QMENU_PTR(menu));
    }

    void Handle_showMenu(HandleRef _this) {
        THIS->showMenu();
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QPushButton(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QPushButton(QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Icon::HandleRef icon, const std::string& text, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QPushButton(QICON_VALUE(icon), QString::fromStdString(text), AS_QWIDGET_PTR(parent)));
    }
}
