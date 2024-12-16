#pragma once

#include "../generated/AbstractItemDelegate.h"
#include "Object.h"

#include <QAbstractItemDelegate>

namespace AbstractItemDelegate {
    class SignalRelay : public Object::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CloseEditor, SIGNAL(closeEditor(QWidget, EndEditHint)), SLOT(onCloseEditor(QWidget,EndEditHint)) },
            { CommitData, SIGNAL(commitData(QWidget)), SLOT(onCommitData(QWidget)) },
            { SizeHintChanged, SIGNAL(sizeHintChanged(QModelIndex)), SLOT(onSizeHintChanged(QModelIndex)) }
        };
    public:
        explicit SignalRelay(QObject *relayFor, const std::shared_ptr<SignalHandler> &handler) :
            Object::SignalRelay(relayFor, SignalHandler::as_Object_SignalHandler(handler)),
            handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalRelay::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, relayFor, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onCloseEditor(QWidget *editor, QAbstractItemDelegate::EndEditHint hint = QAbstractItemDelegate::NoHint) const {
            handler->closeEditor(reinterpret_cast<Widget::HandleRef>(editor), static_cast<AbstractItemDelegate::EndEditHint>(hint));
        }
        void onCommitData(QWidget *editor) const {
            handler->commitData(reinterpret_cast<Widget::HandleRef>(editor));
        }
        void onSizeHintChanged(const QModelIndex &index) const {
            handler->sizeHintChanged((ModelIndex::HandleRef)&index);
        }
    };
}
