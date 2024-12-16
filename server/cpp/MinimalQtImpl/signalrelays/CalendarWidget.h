#pragma once

#include "../generated/CalendarWidget.h"
#include "Widget.h"

namespace CalendarWidget {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Activated, SIGNAL(activated(QDate)), SLOT(onActivated(QDate)) },
            { Clicked, SIGNAL(clicked(QDate)), SLOT(onClicked(QDate)) },
            { CurrentPageChanged, SIGNAL(currentPageChanged(int,int)), SLOT(onCurrentPageChanged(int,int)) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Widget::SignalRelay(relayFor, SignalHandler::as_Widget_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Widget::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
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