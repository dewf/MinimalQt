#include "generated/TabBar.h"
#include "TabBarInternal.h"

#include <QObject>
#include <QTabBar>
#include <utility>

#include "util/convert.h"
#include "IconInternal.h"

#define THIS ((TabBarWithHandler*)_this)

namespace TabBar
{
    class TabBarWithHandler : public QTabBar {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit TabBarWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
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
        return THIS->addTab(QICON_VALUE(icon), QString::fromStdString(text));
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
