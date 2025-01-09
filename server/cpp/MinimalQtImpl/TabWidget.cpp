#include "generated/TabWidget.h"
#include "TabWidgetInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QTabWidget*>(_this))

namespace TabWidget
{
    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    bool Handle_documentMode(HandleRef _this) {
        return THIS->documentMode();
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        THIS->setDocumentMode(state);
    }

    TextElideMode Handle_elideMode(HandleRef _this) {
        return static_cast<TextElideMode>(THIS->elideMode());
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        THIS->setIconSize(toQSize(size));
    }

    bool Handle_isMovable(HandleRef _this) {
        return THIS->isMovable();
    }

    void Handle_setMovable(HandleRef _this, bool state) {
        THIS->setMovable(state);
    }

    bool Handle_tabBarAutoHide(HandleRef _this) {
        return THIS->tabBarAutoHide();
    }

    void Handle_setTabBarAutoHide(HandleRef _this, bool state) {
        THIS->setTabBarAutoHide(state);
    }

    TabPosition Handle_getTabPosition(HandleRef _this) {
        return static_cast<TabPosition>(THIS->tabPosition());
    }

    void Handle_setTabPosition(HandleRef _this, TabPosition position) {
        THIS->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
    }

    TabShape Handle_getTabShape(HandleRef _this) {
        return static_cast<TabShape>(THIS->tabShape());
    }

    void Handle_setTabShape(HandleRef _this, TabShape shape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(shape));
    }

    bool Handle_tabsClosable(HandleRef _this) {
        return THIS->tabsClosable();
    }

    void Handle_setTabsClosable(HandleRef _this, bool state) {
        THIS->setTabsClosable(state);
    }

    bool Handle_usesScrollButtons(HandleRef _this) {
        return THIS->usesScrollButtons();
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool state) {
        THIS->setUsesScrollButtons(state);
    }

    int Handle_addTab(HandleRef _this, Widget::HandleRef page, const std::string& label) {
        return THIS->addTab(AS_QWIDGET_PTR(page), QString::fromStdString(label));
    }

    int Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, const std::string& label) {
        return THIS->insertTab(index, AS_QWIDGET_PTR(page), QString::fromStdString(label));
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

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabWidget::currentChanged, [handler](int index) {
            handler->currentChanged(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabWidget::tabBarClicked, [handler](int index) {
            handler->tabBarClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabWidget::tabBarDoubleClicked, [handler](int index) {
            handler->tabBarDoubleClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabCloseRequested(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabWidget::tabCloseRequested, [handler](int index) {
            handler->tabCloseRequested(index);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QTabWidget());
    }
}
