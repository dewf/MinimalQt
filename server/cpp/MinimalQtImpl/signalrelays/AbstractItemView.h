#pragma once

#include "../generated/AbstractItemView.h"
#include "AbstractScrollArea.h"

namespace AbstractItemView {
    class SignalRelay : public AbstractScrollArea::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Activated, SIGNAL(activated(QModelIndex)), SLOT(onActivated(QModelIndex)) },
            { Clicked, SIGNAL(clicked(QModelIndex)), SLOT(onClicked(QModelIndex)) },
            { DoubleClickedBit, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)) },
            { Entered, SIGNAL(entered(QModelIndex)), SLOT(onEntered(QModelIndex)) },
            { IconSizeChanged, SIGNAL(iconSizeChanged(QSize)), SLOT(onIconSizeChanged(QSize)) },
            { Pressed, SIGNAL(pressed(QModelIndex)), SLOT(onPressed(QModelIndex)) },
            { ViewportEntered, SIGNAL(viewportEntered()), SLOT(onViewportEntered) },
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            AbstractScrollArea::SignalRelay(relayFor, SignalHandler::as_AbstractScrollArea_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractScrollArea::SignalRelay::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onActivated(const QModelIndex& index) const {
            handler->activated((ModelIndex::HandleRef)&index);
        }
        void onClicked(const QModelIndex& index) const {
            handler->clicked((ModelIndex::HandleRef)&index);
        }
        void onDoubleClicked(const QModelIndex& index) const {
            handler->doubleClicked((ModelIndex::HandleRef)&index);
        }
        void onEntered(QModelIndex& index) const {
            handler->entered((ModelIndex::HandleRef)&index);
        }
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onPressed(const QModelIndex& index) const {
            handler->pressed((ModelIndex::HandleRef)&index);
        }
        void onViewportEntered() const {
            handler->viewportEntered();
        }
    };
}
