#include "generated/TreeView.h"

#include <QTreeView>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((TreeViewWithHandler*)_this)

#include "TreeViewInternal.h"

namespace TreeView
{
    class TreeViewWithHandler : public QTreeView {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit TreeViewWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setAllColumnsShowFocus(HandleRef _this, bool value) {
        THIS->setAllColumnsShowFocus(value);
    }

    void Handle_setAnimated(HandleRef _this, bool value) {
        THIS->setAnimated(value);
    }

    void Handle_setAutoExpandDelay(HandleRef _this, int32_t value) {
        THIS->setAutoExpandDelay(value);
    }

    void Handle_setExpandsOnDoubleClick(HandleRef _this, bool value) {
        THIS->setExpandsOnDoubleClick(value);
    }

    void Handle_setHeaderHidden(HandleRef _this, bool value) {
        THIS->setHeaderHidden(value);
    }

    void Handle_setIndentation(HandleRef _this, int32_t value) {
        THIS->setIndentation(value);
    }

    void Handle_setItemsExpandable(HandleRef _this, bool value) {
        THIS->setItemsExpandable(value);
    }

    void Handle_setRootIsDecorated(HandleRef _this, bool value) {
        THIS->setRootIsDecorated(value);
    }

    void Handle_setSortingEnabled(HandleRef _this, bool value) {
        THIS->setSortingEnabled(value);
    }

    void Handle_setUniformRowHeights(HandleRef _this, bool value) {
        THIS->setUniformRowHeights(value);
    }

    void Handle_setWordWrap(HandleRef _this, bool value) {
        THIS->setWordWrap(value);
    }

    void Handle_resizeColumnToContents(HandleRef _this, int32_t column) {
        THIS->resizeColumnToContents(column);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new TreeViewWithHandler(handler));
    }
}

#include "TreeView.moc"
