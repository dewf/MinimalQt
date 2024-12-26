#pragma once

#include "generated/LineEdit.h"
#include "WidgetInternal.h"

#include <QLineEdit>

namespace LineEdit {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QLineEdit *actual;
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
        QLineEdit *getActual() const {
            return actual;
        }
        SignalWrapper(QLineEdit *existing, const std::shared_ptr<SignalHandler>& handler)
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
