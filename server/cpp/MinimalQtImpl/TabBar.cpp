#include "generated/TabBar.h"
#include "TabBarInternal.h"

#include "util/convert.h"
#include "IconInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define TABBAR_THIS (WRAPPER->getActual())

namespace TabBar
{
    void Handle_setAutoHide(HandleRef _this, bool value) {
        TABBAR_THIS->setAutoHide(value);
    }

    void Handle_setChangeCurrentOnDrag(HandleRef _this, bool value) {
        TABBAR_THIS->setChangeCurrentOnDrag(value);
    }

    int32_t Handle_count(HandleRef _this) {
        return TABBAR_THIS->count();
    }

    void Handle_setCurrentIndex(HandleRef _this, int32_t value) {
        TABBAR_THIS->setCurrentIndex(value);
    }

    int32_t Handle_currentIndex(HandleRef _this) {
        return TABBAR_THIS->currentIndex();
    }

    void Handle_setDocumentMode(HandleRef _this, bool value) {
        TABBAR_THIS->setDocumentMode(value);
    }

    void Handle_setDrawBase(HandleRef _this, bool value) {
        TABBAR_THIS->setDrawBase(value);
    }

    void Handle_setElideMode(HandleRef _this, TextElideMode mode) {
        TABBAR_THIS->setElideMode(static_cast<Qt::TextElideMode>(mode));
    }

    void Handle_setExpanding(HandleRef _this, bool value) {
        TABBAR_THIS->setExpanding(value);
    }

    void Handle_setIconSize(HandleRef _this, Size size) {
        TABBAR_THIS->setIconSize(toQSize(size));
    }

    void Handle_setMovable(HandleRef _this, bool value) {
        TABBAR_THIS->setMovable(value);
    }

    void Handle_setSelectionBehaviorOnRemove(HandleRef _this, SelectionBehavior value) {
        TABBAR_THIS->setSelectionBehaviorOnRemove(static_cast<QTabBar::SelectionBehavior>(value));
    }

    void Handle_setShape(HandleRef _this, Shape shape) {
        TABBAR_THIS->setShape(static_cast<QTabBar::Shape>(shape));
    }

    void Handle_setTabsClosable(HandleRef _this, bool value) {
        TABBAR_THIS->setTabsClosable(value);
    }

    void Handle_setUsesScrollButtons(HandleRef _this, bool value) {
        TABBAR_THIS->setUsesScrollButtons(value);
    }

    void Handle_removeAllTabs(HandleRef _this) {
        auto count = TABBAR_THIS->count();
        for (auto i=0; i< count; i++) {
            TABBAR_THIS->removeTab(0);
        }
    }

    int32_t Handle_addTab(HandleRef _this, const std::string& text) {
        return TABBAR_THIS->addTab(QString::fromStdString(text));
    }

    int32_t Handle_addTab(HandleRef _this, Icon::HandleRef icon, const std::string& text) {
        return TABBAR_THIS->addTab(QICON_VALUE(icon), QString::fromStdString(text));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QTabBar(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}
