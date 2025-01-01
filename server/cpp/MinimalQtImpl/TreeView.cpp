#include "generated/TreeView.h"
#include "TreeViewInternal.h"

#include "HeaderViewInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TREEVIEW_THIS (WRAPPER->getActual())

namespace TreeView
{
    bool Handle_allColumnsShowFocus(HandleRef _this) {
        return TREEVIEW_THIS->allColumnsShowFocus();
    }

    void Handle_setAllColumnsShowFocus(HandleRef _this, bool value) {
        TREEVIEW_THIS->setAllColumnsShowFocus(value);
    }

    bool Handle_isAnimated(HandleRef _this) {
        return TREEVIEW_THIS->isAnimated();
    }

    void Handle_setAnimated(HandleRef _this, bool value) {
        TREEVIEW_THIS->setAnimated(value);
    }

    int32_t Handle_autoExpandDelay(HandleRef _this) {
        return TREEVIEW_THIS->autoExpandDelay();
    }

    void Handle_setAutoExpandDelay(HandleRef _this, int32_t value) {
        TREEVIEW_THIS->setAutoExpandDelay(value);
    }

    bool Handle_expandsOnDoubleClick(HandleRef _this) {
        return TREEVIEW_THIS->expandsOnDoubleClick();
    }

    void Handle_setExpandsOnDoubleClick(HandleRef _this, bool value) {
        TREEVIEW_THIS->setExpandsOnDoubleClick(value);
    }

    bool Handle_isHeaderHidden(HandleRef _this) {
        return TREEVIEW_THIS->isHeaderHidden();
    }

    void Handle_setHeaderHidden(HandleRef _this, bool value) {
        TREEVIEW_THIS->setHeaderHidden(value);
    }

    int32_t Handle_indentation(HandleRef _this) {
        return TREEVIEW_THIS->indentation();
    }

    void Handle_setIndentation(HandleRef _this, int32_t value) {
        TREEVIEW_THIS->setIndentation(value);
    }

    void Handle_resetIndentation(HandleRef _this) {
        return TREEVIEW_THIS->resetIndentation();
    }

    bool Handle_itemsExpandable(HandleRef _this) {
        return TREEVIEW_THIS->itemsExpandable();
    }

    void Handle_setItemsExpandable(HandleRef _this, bool value) {
        TREEVIEW_THIS->setItemsExpandable(value);
    }

    bool Handle_rootIsDecorated(HandleRef _this) {
        return TREEVIEW_THIS->rootIsDecorated();
    }

    void Handle_setRootIsDecorated(HandleRef _this, bool value) {
        TREEVIEW_THIS->setRootIsDecorated(value);
    }

    bool Handle_isSortingEnabled(HandleRef _this) {
        return TREEVIEW_THIS->isSortingEnabled();
    }

    void Handle_setSortingEnabled(HandleRef _this, bool value) {
        TREEVIEW_THIS->setSortingEnabled(value);
    }

    bool Handle_uniformRowHeights(HandleRef _this) {
        return TREEVIEW_THIS->uniformRowHeights();
    }

    void Handle_setUniformRowHeights(HandleRef _this, bool value) {
        TREEVIEW_THIS->setUniformRowHeights(value);
    }

    bool Handle_wordWrap(HandleRef _this) {
        return TREEVIEW_THIS->wordWrap();
    }

    void Handle_setWordWrap(HandleRef _this, bool value) {
        TREEVIEW_THIS->setWordWrap(value);
    }

    std::shared_ptr<HeaderViewResult::Base> Handle_header(HandleRef _this) {
        if (const auto header = TREEVIEW_THIS->header(); header != nullptr) {
            // check for existing wrapper (ie, did we originally set the header ourselves?)
            if (const auto existing = wrapperForQObject(header); existing != nullptr) {
                const auto handleRef = reinterpret_cast<HeaderView::HandleRef>(existing);
                return std::make_shared<HeaderViewResult::AlreadyExists>(handleRef);
            }
            // else, unknown (Qt-supplied) default, need to create a new wrapper
            // return a function which can create one on-demand
            const auto func = [header](const std::shared_ptr<HeaderView::SignalHandler>& handler) {
                const auto wrapper = new HeaderView::SignalWrapper(header, handler);
                return reinterpret_cast<HeaderView::HandleRef>(wrapper);
            };
            return std::make_shared<HeaderViewResult::NeedsWrapper>(func);
        }
        // else
        return std::make_shared<HeaderViewResult::NoHeaderView>();
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
