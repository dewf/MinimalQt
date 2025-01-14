#include "generated/AbstractItemView.h"
#include "AbstractItemViewInternal.h"

#include "ObjectInternal.h"
#include "AbstractItemDelegateInternal.h"
#include "AbstractItemModelInternal.h"
#include "ItemSelectionModelInternal.h"
#include "ModelIndexInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractItemView*>(_this))

namespace AbstractItemView
{
    bool Handle_alternatingRowColors(HandleRef _this) {
        return THIS->alternatingRowColors();
    }

    void Handle_setAlternatingRowColors(HandleRef _this, bool state) {
        THIS->setAlternatingRowColors(state);
    }

    bool Handle_hasAutoScroll(HandleRef _this) {
        return THIS->hasAutoScroll();
    }

    void Handle_setAutoScroll(HandleRef _this, bool state) {
        THIS->setAutoScroll(state);
    }

    int32_t Handle_autoScrollMargin(HandleRef _this) {
        return THIS->autoScrollMargin();
    }

    void Handle_setAutoScrollMargin(HandleRef _this, int32_t margin) {
        THIS->setAutoScrollMargin(margin);
    }

    DropAction Handle_defaultDropAction(HandleRef _this) {
        return static_cast<DropAction>(THIS->defaultDropAction());
    }

    void Handle_setDefaultDropAction(HandleRef _this, DropAction action) {
        THIS->setDefaultDropAction(static_cast<Qt::DropAction>(action));
    }

    DragDropMode Handle_getDragDropMode(HandleRef _this) {
        return static_cast<DragDropMode>(THIS->dragDropMode());
    }

    void Handle_setDragDropMode(HandleRef _this, DragDropMode mode) {
        THIS->setDragDropMode(static_cast<QAbstractItemView::DragDropMode>(mode));
    }

    bool Handle_dragDropOverwriteMode(HandleRef _this) {
        return THIS->dragDropOverwriteMode();
    }

    void Handle_setDragDropOverwriteMode(HandleRef _this, bool mode) {
        THIS->setDragDropOverwriteMode(mode);
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return THIS->dragEnabled();
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        THIS->setDragEnabled(enabled);
    }

    EditTriggers Handle_getEditTriggers(HandleRef _this) {
        return EditTriggers(THIS->editTriggers());
    }

    void Handle_setEditTriggers(HandleRef _this, EditTriggers triggers) {
        THIS->setEditTriggers(static_cast<QAbstractItemView::EditTriggers>(triggers.value));
    }

    ScrollMode Handle_horizontalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(THIS->horizontalScrollMode());
    }

    void Handle_setHorizontalScrollMode(HandleRef _this, ScrollMode mode) {
        THIS->setHorizontalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_resetHorizontalScrollMode(HandleRef _this) {
        THIS->resetHorizontalScrollMode();
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    SelectionBehavior Handle_getSelectionBehavior(HandleRef _this) {
        return static_cast<SelectionBehavior>(THIS->selectionBehavior());
    }

    void Handle_setSelectionBehavior(HandleRef _this, SelectionBehavior behavior) {
        THIS->setSelectionBehavior(static_cast<QAbstractItemView::SelectionBehavior>(behavior));
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(THIS->selectionMode());
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
    }

    bool Handle_showDropIndicator(HandleRef _this) {
        return THIS->showDropIndicator();
    }

    void Handle_setDropIndicatorShown(HandleRef _this, bool state) {
        THIS->setDropIndicatorShown(state);
    }

    bool Handle_tabKeyNavigation(HandleRef _this) {
        return THIS->tabKeyNavigation();
    }

    void Handle_setTabKeyNavigation(HandleRef _this, bool state) {
        THIS->setTabKeyNavigation(state);
    }

    TextElideMode Handle_getTextElideMode(HandleRef _this) {
        return static_cast<TextElideMode>(THIS->textElideMode());
    }

    void Handle_setTextElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setTextElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    ScrollMode Handle_verticalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(THIS->verticalScrollMode());
    }

    void Handle_setVerticalScrollMode(HandleRef _this, ScrollMode mode) {
        THIS->setVerticalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_resetVerticalScrollMode(HandleRef _this) {
        THIS->resetVerticalScrollMode();
    }

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
    }

    void Handle_clearSelection(HandleRef _this) {
        THIS->clearSelection();
    }

    void Handle_edit(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->edit(index->value);
    }

    void Handle_reset(HandleRef _this) {
        THIS->reset();
    }

    void Handle_scrollToBottom(HandleRef _this) {
        THIS->scrollToBottom();
    }

    void Handle_scrollToTop(HandleRef _this) {
        THIS->scrollToTop();
    }

    void Handle_selectAll(HandleRef _this) {
        THIS->selectAll();
    }

    void Handle_setCurrentIndex(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->setCurrentIndex(index->value);
    }

    void Handle_setRootIndex(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->setRootIndex(index->value);
    }

    void Handle_update(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->update(index->value);
    }

    ItemSelectionModel::HandleRef Handle_selectionModel(HandleRef _this) {
        return reinterpret_cast<ItemSelectionModel::HandleRef>(THIS->selectionModel());
    }

    void Handle_setItemDelegate(HandleRef _this, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegate(reinterpret_cast<QAbstractItemDelegate*>(itemDelegate));
    }

    void Handle_setItemDelegateForColumn(HandleRef _this, int32_t column, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegateForColumn(column, reinterpret_cast<QAbstractItemDelegate*>(itemDelegate));
    }

    void Handle_setItemDelegateForRow(HandleRef _this, int32_t row, AbstractItemDelegate::HandleRef itemDelegate) {
        THIS->setItemDelegateForRow(row, reinterpret_cast<QAbstractItemDelegate*>(itemDelegate));
    }

    SignalConnectionRef Handle_connect_Activated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::activated, [handler](const QModelIndex& index) {
            ModelIndex::__Handle index2(index);
            handler->activated(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::clicked, [handler](const QModelIndex& index) {
            ModelIndex::__Handle index2(index);
            handler->clicked(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::doubleClicked, [handler](const QModelIndex& index) {
            ModelIndex::__Handle index2(index);
            handler->doubleClicked(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Entered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::entered, [handler](const QModelIndex &index) {
            ModelIndex::__Handle index2(index);
            handler->entered(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_IconSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::iconSizeChanged, [handler](const QSize &size) {
            handler->iconSizeChanged(toSize(size));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Pressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::pressed, [handler](const QModelIndex &index) {
            ModelIndex::__Handle index2(index);
            handler->pressed(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ViewportEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::viewportEntered, [handler] {
            handler->viewportEntered();
        });
        return new __SignalConnection { connection };
    }
}
