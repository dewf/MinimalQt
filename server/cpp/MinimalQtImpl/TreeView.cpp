#include "generated/TreeView.h"
#include "TreeViewInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TREEVIEW_THIS (WRAPPER->getActual())

namespace TreeView
{
    void Handle_setAllColumnsShowFocus(HandleRef _this, bool value) {
        TREEVIEW_THIS->setAllColumnsShowFocus(value);
    }

    void Handle_setAnimated(HandleRef _this, bool value) {
        TREEVIEW_THIS->setAnimated(value);
    }

    void Handle_setAutoExpandDelay(HandleRef _this, int32_t value) {
        TREEVIEW_THIS->setAutoExpandDelay(value);
    }

    void Handle_setExpandsOnDoubleClick(HandleRef _this, bool value) {
        TREEVIEW_THIS->setExpandsOnDoubleClick(value);
    }

    void Handle_setHeaderHidden(HandleRef _this, bool value) {
        TREEVIEW_THIS->setHeaderHidden(value);
    }

    void Handle_setIndentation(HandleRef _this, int32_t value) {
        TREEVIEW_THIS->setIndentation(value);
    }

    void Handle_setItemsExpandable(HandleRef _this, bool value) {
        TREEVIEW_THIS->setItemsExpandable(value);
    }

    void Handle_setRootIsDecorated(HandleRef _this, bool value) {
        TREEVIEW_THIS->setRootIsDecorated(value);
    }

    void Handle_setSortingEnabled(HandleRef _this, bool value) {
        TREEVIEW_THIS->setSortingEnabled(value);
    }

    void Handle_setUniformRowHeights(HandleRef _this, bool value) {
        TREEVIEW_THIS->setUniformRowHeights(value);
    }

    void Handle_setWordWrap(HandleRef _this, bool value) {
        TREEVIEW_THIS->setWordWrap(value);
    }

    void Handle_resizeColumnToContents(HandleRef _this, int32_t column) {
        TREEVIEW_THIS->resizeColumnToContents(column);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QTreeView(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
