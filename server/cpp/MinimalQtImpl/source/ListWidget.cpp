#include "generated/ListWidget.h"
#include "ListWidgetInternal.h"

#include "ObjectInternal.h"
#include "IconInternal.h"
#include "ItemSelectionModelInternal.h"
#include "ListWidgetItemInternal.h"
#include "MimeDataInternal.h"
#include "ModelIndexInternal.h"
#include "PointInternal.h"
#include "RectInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::ListView;
using namespace ::ListWidgetItem;
using namespace ::Enums;
using namespace ::ModelIndex;
using namespace ::MimeData;
using namespace ::ItemSelectionModel;
using namespace ::AbstractItemView;
using namespace ::Point;
using namespace ::Rect;
using namespace ::Icon;

namespace ListWidget
{
#define THIS (AS_QLISTWIDGET_PTR(_this))

    void Handle_addItem(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->addItem(AS_QLISTWIDGETITEM_PTR(item));
    }

    void Handle_addItem(HandleRef _this, const std::string& label) {
        THIS->addItem(QString::fromStdString(label));
    }

    void Handle_addItems(HandleRef _this, const std::vector<std::string>& labels) {
        THIS->addItems(toQStringList(labels));
    }

    void Handle_closePersistentEditor(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->closePersistentEditor(AS_QLISTWIDGETITEM_PTR(item));
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    ListWidgetItem::HandleRef Handle_currentItem(HandleRef _this) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->currentItem());
    }

    int32_t Handle_currentRow(HandleRef _this) {
        return THIS->currentRow();
    }

    void Handle_editItem(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->editItem(AS_QLISTWIDGETITEM_PTR(item));
    }

    std::vector<ListWidgetItem::HandleRef> Handle_findItems(HandleRef _this, const std::string& text, Flags<MatchFlags> flags_) {
        auto items = THIS->findItems(QString::fromStdString(text), Qt::MatchFlags::fromInt(flags_.value()));
        return fromQList<QListWidgetItem*,ListWidgetItem::HandleRef>(items, [](auto item){
            return reinterpret_cast<ListWidgetItem::HandleRef>(item);
        });
    }

    ModelIndex::OwnedRef Handle_indexFromItem(HandleRef _this, ListWidgetItem::HandleRef item) {
        return MODELINDEX_HEAP_NEW(THIS->indexFromItem(AS_QLISTWIDGETITEM_PTR(item)));
    }

    void Handle_insertItem(HandleRef _this, int32_t row, ListWidgetItem::HandleRef item) {
        THIS->insertItem(row, AS_QLISTWIDGETITEM_PTR(item));
    }

    void Handle_insertItem(HandleRef _this, int32_t row, const std::string& label) {
        THIS->insertItem(row, QString::fromStdString(label));
    }

    void Handle_insertItems(HandleRef _this, int32_t row, const std::vector<std::string>& labels) {
        THIS->insertItems(row, toQStringList(labels));
    }

    bool Handle_isPersistentEditorOpen(HandleRef _this, ListWidgetItem::HandleRef item) {
        return THIS->isPersistentEditorOpen(AS_QLISTWIDGETITEM_PTR(item));
    }

    bool Handle_isSortingEnabled(HandleRef _this) {
        return THIS->isSortingEnabled();
    }

    ListWidgetItem::HandleRef Handle_item(HandleRef _this, int32_t row) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->item(row));
    }

    ListWidgetItem::HandleRef Handle_itemAt(HandleRef _this, Point::HandleRef p) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->itemAt(QPOINT_VALUE(p)));
    }

    ListWidgetItem::HandleRef Handle_itemAt(HandleRef _this, int32_t x, int32_t y) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->itemAt(x, y));
    }

    ListWidgetItem::HandleRef Handle_itemFromIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->itemFromIndex(QMODELINDEX_VALUE(index)));
    }

    Widget::HandleRef Handle_itemWidget(HandleRef _this, ListWidgetItem::HandleRef item) {
        return reinterpret_cast<Widget::HandleRef>(THIS->itemWidget(AS_QLISTWIDGETITEM_PTR(item)));
    }

    std::vector<ListWidgetItem::HandleRef> Handle_items(HandleRef _this, MimeData::HandleRef data) {
        auto items = THIS->items(AS_QMIMEDATA_PTR(data));
        return fromQList<QListWidgetItem*,ListWidgetItem::HandleRef>(items, [](auto item){
            return reinterpret_cast<ListWidgetItem::HandleRef>(item);
        });
    }

    void Handle_openPersistentEditor(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->openPersistentEditor(AS_QLISTWIDGETITEM_PTR(item));
    }

    void Handle_removeItemWidget(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->removeItemWidget(AS_QLISTWIDGETITEM_PTR(item));
    }

    int32_t Handle_row(HandleRef _this, ListWidgetItem::HandleRef item) {
        return THIS->row(AS_QLISTWIDGETITEM_PTR(item));
    }

    std::vector<ListWidgetItem::HandleRef> Handle_selectedItems(HandleRef _this) {
        auto items = THIS->selectedItems();
        return fromQList<QListWidgetItem*,ListWidgetItem::HandleRef>(items, [](auto item){
            return reinterpret_cast<ListWidgetItem::HandleRef>(item);
        });
    }

    void Handle_setCurrentItem(HandleRef _this, ListWidgetItem::HandleRef item) {
        THIS->setCurrentItem(AS_QLISTWIDGETITEM_PTR(item));
    }

    void Handle_setCurrentItem(HandleRef _this, ListWidgetItem::HandleRef item, Flags<SelectionFlags> command) {
        THIS->setCurrentItem(AS_QLISTWIDGETITEM_PTR(item), QItemSelectionModel::SelectionFlags::fromInt(command.value()));
    }

    void Handle_setCurrentRow(HandleRef _this, int32_t row) {
        THIS->setCurrentRow(row);
    }

    void Handle_setCurrentRow(HandleRef _this, int32_t row, Flags<SelectionFlags> command) {
        THIS->setCurrentRow(row, QItemSelectionModel::SelectionFlags::fromInt(command.value()));
    }

    void Handle_setItemWidget(HandleRef _this, ListWidgetItem::HandleRef item, Widget::HandleRef widget) {
        THIS->setItemWidget(AS_QLISTWIDGETITEM_PTR(item), AS_QWIDGET_PTR(widget));
    }

    void Handle_setSortingEnabled(HandleRef _this, bool enable) {
        THIS->setSortingEnabled(enable);
    }

    void Handle_setSupportedDragActions(HandleRef _this, Flags<DropActions> actions) {
        THIS->setSupportedDragActions(Qt::DropActions::fromInt(actions.value()));
    }

    void Handle_sortItems(HandleRef _this, SortOrder order /* SortOrder::AscendingOrder */) {
        THIS->sortItems(static_cast<Qt::SortOrder>(order));
    }

    Flags<DropActions> Handle_supportedDragActions(HandleRef _this) {
        return Flags<DropActions>(THIS->supportedDragActions());
    }

    ListWidgetItem::HandleRef Handle_takeItem(HandleRef _this, int32_t row) {
        return reinterpret_cast<ListWidgetItem::HandleRef>(THIS->takeItem(row));
    }

    Rect::OwnedRef Handle_visualItemRect(HandleRef _this, ListWidgetItem::HandleRef item) {
        return RECT_HEAP_NEW(THIS->visualItemRect(AS_QLISTWIDGETITEM_PTR(item)));
    }

    void Handle_setSelectionModel(HandleRef _this, ItemSelectionModel::HandleRef selectionModel) {
        THIS->setSelectionModel(AS_QITEMSELECTIONMODEL_PTR(selectionModel));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_scrollToItem(HandleRef _this, ListWidgetItem::HandleRef item, ScrollHint hint /* ScrollHint::EnsureVisible */) {
        THIS->scrollToItem(AS_QLISTWIDGETITEM_PTR(item), static_cast<QAbstractItemView::ScrollHint>(hint));
    }

    SignalConnectionRef Handle_connect_CurrentItemChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::currentItemChanged, [handler](QListWidgetItem *current, QListWidgetItem *previous) {
            handler->sig_currentItemChanged(reinterpret_cast<ListWidgetItem::HandleRef>(current), reinterpret_cast<ListWidgetItem::HandleRef>(previous));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentRowChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::currentRowChanged, [handler](int currentRow) {
            handler->sig_currentRowChanged(currentRow);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentTextChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::currentTextChanged, [handler](const QString &currentText) {
            handler->sig_currentTextChanged(currentText.toStdString());
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemActivated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemActivated, [handler](QListWidgetItem *item) {
            handler->sig_itemActivated(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemChanged, [handler](QListWidgetItem *item) {
            handler->sig_itemChanged(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemClicked, [handler](QListWidgetItem *item) {
            handler->sig_itemClicked(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemDoubleClicked, [handler](QListWidgetItem *item) {
            handler->sig_itemDoubleClicked(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemEntered(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemEntered, [handler](QListWidgetItem *item) {
            handler->sig_itemEntered(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemPressed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemPressed, [handler](QListWidgetItem *item) {
            handler->sig_itemPressed(reinterpret_cast<ListWidgetItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ItemSelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QListWidget::itemSelectionChanged, [handler] {
            handler->sig_itemSelectionChanged();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto listWidget = AS_QLISTWIDGET_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(listWidget);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(listWidget);
        case Handle_CastTarget::Frame_Handle:
            return static_cast<QFrame*>(listWidget);
        case Handle_CastTarget::AbstractScrollArea_Handle:
            return static_cast<QAbstractScrollArea*>(listWidget);
        case Handle_CastTarget::AbstractItemView_Handle:
            return static_cast<QAbstractItemView*>(listWidget);
        case Handle_CastTarget::ListView_Handle:
            return static_cast<QListView*>(listWidget);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QListWidget(AS_QWIDGET_PTR(parent)));
    }

    // QListWidget item circular ctors + extension methods ============================================================

    ListWidgetItem::HandleRef ctor_ListWidgetItem(HandleRef parent /* nullptr */, int32_t type /* static_cast<int32_t>(ItemType::Type) */) {
        auto item = new QListWidgetItem(AS_QLISTWIDGET_PTR(parent), type);
        return reinterpret_cast<ListWidgetItem::HandleRef>(item);
    }
    ListWidgetItem::HandleRef ctor_ListWidgetItem(const std::string& text, HandleRef parent /* nullptr */, int32_t type /* static_cast<int32_t>(ItemType::Type) */) {
        auto item = new QListWidgetItem(QString::fromStdString(text), AS_QLISTWIDGET_PTR(parent), type);
        return reinterpret_cast<ListWidgetItem::HandleRef>(item);
    }
    ListWidgetItem::HandleRef ctor_ListWidgetItem(Icon::HandleRef icon, const std::string& text, HandleRef parent /* nullptr */, int32_t type /* static_cast<int32_t>(ItemType::Type) */) {
        auto item = new QListWidgetItem(QICON_VALUE(icon), QString::fromStdString(text), AS_QLISTWIDGET_PTR(parent), type);
        return reinterpret_cast<ListWidgetItem::HandleRef>(item);
    }

    HandleRef ext_ListWidgetItem_listWidget(ListWidgetItem::HandleRef this_) {
        return reinterpret_cast<HandleRef>(AS_QLISTWIDGETITEM_PTR(this_)->listWidget());
    }
}
