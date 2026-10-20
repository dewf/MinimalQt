#include "generated/PushButton.h"
#include "PushButtonInternal.h"

#include "IconInternal.h"
#include "MenuInternal.h"
#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Icon;
using namespace ::AbstractButton;
using namespace ::Menu;

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

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto button = AS_QPUSHBUTTON_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(button);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(button);
        case Handle_CastTarget::AbstractButton_Handle:
            return static_cast<QAbstractButton*>(button);
            break;
        }
        std::unreachable();
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
