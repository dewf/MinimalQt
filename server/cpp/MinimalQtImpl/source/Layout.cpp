#include "generated/Layout.h"
#include "LayoutInternal.h"

#include "WidgetInternal.h"
#include "LayoutItemInternal.h"
#include "SizeInternal.h"
#include "RectInternal.h"
#include "MarginsInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Margins;
using namespace ::Size;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::LayoutItem;
using namespace ::Widget;

#define THIS (reinterpret_cast<QLayout*>(_this))

namespace Layout
{
    LayoutItem::HandleRef Handle_asLayoutItem(HandleRef _this) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS);
    }

    bool Handle_activate(HandleRef _this) {
        return THIS->activate();
    }

    void Handle_addItem(HandleRef _this, LayoutItem::HandleRef item) {
        THIS->addItem(AS_QLAYOUTITEM_PTR(item));
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->addWidget(AS_QWIDGET_PTR(widget));
    }

    Margins::OwnedRef Handle_contentsMargins(HandleRef _this) {
        return MARGINS_HEAP_NEW(THIS->contentsMargins());
    }

    Rect::OwnedRef Handle_contentsRect(HandleRef _this) {
        return RECT_HEAP_NEW(THIS->contentsRect());
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    std::tuple<int32_t,int32_t,int32_t,int32_t> Handle_getContentsMargins(HandleRef _this) {
        int left, top, right, bottom;
        THIS->getContentsMargins(&left, &top, &right, &bottom);
        return std::tuple{ left, top, right, bottom };
    }

    SizeConstraint Handle_horizontalSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(THIS->horizontalSizeConstraint());
    }

    int32_t Handle_indexOf(HandleRef _this, LayoutItem::HandleRef layoutItem) {
        return THIS->indexOf(AS_QLAYOUTITEM_PTR(layoutItem));
    }

    int32_t Handle_indexOf(HandleRef _this, Widget::HandleRef widget) {
        return THIS->indexOf(AS_QWIDGET_PTR(widget));
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    LayoutItem::HandleRef Handle_itemAt(HandleRef _this, int32_t index) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS->itemAt(index));
    }

    Widget::HandleRef Handle_menuBar(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->menuBar());
    }

    Widget::HandleRef Handle_parentWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->parentWidget());
    }

    void Handle_removeItem(HandleRef _this, LayoutItem::HandleRef item) {
        THIS->removeItem(AS_QLAYOUTITEM_PTR(item));
    }

    void Handle_removeWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->removeWidget(AS_QWIDGET_PTR(widget));
    }

    LayoutItem::HandleRef Handle_replaceWidget(HandleRef _this, Widget::HandleRef from, Widget::HandleRef to, Flags<FindChildOptions> options_ /* FindChildOptions::FindChildrenRecursively */) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS->replaceWidget(AS_QWIDGET_PTR(from), AS_QWIDGET_PTR(to), static_cast<Qt::FindChildOptions>(options_.value())));
    }

    bool Handle_setAlignment(HandleRef _this, Widget::HandleRef widget, Flags<Alignment> alignment) {
        return THIS->setAlignment(AS_QWIDGET_PTR(widget), static_cast<Qt::Alignment>(alignment.value()));
    }

    bool Handle_setAlignment(HandleRef _this, HandleRef layout, Flags<Alignment> alignment) {
        return THIS->setAlignment(AS_QLAYOUT_PTR(layout), static_cast<Qt::Alignment>(alignment.value()));
    }

    void Handle_setContentsMargins(HandleRef _this, Margins::HandleRef margins) {
        THIS->setContentsMargins(QMARGINS_VALUE(margins));
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    void Handle_setHorizontalSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        THIS->setHorizontalSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    void Handle_setMenuBar(HandleRef _this, Widget::HandleRef widget) {
        THIS->setMenuBar(AS_QWIDGET_PTR(widget));
    }

    void Handle_setSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        THIS->setSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    void Handle_setVerticalSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        THIS->setVerticalSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    SizeConstraint Handle_getSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(THIS->sizeConstraint());
    }

    int32_t Handle_spacing(HandleRef _this) {
        return THIS->spacing();
    }

    LayoutItem::HandleRef Handle_takeAt(HandleRef _this, int32_t index) {
        return reinterpret_cast<LayoutItem::HandleRef>(THIS->takeAt(index));
    }

    void Handle_unsetContentsMargins(HandleRef _this) {
        THIS->unsetContentsMargins();
    }

    void Handle_update(HandleRef _this) {
        THIS->update();
    }

    SizeConstraint Handle_verticalSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(THIS->verticalSizeConstraint());
    }

    Size::OwnedRef closestAcceptableSize(Widget::HandleRef widget, Size::HandleRef size) {
        return SIZE_HEAP_NEW(QLayout::closestAcceptableSize(AS_QWIDGET_PTR(widget), QSIZE_VALUE(size)));
    }

    // ext methods block for: Widget::HandleRef ====
    HandleRef ext_Widget_layout(Widget::HandleRef this_) {
        return reinterpret_cast<HandleRef>(AS_QWIDGET_PTR(this_)->layout());
    }
    void ext_Widget_setLayout(Widget::HandleRef this_, HandleRef layout) {
        AS_QWIDGET_PTR(this_)->setLayout(AS_QLAYOUT_PTR(layout));
    }

    // ext methods block for: LayoutItem::HandleRef ====
    HandleRef ext_LayoutItem_layout(LayoutItem::HandleRef this_) {
        return reinterpret_cast<HandleRef>(AS_QLAYOUTITEM_PTR(this_)->layout());
    }
}
