#include "generated/AbstractItemView.h"
#include "AbstractItemViewInternal.h"

#include "ObjectInternal.h"
#include "AbstractItemDelegateInternal.h"
#include "AbstractItemModelInternal.h"
#include "ItemSelectionModelInternal.h"
#include "ModelIndexInternal.h"
#include "PointInternal.h"
#include "WidgetInternal.h"
#include "SizeInternal.h"
#include "RectInternal.h"

#include "EventInternal.h"
#include "StyleOptionViewItemInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Size;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Enums;
using namespace ::Icon;
using namespace ::AbstractScrollArea;
using namespace ::AbstractItemModel;
using namespace ::ModelIndex;
using namespace ::AbstractItemDelegate;
using namespace ::ItemSelectionModel;
using namespace ::Widget;
using namespace ::Event;
using namespace ::StyleOptionViewItem;

#define THIS (reinterpret_cast<QAbstractItemView*>(_this))

namespace AbstractItemView
{
    bool Handle_alternatingRowColors(HandleRef _this) {
        return THIS->alternatingRowColors();
    }

    int32_t Handle_autoScrollMargin(HandleRef _this) {
        return THIS->autoScrollMargin();
    }

    void Handle_closePersistentEditor(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->closePersistentEditor(QMODELINDEX_VALUE(index));
    }

    ModelIndex::OwnedRef Handle_currentIndex(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->currentIndex());
    }

    DropAction Handle_defaultDropAction(HandleRef _this) {
        return static_cast<DropAction>(THIS->defaultDropAction());
    }

    DragDropMode Handle_getDragDropMode(HandleRef _this) {
        return static_cast<DragDropMode>(THIS->dragDropMode());
    }

    bool Handle_dragDropOverwriteMode(HandleRef _this) {
        return THIS->dragDropOverwriteMode();
    }

    bool Handle_dragEnabled(HandleRef _this) {
        return THIS->dragEnabled();
    }

    Flags<EditTriggers> Handle_getEditTriggers(HandleRef _this) {
        return static_cast<Flags<EditTriggers>>(THIS->editTriggers());
    }

    bool Handle_hasAutoScroll(HandleRef _this) {
        return THIS->hasAutoScroll();
    }

    ScrollMode Handle_horizontalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(THIS->horizontalScrollMode());
    }

    Size::OwnedRef Handle_iconSize(HandleRef _this) {
        return SIZE_HEAP_NEW(THIS->iconSize());
    }

    ModelIndex::OwnedRef Handle_indexAt(HandleRef _this, Point::HandleRef point) {
        return MODELINDEX_HEAP_NEW(THIS->indexAt(QPOINT_VALUE(point)));
    }

    Widget::HandleRef Handle_indexWidget(HandleRef _this, ModelIndex::HandleRef index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->indexWidget(QMODELINDEX_VALUE(index)));
    }

    bool Handle_isPersistentEditorOpen(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->isPersistentEditorOpen(QMODELINDEX_VALUE(index));
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegate(HandleRef _this) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegate());
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegateForColumn(HandleRef _this, int32_t column) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegateForColumn(column));
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegateForIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegateForIndex(QMODELINDEX_VALUE(index)));
    }

    AbstractItemDelegate::HandleRef Handle_itemDelegateForRow(HandleRef _this, int32_t row) {
        return reinterpret_cast<AbstractItemDelegate::HandleRef>(THIS->itemDelegateForRow(row));
    }

    void Handle_keyboardSearch(HandleRef _this, const std::string& search) {
        THIS->keyboardSearch(QString::fromStdString(search));
    }

    AbstractItemModel::HandleRef Handle_model(HandleRef _this) {
        return reinterpret_cast<AbstractItemModel::HandleRef>(THIS->model());
    }

    void Handle_openPersistentEditor(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->openPersistentEditor(QMODELINDEX_VALUE(index));
    }

    void Handle_resetHorizontalScrollMode(HandleRef _this) {
        THIS->resetHorizontalScrollMode();
    }

    void Handle_resetVerticalScrollMode(HandleRef _this) {
        THIS->resetVerticalScrollMode();
    }

    ModelIndex::OwnedRef Handle_rootIndex(HandleRef _this) {
        return MODELINDEX_HEAP_NEW(THIS->rootIndex());
    }

    void Handle_scrollTo(HandleRef _this, ModelIndex::HandleRef index, ScrollHint hint /* ScrollHint::EnsureVisible */) {
        THIS->scrollTo(QMODELINDEX_VALUE(index), static_cast<QAbstractItemView::ScrollHint>(hint));
    }

    SelectionBehavior Handle_getSelectionBehavior(HandleRef _this) {
        return static_cast<SelectionBehavior>(THIS->selectionBehavior());
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(THIS->selectionMode());
    }

    ItemSelectionModel::HandleRef Handle_selectionModel(HandleRef _this) {
        return reinterpret_cast<ItemSelectionModel::HandleRef>(THIS->selectionModel());
    }

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

    void Handle_setDropIndicatorShown(HandleRef _this, bool state) {
        THIS->setDropIndicatorShown(state);
    }

    void Handle_setEditTriggers(HandleRef _this, Flags<EditTriggers> triggers) {
        THIS->setEditTriggers(static_cast<QAbstractItemView::EditTriggers>(triggers.value()));
    }

    void Handle_setHorizontalScrollMode(HandleRef _this, ScrollMode mode) {
        THIS->setHorizontalScrollMode(static_cast<QAbstractItemView::ScrollMode>(mode));
    }

    void Handle_setIconSize(HandleRef _this, Size::HandleRef size) {
        THIS->setIconSize(QSIZE_VALUE(size));
    }

    void Handle_setIndexWidget(HandleRef _this, ModelIndex::HandleRef index, Widget::HandleRef widget) {
        THIS->setIndexWidget(QMODELINDEX_VALUE(index), AS_QWIDGET_PTR(widget));
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

    void Handle_setModel(HandleRef _this, AbstractItemModel::HandleRef model) {
        THIS->setModel(reinterpret_cast<QAbstractItemModel*>(model));
    }

    void Handle_setSelectionBehavior(HandleRef _this, SelectionBehavior behavior) {
        THIS->setSelectionBehavior(static_cast<QAbstractItemView::SelectionBehavior>(behavior));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QAbstractItemView::SelectionMode>(mode));
    }

    void Handle_setSelectionModel(HandleRef _this, ItemSelectionModel::HandleRef selectionModel) {
        THIS->setSelectionModel(reinterpret_cast<QItemSelectionModel*>(selectionModel));
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

    bool Handle_showDropIndicator(HandleRef _this) {
        return THIS->showDropIndicator();
    }

    int32_t Handle_sizeHintForColumn(HandleRef _this, int32_t column) {
        return THIS->sizeHintForColumn(column);
    }

    Size::OwnedRef Handle_sizeHintForIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return SIZE_HEAP_NEW(THIS->sizeHintForIndex(QMODELINDEX_VALUE(index)));
    }

    int32_t Handle_sizeHintForRow(HandleRef _this, int32_t row) {
        return THIS->sizeHintForRow(row);
    }

    bool Handle_tabKeyNavigation(HandleRef _this) {
        return THIS->tabKeyNavigation();
    }

    TextElideMode Handle_textElideMode(HandleRef _this) {
        return static_cast<TextElideMode>(THIS->textElideMode());
    }

    ScrollMode Handle_verticalScrollMode(HandleRef _this) {
        return static_cast<ScrollMode>(THIS->verticalScrollMode());
    }

    Rect::OwnedRef Handle_visualRect(HandleRef _this, ModelIndex::HandleRef index) {
        return RECT_HEAP_NEW(THIS->visualRect(QMODELINDEX_VALUE(index)));
    }

    void Handle_clearSelection(HandleRef _this) {
        THIS->clearSelection();
    }

    void Handle_edit(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->edit(QMODELINDEX_VALUE(index));
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
        THIS->setCurrentIndex(QMODELINDEX_VALUE(index));
    }

    void Handle_setRootIndex(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->setRootIndex(QMODELINDEX_VALUE(index));
    }

    void Handle_update(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->update(QMODELINDEX_VALUE(index));
    }

    SignalConnectionRef Handle_connect_Activated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::activated, [handler](const QModelIndex& index) {
            QModelIndex index2(index);
            handler->activated(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::clicked, [handler](const QModelIndex& index) {
            QModelIndex index2(index);
            handler->clicked(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::doubleClicked, [handler](const QModelIndex& index) {
            QModelIndex index2(index);
            handler->doubleClicked(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Entered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::entered, [handler](const QModelIndex &index) {
            QModelIndex index2(index);
            handler->entered(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_IconSizeChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::iconSizeChanged, [handler](const QSize &size) {
            QSize size2(size);
            handler->iconSizeChanged(reinterpret_cast<Size::HandleRef>(&size2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Pressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::pressed, [handler](const QModelIndex &index) {
            QModelIndex index2(index);
            handler->pressed(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ViewportEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemView::viewportEntered, [handler] {
            handler->viewportEntered();
        });
        return new __SignalConnection { connection };
    }

    // ext methods block for: AbstractItemDelegate::HandleRef ====
    bool ext__AbstractItemDelegate_Handle_helpEvent(AbstractItemDelegate::HandleRef _this, HelpEventRef event_, HandleRef view, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return AS_QABSTRACTITEMDELEGATE_PTR(_this)->helpEvent(
            AS_QHELPEVENT_PTR(event_),
            AS_QABSTRACTITEMVIEW_PTR(view),
            QSTYLEOPTIONVIEWITEM_VALUE(option),
            QMODELINDEX_VALUE(index));
    }
    // ==============================
}
