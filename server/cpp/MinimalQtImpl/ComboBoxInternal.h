#pragma once

#include "generated/ComboBox.h"
#include "WidgetInternal.h"

#include <QComboBox>

namespace ComboBox {
    class SignalWrapper : public Widget::SignalWrapper {
        Q_OBJECT
    private:
        QComboBox *actual;
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
        QComboBox *getActual() const {
            return actual;
        }
        SignalWrapper(QComboBox *existing, const std::shared_ptr<SignalHandler>& handler)
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
