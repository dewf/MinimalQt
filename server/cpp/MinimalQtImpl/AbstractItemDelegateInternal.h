#pragma once

#include "generated/AbstractItemDelegate.h"
#include "ObjectInternal.h"

#include <QAbstractItemDelegate>

namespace AbstractItemDelegate {
    class SignalWrapper : public Object::SignalWrapper {
        Q_OBJECT
    private:
        QAbstractItemDelegate *actual;
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CloseEditor, SIGNAL(closeEditor(QWidget, EndEditHint)), SLOT(onCloseEditor(QWidget,EndEditHint)) },
            { CommitData, SIGNAL(commitData(QWidget)), SLOT(onCommitData(QWidget)) },
            { SizeHintChanged, SIGNAL(sizeHintChanged(QModelIndex)), SLOT(onSizeHintChanged(QModelIndex)) }
        };
    public:
        QAbstractItemDelegate *getActual() const {
            return actual;
        }
        SignalWrapper(QAbstractItemDelegate *existing, const std::shared_ptr<SignalHandler>& handler)
            : Object::SignalWrapper(existing, SignalHandler::as_Object_SignalHandler(handler)),
              actual(existing),
              handler(handler) {}
        void setSignalMask(SignalMask newMask) {
            // update inherited signals
            Object::SignalWrapper::setSignalMask(newMask);
            // continue:
            if (newMask != lastMask) {
                processChanges(lastMask, newMask, signalMap, actual, this);
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
