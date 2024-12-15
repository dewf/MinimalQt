#include "generated/AbstractItemView.h"

#include <QAbstractItemView>
#include "util/convert.h"

#define THIS ((QAbstractItemView*)_this)

namespace AbstractItemView
{
    void Handle_setAlternatingRowColors(HandleRef _this, bool state) {
        THIS->setAlternatingRowColors(state);
    }

    void Handle_setAutoScroll(HandleRef _this, bool state) {
        THIS->setAutoScroll(state);
    }

    void Handle_setAutoScrollMargin(HandleRef _this, int32_t margin) {
        THIS->setAutoScrollMargin(margin);
    }

    void Handle_setDefaultDropAction(HandleRef _this, DropAction action) {
        THIS->setDefaultDropAction(static_cast<Qt::DropAction>(action));
    }

    void Handle_setDragDropMode(HandleRef _this, DragDropMode mode) {
        THIS->setDragDropMode(static_cast<QAbstractItemView::DragDropMode>(mode));
    }

    void Handle_setDragDropOverwriteMode(HandleRef _this, bool mode) {
        THIS->setDragDropOverwriteMode(mode);
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        THIS->setDragEnabled(enabled);
    }

    void Handle_setEditTriggers(HandleRef _this, EditTriggers triggers) {
        THIS->setEditTriggers(static_cast<QAbstractItemView::EditTriggers>(triggers));
    }

    void Handle_setHorizontalScrollMode(HandleRef _this, ScrollMode mode) {
        THIS->setHorizontalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setSelectionBehavior(HandleRef _this, SelectionBehavior behavior) {
        THIS->setSelectionBehavior(static_cast<QAbstractItemView::SelectionBehavior>(behavior));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
    }

    void Handle_setDropIndicatorShown(HandleRef _this, bool state) {
        THIS->setDropIndicatorShown(state);
    }

    void Handle_setTabKeyNavigation(HandleRef _this, bool state) {
        THIS->setTabKeyNavigation(state);
    }

    void Handle_setTextElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setTextElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setVerticalScrollMode(HandleRef _this, ScrollMode mode) {
        THIS->setVerticalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel *>(model));
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegate(reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }

    void Handle_setItemDelegateForColumn(HandleRef _this, int32_t column, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegateForColumn(column, reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }

    void Handle_setItemDelegateForRow(HandleRef _this, int32_t row, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegateForRow(row, reinterpret_cast<QAbstractItemDelegate *>(itemDelegate));
    }
}
