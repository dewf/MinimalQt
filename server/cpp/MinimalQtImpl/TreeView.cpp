#include "generated/TreeView.h"
#include "TreeViewInternal.h"

#include "ObjectInternal.h"
#include "ModelIndexInternal.h"
#include "HeaderViewInternal.h"

#define THIS (reinterpret_cast<QTreeView*>(_this))

namespace TreeView
{
    bool Handle_allColumnsShowFocus(HandleRef _this) {
        return THIS->allColumnsShowFocus();
    }

    void Handle_setAllColumnsShowFocus(HandleRef _this, bool value) {
        THIS->setAllColumnsShowFocus(value);
    }

    bool Handle_isAnimated(HandleRef _this) {
        return THIS->isAnimated();
    }

    void Handle_setAnimated(HandleRef _this, bool value) {
        THIS->setAnimated(value);
    }

    int32_t Handle_autoExpandDelay(HandleRef _this) {
        return THIS->autoExpandDelay();
    }

    void Handle_setAutoExpandDelay(HandleRef _this, int32_t value) {
        THIS->setAutoExpandDelay(value);
    }

    bool Handle_expandsOnDoubleClick(HandleRef _this) {
        return THIS->expandsOnDoubleClick();
    }

    void Handle_setExpandsOnDoubleClick(HandleRef _this, bool value) {
        THIS->setExpandsOnDoubleClick(value);
    }

    bool Handle_isHeaderHidden(HandleRef _this) {
        return THIS->isHeaderHidden();
    }

    void Handle_setHeaderHidden(HandleRef _this, bool value) {
        THIS->setHeaderHidden(value);
    }

    int32_t Handle_indentation(HandleRef _this) {
        return THIS->indentation();
    }

    void Handle_setIndentation(HandleRef _this, int32_t value) {
        THIS->setIndentation(value);
    }

    void Handle_resetIndentation(HandleRef _this) {
        return THIS->resetIndentation();
    }

    bool Handle_itemsExpandable(HandleRef _this) {
        return THIS->itemsExpandable();
    }

    void Handle_setItemsExpandable(HandleRef _this, bool value) {
        THIS->setItemsExpandable(value);
    }

    bool Handle_rootIsDecorated(HandleRef _this) {
        return THIS->rootIsDecorated();
    }

    void Handle_setRootIsDecorated(HandleRef _this, bool value) {
        THIS->setRootIsDecorated(value);
    }

    bool Handle_isSortingEnabled(HandleRef _this) {
        return THIS->isSortingEnabled();
    }

    void Handle_setSortingEnabled(HandleRef _this, bool value) {
        THIS->setSortingEnabled(value);
    }

    bool Handle_uniformRowHeights(HandleRef _this) {
        return THIS->uniformRowHeights();
    }

    void Handle_setUniformRowHeights(HandleRef _this, bool value) {
        THIS->setUniformRowHeights(value);
    }

    bool Handle_wordWrap(HandleRef _this) {
        return THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool value) {
        THIS->setWordWrap(value);
    }

    HeaderView::HandleRef Handle_header(HandleRef _this) {
        return reinterpret_cast<HeaderView::HandleRef>(THIS->header());
    }

    void Handle_resizeColumnToContents(HandleRef _this, int32_t column) {
        THIS->resizeColumnToContents(column);
    }

    SignalConnectionRef Handle_connect_Collapsed(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTreeView::collapsed, [handler](const QModelIndex& index) {
            ModelIndex::__Owned index2(index);
            handler->collapsed(&index2);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Expanded(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTreeView::expanded, [handler](const QModelIndex& index) {
            ModelIndex::__Owned index2(index);
            handler->expanded(&index2);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QTreeView());
    }
}
