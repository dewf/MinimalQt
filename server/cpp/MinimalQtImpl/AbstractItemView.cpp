#include "generated/AbstractItemView.h"
#include "AbstractItemViewInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSITEMVIEW_THIS (WRAPPER->getActual())

namespace AbstractItemView
{
    void Handle_setAlternatingRowColors(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setAlternatingRowColors(state);
    }

    void Handle_setAutoScroll(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setAutoScroll(state);
    }

    void Handle_setAutoScrollMargin(HandleRef _this, int32_t margin) {
        ABSITEMVIEW_THIS->setAutoScrollMargin(margin);
    }

    void Handle_setDefaultDropAction(HandleRef _this, DropAction action) {
        ABSITEMVIEW_THIS->setDefaultDropAction(static_cast<Qt::DropAction>(action));
    }

    void Handle_setDragDropMode(HandleRef _this, DragDropMode mode) {
        ABSITEMVIEW_THIS->setDragDropMode(static_cast<QAbstractItemView::DragDropMode>(mode));
    }

    void Handle_setDragDropOverwriteMode(HandleRef _this, bool mode) {
        ABSITEMVIEW_THIS->setDragDropOverwriteMode(mode);
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        ABSITEMVIEW_THIS->setDragEnabled(enabled);
    }

    void Handle_setEditTriggers(HandleRef _this, EditTriggers triggers) {
        ABSITEMVIEW_THIS->setEditTriggers(static_cast<QAbstractItemView::EditTriggers>(triggers));
    }

    void Handle_setHorizontalScrollMode(HandleRef _this, ScrollMode mode) {
        ABSITEMVIEW_THIS->setHorizontalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        ABSITEMVIEW_THIS->setIconSize(toQSize(size));
    }

    void Handle_setSelectionBehavior(HandleRef _this, SelectionBehavior behavior) {
        ABSITEMVIEW_THIS->setSelectionBehavior(static_cast<QAbstractItemView::SelectionBehavior>(behavior));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        ABSITEMVIEW_THIS->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
    }

    void Handle_setDropIndicatorShown(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setDropIndicatorShown(state);
    }

    void Handle_setTabKeyNavigation(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setTabKeyNavigation(state);
    }

    void Handle_setTextElideMode(HandleRef _this, TextElideMode mode) {
        ABSITEMVIEW_THIS->setTextElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setVerticalScrollMode(HandleRef _this, ScrollMode mode) {
        ABSITEMVIEW_THIS->setVerticalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        ABSITEMVIEW_THIS->setModel(reinterpret_cast<QAbstractItemModel *>(model));
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef itemDelegate) {
        ABSITEMVIEW_THIS->setItemDelegate(reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }

    void Handle_setItemDelegateForColumn(HandleRef _this, int32_t column, AbstractItemDelegate::HandleRef itemDelegate) {
        ABSITEMVIEW_THIS->setItemDelegateForColumn(column, reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }

    void Handle_setItemDelegateForRow(HandleRef _this, int32_t row, AbstractItemDelegate::HandleRef itemDelegate) {
        ABSITEMVIEW_THIS->setItemDelegateForRow(row, reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }
}
