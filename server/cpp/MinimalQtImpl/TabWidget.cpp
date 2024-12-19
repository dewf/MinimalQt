#include "generated/TabWidget.h"
#include "TabWidgetInternal.h"

#include <QObject>
#include <QTabWidget>
#include "util/convert.h"

#define THIS ((TabWidgetWithHandler*)_this)

namespace TabWidget
{
    class TabWidgetWithHandler : public QTabWidget {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit TabWidgetWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
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

    // Subclassing stuff =====================================================================================

#define DELEGATED_THIS (reinterpret_cast<DelegatedTabWidget*>(_this))

    class DelegatedTabWidget : public TabWidgetWithHandler {
    private:
        std::shared_ptr<MethodDelegate> methodDelegate;
        MethodMask methodMask = 0;
    public:
        explicit DelegatedTabWidget(const std::shared_ptr<SignalHandler> &handler) : TabWidgetWithHandler(handler) {
        }
        void setDelegate(const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
            this->methodDelegate = methodDelegate;
            this->methodMask = methodMask;
        }
    protected:
        void tabInserted(int index) override {
            if (methodMask & TabInserted) {
                methodDelegate->tabInserted(index);
            } else {
                QTabWidget::tabInserted(index);
            }
        }
        void tabRemoved(int index) override {
            if (methodMask & TabRemoved) {
                methodDelegate->tabRemoved(index);
            } else {
                QTabWidget::tabRemoved(index);
            }
        }
    };

    void Delegated_setDelegate(DelegatedRef _this, const std::shared_ptr<MethodDelegate>& methodDelegate, MethodMask methodMask) {
        DELEGATED_THIS->setDelegate(methodDelegate, methodMask);
    }

    void Delegated_dispose(DelegatedRef _this) {
        delete DELEGATED_THIS;
    }

    DelegatedRef createDelegated(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<DelegatedRef>(new DelegatedTabWidget(handler));
    }
}

#include "TabWidget.moc"
