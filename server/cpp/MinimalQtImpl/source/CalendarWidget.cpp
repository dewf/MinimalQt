#include "generated/CalendarWidget.h"
#include "CalendarWidgetInternal.h"

#include "ObjectInternal.h"
#include "DateInternal.h"
#include "TextCharFormatInternal.h"

using namespace ::Object;
using namespace ::Widget;
using namespace ::Icon;
using namespace ::Date;
using namespace ::Enums;
using namespace ::TextCharFormat;

#define THIS (reinterpret_cast<QCalendarWidget*>(_this))

namespace CalendarWidget
{
    void Handle_clearMaximumDate(HandleRef _this) {
        THIS->clearMaximumDate();
    }

    void Handle_clearMinimumDate(HandleRef _this) {
        THIS->clearMinimumDate();
    }

    int32_t Handle_dateEditAcceptDelay(HandleRef _this) {
        return THIS->dateEditAcceptDelay();
    }

    std::map<Date::OwnedRef,TextCharFormat::OwnedRef> Handle_dateTextFormat(HandleRef _this) {
        std::map<Date::OwnedRef,TextCharFormat::OwnedRef> ret;
        const auto qMap = THIS->dateTextFormat();
        for (auto i = qMap.begin(); i != qMap.end(); ++i) {
            const auto date = DATE_HEAP_NEW(i.key());
            const auto format = TEXTCHARFORMAT_HEAP_NEW(i.value());
            ret[date] = format;
        }
        return ret;
    }

    TextCharFormat::OwnedRef Handle_dateTextFormat(HandleRef _this, Date::HandleRef date) {
        return TEXTCHARFORMAT_HEAP_NEW(THIS->dateTextFormat(QDATE_VALUE(date)));
    }

    QDayOfWeek Handle_firstDayOfWeek(HandleRef _this) {
        return static_cast<QDayOfWeek>(THIS->firstDayOfWeek());
    }

    TextCharFormat::OwnedRef Handle_headerTextFormat(HandleRef _this) {
        return TEXTCHARFORMAT_HEAP_NEW(THIS->headerTextFormat());
    }

    HorizontalHeaderFormat Handle_getHorizontalHeaderFormat(HandleRef _this) {
        return static_cast<HorizontalHeaderFormat>(THIS->horizontalHeaderFormat());
    }

    bool Handle_isDateEditEnabled(HandleRef _this) {
        return THIS->isDateEditEnabled();
    }

    bool Handle_isGridVisible(HandleRef _this) {
        return THIS->isGridVisible();
    }

    bool Handle_isNavigationBarVisible(HandleRef _this) {
        return THIS->isNavigationBarVisible();
    }

    Date::OwnedRef Handle_maximumDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->maximumDate());
    }

    Date::OwnedRef Handle_minimumDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->minimumDate());
    }

    int32_t Handle_monthShown(HandleRef _this) {
        return THIS->monthShown();
    }

    Date::OwnedRef Handle_selectedDate(HandleRef _this) {
        return DATE_HEAP_NEW(THIS->selectedDate());
    }

    SelectionMode Handle_getSelectionMode(HandleRef _this) {
        return static_cast<SelectionMode>(THIS->selectionMode());
    }

    void Handle_setDateEditAcceptDelay(HandleRef _this, int32_t value) {
        THIS->setDateEditAcceptDelay(value);
    }

    void Handle_setDateEditEnabled(HandleRef _this, bool enabled) {
        THIS->setDateEditEnabled(enabled);
    }

    void Handle_setDateTextFormat(HandleRef _this, Date::HandleRef date, TextCharFormat::HandleRef format) {
        THIS->setDateTextFormat(QDATE_VALUE(date), QTEXTCHARFORMAT_VALUE(format));
    }

    void Handle_setFirstDayOfWeek(HandleRef _this, QDayOfWeek value) {
        THIS->setFirstDayOfWeek(static_cast<Qt::DayOfWeek>(value));
    }

    void Handle_setHeaderTextFormat(HandleRef _this, TextCharFormat::HandleRef format) {
        THIS->setHeaderTextFormat(QTEXTCHARFORMAT_VALUE(format));
    }

    void Handle_setHorizontalHeaderFormat(HandleRef _this, HorizontalHeaderFormat format) {
        THIS->setHorizontalHeaderFormat(static_cast<QCalendarWidget::HorizontalHeaderFormat>(format));
    }

    void Handle_setMaximumDate(HandleRef _this, Date::HandleRef value) {
        THIS->setMaximumDate(QDATE_VALUE(value));
    }

    void Handle_setMinimumDate(HandleRef _this, Date::HandleRef value) {
        THIS->setMinimumDate(QDATE_VALUE(value));
    }

    void Handle_setSelectionMode(HandleRef _this, SelectionMode mode) {
        THIS->setSelectionMode(static_cast<QCalendarWidget::SelectionMode>(mode));
    }

    void Handle_setVerticalHeaderFormat(HandleRef _this, VerticalHeaderFormat format) {
        THIS->setVerticalHeaderFormat(static_cast<QCalendarWidget::VerticalHeaderFormat>(format));
    }

    void Handle_setWeekdayTextFormat(HandleRef _this, QDayOfWeek dayOfWeek, TextCharFormat::HandleRef format) {
        THIS->setWeekdayTextFormat(static_cast<Qt::DayOfWeek>(dayOfWeek), QTEXTCHARFORMAT_VALUE(format));
    }

    VerticalHeaderFormat Handle_getVerticalHeaderFormat(HandleRef _this) {
        return static_cast<VerticalHeaderFormat>(THIS->verticalHeaderFormat());
    }

    TextCharFormat::OwnedRef Handle_weekdayTextFormat(HandleRef _this, QDayOfWeek dayOfWeek) {
        return TEXTCHARFORMAT_HEAP_NEW(THIS->weekdayTextFormat(static_cast<Qt::DayOfWeek>(dayOfWeek)));
    }

    int32_t Handle_yearShown(HandleRef _this) {
        return THIS->yearShown();
    }

    void Handle_setCurrentPage(HandleRef _this, int32_t year, int32_t month) {
        THIS->setCurrentPage(year, month);
    }

    void Handle_setDateRange(HandleRef _this, Date::HandleRef min, Date::HandleRef max) {
        THIS->setDateRange(QDATE_VALUE(min), QDATE_VALUE(max));
    }

    void Handle_setGridVisible(HandleRef _this, bool visible) {
        THIS->setGridVisible(visible);
    }

    void Handle_setNavigationBarVisible(HandleRef _this, bool visible) {
        THIS->setNavigationBarVisible(visible);
    }

    void Handle_setSelectedDate(HandleRef _this, Date::HandleRef selected) {
        THIS->setSelectedDate(QDATE_VALUE(selected));
    }

    void Handle_showNextMonth(HandleRef _this) {
        THIS->showNextMonth();
    }

    void Handle_showNextYear(HandleRef _this) {
        THIS->showNextYear();
    }

    void Handle_showPreviousMonth(HandleRef _this) {
        THIS->showPreviousMonth();
    }

    void Handle_showPreviousYear(HandleRef _this) {
        THIS->showPreviousYear();
    }

    void Handle_showSelectedDate(HandleRef _this) {
        THIS->showSelectedDate();
    }

    void Handle_showToday(HandleRef _this) {
        THIS->showToday();
    }

    SignalConnectionRef Handle_connect_Activated(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::activated, [handler](const QDate& date) {
            QDate date2(date);
            handler->sig_activated(reinterpret_cast<Date::HandleRef>(&date2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_Clicked(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::clicked, [handler](const QDate& date) {
            QDate date2(date);
            handler->sig_clicked(reinterpret_cast<Date::HandleRef>(&date2));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CurrentPageChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::currentPageChanged, [handler](int year, int month) {
            handler->sig_currentPageChanged(year, month);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_SelectionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QCalendarWidget::selectionChanged, [handler] {
            handler->sig_selectionChanged();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    void* Handle_staticCast(HandleRef obj, Handle_CastTarget target) {
        auto cal = AS_QCALENDARWIDGET_PTR(obj);
        switch (target)
        {
        case Handle_CastTarget::Object_Handle:
            return static_cast<QObject*>(cal);
        case Handle_CastTarget::Widget_Handle:
            return static_cast<QWidget*>(cal);
        }
        std::unreachable();
    }

    HandleRef create(Widget::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QCalendarWidget(AS_QWIDGET_PTR(parent)));
    }
}
