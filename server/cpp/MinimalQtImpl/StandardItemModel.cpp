#include "generated/StandardItemModel.h"

#include "ModelIndexInternal.h"
#include "StandardItemModelInternal.h"

#include "StandardItemInternal.h"
#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define MODEL_THIS (WRAPPER->getActual())
#define AS_ITEM(x) (reinterpret_cast<QStandardItem*>(x))

namespace StandardItemModel
{
    int32_t Handle_sortRole(HandleRef _this) {
        return MODEL_THIS->sortRole();
    }

    void Handle_setSortRole(HandleRef _this, int32_t role) {
        MODEL_THIS->setSortRole(role);
    }

    void Handle_appendColumn(HandleRef _this, const std::vector<StandardItem::HandleRef>& items) {
        MODEL_THIS->appendColumn(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, const std::vector<StandardItem::HandleRef>& items) {
        MODEL_THIS->appendRow(arrayToList(items));
    }

    void Handle_appendRow(HandleRef _this, StandardItem::HandleRef item) {
        MODEL_THIS->appendRow(AS_ITEM(item));
    }

    void Handle_clear(HandleRef _this) {
        MODEL_THIS->clear();
    }

    std::vector<StandardItem::HandleRef> Handle_findItems(HandleRef _this, const std::string& text, const Handle::FindItemsArgs& args) {
        const auto qMatchFlags = static_cast<Qt::MatchFlags>(args.getOrDefaultFlags_(MatchExactly));
        const auto column = args.getOrDefaultColumn(0);
        return listToArray(MODEL_THIS->findItems(QString::fromStdString(text), qMatchFlags, column));
    }

    StandardItem::HandleRef Handle_horizontalHeaderItem(HandleRef _this, int32_t column) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->horizontalHeaderItem(column));
    }

    ModelIndex::OwnedRef Handle_indexFromItem(HandleRef _this, StandardItem::HandleRef item) {
        return new ModelIndex::__Owned { MODEL_THIS->indexFromItem(AS_ITEM(item)) };
    }

    void Handle_insertColumn(HandleRef _this, int32_t column, const std::vector<StandardItem::HandleRef>& items) {
        MODEL_THIS->insertColumn(column, arrayToList(items));
    }

    bool Handle_insertColumn(HandleRef _this, int32_t column, const std::optional<ModelIndex::HandleRef>& parent) {
        return MODEL_THIS->insertColumn(column, fromOptionalIndex(parent));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, const std::vector<StandardItem::HandleRef>& items) {
        MODEL_THIS->insertRow(row, arrayToList(items));
    }

    bool Handle_insertRow(HandleRef _this, int32_t row, const std::optional<ModelIndex::HandleRef>& parent) {
        return MODEL_THIS->insertRow(row, fromOptionalIndex(parent));
    }

    void Handle_insertRow(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        MODEL_THIS->insertRow(row, AS_ITEM(item));
    }

    StandardItem::HandleRef Handle_invisibleRootItem(HandleRef _this) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->invisibleRootItem());
    }

    StandardItem::HandleRef Handle_item(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->item(row, column.value_or(0)));
    }

    StandardItem::HandleRef Handle_itemFromIndex(HandleRef _this, ModelIndex::HandleRef index) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->itemFromIndex(index->value));
    }

    StandardItem::HandleRef Handle_itemPrototype(HandleRef _this) {
        return (StandardItem::HandleRef)MODEL_THIS->itemPrototype();
    }

    void Handle_setColumnCount(HandleRef _this, int32_t columns) {
        MODEL_THIS->setColumnCount(columns);
    }

    void Handle_setHorizontalHeaderItem(HandleRef _this, int32_t column, StandardItem::HandleRef item) {
        MODEL_THIS->setHorizontalHeaderItem(column, AS_ITEM(item));
    }

    void Handle_setHorizontalHeaderLabels(HandleRef _this, const std::vector<std::string>& labels) {
        MODEL_THIS->setHorizontalHeaderLabels(toQStringList(labels));
    }

    void Handle_setItem(HandleRef _this, int32_t row, int32_t column, StandardItem::HandleRef item) {
        MODEL_THIS->setItem(row, column, AS_ITEM(item));
    }

    void Handle_setItem(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        MODEL_THIS->setItem(row, AS_ITEM(item));
    }

    void Handle_setItemPrototype(HandleRef _this, StandardItem::HandleRef item) {
        MODEL_THIS->setItemPrototype(AS_ITEM(item));
    }

    void Handle_setRowCount(HandleRef _this, int32_t rows) {
        MODEL_THIS->setRowCount(rows);
    }

    void Handle_setVerticalHeaderItem(HandleRef _this, int32_t row, StandardItem::HandleRef item) {
        MODEL_THIS->setVerticalHeaderItem(row, AS_ITEM(item));
    }

    void Handle_setVerticalHeaderLabels(HandleRef _this, const std::vector<std::string>& labels) {
        MODEL_THIS->setVerticalHeaderLabels(toQStringList(labels));
    }

    std::vector<StandardItem::HandleRef> Handle_takeColumn(HandleRef _this, int32_t column) {
        return listToArray(MODEL_THIS->takeColumn(column));
    }

    StandardItem::HandleRef Handle_takeHorizontalHeaderItem(HandleRef _this, int32_t column) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->takeHorizontalHeaderItem(column));
    }

    StandardItem::HandleRef Handle_takeItem(HandleRef _this, int32_t row, const std::optional<int32_t>& column) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->takeItem(row, column.value_or(0)));
    }

    std::vector<StandardItem::HandleRef> Handle_takeRow(HandleRef _this, int32_t row) {
        return listToArray(MODEL_THIS->takeRow(row));
    }

    StandardItem::HandleRef Handle_takeVerticalHeaderItem(HandleRef _this, int32_t row) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->takeVerticalHeaderItem(row));
    }

    StandardItem::HandleRef Handle_verticalHeaderItem(HandleRef _this, int32_t row) {
        return reinterpret_cast<StandardItem::HandleRef>(MODEL_THIS->verticalHeaderItem(row));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QStandardItemModel(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }

    HandleRef create(int32_t rows, int32_t columns, const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QStandardItemModel(rows, columns), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
