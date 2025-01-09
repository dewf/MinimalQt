#include "generated/TabBar.h"
#include "TabBarInternal.h"

#include "ObjectInternal.h"
#include "IconInternal.h"
#include "util/convert.h"

#define THIS (reinterpret_cast<QTabBar*>(_this))

namespace TabBar
{
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
        return THIS->addTab(QICON_VALUE(icon), QString::fromStdString(text));
    }

    SignalConnectionRef Handle_connect_CurrentChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::currentChanged, [handler](int index) {
            handler->currentChanged(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabBarClicked, [handler](int index) {
            handler->tabBarClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabBarDoubleClicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabBarDoubleClicked, [handler](int index) {
            handler->tabBarDoubleClicked(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabCloseRequested(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabCloseRequested, [handler](int index) {
            handler->tabCloseRequested(index);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_TabMoved(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTabBar::tabMoved, [handler](int fromIndex, int toIndex) {
            handler->tabMoved(fromIndex, toIndex);
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QTabBar());
    }
}
