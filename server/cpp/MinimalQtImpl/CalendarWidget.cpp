#include "generated/CalendarWidget.h"
#include "CalendarWidgetInternal.h"

#include <QCalendarWidget>
#include <utility>

#include "DateInternal.h"

#define WRAPPER (reinterpret_cast<SignalWrapper*>(_this))
#define CALENDAR_THIS (WRAPPER->getActual())

namespace CalendarWidget
{
    int32_t Handle_dateEditAcceptDelay(HandleRef _this) {
        return CALENDAR_THIS->dateEditAcceptDelay();
    }

    void Handle_setDateEditAcceptDelay(HandleRef _this, int32_t value) {
        CALENDAR_THIS->setDateEditAcceptDelay(value);
    }

    bool Handle_isDateEditEnabled(HandleRef _this) {
        return CALENDAR_THIS->isDateEditEnabled();
    }

    void Handle_setDateEditEnabled(HandleRef _this, bool enabled) {
        CALENDAR_THIS->setDateEditEnabled(enabled);
    }

    QDayOfWeek Handle_firstDayOfWeek(HandleRef _this) {
        return static_cast<QDayOfWeek>(CALENDAR_THIS->firstDayOfWeek());
    }

    void Handle_setFirstDayOfWeek(HandleRef _this, QDayOfWeek value) {
        CALENDAR_THIS->setFirstDayOfWeek(static_cast<Qt::DayOfWeek>(value));
    }

    bool Handle_isGridVisible(HandleRef _this) {
        return CALENDAR_THIS->isGridVisible();
    }

    void Handle_setGridVisible(HandleRef _this, bool visible) {
        CALENDAR_THIS->setGridVisible(visible);
    }

    HorizontalHeaderFormat Handle_getHorizontalHeaderFormat(HandleRef _this) {
        return static_cast<HorizontalHeaderFormat>(CALENDAR_THIS->horizontalHeaderFormat());
    }

    void Handle_setHorizontalHeaderFormat(HandleRef _this, HorizontalHeaderFormat format) {
        CALENDAR_THIS->setHorizontalHeaderFormat(static_cast<QCalendarWidget::HorizontalHeaderFormat>(format));
    }

    Date::OwnedRef Handle_maximumDate(HandleRef _this) {
        return DATE_HEAP_NEW(CALENDAR_THIS->maximumDate());
    }

    void Handle_setMaximumDate(HandleRef _this, Date::HandleRef value) {
        CALENDAR_THIS->setMaximumDate(QDATE_VALUE(value));
    }

    void Handle_clearMaximumDate(HandleRef _this) {
        CALENDAR_THIS->clearMaximumDate();
    }

    Date::OwnedRef Handle_minimumDate(HandleRef _this) {
        return DATE_HEAP_NEW(CALENDAR_THIS->minimumDate());
    }

    void Handle_setMinimumDate(HandleRef _this, Date::HandleRef value) {
        CALENDAR_THIS->setMinimumDate(QDATE_VALUE(value));
    }

    void Handle_clearMinimumDate(HandleRef _this) {
        CALENDAR_THIS->clearMinimumDate();
    }

    int32_t Handle_monthShown(HandleRef _this) {
        return CALENDAR_THIS->monthShown();
    }

    bool Handle_isNavigationBarVisible(HandleRef _this) {
        return CALENDAR_THIS->isNavigationBarVisible();
    }

    void Handle_setNavigationBarVisible(HandleRef _this, bool visible) {
        CALENDAR_THIS->setNavigationBarVisible(visible);
    }

    Date::OwnedRef Handle_selectedDate(HandleRef _this) {
        return DATE_HEAP_NEW(CALENDAR_THIS->selectedDate());
    }

    void Handle_setSelectedDate(HandleRef _this, Date::HandleRef selected) {
        CALENDAR_THIS->setSelectedDate(QDATE_VALUE(selected));
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(CALENDAR_THIS->selectionMode());
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        CALENDAR_THIS->setSelectionMode(static_cast<QCalendarWidget::SelectionMode>(mode));
    }

    VerticalHeaderFormat Handle_getVerticalHeaderFormat(HandleRef _this) {
        return static_cast<VerticalHeaderFormat>(CALENDAR_THIS->verticalHeaderFormat());
    }

    void Handle_setVerticalHeaderFormat(HandleRef _this, VerticalHeaderFormat format) {
        CALENDAR_THIS->setVerticalHeaderFormat(static_cast<QCalendarWidget::VerticalHeaderFormat>(format));
    }

    int32_t Handle_yearShown(HandleRef _this) {
        return CALENDAR_THIS->yearShown();
    }

    // ============================================

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
