#include "generated/TabBar.h"

#include <QObject>
#include <QTabBar>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((TabBarWithHandler*)_this)

namespace TabBar
{
    class TabBarWithHandler : public QTabBar {
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
            // TabBar:
            { CurrentChanged, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)) },
            { TabBarClicked, SIGNAL(tabBarClicked(int)), SLOT(onTabBarClicked(int)) },
            { TabBarDoubleClicked, SIGNAL(tabBarDoubleClicked(int)), SLOT(onTabBarDoubleClicked(int)) },
            { TabCloseRequested, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)) },
            { TabMoved, SIGNAL(tabMoved(int,int)), SLOT(onTabMoved(int,int)) }
        };
    public:
        explicit TabBarWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
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
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // TabBar ==================
        void onCurrentChanged(int index) const {
            handler->currentChanged(index);
        }
        void onTabBarClicked(int index) const {
            handler->tabBarClicked(index);
        }
        void onTabBarDoubleClicked(int index) const {
            handler->tabBarDoubleClicked(index);
        }
        void onTabCloseRequested(int index) const {
            handler->tabCloseRequested(index);
        }
        void onTabMoved(int fromIndex, int toIndex) const {
            handler->tabMoved(fromIndex, toIndex);
        }
    };

    void Handle_setAutoHide(HandleRef _this, bool value) {
        THIS->setAutoHide(value);
    }

    void Handle_setChangeCurrentOnDrag(HandleRef _this, bool value) {
        THIS->setChangeCurrentOnDrag(value);
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t value) {
        THIS->setCurrentIndex(value);
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    void Handle_setDocumentMode(HandleRef _this, bool value) {
        THIS->setDocumentMode(value);
    }

    void Handle_setDrawBase(HandleRef _this, bool value) {
        THIS->setDrawBase(value);
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setExpanding(HandleRef _this, bool value) {
        THIS->setExpanding(value);
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        THIS->setMovable(value);
    }

    void Handle_setSelectionBehaviorOnRemove(HandleRef _this, SelectionBehavior value) {
        THIS->setSelectionBehaviorOnRemove(static_cast<QTabBar::SelectionBehavior>(value));
    }

    void Handle_setShape(HandleRef _this, Shape shape) {
        THIS->setShape(static_cast<QTabBar::Shape>(shape));
    }

    void Handle_setTabsClosable(HandleRef _this, bool value) {
        THIS->setTabsClosable(value);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool value) {
        THIS->setUsesScrollButtons(value);
    }

    void Handle_removeAllTabs(HandleRef _this) {
        auto count = THIS->count();
        for (auto i=0; i< count; i++) {
            THIS->removeTab(0);
        }
    }

    int32_t Handle_addTab(HandleRef _this, const std::string& text) {
        return THIS->addTab(QString::fromStdString(text));
    }

    int32_t Handle_addTab(HandleRef _this, Icon::HandleRef icon, const std::string& text) {
        return THIS->addTab(ICON_VALUE(icon), QString::fromStdString(text));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new TabBarWithHandler(handler));
    }
}

#include "TabBar.moc"
