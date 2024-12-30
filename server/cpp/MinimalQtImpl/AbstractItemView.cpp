#include "generated/AbstractItemView.h"

#include "AbstractItemDelegateInternal.h"
#include "AbstractItemModelInternal.h"
#include "AbstractItemViewInternal.h"
#include "ItemSelectionModelInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define ABSITEMVIEW_THIS (WRAPPER->getActual())

namespace AbstractItemView
{
    bool Handle_alternatingRowColors(HandleRef _this) {
        return ABSITEMVIEW_THIS->alternatingRowColors();
    }

    void Handle_setAlternatingRowColors(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setAlternatingRowColors(state);
    }

    bool Handle_hasAutoScroll(HandleRef _this) {
        return ABSITEMVIEW_THIS->hasAutoScroll();
    }

    void Handle_setAutoScroll(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setAutoScroll(state);
    }

    int32_t Handle_autoScrollMargin(HandleRef _this) {
        return ABSITEMVIEW_THIS->autoScrollMargin();
    }

    void Handle_setAutoScrollMargin(HandleRef _this, int32_t margin) {
        ABSITEMVIEW_THIS->setAutoScrollMargin(margin);
    }

    DropAction Handle_defaultDropAction(HandleRef _this) {
        return static_cast<DropAction>(ABSITEMVIEW_THIS->defaultDropAction());
    }

    void Handle_setDefaultDropAction(HandleRef _this, DropAction action) {
        ABSITEMVIEW_THIS->setDefaultDropAction(static_cast<Qt::DropAction>(action));
    }

    DragDropMode Handle_getDragDropMode(HandleRef _this) {
        return static_cast<DragDropMode>(ABSITEMVIEW_THIS->dragDropMode());
    }

    void Handle_setDragDropMode(HandleRef _this, DragDropMode mode) {
        ABSITEMVIEW_THIS->setDragDropMode(static_cast<QAbstractItemView::DragDropMode>(mode));
    }

    bool Handle_dragDropOverwriteMode(HandleRef _this) {
        return ABSITEMVIEW_THIS->dragDropOverwriteMode();
    }

    void Handle_setDragDropOverwriteMode(HandleRef _this, bool mode) {
        ABSITEMVIEW_THIS->setDragDropOverwriteMode(mode);
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return ABSITEMVIEW_THIS->dragEnabled();
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        ABSITEMVIEW_THIS->setDragEnabled(enabled);
    }

    EditTriggers Handle_getEditTriggers(HandleRef _this) {
        return ABSITEMVIEW_THIS->editTriggers();
    }

    void Handle_setEditTriggers(HandleRef _this, EditTriggers triggers) {
        ABSITEMVIEW_THIS->setEditTriggers(static_cast<QAbstractItemView::EditTriggers>(triggers));
    }

    ScrollMode Handle_horizontalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(ABSITEMVIEW_THIS->horizontalScrollMode());
    }

    void Handle_setHorizontalScrollMode(HandleRef _this, ScrollMode mode) {
        ABSITEMVIEW_THIS->setHorizontalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_resetHorizontalScrollMode(HandleRef _this) {
        ABSITEMVIEW_THIS->resetHorizontalScrollMode();
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(ABSITEMVIEW_THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        ABSITEMVIEW_THIS->setIconSize(toQSize(size));
    }

    SelectionBehavior Handle_getSelectionBehavior(HandleRef _this) {
        return static_cast<SelectionBehavior>(ABSITEMVIEW_THIS->selectionBehavior());
    }

    void Handle_setSelectionBehavior(HandleRef _this, SelectionBehavior behavior) {
        ABSITEMVIEW_THIS->setSelectionBehavior(static_cast<QAbstractItemView::SelectionBehavior>(behavior));
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(ABSITEMVIEW_THIS->selectionMode());
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        ABSITEMVIEW_THIS->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
    }

    bool Handle_showDropIndicator(HandleRef _this) {
        return ABSITEMVIEW_THIS->showDropIndicator();
    }

    void Handle_setDropIndicatorShown(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setDropIndicatorShown(state);
    }

    bool Handle_tabKeyNavigation(HandleRef _this) {
        return ABSITEMVIEW_THIS->tabKeyNavigation();
    }

    void Handle_setTabKeyNavigation(HandleRef _this, bool state) {
        ABSITEMVIEW_THIS->setTabKeyNavigation(state);
    }

    TextElideMode Handle_getTextElideMode(HandleRef _this) {
        return static_cast<TextElideMode>(ABSITEMVIEW_THIS->textElideMode());
    }

    void Handle_setTextElideMode(HandleRef _this, TextElideMode mode) {
        ABSITEMVIEW_THIS->setTextElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    ScrollMode Handle_verticalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(ABSITEMVIEW_THIS->verticalScrollMode());
    }

    void Handle_setVerticalScrollMode(HandleRef _this, ScrollMode mode) {
        ABSITEMVIEW_THIS->setVerticalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_resetVerticalScrollMode(HandleRef _this) {
        ABSITEMVIEW_THIS->resetVerticalScrollMode();
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        const auto modelWrapper = reinterpret_cast<AbstractItemModel::SignalWrapper*>(model);
        ABSITEMVIEW_THIS->setModel(modelWrapper->getActual());
    }

    ItemSelectionModel::HandleRef Handle_selectionModel(HandleRef _this, const std::function<CreateSelectionModelHandlerFunc>& createHandlerFunc) {
        if (const auto model = ABSITEMVIEW_THIS->selectionModel(); model != nullptr) {
            // check for existing wrapper (ie, did we originally create/supply the selectionModel?)
            if (const auto existing = wrapperForQObject(model); existing != nullptr) {
                return reinterpret_cast<ItemSelectionModel::HandleRef>(existing);
            }
            // else, need to create a new one
            const auto wrapper = new ItemSelectionModel::SignalWrapper(model, createHandlerFunc());
            return reinterpret_cast<ItemSelectionModel::HandleRef>(wrapper);
        }
        // else
        return nullptr;
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef itemDelegate) {
        const auto delegateWrapper = reinterpret_cast<AbstractItemDelegate::SignalWrapper*>(itemDelegate);
        ABSITEMVIEW_THIS->setItemDelegate(delegateWrapper->getActual());
    }

    void Handle_setItemDelegateForColumn(HandleRef _this, int32_t column, AbstractItemDelegate::HandleRef itemDelegate) {
        const auto delegateWrapper = reinterpret_cast<AbstractItemDelegate::SignalWrapper*>(itemDelegate);
        ABSITEMVIEW_THIS->setItemDelegateForColumn(column, delegateWrapper->getActual());
    }

    void Handle_setItemDelegateForRow(HandleRef _this, int32_t row, AbstractItemDelegate::HandleRef itemDelegate) {
        const auto delegateWrapper = reinterpret_cast<AbstractItemDelegate::SignalWrapper*>(itemDelegate);
        ABSITEMVIEW_THIS->setItemDelegateForRow(row, delegateWrapper->getActual());
    }
}
