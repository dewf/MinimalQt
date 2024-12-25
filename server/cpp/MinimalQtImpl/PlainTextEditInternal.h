#pragma once

#include "generated/PlainTextEdit.h"
#include "AbstractScrollAreaInternal.h"

namespace PlainTextEdit {
    class SignalRelay : public AbstractScrollArea::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { BlockCountChanged, SIGNAL(blockCountChanged(int)), SLOT(onBlockCountChanged(int)) },
            { CopyAvailable, SIGNAL(copyAvailable(bool)), SLOT(onCopyAvailable(bool)) },
            { CursorPositionChanged, SIGNAL(cursorPositionChanged()), SLOT(onCursorPositionChanged()) },
            { ModificationChanged, SIGNAL(modificationChanged(bool)), SLOT(onModificationChanged(bool)) },
            { RedoAvailable, SIGNAL(redoAvailable(bool)), SLOT(onRedoAvailable(bool)) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) },
            { TextChanged, SIGNAL(textChanged()), SLOT(onTextChanged()) },
            { UndoAvailable, SIGNAL(undoAvailable(bool)), SLOT(onUndoAvailable(bool)) },
            { UpdateRequest, SIGNAL(updateRequest(QRect,int)), SLOT(onUpdateRequest(QRect,int)) },
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
                processChanges(lastMask, newMask, signalMap, actual, this);
                lastMask = newMask;
            }
        }
    public slots:
        void onBlockCountChanged(int newBlockCount) const {
            handler->blockCountChanged(newBlockCount);
        }
        void onCopyAvailable(bool yes) const {
            handler->copyAvailable(yes);
        }
        void onCursorPositionChanged() const {
            handler->cursorPositionChanged();
        }
        void onModificationChanged(bool changed) const {
            handler->modificationChanged(changed);
        }
        void onRedoAvailable(bool available) const {
            handler->redoAvailable(available);
        }
        void onSelectionChanged() const {
            handler->selectionChanged();
        }
        void onTextChanged() const {
            handler->textChanged();
        }
        void onUndoAvailable(bool available) const {
            handler->undoAvailable(available);
        }
        void onUpdateRequest(const QRect &rect, int dy) const {
            handler->updateRequest(toRect(rect), dy);
        }
    };
}
