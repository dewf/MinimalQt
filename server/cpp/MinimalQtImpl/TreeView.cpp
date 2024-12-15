#include "generated/TreeView.h"

#include <QTreeView>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((TreeViewWithHandler*)_this)

namespace TreeView
{
    class TreeViewWithHandler : public QTreeView {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // Frame:
            // ..... (none)
            // AbstractScrollArea:
            // ..... (none)
            // AbstractItemView:
            { Activated, SIGNAL(activated(QModelIndex)), SLOT(onActivated(QModelIndex)) },
            { Clicked, SIGNAL(clicked(QModelIndex)), SLOT(onClicked(QModelIndex)) },
            { DoubleClickedBit, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)) },
            { Entered, SIGNAL(entered(QModelIndex)), SLOT(onEntered(QModelIndex)) },
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { Pressed, SIGNAL(pressed(QModelIndex)), SLOT(onPressed(QModelIndex)) },
            { ViewportEntered, SIGNAL(viewportEntered()), SLOT(onViewportEntered) },
            // TreeView:
            { Collapsed, SIGNAL(collapsed(QModelIndex)), SLOT(onCollapsed(QModelIndex)) },
            { Expanded, SIGNAL(expanded(QModelIndex)), SLOT(onExpanded(QModelIndex)) },
        };
    public:
        explicit TreeViewWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Frame ====================
        // .... (none)

        // AbstractScrollArea =======
        // .... (none)

        // AbstractItemView =========
        void onActivated(const QModelIndex& index) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    activated((ModelIndex::HandleRef)&index);
        }
        void onClicked(const QModelIndex& index) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    clicked((ModelIndex::HandleRef)&index);
        }
        void onDoubleClicked(const QModelIndex& index) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    doubleClicked((ModelIndex::HandleRef)&index);
        }
        void onEntered(QModelIndex& index) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    entered((ModelIndex::HandleRef)&index);
        }
        void onIconSizeChanged(const QSize& size) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    iconSizeChanged(toSize(size));
        }
        void onPressed(const QModelIndex& index) const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    pressed((ModelIndex::HandleRef)&index);
        }
        void onViewportEntered() const {
            handler->
                inherited_AbstractItemView_SignalHandler()->
                    viewportEntered();
        }
        // TreeView =================
        void onCollapsed(const QModelIndex& index) const {
            handler->collapsed((ModelIndex::HandleRef)&index);
        }
        void onExpanded(const QModelIndex& index) const {
            handler->expanded((ModelIndex::HandleRef)&index);
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
