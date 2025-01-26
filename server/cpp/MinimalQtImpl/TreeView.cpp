#include "generated/TreeView.h"
#include "TreeViewInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "HeaderViewInternal.h"
#include "WidgetInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Common;
using namespace ::Icon;
using namespace ::Enums;
using namespace ::AbstractItemView;
using namespace ::ModelIndex;
using namespace ::HeaderView;

#define THIS (reinterpret_cast<QTreeView*>(_this))

namespace TreeView
{
    bool Handle_allColumnsShowFocus(HandleRef _this) {
        return THIS->allColumnsShowFocus();
    }

    int32_t Handle_autoExpandDelay(HandleRef _this) {
        return THIS->autoExpandDelay();
    }

    int32_t Handle_columnAt(HandleRef _this, int32_t x) {
        return THIS->columnAt(x);
    }

    int32_t Handle_columnViewportPosition(HandleRef _this, int32_t column) {
        return THIS->columnViewportPosition(column);
    }

    int32_t Handle_columnWidth(HandleRef _this, int32_t column) {
        return THIS->columnWidth(column);
    }

    bool Handle_expandsOnDoubleClick(HandleRef _this) {
        return THIS->expandsOnDoubleClick();
    }

    HeaderView::HandleRef Handle_header(HandleRef _this) {
        return reinterpret_cast<HeaderView::HandleRef>(THIS->header());
    }

    int32_t Handle_indentation(HandleRef _this) {
        return THIS->indentation();
    }

    ModelIndex::OwnedRef Handle_indexAbove(HandleRef _this, ModelIndex::HandleRef index) {
        return MODELINDEX_HEAP_NEW(THIS->indexAbove(QMODELINDEX_VALUE(index)));
    }

    ModelIndex::OwnedRef Handle_indexBelow(HandleRef _this, ModelIndex::HandleRef index) {
        return MODELINDEX_HEAP_NEW(THIS->indexBelow(QMODELINDEX_VALUE(index)));
    }

    bool Handle_isAnimated(HandleRef _this) {
        return THIS->isAnimated();
    }

    bool Handle_isColumnHidden(HandleRef _this, int32_t column) {
        return THIS->isColumnHidden(column);
    }

    bool Handle_isExpanded(HandleRef _this, ModelIndex::HandleRef index) {
        return THIS->isExpanded(QMODELINDEX_VALUE(index));
    }

    bool Handle_isFirstColumnSpanned(HandleRef _this, int32_t row, ModelIndex::HandleRef parent) {
        return THIS->isFirstColumnSpanned(row, QMODELINDEX_VALUE(parent));
    }

    bool Handle_isHeaderHidden(HandleRef _this) {
        return THIS->isHeaderHidden();
    }

    bool Handle_isRowHidden(HandleRef _this, int32_t row, ModelIndex::HandleRef parent) {
        return THIS->isRowHidden(row, QMODELINDEX_VALUE(parent));
    }

    bool Handle_isSortingEnabled(HandleRef _this) {
        return THIS->isSortingEnabled();
    }

    bool Handle_itemsExpandable(HandleRef _this) {
        return THIS->itemsExpandable();
    }

    void Handle_resetIndentation(HandleRef _this) {
        THIS->resetIndentation();
    }

    bool Handle_rootIsDecorated(HandleRef _this) {
        return THIS->rootIsDecorated();
    }

    void Handle_setAllColumnsShowFocus(HandleRef _this, bool enable) {
        return THIS->setAllColumnsShowFocus(enable);
    }

    void Handle_setAnimated(HandleRef _this, bool enable) {
        return THIS->setAnimated(enable);
    }

    void Handle_setAutoExpandDelay(HandleRef _this, int32_t delay) {
        return THIS->setAutoExpandDelay(delay);
    }

    void Handle_setColumnHidden(HandleRef _this, int32_t column, bool hide) {
        return THIS->setColumnHidden(column, hide);
    }

    void Handle_setColumnWidth(HandleRef _this, int32_t column, int32_t width) {
        THIS->setColumnWidth(column, width);
    }

    void Handle_setExpanded(HandleRef _this, ModelIndex::HandleRef index, bool expanded) {
        THIS->setExpanded(QMODELINDEX_VALUE(index), expanded);
    }

    void Handle_setExpandsOnDoubleClick(HandleRef _this, bool enable) {
        THIS->setExpandsOnDoubleClick(enable);
    }

    void Handle_setFirstColumnSpanned(HandleRef _this, int32_t row, ModelIndex::HandleRef parent, bool span) {
        THIS->setFirstColumnSpanned(row, QMODELINDEX_VALUE(parent), span);
    }

    void Handle_setHeader(HandleRef _this, HeaderView::HandleRef header) {
        THIS->setHeader(reinterpret_cast<QHeaderView*>(header));
    }

    void Handle_setHeaderHidden(HandleRef _this, bool hide) {
        THIS->setHeaderHidden(hide);
    }

    void Handle_setIndentation(HandleRef _this, int32_t i) {
        THIS->setIndentation(i);
    }

    void Handle_setItemsExpandable(HandleRef _this, bool enable) {
        THIS->setItemsExpandable(enable);
    }

    void Handle_setRootIsDecorated(HandleRef _this, bool show) {
        THIS->setRootIsDecorated(show);
    }

    void Handle_setRowHidden(HandleRef _this, int32_t row, ModelIndex::HandleRef parent, bool hide) {
        THIS->setRowHidden(row, QMODELINDEX_VALUE(parent), hide);
    }

    void Handle_setSortingEnabled(HandleRef _this, bool enable) {
        THIS->setSortingEnabled(enable);
    }

    void Handle_setTreePosition(HandleRef _this, int32_t index) {
        THIS->setTreePosition(index);
    }

    void Handle_setUniformRowHeights(HandleRef _this, bool uniform) {
        THIS->setUniformRowHeights(uniform);
    }

    void Handle_setWordWrap(HandleRef _this, bool on) {
        THIS->setWordWrap(on);
    }

    int32_t Handle_treePosition(HandleRef _this) {
        return THIS->treePosition();
    }

    bool Handle_uniformRowHeights(HandleRef _this) {
        return THIS->uniformRowHeights();
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    void Handle_collapse(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->collapse(QMODELINDEX_VALUE(index));
    }

    void Handle_collapseAll(HandleRef _this) {
        THIS->collapseAll();
    }

    void Handle_expand(HandleRef _this, ModelIndex::HandleRef index) {
        THIS->expand(QMODELINDEX_VALUE(index));
    }

    void Handle_expandAll(HandleRef _this) {
        THIS->expandAll();
    }

    void Handle_expandRecursively(HandleRef _this, ModelIndex::HandleRef index, int32_t depth /* -1 */) {
        THIS->expandRecursively(QMODELINDEX_VALUE(index), depth);
    }

    void Handle_expandToDepth(HandleRef _this, int32_t depth) {
        THIS->expandToDepth(depth);
    }

    void Handle_hideColumn(HandleRef _this, int32_t column) {
        THIS->hideColumn(column);
    }

    void Handle_resizeColumnToContents(HandleRef _this, int32_t column) {
        THIS->resizeColumnToContents(column);
    }

    void Handle_showColumn(HandleRef _this, int32_t column) {
        THIS->showColumn(column);
    }

    void Handle_sortByColumn(HandleRef _this, int32_t column, SortOrder order) {
        THIS->sortByColumn(column, static_cast<Qt::SortOrder>(order));
    }

    SignalConnectionRef Handle_connect_Collapsed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTreeView::collapsed, [handler](const QModelIndex& index) {
            QModelIndex index2(index);
            handler->collapsed(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Expanded(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTreeView::expanded, [handler](const QModelIndex& index) {
            QModelIndex index2(index);
            handler->expanded(reinterpret_cast<ModelIndex::HandleRef>(&index2));
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTreeView(AS_QWIDGET_PTR(parent)));
    }
}
