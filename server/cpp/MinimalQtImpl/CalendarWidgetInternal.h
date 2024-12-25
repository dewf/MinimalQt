#pragma once

#include "generated/CalendarWidget.h"
#include "WidgetInternal.h"

#include <QCalendarWidget>

namespace CalendarWidget {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QCalendarWidget *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Activated, SIGNAL(activated(QDate)), SLOT(onActivated(QDate)) },
            { Clicked, SIGNAL(clicked(QDate)), SLOT(onClicked(QDate)) },
            { CurrentPageChanged, SIGNAL(currentPageChanged(int,int)), SLOT(onCurrentPageChanged(int,int)) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) }
        };
    public:
        QCalendarWidget *getActual() {
            return actual;
        }
        SignalWrapper(QCalendarWidget *existing, const std::shared_ptr<SignalHandler>& handler)
            : Widget::SignalWrapper(existing, SignalHandler::as_Widget_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
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
}
