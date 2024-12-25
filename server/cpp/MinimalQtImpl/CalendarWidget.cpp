#include "generated/CalendarWidget.h"
#include "CalendarWidgetInternal.h"

#include <QCalendarWidget>
#include <utility>

#include "DateInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define CALENDAR_THIS (WRAPPER->getActual())

namespace CalendarWidget
{
    void Handle_setDateEditAcceptDelay(HandleRef _this, int32_t value) {
        CALENDAR_THIS->setDateEditAcceptDelay(value);
    }

    void Handle_setDateEditEnabled(HandleRef _this, bool enabled) {
        CALENDAR_THIS->setDateEditEnabled(enabled);
    }

    void Handle_setFirstDayOfWeek(HandleRef _this, QDayOfWeek value) {
        CALENDAR_THIS->setFirstDayOfWeek(static_cast<Qt::DayOfWeek>(value));
    }

    void Handle_setGridVisible(HandleRef _this, bool visible) {
        CALENDAR_THIS->setGridVisible(visible);
    }

    void Handle_setHorizontalHeaderFormat(HandleRef _this, HorizontalHeaderFormat format) {
        CALENDAR_THIS->setHorizontalHeaderFormat(static_cast<QCalendarWidget::HorizontalHeaderFormat>(format));
    }

    void Handle_setMaximumDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& value) {
        CALENDAR_THIS->setMaximumDate(Date::fromDeferred(value));
    }

    void Handle_setMinimumDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& value) {
        CALENDAR_THIS->setMinimumDate(Date::fromDeferred(value));
    }

    void Handle_setNavigationBarVisible(HandleRef _this, bool visible) {
        CALENDAR_THIS->setNavigationBarVisible(visible);
    }

    Date::OwnedRef Handle_selectedDate(HandleRef _this) {
        return reinterpret_cast<Date::OwnedRef>(new QDate(CALENDAR_THIS->selectedDate()));
    }

    void Handle_setSelectedDate(HandleRef _this, const std::shared_ptr<Date::Deferred::Base>& selected) {
        CALENDAR_THIS->setSelectedDate(Date::fromDeferred(selected));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        CALENDAR_THIS->setSelectionMode(static_cast<QCalendarWidget::SelectionMode>(mode));
    }

    void Handle_setVerticalHeaderFormat(HandleRef _this, VerticalHeaderFormat format) {
        CALENDAR_THIS->setVerticalHeaderFormat(static_cast<QCalendarWidget::VerticalHeaderFormat>(format));
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        WRAPPER->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete WRAPPER;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        const auto wrapper = new SignalWrapper(new QCalendarWidget(), handler);
        return reinterpret_cast<HandleRef>(wrapper);
    }
}

#include "CalendarWidget.moc"
