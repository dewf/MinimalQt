#include "generated/TextDocument.h"

#include "ObjectInternal.h"
#include "TextCursorInternal.h"
#include "TextDocumentInternal.h"
#include "UrlInternal.h"

using namespace ::Object;
using namespace ::Url;
using namespace ::TextCursor;

#define THIS (AS_QTEXTDOCUMENT_PTR(_this))

namespace TextDocument
{
    SignalConnectionRef Handle_connect_BaseUrlChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::baseUrlChanged, [handler](const QUrl &url)
        {
            handler->sig_baseUrlChanged(URL_HEAP_NEW(url));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_BlockCountChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::blockCountChanged, [handler](int newBlockCount)
        {
            handler->sig_blockCountChanged(newBlockCount);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ContentsChange(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::contentsChange, [handler](int from, int charsRemoved, int charsAdded)
        {
            handler->sig_contentsChange(from, charsRemoved, charsAdded);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ContentsChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::contentsChanged, [handler]
        {
            handler->sig_contentsChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_CursorPositionChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::cursorPositionChanged, [handler](const QTextCursor &cursor)
        {
            handler->sig_cursorPositionChanged(TEXTCURSOR_HEAP_NEW(cursor));
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_DocumentLayoutChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::documentLayoutChanged, [handler]
        {
            handler->sig_documentLayoutChanged();
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_ModificationChanged(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::modificationChanged, [handler](bool changed)
        {
            handler->sig_modificationChanged(changed);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_RedoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::redoAvailable, [handler](bool available)
        {
            handler->sig_redoAvailable(available);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UndoAvailable(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::undoAvailable, [handler](bool available)
        {
            handler->sig_undoAvailable(available);
        });
        return new __SignalConnection { connection };
    }

    SignalConnectionRef Handle_connect_UndoCommandAdded(HandleRef _this, const std::shared_ptr<SignalHandler>& handler) {
        const auto connection = QObject::connect(THIS, &QTextDocument::undoCommandAdded, [handler]
        {
            handler->sig_undoCommandAdded();
        });
        return new __SignalConnection { connection };
    }

    void Handle_dispose(HandleRef _this) {
        delete THIS;
    }

    HandleRef create(Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTextDocument(AS_QOBJECT_PTR(parent)));
    }

    HandleRef create(const std::string& text, Object::HandleRef parent /* nullptr */) {
        return reinterpret_cast<HandleRef>(new QTextDocument(QString::fromStdString(text), AS_QOBJECT_PTR(parent)));
    }
}
