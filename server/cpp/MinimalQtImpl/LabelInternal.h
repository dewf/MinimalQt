#pragma once

#include "generated/Label.h"
#include "FrameInternal.h"

namespace Label {
    class SignalRelay : public Frame::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { LinkActivated, SIGNAL(linkActivated(QString)), SLOT(onLinkActivated(QString)) },
            { LinkHovered, SIGNAL(linkHovered(QString)), SLOT(onLinkHovered(QString)) },
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Frame::SignalRelay(relayFor, SignalHandler::as_Frame_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Frame::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onLinkActivated(const QString& link) const {
            handler->linkActivated(link.toStdString());
        }
        void onLinkHovered(const QString& link) const {
            handler->linkHovered(link.toStdString());
        }
    };
}
