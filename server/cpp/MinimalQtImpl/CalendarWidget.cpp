#include "generated/CalendarWidget.h"

#include <QCalendarWidget>
#include <utility>

#include "util/SignalStuff.h"
#include "util/convert.h"
#include "IconInternal.h"
#include "DateInternal.h"

#define THIS ((CalendarWidgetWithHandler*)_this)

namespace CalendarWidget
{
    class CalendarWidgetWithHandler : public QCalendarWidget {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // CalendarWidget:
            { Activated, SIGNAL(activated(QDate)), SLOT(onActivated(QDate)) },
            { Clicked, SIGNAL(clicked(QDate)), SLOT(onClicked(QDate)) },
            { CurrentPageChanged, SIGNAL(currentPageChanged(int,int)), SLOT(onCurrentPageChanged(int,int)) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) }
        };
    public:
        explicit CalendarWidgetWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // CalendarWidget ===========
        void onActivated(const QDate& date) const {
            handler->activated((Date::HandleRef)&date);
        }
        void onClicked(const QDate& date) const {
            handler->clicked((Date::HandleRef)&date);
        }
        void onCurrentPageChanged(int year, int month) const {
            handler->currentPageChanged(year, month);
        }
        void onSelectionChanged() const {
            handler->selectionChanged();
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
