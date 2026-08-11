#include "generated/BoxLayout.h"
#include "BoxLayoutInternal.h"

#include "LayoutItemInternal.h"
#include "LayoutInternal.h"
#include "WidgetInternal.h"

using namespace ::Widget;
using namespace ::Layout;
using namespace ::Enums;
using namespace ::Object;
using namespace ::LayoutItem;

#define THIS (reinterpret_cast<QBoxLayout*>(_this))

namespace BoxLayout
{
    void Handle_addLayout(HandleRef _this, Layout::HandleRef layout, int32_t stretch /* 0 */) {
        THIS->addLayout(AS_QLAYOUT_PTR(layout), stretch);
    }

    void Handle_addSpacing(HandleRef _this, int32_t size) {
        THIS->addSpacing(size);
    }

    void Handle_addStretch(HandleRef _this, int32_t stretch /* 0 */) {
        THIS->addStretch(stretch);
    }

    void Handle_addStrut(HandleRef _this, int32_t size) {
        THIS->addStrut(size);
    }

    void Handle_addWidget(HandleRef _this, Widget::HandleRef widget, int32_t stretch /* 0 */, Flags<Alignment> alignment /* 0 */) {
        THIS->addWidget(AS_QWIDGET_PTR(widget), stretch, static_cast<Qt::Alignment>(alignment.value()));
    }

    Direction Handle_getDirection(HandleRef _this) {
        return static_cast<Direction>(THIS->direction());
    }

    void Handle_insertItem(HandleRef _this, int32_t index, LayoutItem::HandleRef item) {
        THIS->insertItem(index, AS_QLAYOUTITEM_PTR(item));
    }

    void Handle_insertLayout(HandleRef _this, int32_t index, Layout::HandleRef layout, int32_t stretch /* 0 */) {
        THIS->insertLayout(index, AS_QLAYOUT_PTR(layout), stretch);
    }

    void Handle_insertSpacing(HandleRef _this, int32_t index, int32_t size) {
        THIS->insertSpacing(index, size);
    }

    void Handle_insertStretch(HandleRef _this, int32_t index, int32_t stretch /* 0 */) {
        THIS->insertStretch(index, stretch);
    }

    void Handle_insertWidget(HandleRef _this, int32_t index, Widget::HandleRef widget, int32_t stretch /* 0 */, Flags<Alignment> alignment /* 0 */) {
        THIS->insertWidget(index, AS_QWIDGET_PTR(widget), stretch, static_cast<Qt::Alignment>(alignment.value()));
    }

    void Handle_setDirection(HandleRef _this, Direction direction) {
        THIS->setDirection(static_cast<QBoxLayout::Direction>(direction));
    }

    void Handle_setStretch(HandleRef _this, int32_t index, int32_t stretch) {
        THIS->setStretch(index, stretch);
    }

    bool Handle_setStretchFactor(HandleRef _this, Widget::HandleRef widget, int32_t stretch) {
        return THIS->setStretchFactor(AS_QWIDGET_PTR(widget), stretch);
    }

    bool Handle_setStretchFactor(HandleRef _this, Layout::HandleRef layout, int32_t stretch) {
        return THIS->setStretchFactor(AS_QLAYOUT_PTR(layout), stretch);
    }

    int32_t Handle_stretch(HandleRef _this, int32_t index) {
        return THIS->stretch(index);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Direction dir, Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QBoxLayout(static_cast<QBoxLayout::Direction>(dir), AS_QWIDGET_PTR(parent)));
    }
}
