#pragma once

#include "generated/StatusBar.h"
#include "WidgetInternal.h"

#include <QStatusBar>

namespace StatusBar {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QStatusBar *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { MessageChanged, SIGNAL(messageChanged(QString)), SLOT(onMessageChanged(QString)) },
        };
    public:
        QStatusBar *getActual() const {
            return actual;
        }
        SignalWrapper(QStatusBar *existing, const std::shared_ptr<SignalHandler> &handler)
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
        void onMessageChanged(const QString& message) const {
            handler->messageChanged(message.toStdString());
        };
    };
}
