#include "generated/ListView.h"

#include <QListView>
#include <utility>
#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((ListViewWithHandler*)_this)

namespace ListView
{
    class ListViewWithHandler : public QListView {
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
            // ListView:
            { IndexesMoved, SIGNAL(indexesMoved(QModelIndexList)), SLOT(onIndexesMoved(QModelIndexList)) },
        };
    public:
        explicit ListViewWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
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
        // ListView ========================
        void onIndexesMoved(const QModelIndexList &indexes) const {
            std::vector<ModelIndex::HandleRef> indexes2;
            for (auto &index : indexes) {
                // will this work? seems sketchy
                indexes2.push_back((ModelIndex::HandleRef)&index);
            }
            handler->indexesMoved(indexes2);
        }
    };

    void Handle_setBatchSize(HandleRef _this, int32_t size) {
        THIS->setBatchSize(size);
    }

    void Handle_setFlow(HandleRef _this, Flow flow) {
        THIS->setFlow(static_cast<QListView::Flow>(flow));
    }

    void Handle_setGridSize(HandleRef _this, Size size) {
        THIS->setGridSize(toQSize(size));
    }

    void Handle_setWrapping(HandleRef _this, bool wrapping) {
        THIS->setWrapping(wrapping);
    }

    void Handle_setItemAlignment(HandleRef _this, Alignment align) {
        THIS->setItemAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setLayoutMode(HandleRef _this, LayoutMode mode) {
        THIS->setLayoutMode(static_cast<QListView::LayoutMode>(mode));
    }

    void Handle_setModelColumn(HandleRef _this, int32_t column) {
        THIS->setModelColumn(column);
    }

    void Handle_setMovement(HandleRef _this, Movement movement) {
        THIS->setMovement(static_cast<QListView::Movement>(movement));
    }

    void Handle_setResizeMode(HandleRef _this, ResizeMode mode) {
        THIS->setResizeMode(static_cast<QListView::ResizeMode>(mode));
    }

    void Handle_setSelectionRectVisible(HandleRef _this, bool visible) {
        THIS->setSelectionRectVisible(visible);
    }

    void Handle_setSpacing(HandleRef _this, int32_t spacing) {
        THIS->setSpacing(spacing);
    }

    void Handle_setUniformItemSizes(HandleRef _this, bool state) {
        THIS->setUniformItemSizes(state);
    }

    void Handle_setViewMode(HandleRef _this, ViewMode mode) {
        THIS->setViewMode(static_cast<QListView::ViewMode>(mode));
    }

    void Handle_setWordWrap(HandleRef _this, bool state) {
        THIS->setWordWrap(state);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new ListViewWithHandler(handler));
    }
}

#include "ListView.moc"
