#pragma once

#include "generated/LineEdit.h"
#include "WidgetInternal.h"

namespace LineEdit {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { CursorPositionChanged, SIGNAL(cursorPositionChanged(int, int)), SLOT(onCursorPositionChanged(int,int)) },
            { EditingFinished, SIGNAL(editingFinished()), SLOT(onEditingFinished()) },
            { InputRejected, SIGNAL(inputRejected()), SLOT(onInputRejected()) },
            { ReturnPressed, SIGNAL(returnPressed()), SLOT(onReturnPressed()) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) },
            { TextChanged, SIGNAL(textChanged(QString)), SLOT(onTextChanged(QString)) },
            { TextEdited, SIGNAL(textEdited(QString)), SLOT(onTextEdited(QString)) }
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
        void onCursorPositionChanged(int oldPos, int newPos) const {
            handler->cursorPositionChanged(oldPos, newPos);
        };
        void onEditingFinished() const {
            handler->editingFinished();
        }
        void onInputRejected() const {
            handler->inputRejected();
        }
        void onReturnPressed() const {
            handler->returnPressed();
        }
        void onSelectionChanged() const {
            handler->selectionChanged();
        }
        void onTextChanged(const QString& text) const {
            handler->textChanged(text.toStdString());
        }
        void onTextEdited(const QString& text) const {
            handler->textEdited(text.toStdString());
        }
    };
}
