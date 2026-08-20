#include "generated/AbstractScrollArea.h"
#include "AbstractScrollAreaInternal.h"

#include "WidgetInternal.h"
#include "SizeInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::Icon;
using namespace ::Frame;
using namespace ::Enums;
using namespace ::ScrollBar;
using namespace ::Widget;

#define THIS (reinterpret_cast<QAbstractScrollArea*>(_this))

namespace AbstractScrollArea
{
    void Handle_addScrollBarWidget(HandleRef _this, Widget::HandleRef widget, Flags<Alignment> alignment) {
        THIS->addScrollBarWidget(AS_QWIDGET_PTR(widget), static_cast<Qt::Alignment>(alignment.value()));
    }

    Widget::HandleRef Handle_cornerWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->cornerWidget());
    }

    ScrollBar::HandleRef Handle_horizontalScrollBar(HandleRef _this) {
        return reinterpret_cast<ScrollBar::HandleRef>(THIS->horizontalScrollBar());
    }

    ScrollBarPolicy Handle_horizontalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(THIS->horizontalScrollBarPolicy());
    }

    Size::OwnedRef Handle_maximumViewportSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->maximumViewportSize());
    }

    std::vector<Widget::HandleRef> Handle_scrollBarWidgets(HandleRef _this, Flags<Alignment> alignment) {
        const auto qList = THIS->scrollBarWidgets(static_cast<Qt::Alignment>(alignment.value()));
        return fromQList<QWidget*,Widget::HandleRef>(qList, [](auto w) { return reinterpret_cast<Widget::HandleRef>(w); });
    }

    void Handle_setCornerWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setCornerWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setHorizontalScrollBar(HandleRef _this, ScrollBar::HandleRef scrollBar) {
        THIS->setHorizontalScrollBar(reinterpret_cast<QScrollBar*>(scrollBar));
    }

    void Handle_setHorizontalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setHorizontalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }

    void Handle_setSizeAdjustPolicy(HandleRef _this, SizeAdjustPolicy policy) {
        THIS->setSizeAdjustPolicy(static_cast<QAbstractScrollArea::SizeAdjustPolicy>(policy));
    }

    void Handle_setVerticalScrollBar(HandleRef _this, ScrollBar::HandleRef scrollBar) {
        THIS->setVerticalScrollBar(reinterpret_cast<QScrollBar*>(scrollBar));
    }

    void Handle_setVerticalScrollBarPolicy(HandleRef _this, ScrollBarPolicy policy) {
        THIS->setVerticalScrollBarPolicy(static_cast<Qt::ScrollBarPolicy>(policy));
    }

    void Handle_setViewport(HandleRef _this, Widget::HandleRef widget) {
        THIS->setViewport(AS_QWIDGET_PTR(widget));
    }

    void Handle_setupViewport(HandleRef _this, Widget::HandleRef viewport) {
        THIS->setupViewport(AS_QWIDGET_PTR(viewport));
    }

    SizeAdjustPolicy Handle_getSizeAdjustPolicy(HandleRef _this) {
        return static_cast<SizeAdjustPolicy>(THIS->sizeAdjustPolicy());
    }

    ScrollBar::HandleRef Handle_verticalScrollBar(HandleRef _this) {
        return reinterpret_cast<ScrollBar::HandleRef>(THIS->verticalScrollBar());
    }

    ScrollBarPolicy Handle_verticalScrollBarPolicy(HandleRef _this) {
        return static_cast<ScrollBarPolicy>(THIS->verticalScrollBarPolicy());
    }

    Widget::HandleRef Handle_viewport(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->viewport());
    }
}
