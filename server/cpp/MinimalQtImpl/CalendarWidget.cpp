#include "generated/CalendarWidget.h"
#include "CalendarWidgetInternal.h"

#include <QCalendarWidget>
#include <utility>

#include "DateInternal.h"

#define THIS ((CalendarWidgetWithHandler*)_this)

namespace CalendarWidget
{
    class CalendarWidgetWithHandler : public QCalendarWidget {
        Q_OBJECT
    private:
        SignalRelay relay;
    public:
        explicit CalendarWidgetWithHandler(const std::shared_ptr<SignalHandler>& handler) : relay(this, handler) {}
        void setSignalMask(SignalMask newMask) {
            relay.setSignalMask(newMask);
        }
    };

    void Handle_setDateEditAcceptDelay(HandleRef _this, int32_t value) {
        THIS->setDateEditAcceptDelay(value);
    }

    void Handle_setDateEditEnabled(HandleRef _this, bool enabled) {
        THIS->setDateEditEnabled(enabled);
    }

    void Handle_setFirstDayOfWeek(HandleRef _this, QDayOfWeek value) {
        THIS->setFirstDayOfWeek(static_cast<Qt::DayOfWeek>(value));
    }

    void Handle_setGridVisible(HandleRef _this, bool visible) {
        THIS->setGridVisible(visible);
    }

    void Handle_setHorizontalHeaderFormat(HandleRef _this, HorizontalHeaderFormat format) {
        THIS->setHorizontalHeaderFormat(static_cast<QCalendarWidget::HorizontalHeaderFormat>(format));
    }

    void Handle_setMaximumDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& value) {
        THIS->setMaximumDate(Date::fromDeferred(value));
    }

    void Handle_setMinimumDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& value) {
        THIS->setMinimumDate(Date::fromDeferred(value));
    }

    void Handle_setNavigationBarVisible(HandleRef _this, bool visible) {
        THIS->setNavigationBarVisible(visible);
    }

    Date::OwnedRef Handle_selectedDate(HandleRef _this) {
        return reinterpret_cast<Date::OwnedRef>(new QDate(THIS->selectedDate()));
    }

    void Handle_setSelectedDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& selected) {
        THIS->setSelectedDate(Date::fromDeferred(selected));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QCalendarWidget::SelectionMode>(mode));
    }

    void Handle_setVerticalHeaderFormat(HandleRef _this, VerticalHeaderFormat format) {
        THIS->setVerticalHeaderFormat(static_cast<QCalendarWidget::VerticalHeaderFormat>(format));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new CalendarWidgetWithHandler(handler));
    }
}

#include "CalendarWidget.moc"
