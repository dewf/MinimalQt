#include "generated/ScrollBar.h"
#include "ScrollBarInternal.h"

#include "WidgetInternal.h"
#include "MenuInternal.h"
#include "PointInternal.h"

using namespace ::AbstractSlider;
using namespace ::Widget;
using namespace ::Enums;
using namespace ::Menu;
using namespace ::Point;

#define THIS (AS_QSCROLLBAR_PTR(_this))

namespace ScrollBar
{
    Menu::HandleRef Handle_createStandardContextMenu(HandleRef _this, Point::HandleRef position) {
        return reinterpret_cast<Menu::HandleRef>(THIS->createStandardContextMenu(QPOINT_VALUE(position)));
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto scrollbar = AS_QSCROLLBAR_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(scrollbar);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(scrollbar);
        case Handle_CastTarget::AbstractSlider_Handle:
            return static_cast<QAbstractSlider*>(scrollbar);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QScrollBar(AS_QWIDGET_PTR(parent)));
    }

    HandleRef create(Orientation orientation, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QScrollBar(static_cast<Qt::Orientation>(orientation), AS_QWIDGET_PTR(parent)));
    }
}
