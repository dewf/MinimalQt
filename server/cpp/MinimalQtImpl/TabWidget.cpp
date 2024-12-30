#include "generated/TabWidget.h"
#include "TabWidgetInternal.h"

#include "util/convert.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TABWIDGET_THIS (WRAPPER->getActual())

namespace TabWidget
{
    int32_t Handle_count(HandleRef _this) {
        return TABWIDGET_THIS->count();
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return TABWIDGET_THIS->currentIndex();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        TABWIDGET_THIS->setCurrentIndex(index);
    }

    bool Handle_documentMode(HandleRef _this) {
        return TABWIDGET_THIS->documentMode();
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        TABWIDGET_THIS->setDocumentMode(state);
    }

    TextElideMode Handle_elideMode(HandleRef _this) {
        return static_cast<TextElideMode>(TABWIDGET_THIS->elideMode());
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        TABWIDGET_THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    Size Handle_iconSize(HandleRef _this) {
        return toSize(TABWIDGET_THIS->iconSize());
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        TABWIDGET_THIS->setIconSize(toQSize(size));
    }

    bool Handle_isMovable(HandleRef _this) {
        return TABWIDGET_THIS->isMovable();
    }

    void Handle_setMovable(HandleRef _this, bool state) {
        TABWIDGET_THIS->setMovable(state);
    }

    bool Handle_tabBarAutoHide(HandleRef _this) {
        return TABWIDGET_THIS->tabBarAutoHide();
    }

    void Handle_setTabBarAutoHide(HandleRef _this, bool state) {
        TABWIDGET_THIS->setTabBarAutoHide(state);
    }

    TabPosition Handle_getTabPosition(HandleRef _this) {
        return static_cast<TabPosition>(TABWIDGET_THIS->tabPosition());
    }

    void Handle_setTabPosition(HandleRef _this, TabPosition position) {
        TABWIDGET_THIS->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
    }

    TabShape Handle_getTabShape(HandleRef _this) {
        return static_cast<TabShape>(TABWIDGET_THIS->tabShape());
    }

    void Handle_setTabShape(HandleRef _this, TabShape shape) {
        TABWIDGET_THIS->setTabShape(static_cast<QTabWidget::TabShape>(shape));
    }

    bool Handle_tabsClosable(HandleRef _this) {
        return TABWIDGET_THIS->tabsClosable();
    }

    void Handle_setTabsClosable(HandleRef _this, bool state) {
        TABWIDGET_THIS->setTabsClosable(state);
    }

    bool Handle_usesScrollButtons(HandleRef _this) {
        return TABWIDGET_THIS->usesScrollButtons();
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool state) {
        TABWIDGET_THIS->setUsesScrollButtons(state);
    }

    int Handle_addTab(HandleRef _this, Widget::HandleRef page, const std::string& label) {
        const auto pageWrapper = reinterpret_cast<Widget::SignalWrapper*>(page);
        return TABWIDGET_THIS->addTab(pageWrapper->getActual(), QString::fromStdString(label));
    }

    int Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, const std::string& label) {
        const auto pageWrapper = reinterpret_cast<Widget::SignalWrapper*>(page);
        return TABWIDGET_THIS->insertTab(index, pageWrapper->getActual(), QString::fromStdString(label));
    }

    Widget::HandleRef Handle_widgetAt(HandleRef _this, int32_t index) {
        const auto wrapper = wrapperForQObject(TABWIDGET_THIS->widget(index));
        // technically the wrapper is only guaranteed to be an Object::SignalWrapper, but how could it be in the tabwidget if not a Widget wrapper?
        if (wrapper == nullptr) {
            printf("warning: TabWidget::Handle_widgetAt - couldn't find wrapper for [%p], wat do?\n", wrapper);
        }
        return reinterpret_cast<Widget::HandleRef>(wrapper);
    }

    void Handle_clear(HandleRef _this) {
        TABWIDGET_THIS->clear();
    }

    void Handle_removeTab(HandleRef _this, int32_t index) {
        TABWIDGET_THIS->removeTab(index);
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QTabWidget(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
