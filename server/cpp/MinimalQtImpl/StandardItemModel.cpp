#include "generated/StandardItemModel.h"
#include "StandardItemModelInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "StandardItemInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QStandardItemModel*>(_this))
#define AS_ITEM(x) (reinterpret_cast<QStandardItem*>(x))

namespace StandardItemModel
{
    int32_t Handle_sortRole(HandleRef _this) {
        return THIS->sortRole();
    }

    void Handle_setSortRole(HandleRef _this, int32_t role) {
        THIS->setSortRole(role);
    }

    void Handle_appendColumn(HandleRef _this, const std::vector<StandardItem::HandleRef>& items) {
        THIS->appendColumn(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, const std::vector<StandardItem::HandleRef>& items) {
        THIS->appendRow(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, StandardItem::HandleRef item) {
        THIS->appendRow(AS_ITEM(item));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    std::vector<StandardItem::HandleRef> Handle_findItems(HandleRef _this, const std::string& text, const Handle::FindItemsArgs& args) {
        const auto qMatchFlags = static_cast<Qt::MatchFlags>(args.getOrDefaultFlags_(MatchExactly));
        const auto column = args.getOrDefaultColumn(0);
        return listToArray(THIS->findItems(QString::fromStdString(text), qMatchFlags, column));
    }

    StandardItem::HandleRef Handle_horizontalHeaderItem(HandleRef _this, int32_t column) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->horizontalHeaderItem(column));
    }

    ModelIndex::OwnedRef Handle_indexFromItem(HandleRef _this, StandardItem::HandleRef item) {
        return new ModelIndex::__Owned { THIS->indexFromItem(AS_ITEM(item)) };
    }

    void Handle_insertColumn(HandleRef _this, int32_t column, const std::vector<StandardItem::HandleRef>& items) {
        THIS->insertColumn(column, arrayToList(items));
    }

    bool Handle_insertColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertColumn(column, fromOptionalIndex(parent));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, const std::vector<StandardItem::HandleRef>& items) {
        THIS->insertRow(row, arrayToList(items));
    }

    bool Handle_insertRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return THIS->insertRow(row, fromOptionalIndex(parent));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        THIS->insertRow(row, AS_ITEM(item));
    }

    StandardItem::HandleRef Handle_invisibleRootItem(HandleRef _this) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->invisibleRootItem());
    }

    StandardItem::HandleRef Handle_item(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->item(row, column.value_or(0)));
    }

    StandardItem::HandleRef Handle_itemFromIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->itemFromIndex(index->value));
    }

    StandardItem::HandleRef Handle_itemPrototype(HandleRef _this) {
        return (StandardItem::HandleRef)THIS->itemPrototype();
    }

    void Handle_setColumnCount(HandleRef _this, int32_t columns) {
        THIS->setColumnCount(columns);
    }

    void Handle_setHorizontalHeaderItem(HandleRef _this, int32_t column, StandardItem::HandleRef item) {
        THIS->setHorizontalHeaderItem(column, AS_ITEM(item));
    }

    void Handle_setHorizontalHeaderLabels(HandleRef _this, const std::vector<std::string>& labels) {
        THIS->setHorizontalHeaderLabels(toQStringList(labels));
    }

    void Handle_setItem(HandleRef _this, int32_t row, int32_t column, StandardItem::HandleRef item) {
        THIS->setItem(row, column, AS_ITEM(item));
    }

    void Handle_setItem(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        THIS->setItem(row, AS_ITEM(item));
    }

    void Handle_setItemPrototype(HandleRef _this, StandardItem::HandleRef item) {
        THIS->setItemPrototype(AS_ITEM(item));
    }

    void Handle_setRowCount(HandleRef _this, int32_t rows) {
        THIS->setRowCount(rows);
    }

    void Handle_setVerticalHeaderItem(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        THIS->setVerticalHeaderItem(row, AS_ITEM(item));
    }

    void Handle_setVerticalHeaderLabels(HandleRef _this, const std::vector<std::string>& labels) {
        THIS->setVerticalHeaderLabels(toQStringList(labels));
    }

    std::vector<StandardItem::HandleRef> Handle_takeColumn(HandleRef _this, int32_t column) {
        return listToArray(THIS->takeColumn(column));
    }

    StandardItem::HandleRef Handle_takeHorizontalHeaderItem(HandleRef _this, int32_t column) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->takeHorizontalHeaderItem(column));
    }

    StandardItem::HandleRef Handle_takeItem(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->takeItem(row, column.value_or(0)));
    }

    std::vector<StandardItem::HandleRef> Handle_takeRow(HandleRef _this, int32_t row) {
        return listToArray(THIS->takeRow(row));
    }

    StandardItem::HandleRef Handle_takeVerticalHeaderItem(HandleRef _this, int32_t row) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->takeVerticalHeaderItem(row));
    }

    StandardItem::HandleRef Handle_verticalHeaderItem(HandleRef _this, int32_t row) {
        return reinterpret_cast<StandardItem::HandleRef>(THIS->verticalHeaderItem(row));
    }

    SignalConnectionRef Handle_connect_ItemChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QStandardItemModel::itemChanged, [handler](QStandardItem *item) {
            handler->itemChanged(reinterpret_cast<StandardItem::HandleRef>(item));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QStandardItemModel());
    }

    HandleRef create(int32_t rows, int32_t columns) {
        return reinterpret_cast<HandleRef>(new QStandardItemModel(rows, columns));
    }
}
