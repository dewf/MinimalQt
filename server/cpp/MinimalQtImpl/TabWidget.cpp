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

    void Handle_setCurrentIndex(HandleRef _this, int32_t index) {
        TABWIDGET_THIS->setCurrentIndex(index);
    }

    void Handle_setDocumentMode(HandleRef _this, bool state) {
        TABWIDGET_THIS->setDocumentMode(state);
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        TABWIDGET_THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        TABWIDGET_THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool state) {
        TABWIDGET_THIS->setMovable(state);
    }

    void Handle_setTabBarAutoHide(HandleRef _this, bool state) {
        TABWIDGET_THIS->setTabBarAutoHide(state);
    }

    void Handle_setTabPosition(HandleRef _this, TabPosition position) {
        TABWIDGET_THIS->setTabPosition(static_cast<QTabWidget::TabPosition>(position));
    }

    void Handle_setTabShape(HandleRef _this, TabShape shape) {
        TABWIDGET_THIS->setTabShape(static_cast<QTabWidget::TabShape>(shape));
    }

    void Handle_setTabsClosable(HandleRef _this, bool state) {
        TABWIDGET_THIS->setTabsClosable(state);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool state) {
        TABWIDGET_THIS->setUsesScrollButtons(state);
    }

    int Handle_addTab(HandleRef _this, Widget::HandleRef page, const std::string& label) {
        auto pageWrapper = reinterpret_cast<Widget::SignalWrapper*>(page);
        return TABWIDGET_THIS->addTab(pageWrapper->getActual(), QString::fromStdString(label));
    }

    int Handle_insertTab(HandleRef _this, int32_t index, Widget::HandleRef page, const std::string& label) {
        auto pageWrapper = reinterpret_cast<Widget::SignalWrapper*>(page);
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
