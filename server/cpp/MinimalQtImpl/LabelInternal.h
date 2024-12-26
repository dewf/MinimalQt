#pragma once

#include "generated/Label.h"
#include "FrameInternal.h"

#include <QLabel>

namespace Label {
    class SignalWrapper : public Frame::SignalWrapper {
        Q_OBJECT
    private:
        QLabel *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { LinkActivated, SIGNAL(linkActivated(QString)), SLOT(onLinkActivated(QString)) },
            { LinkHovered, SIGNAL(linkHovered(QString)), SLOT(onLinkHovered(QString)) },
        };
    public:
        QLabel *getActual() const {
            return actual;
        }
        SignalWrapper(QLabel *existing, const std::shared_ptr<SignalHandler>& handler)
            : Frame::SignalWrapper(existing, SignalHandler::as_Frame_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Frame::SignalWrapper::setSignalMask(newMask);
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
