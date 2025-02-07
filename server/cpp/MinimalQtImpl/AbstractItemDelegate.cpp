#include "generated/AbstractItemDelegate.h"
#include "AbstractItemDelegateInternal.h"

#include "EventInternal.h"
#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "PainterInternal.h"
#include "SizeInternal.h"
#include "StyleOptionViewItemInternal.h"
#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Common;
using namespace ::Size;
using namespace ::ModelIndex;
using namespace ::StyleOptionViewItem;
using namespace ::Event;
using namespace ::AbstractItemModel;
using namespace ::Painter;

#include "util/convert.h"

#define THIS (reinterpret_cast<QAbstractItemDelegate*>(_this))

namespace AbstractItemDelegate
{
    Widget::HandleRef Handle_createEditor(HandleRef _this, Widget::HandleRef parent, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->createEditor(AS_QWIDGET_PTR(parent), QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index)));
    }

    void Handle_destroyEditor(HandleRef _this, Widget::HandleRef editor, ModelIndex::HandleRef index) {
        THIS->destroyEditor(AS_QWIDGET_PTR(editor), QMODELINDEX_VALUE(index));
    }

    bool Handle_editorEvent(HandleRef _this, Event::HandleRef event_, AbstractItemModel::HandleRef model, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return THIS->editorEvent(reinterpret_cast<QEvent*>(event_), reinterpret_cast<QAbstractItemModel*>(model), QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index));
    }

    bool Handle_helpEvent(HandleRef _this, HelpEventRef event_, AbstractItemViewHandleRef view, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return THIS->helpEvent(reinterpret_cast<QHelpEvent*>(event_), reinterpret_cast<QAbstractItemView*>(view), QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index));
    }

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        THIS->paint(AS_QPAINTER_PTR(painter), QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index));
    }

    void Handle_setEditorData(HandleRef _this, Widget::HandleRef editor, ModelIndex::HandleRef index) {
        THIS->setEditorData(AS_QWIDGET_PTR(editor), QMODELINDEX_VALUE(index));
    }

    void Handle_setModelData(HandleRef _this, Widget::HandleRef editor, AbstractItemModel::HandleRef model, ModelIndex::HandleRef index) {
        THIS->setModelData(AS_QWIDGET_PTR(editor), reinterpret_cast<QAbstractItemModel*>(model), QMODELINDEX_VALUE(index));
    }

    Size::OwnedRef Handle_sizeHint(HandleRef _this, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        return SIZE_HEAP_NEW(THIS->sizeHint(QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index)));
    }

    void Handle_updateEditorGeometry(HandleRef _this, Widget::HandleRef editor, StyleOptionViewItem::HandleRef option, ModelIndex::HandleRef index) {
        THIS->updateEditorGeometry(AS_QWIDGET_PTR(editor), QSTYLEOPTIONVIEWITEM_VALUE(option), QMODELINDEX_VALUE(index));
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
            QModelIndex index2(index); // until we fix this with proxies or whatever we decide ...
            handler->sizeHintChanged(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }
}
