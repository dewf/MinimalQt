#pragma once

#include "generated/TabWidget.h"
#include "WidgetInternal.h"

#include <QTabWidget>

namespace TabWidget {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CurrentChanged, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)) },
            { TabBarClicked, SIGNAL(tabBarClicked(int)), SLOT(onTabBarClicked(int)) },
            { TabBarDoubleClicked, SIGNAL(tabBarDoubleClicked(int)), SLOT(onTabBarDoubleClicked(int)) },
            { TabCloseRequested, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)) }
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
        void onCurrentChanged(int index) const {
            handler->currentChanged(index);
        }
        void onTabBarClicked(int index) const {
            handler->tabBarClicked(index);
        }
        void onTabBarDoubleClicked(int index) const {
            handler->tabBarDoubleClicked(index);
        }
        void onTabCloseRequested(int index) const {
            handler->tabCloseRequested(index);
        }
    };
}
