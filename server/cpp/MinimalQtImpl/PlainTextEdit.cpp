#include "generated/PlainTextEdit.h"

#include <QObject>
#include <QPlainTextEdit>

#include "util/SignalStuff.h"
#include "util/convert.h"

#define THIS ((PlainTextEditWithHandler*)_this)

namespace PlainTextEdit
{
    class PlainTextEditWithHandler : public QPlainTextEdit {
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
            // Frame:
            // ..... (none)
            // AbstractScrollArea:
            // ..... (none)
            // PlainTextEdit:
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
        explicit PlainTextEditWithHandler(std::shared_ptr<SignalHandler> handler) : handler(std::move(handler)) {}
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
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    destroyed(reinterpret_cast<Object::HandleRef>(obj));
        }
        void onObjectNameChanged(const QString& name) const {
            handler->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                inherited_Object_SignalHandler()->
                    objectNameChanged(name.toStdString());
        }
        // Widget ==================
        void onCustomContextMenuRequested(const QPoint& pos) const {
            handler->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    customContextMenuRequested(toPoint(pos));
        }
        void onWindowIconChanged(const QIcon& icon) const {
            handler->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowIconChanged((Icon::HandleRef)&icon);
        }
        void onWindowTitleChanged(const QString& title) const {
            handler->
                inherited_AbstractScrollArea_SignalHandler()->
                inherited_Frame_SignalHandler()->
                inherited_Widget_SignalHandler()->
                    windowTitleChanged(title.toStdString());
        }
        // Frame ====================
        // .... (none)
        // AbstractScrollArea =======
        // .... (none)
        // PlainTextEdit ============
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

    void Handle_setBackgroundVisible(HandleRef _this, bool visible) {
        THIS->setBackgroundVisible(visible);
    }

    int32_t Handle_blockCount(HandleRef _this) {
        return THIS->blockCount();
    }

    void Handle_setCenterOnScroll(HandleRef _this, bool state) {
        THIS->setCenterOnScroll(state);
    }

    void Handle_setCursorWidth(HandleRef _this, int32_t width) {
        THIS->setCursorWidth(width);
    }

    void Handle_setDocumentTitle(HandleRef _this, const std::string& title) {
        THIS->setDocumentTitle(QString::fromStdString(title));
    }

    void Handle_setLineWrapMode(HandleRef _this, LineWrapMode mode) {
        THIS->setLineWrapMode(static_cast<QPlainTextEdit::LineWrapMode>(mode));
    }

    void Handle_setMaximumBlockCount(HandleRef _this, int32_t count) {
        THIS->setMaximumBlockCount(count);
    }

    void Handle_setOverwriteMode(HandleRef _this, bool overwrite) {
        THIS->setOverwriteMode(overwrite);
    }

    void Handle_setPlaceholderText(HandleRef _this, const std::string& text) {
        THIS->setPlaceholderText(QString::fromStdString(text));
    }

    void Handle_setPlainText(HandleRef _this, const std::string& text) {
        THIS->setPlainText(QString::fromStdString(text));
    }

    void Handle_setReadOnly(HandleRef _this, bool state) {
        THIS->setReadOnly(state);
    }

    void Handle_setTabChangesFocus(HandleRef _this, bool state) {
        THIS->setTabChangesFocus(state);
    }

    void Handle_setTabStopDistance(HandleRef _this, double distance) {
        THIS->setTabStopDistance(distance);
    }

    void Handle_setTextInteractionFlags(HandleRef _this, TextInteractionFlags tiFlags) {
        THIS->setTextInteractionFlags(static_cast<Qt::TextInteractionFlags>(tiFlags));
    }

    void Handle_setUndoRedoEnabled(HandleRef _this, bool enabled) {
        THIS->setUndoRedoEnabled(enabled);
    }

    void Handle_setWordWrapMode(HandleRef _this, WrapMode mode) {
        THIS->setWordWrapMode(static_cast<QTextOption::WrapMode>(mode));
    }

    std::string Handle_toPlainText(HandleRef _this) {
        return THIS->toPlainText().toStdString();
    }

    void Handle_setSignalMask(HandleRef _this, SignalMask mask) {
        THIS->setSignalMask(mask);
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(const std::shared_ptr<SignalHandler>& handler) {
        return reinterpret_cast<HandleRef>(new PlainTextEditWithHandler(handler));
    }
}

#include "PlainTextEdit.moc"
