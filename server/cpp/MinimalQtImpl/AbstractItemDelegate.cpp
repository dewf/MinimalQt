#include "generated/AbstractItemDelegate.h"
#include "AbstractItemDelegateInternal.h"

#include "EventInternal.h"
#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "PainterInternal.h"
#include "StyleOptionViewItemInternal.h"
#include "WidgetInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractItemDelegate*>(_this))

namespace AbstractItemDelegate
{
    Widget::HandleRef Handle_createEditor(HandleRef _this, Widget::HandleRef parent, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->createEditor(AS_QWIDGET_PTR(parent), QSTYLEOPTIONVIEWITEM_VALUE(option), index->value));
    }

    void Handle_destroyEditor(HandleRef _this, Widget::HandleRef editor, ModelIndex::HandleRef index) {
        THIS->destroyEditor(AS_QWIDGET_PTR(editor), index->value);
    }

    bool Handle_editorEvent(HandleRef _this, Event::HandleRef event_, AbstractItemModel::HandleRef model, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return THIS->editorEvent(AS_QEVENT_PTR(event_), reinterpret_cast<QAbstractItemModel*>(model), QSTYLEOPTIONVIEWITEM_VALUE(option), index->value);
    }

    bool Handle_helpEvent(HandleRef _this, HelpEvent_HandleRef event_, AbstractItemViewHandleRef view, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return THIS->helpEvent(AS_QHELPEVENT_PTR(event_), reinterpret_cast<QAbstractItemView*>(view), QSTYLEOPTIONVIEWITEM_VALUE(option), index->value);
    }

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        THIS->paint(AS_QPAINTER_PTR(painter), QSTYLEOPTIONVIEWITEM_VALUE(option), index->value);
    }

    void Handle_setEditorData(HandleRef _this, Widget::HandleRef editor, ModelIndex::HandleRef index) {
        THIS->setEditorData(AS_QWIDGET_PTR(editor), index->value);
    }

    void Handle_setModelData(HandleRef _this, Widget::HandleRef editor, AbstractItemModel::HandleRef model, ModelIndex::HandleRef index) {
        THIS->setModelData(AS_QWIDGET_PTR(editor), reinterpret_cast<QAbstractItemModel*>(model), index->value);
    }

    Size Handle_sizeHint(HandleRef _this, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return toSize(THIS->sizeHint(QSTYLEOPTIONVIEWITEM_VALUE(option), index->value));
    }

    void Handle_updateEditorGeometry(HandleRef _this, Widget::HandleRef editor, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        THIS->updateEditorGeometry(AS_QWIDGET_PTR(editor), QSTYLEOPTIONVIEWITEM_VALUE(option), index->value);
    }

    SignalConnectionRef Handle_connect_CloseEditor(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::closeEditor, [handler](QWidget *editor, QAbstractItemDelegate::EndEditHint hint) {
            handler->closeEditor(reinterpret_cast<Widget::HandleRef>(editor), static_cast<AbstractItemDelegate::EndEditHint>(hint));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CommitData(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::commitData, [handler](QWidget *editor) {
            handler->commitData(reinterpret_cast<Widget::HandleRef>(editor));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SizeHintChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QAbstractItemDelegate::sizeHintChanged, [handler](const QModelIndex &index) {
            ModelIndex::__Handle index2(index); // until we fix this with proxies or whatever we decide ...
            handler->sizeHintChanged(&index2);
        });
        return new __SignalConnection { connection };
    }
}
