#include "generated/TabWidget.h"

#include <QObject>
#include <QTabWidget>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((TabWidgetWithHandler*)_this)

namespace TabWidget
{
    class TabWidgetWithHandler : public QTabWidget {
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
            // TabWidget:
            { CurrentChanged, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)) },
            { TabBarClicked, SIGNAL(tabBarClicked(int)), SLOT(onTabBarClicked(int)) },
            { TabBarDoubleClicked, SIGNAL(tabBarDoubleClicked(int)), SLOT(onTabBarDoubleClicked(int)) },
            { TabCloseRequested, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)) }
        };
    public:
        explicit TabWidgetWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
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
        // TabWidget ===============
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
    };

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        THIS->setDocumentMode(state);
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool state) {
        THIS->setMovable(state);
    }

    void Handle_setTabBarAutoHide(HandleRef _this, bool state) {
        THIS->setTabBarAutoHide(state);
    }

    void Handle_setTabPosition(HandleRef _this, TabPosition position) {
        THIS->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
    }

    void Handle_setTabShape(HandleRef _this, TabShape shape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(shape));
    }

    void Handle_setTabsClosable(HandleRef _this, bool state) {
        THIS->setTabsClosable(state);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool state) {
        THIS->setUsesScrollButtons(state);
    }

    void Handle_addTab(HandleRef _this, Widget::HandleRef page, const std::string& label) {
        THIS->addTab(reinterpret_cast<QWidget *>(page), QString::fromStdString(label));
    }

    void Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, const std::string& label) {
        THIS->insertTab(index, reinterpret_cast<QWidget *>(page), QString::fromStdString(label));
    }

    Widget::HandleRef Handle_widgetAt(HandleRef _this, int32_t index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget(index));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_removeTab(HandleRef _this, int32_t index) {
        THIS->removeTab(index);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new TabWidgetWithHandler(handler));
    }
}

#include "TabWidget.moc"
