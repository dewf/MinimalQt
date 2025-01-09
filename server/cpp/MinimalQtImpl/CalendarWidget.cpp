#include "generated/CalendarWidget.h"
#include "CalendarWidgetInternal.h"

#include "DateInternal.h"

#define THIS (reinterpret_cast<QCalendarWidget*>(_this))

namespace CalendarWidget
{
    int32_t Handle_dateEditAcceptDelay(HandleRef _this) {
        return THIS->dateEditAcceptDelay();
    }

    void Handle_setDateEditAcceptDelay(HandleRef _this, int32_t value) {
        THIS->setDateEditAcceptDelay(value);
    }

    bool Handle_isDateEditEnabled(HandleRef _this) {
        return THIS->isDateEditEnabled();
    }

    void Handle_setDateEditEnabled(HandleRef _this, bool enabled) {
        THIS->setDateEditEnabled(enabled);
    }

    QDayOfWeek Handle_firstDayOfWeek(HandleRef _this) {
        return static_cast<QDayOfWeek>(THIS->firstDayOfWeek());
    }

    void Handle_setFirstDayOfWeek(HandleRef _this, QDayOfWeek value) {
        THIS->setFirstDayOfWeek(static_cast<Qt::DayOfWeek>(value));
    }

    bool Handle_isGridVisible(HandleRef _this) {
        return THIS->isGridVisible();
    }

    void Handle_setGridVisible(HandleRef _this, bool visible) {
        THIS->setGridVisible(visible);
    }

    HorizontalHeaderFormat Handle_getHorizontalHeaderFormat(HandleRef _this) {
        return static_cast<HorizontalHeaderFormat>(THIS->horizontalHeaderFormat());
    }

    void Handle_setHorizontalHeaderFormat(HandleRef _this, HorizontalHeaderFormat format) {
        THIS->setHorizontalHeaderFormat(static_cast<QCalendarWidget::HorizontalHeaderFormat>(format));
    }

    Date::OwnedRef Handle_maximumDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->maximumDate());
    }

    void Handle_setMaximumDate(HandleRef _this, Date::HandleRef value) {
        THIS->setMaximumDate(QDATE_VALUE(value));
    }

    void Handle_clearMaximumDate(HandleRef _this) {
        THIS->clearMaximumDate();
    }

    Date::OwnedRef Handle_minimumDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->minimumDate());
    }

    void Handle_setMinimumDate(HandleRef _this, Date::HandleRef value) {
        THIS->setMinimumDate(QDATE_VALUE(value));
    }

    void Handle_clearMinimumDate(HandleRef _this) {
        THIS->clearMinimumDate();
    }

    int32_t Handle_monthShown(HandleRef _this) {
        return THIS->monthShown();
    }

    bool Handle_isNavigationBarVisible(HandleRef _this) {
        return THIS->isNavigationBarVisible();
    }

    void Handle_setNavigationBarVisible(HandleRef _this, bool visible) {
        THIS->setNavigationBarVisible(visible);
    }

    Date::OwnedRef Handle_selectedDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->selectedDate());
    }

    void Handle_setSelectedDate(HandleRef _this, Date::HandleRef selected) {
        THIS->setSelectedDate(QDATE_VALUE(selected));
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(THIS->selectionMode());
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QCalendarWidget::SelectionMode>(mode));
    }

    VerticalHeaderFormat Handle_getVerticalHeaderFormat(HandleRef _this) {
        return static_cast<VerticalHeaderFormat>(THIS->verticalHeaderFormat());
    }

    void Handle_setVerticalHeaderFormat(HandleRef _this, VerticalHeaderFormat format) {
        THIS->setVerticalHeaderFormat(static_cast<QCalendarWidget::VerticalHeaderFormat>(format));
    }

    int32_t Handle_yearShown(HandleRef _this) {
        return THIS->yearShown();
    }

    SignalConnectionRef Handle_connect_Activated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::activated, [handler](const QDate& date) {
            handler->activated((Date::HandleRef)&date);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::clicked, [handler](const QDate& date) {
            handler->activated((Date::HandleRef)&date);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentPageChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::currentPageChanged, [handler](int year, int month) {
            handler->currentPageChanged(year, month);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::selectionChanged, [handler] {
            handler->selectionChanged();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create() {
        return reinterpret_cast<HandleRef>(new QCalendarWidget());
    }
}
