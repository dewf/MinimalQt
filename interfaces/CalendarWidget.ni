module CalendarWidget;

import Object;
import Widget;
import Icon;
import Date;
import Enums;
import TextCharFormat;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void activated(Date.Handle date);
    void clicked(Date.Handle date);
    void currentPageChanged(int year, int month);
    void selectionChanged();
}

enum HorizontalHeaderFormat {
    NoHorizontalHeader,
    SingleLetterDayNames,
    ShortDayNames,
    LongDayNames
}

enum VerticalHeaderFormat {
    NoVerticalHeader,
    ISOWeekNumbers
}

enum SelectionMode {
    NoSelection,
    SingleSelection
}

opaque Handle extends Widget.Handle {

    // QCalendar calendar() const
    // TODO

    void clearMaximumDate();
    void clearMinimumDate();
    int dateEditAcceptDelay();
    Map<Date.Owned, TextCharFormat.Owned> dateTextFormat();
    TextCharFormat.Owned dateTextFormat(Date.Handle date);
    QDayOfWeek firstDayOfWeek();
    TextCharFormat.Owned headerTextFormat();
    HorizontalHeaderFormat getHorizontalHeaderFormat();
    bool isDateEditEnabled();
    bool isGridVisible();
    bool isNavigationBarVisible();
    Date.Owned maximumDate();
    Date.Owned minimumDate();
    int monthShown();
    Date.Owned selectedDate();
    SelectionMode getSelectionMode();

    // void setCalendar(QCalendar c)
    // TODO

    void setDateEditAcceptDelay(int delay);
    void setDateEditEnabled(bool enable);
    void setDateTextFormat(Date.Handle date, TextCharFormat.Handle format);
    void setFirstDayOfWeek(QDayOfWeek dayOfWeek);
    void setHeaderTextFormat(TextCharFormat.Handle format);
    void setHorizontalHeaderFormat(HorizontalHeaderFormat format);
    void setMaximumDate(Date.Handle date);
    void setMinimumDate(Date.Handle date);
    void setSelectionMode(SelectionMode mode);
    void setVerticalHeaderFormat(VerticalHeaderFormat format);
    void setWeekdayTextFormat(QDayOfWeek dayOfWeek, TextCharFormat.Handle format);
    VerticalHeaderFormat getVerticalHeaderFormat();
    TextCharFormat.Owned weekdayTextFormat(QDayOfWeek dayOfWeek);
    int yearShown();

    void setCurrentPage(int year, int month);
    void setDateRange(Date.Handle min, Date.Handle max);
    void setGridVisible(bool show);
    void setNavigationBarVisible(bool visible);
    void setSelectedDate(Date.Handle date);
    void showNextMonth();
    void showNextYear();
    void showPreviousMonth();
    void showPreviousYear();
    void showSelectedDate();
    void showToday();

    // signals ============================
    SignalConnection connect_Activated(SignalHandler handler);
    SignalConnection connect_Clicked(SignalHandler handler);
    SignalConnection connect_CurrentPageChanged(SignalHandler handler);
    SignalConnection connect_SelectionChanged(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
