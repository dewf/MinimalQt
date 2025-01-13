#include "generated/TabWidget.h"

#include "IconInternal.h"
#include "TabWidgetInternal.h"

#include "ObjectInternal.h"
#include "WidgetInternal.h"
#include "IconInternal.h"

#include "util/convert.h"

#define THIS (reinterpret_cast<QTabWidget*>(_this))

namespace TabWidget
{
    int Handle_addTab(HandleRef _this, Widget::HandleRef page, const std::string& label) {
        return THIS->addTab(AS_QWIDGET_PTR(page), QString::fromStdString(label));
    }

    int32_t Handle_addTab(HandleRef _this, Widget::HandleRef page, Icon::HandleRef icon, const std::string& label) {
        return THIS->addTab(AS_QWIDGET_PTR(page), QICON_VALUE(icon), QString::fromStdString(label));
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    Widget::HandleRef Handle_cornerWidget(HandleRef _this, Corner corner /* Corner::TopRightCorner */) {
        return reinterpret_cast<Widget::HandleRef>(THIS->cornerWidget(static_cast<Qt::Corner>(corner)));
    }

    int32_t Handle_count(HandleRef _this) {
        return THIS->count();
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return THIS->currentIndex();
    }

    Widget::HandleRef Handle_currentWidget(HandleRef _this) {
        return reinterpret_cast<Widget::HandleRef>(THIS->currentWidget());
    }

    bool Handle_documentMode(HandleRef _this) {
        return THIS->documentMode();
    }

    TextElideMode Handle_elideMode(HandleRef _this) {
        return static_cast<TextElideMode>(THIS->elideMode());
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(THIS->iconSize());
    }

    int32_t Handle_indexOf(HandleRef _this, Widget::HandleRef w) {
        return THIS->indexOf(AS_QWIDGET_PTR(w));
    }

    int32_t Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, const std::string& label) {
        return THIS->insertTab(index, AS_QWIDGET_PTR(page), QString::fromStdString(label));
    }

    int32_t Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, Icon::HandleRef icon, const std::string& label) {
        return THIS->insertTab(index, AS_QWIDGET_PTR(page), QICON_VALUE(icon), QString::fromStdString(label));
    }

    bool Handle_isMovable(HandleRef _this) {
        return THIS->isMovable();
    }

    bool Handle_isTabEnabled(HandleRef _this, int32_t index) {
        return THIS->isTabEnabled(index);
    }

    bool Handle_isTabVisible(HandleRef _this, int32_t index) {
        return THIS->isTabVisible(index);
    }

    void Handle_removeTab(HandleRef _this, int32_t index) {
        THIS->removeTab(index);
    }

    void Handle_setCornerWidget(HandleRef _this, Widget::HandleRef widget, Corner corner /* Corner::TopRightCorner */) {
        THIS->setCornerWidget(AS_QWIDGET_PTR(widget), static_cast<Qt::Corner>(corner));
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

    void Handle_setTabEnabled(HandleRef _this, int32_t index, bool enable) {
        THIS->setTabEnabled(index, enable);
    }

    void Handle_setTabIcon(HandleRef _this, int32_t index, Icon::HandleRef icon) {
        THIS->setTabIcon(index, QICON_VALUE(icon));
    }

    void Handle_setTabPosition(HandleRef _this, TabPosition position) {
        THIS->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
    }

    void Handle_setTabShape(HandleRef _this, TabShape shape) {
        THIS->setTabShape(static_cast<QTabWidget::TabShape>(shape));
    }

    void Handle_setTabText(HandleRef _this, int32_t index, const std::string& label) {
        THIS->setTabText(index, QString::fromStdString(label));
    }

    void Handle_setTabToolTip(HandleRef _this, int32_t index, const std::string& tip) {
        THIS->setTabToolTip(index, QString::fromStdString(tip));
    }

    void Handle_setTabVisible(HandleRef _this, int32_t index, bool visible) {
        THIS->setTabVisible(index, visible);
    }

    void Handle_setTabWhatsThis(HandleRef _this, int32_t index, const std::string& text) {
        THIS->setTabWhatsThis(index, QString::fromStdString(text));
    }

    void Handle_setTabsClosable(HandleRef _this, bool state) {
        THIS->setTabsClosable(state);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool state) {
        THIS->setUsesScrollButtons(state);
    }

    TabBar::HandleRef Handle_tabBar(HandleRef _this) {
        return reinterpret_cast<TabBar::HandleRef>(THIS->tabBar());
    }

    bool Handle_tabBarAutoHide(HandleRef _this) {
        return THIS->tabBarAutoHide();
    }

    Icon::OwnedRef Handle_tabIcon(HandleRef _this, int32_t index) {
        return ICON_HEAP_NEW(THIS->tabIcon(index));
    }

    TabPosition Handle_getTabPosition(HandleRef _this) {
        return static_cast<TabPosition>(THIS->tabPosition());
    }

    TabShape Handle_getTabShape(HandleRef _this) {
        return static_cast<TabShape>(THIS->tabShape());
    }

    std::string Handle_tabText(HandleRef _this, int32_t index) {
        return THIS->tabText(index).toStdString();
    }

    std::string Handle_tabToolTip(HandleRef _this, int32_t index) {
        return THIS->tabToolTip(index).toStdString();
    }

    std::string Handle_tabWhatsThis(HandleRef _this, int32_t index) {
        return THIS->tabWhatsThis(index).toStdString();
    }

    bool Handle_tabsClosable(HandleRef _this) {
        return THIS->tabsClosable();
    }

    bool Handle_usesScrollButtons(HandleRef _this) {
        return THIS->usesScrollButtons();
    }

    Widget::HandleRef Handle_widget(HandleRef _this, int32_t index) {
        return reinterpret_cast<Widget::HandleRef>(THIS->widget(index));
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        THIS->setCurrentIndex(index);
    }

    void Handle_setCurrentWidget(HandleRef _this, Widget::HandleRef widget) {
        THIS->setCurrentWidget(AS_QWIDGET_PTR(widget));
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

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTabWidget(AS_QWIDGET_PTR(parent)));
    }
}
