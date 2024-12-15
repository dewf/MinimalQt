#include "generated/LineEdit.h"

#include <QObject>
#include <QLineEdit>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((LineEditWithHandler*)_this)

namespace LineEdit
{
    class LineEditWithHandler : public QLineEdit {
        Q_OBJECT
    private:
        std::shared_ptr<SignalHandler> handler;
        SignalMask lastMask = 0;
        std::vector<SignalMapItem<SignalMaskFlags>> signalMap = {
            // Object:
            { Destroyed, SIGNAL(destroyed(QObject)), SLOT(onDestroyed(QObject)) },
            { ObjectNameChanged, SIGNAL(objectNameChanged(QString)), SLOT(onObjectNameChanged(QString)) },
            // Widget:
            { CustomContextMenuRequested, SIGNAL(customContextMenuRequested(QPoint)), SLOT(onCustomContextMenuRequested(QPoint)) },
            { WindowIconChanged, SIGNAL(windowIconChanged(QIcon)), SLOT(onWindowIconChanged(QIcon)) },
            { WindowTitleChanged, SIGNAL(windowTitleChanged(QString)), SLOT(onWindowTitleChanged(QString)) },
            // LineEdit
            { CursorPositionChanged, SIGNAL(cursorPositionChanged(int, int)), SLOT(onCursorPositionChanged(int,int)) },
            { EditingFinished, SIGNAL(editingFinished()), SLOT(onEditingFinished()) },
            { InputRejected, SIGNAL(inputRejected()), SLOT(onInputRejected()) },
            { ReturnPressed, SIGNAL(returnPressed()), SLOT(onReturnPressed()) },
            { SelectionChanged, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()) },
            { TextChanged, SIGNAL(textChanged(QString)), SLOT(onTextChanged(QString)) },
            { TextEdited, SIGNAL(textEdited(QString)), SLOT(onTextEdited(QString)) }
        };
    public:
        explicit LineEditWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
        void setSignalMask(SignalMask newMask) {
            if (newMask != lastMask) {
                processChanged_OLD(lastMask, newMask, signalMap, this);
                lastMask = newMask;
            }
        }
    public slots:
        // Object =================
        void onDestroyed(QObject *obj) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // LineEdit =================
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

    bool Handle_hasAcceptableInput(HandleRef _this) {
        return THIS->hasAcceptableInput();
    }

    void Handle_setAlignment(HandleRef _this, Enums::Alignment align) {
        THIS->setAlignment(static_cast<Qt::Alignment>(align));
    }

    void Handle_setClearButtonEnabled(HandleRef _this, bool enabled) {
        THIS->setClearButtonEnabled(enabled);
    }

    void Handle_setCursorMoveStyle(HandleRef _this, CursorMoveStyle style) {
        THIS->setCursorMoveStyle(static_cast<Qt::CursorMoveStyle>(style));
    }

    void Handle_setCursorPosition(HandleRef _this, int32_t pos) {
        THIS->setCursorPosition(pos);
    }

    std::string Handle_displayText(HandleRef _this) {
        return THIS->displayText().toStdString();
    }

    void Handle_setDragEnabled(HandleRef _this, bool enabled) {
        THIS->setDragEnabled(enabled);
    }

    void Handle_setEchoMode(HandleRef _this, EchoMode mode) {
        THIS->setEchoMode(static_cast<QLineEdit::EchoMode>(mode));
    }

    void Handle_setFrame(HandleRef _this, bool enabled) {
        THIS->setFrame(enabled);
    }

    bool Handle_hasSelectedText(HandleRef _this) {
        return THIS->hasSelectedText();
    }

    void Handle_setInputMask(HandleRef _this, const std::string& mask) {
        return THIS->setInputMask(QString::fromStdString(mask));
    }

    void Handle_setMaxLength(HandleRef _this, int32_t length) {
        THIS->setMaxLength(length);
    }

    bool Handle_isModified(HandleRef _this) {
        return THIS->isModified();
    }

    void Handle_setModified(HandleRef _this, bool modified) {
        THIS->setModified(modified);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setReadOnly(HandleRef _this, bool value) {
        THIS->setReadOnly(value);
    }

    bool Handle_isRedoAvailable(HandleRef _this) {
        return THIS->isRedoAvailable();
    }

    std::string Handle_selectedText(HandleRef _this) {
        return THIS->selectedText().toStdString();
    }

    void Handle_setText(HandleRef _this, const std::string& text) {
        THIS->setText(QString::fromStdString(text));
    }

    std::string Handle_text(HandleRef _this) {
        return THIS->text().toStdString();
    }

    bool Handle_isUndoAvailable(HandleRef _this) {
        return THIS->isUndoAvailable();
    }

    void Handle_clear(HandleRef _this) {
        THIS->clear();
    }

    void Handle_copy(HandleRef _this) {
        THIS->copy();
    }

    void Handle_cut(HandleRef _this) {
        THIS->cut();
    }

    void Handle_paste(HandleRef _this) {
        THIS->paste();
    }

    void Handle_redo(HandleRef _this) {
        THIS->redo();
    }

    void Handle_selectAll(HandleRef _this) {
        THIS->selectAll();
    }

    void Handle_undo(HandleRef _this) {
        THIS->undo();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new LineEditWithHandler(handler));
    }
}

#include "LineEdit.moc"