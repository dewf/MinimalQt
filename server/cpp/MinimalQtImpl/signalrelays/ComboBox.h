#pragma once

#include "../generated/ComboBox.h"
#include "Widget.h"

namespace ComboBox {
    class SignalRelay : public Widget::SignalRelay {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            { Activated, SIGNAL(activated(int)), SLOT(onActivated(int)) },
            { CurrentIndexChanged, SIGNAL(currentIndexChanged(int)), SLOT(onCurrentIndexChanged(int)) },
            { CurrentTextChanged, SIGNAL(currentTextChanged(QString)), SLOT(onCurrentTextChanged(QString)) },
            { EditTextChanged, SIGNAL(editTextChanged(QString)), SLOT(onEditTextChanged(QString)) },
            { Highlighted, SIGNAL(highlighted(int)), SLOT(onHighlighted(int)) },
            { TextActivated, SIGNAL(textActivated(QString)), SLOT(onTextActivated(QString)) },
            { TextHighlighted, SIGNAL(textHighlighted(QString)), SLOT(onTextHighlighted(QString)) },
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
        void onActivated(int index) const {
            handler->activated(index);
        }
        void onCurrentIndexChanged(int index) const {
            handler->currentIndexChanged(index);
        }
        void onCurrentTextChanged(const QString& text) const {
            handler->currentTextChanged(text.toStdString());
        }
        void onEditTextChanged(const QString& text) const {
            handler->editTextChanged(text.toStdString());
        }
        void onHighlighted(int index) const {
            handler->highlighted(index);
        }
        void onTextActivated(const QString& text) const {
            handler->textActivated(text.toStdString());
        }
        void onTextHighlighted(const QString& text) const {
            handler->textHighlighted(text.toStdString());
        }
    };
}
