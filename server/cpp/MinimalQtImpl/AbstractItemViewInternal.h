#pragma once

#include "generated/AbstractItemView.h"
#include "AbstractScrollAreaInternal.h"
#include "ModelIndexInternal.h"

#include <QAbstractItemView>

namespace AbstractItemView {
    class SignalWrapper : public AbstractScrollArea::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractItemView *actual;
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
        QAbstractItemView *getActual() const {
            return actual;
        }
        SignalWrapper(QAbstractItemView *existing, const std::shared_ptr<SignalHandler>& handler)
            : AbstractScrollArea::SignalWrapper(existing, SignalHandler::as_AbstractScrollArea_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            AbstractScrollArea::SignalWrapper::setSignalMask(newMask);
            // ours:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onActivated(const QModelIndex& index) const {
            ModelIndex::__Handle index2(index);
            handler->activated(&index2);
        }
        void onClicked(const QModelIndex& index) const {
            ModelIndex::__Handle index2(index);
            handler->clicked(&index2);
        }
        void onDoubleClicked(const QModelIndex& index) const {
            ModelIndex::__Handle index2(index);
            handler->doubleClicked(&index2);
        }
        void onEntered(QModelIndex& index) const {
            ModelIndex::__Handle index2(index);
            handler->entered(&index2);
        }
        void onIconSizeChanged(const QSize& size) const {
            handler->iconSizeChanged(toSize(size));
        }
        void onPressed(const QModelIndex& index) const {
            ModelIndex::__Handle index2(index);
            handler->pressed(&index2);
        }
        void onViewportEntered() const {
            handler->viewportEntered();
        }
    };
}
