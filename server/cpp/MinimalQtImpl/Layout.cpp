#include "generated/Layout.h"
#include "LayoutInternal.h"

#include "WidgetInternal.h"

#define THIS (reinterpret_cast<QLayout*>(_this))

namespace Layout
{
    // void Handle_removeAll(HandleRef _this) {
    //     QLayoutItem *item;
    //     while ((item = LAYOUT_THIS->takeAt(0)) != nullptr) {
    //         item->widget()->setParent(nullptr);
    //         delete item;
    //     }
    // }

    SizeConstraint Handle_getSizeConstraint(HandleRef _this) {
        return static_cast<SizeConstraint>(THIS->sizeConstraint());
    }

    void Handle_setSizeConstraint(HandleRef _this, SizeConstraint constraint) {
        THIS->setSizeConstraint(static_cast<QLayout::SizeConstraint>(constraint));
    }

    int32_t Handle_spacing(HandleRef _this) {
        return THIS->spacing();
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    bool Handle_isEnabled(HandleRef _this) {
        return THIS->isEnabled();
    }

    void Handle_setEnabled(HandleRef _this, bool enabled) {
        THIS->setEnabled(enabled);
    }

    bool Handle_activate(HandleRef _this) {
        return THIS->activate();
    }

    void Handle_addWidget(HandleRef _this, WidgetHandleRef widget) {
        THIS->addWidget(AS_QWIDGET_PTR(widget));
    }

    Margins Handle_contentsMargins(HandleRef _this) {
        int left, top, right, bottom;
        THIS->getContentsMargins(&left, &top, &right, &bottom);
        return Margins { left, top, right, bottom };
    }

    Rect Handle_contentsRect(HandleRef _this) {
        return toRect(THIS->contentsRect());
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    int32_t Handle_indexOf(HandleRef _this, WidgetHandleRef widget) {
        return THIS->indexOf(AS_QWIDGET_PTR(widget));
    }

    WidgetHandleRef Handle_menuBar(HandleRef _this) {
        return reinterpret_cast<WidgetHandleRef>(THIS->menuBar());
    }

    WidgetHandleRef Handle_parentWidget(HandleRef _this) {
        return reinterpret_cast<WidgetHandleRef>(THIS->parentWidget());
    }

    void Handle_removeWidget(HandleRef _this, WidgetHandleRef widget) {
        THIS->removeWidget(AS_QWIDGET_PTR(widget));
    }

    void Handle_setAlignment(HandleRef _this, WidgetHandleRef widget, Alignment alignment) {
        THIS->setAlignment(AS_QWIDGET_PTR(widget), static_cast<Qt::Alignment>(alignment));
    }

    void Handle_setAlignment(HandleRef _this, HandleRef layout, Alignment alignment) {
        THIS->setAlignment(AS_QLAYOUT_PTR(layout), static_cast<Qt::Alignment>(alignment));
    }

    void Handle_setContentsMargins(HandleRef _this, Margins margins) {
        THIS->setContentsMargins(toQMargins(margins));
    }

    void Handle_setContentsMargins(HandleRef _this, int32_t left, int32_t top, int32_t right, int32_t bottom) {
        THIS->setContentsMargins(left, top, right, bottom);
    }

    void Handle_setMenuBar(HandleRef _this, WidgetHandleRef widget) {
        THIS->setMenuBar(AS_QWIDGET_PTR(widget));
    }

    void Handle_unsetContentsMargins(HandleRef _this) {
        THIS->unsetContentsMargins();
    }

    void Handle_update(HandleRef _this) {
        THIS->update();
    }
}

