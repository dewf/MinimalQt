#pragma once

#include "generated/TabBar.h"
#include "WidgetInternal.h"

#include <QTabBar>

namespace TabBar {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QTabBar *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CurrentChanged, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)) },
            { TabBarClicked, SIGNAL(tabBarClicked(int)), SLOT(onTabBarClicked(int)) },
            { TabBarDoubleClicked, SIGNAL(tabBarDoubleClicked(int)), SLOT(onTabBarDoubleClicked(int)) },
            { TabCloseRequested, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)) },
            { TabMoved, SIGNAL(tabMoved(int,int)), SLOT(onTabMoved(int,int)) }
        };
    public:
        QTabBar *getActual() const {
            return actual;
        }
        SignalWrapper(QTabBar *existing, const std::shared_ptr<SignalHandler> &handler)
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
        void onTabMoved(int fromIndex, int toIndex) const {
            handler->tabMoved(fromIndex, toIndex);
        }
    };
}
