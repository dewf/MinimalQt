#include "generated/TextEdit.h"
#include "TextEditInternal.h"

#include "TextCursorInternal.h"
#include "TextCharFormatInternal.h"

namespace TextEdit
{
    namespace ExtraSelection {

        #define EXTRASEL_THIS (reinterpret_cast<QTextEdit::ExtraSelection*>(_this))

        TextCursor::OwnedRef Handle_cursor(HandleRef _this) {
            return TEXTCURSOR_HEAP_NEW(EXTRASEL_THIS->cursor);
        }

        TextCharFormat::OwnedRef Handle_format(HandleRef _this) {
            return TEXTCHARFORMAT_HEAP_NEW(EXTRASEL_THIS->format);
        }

        void Owned_dispose(OwnedRef _this) {
            delete EXTRASEL_THIS;
        }

        OwnedRef create(TextCursor::HandleRef cursor, TextCharFormat::HandleRef format) {
            return TEXTEDIT_EXTRASEL_HEAP_NEW(QTEXTCURSOR_VALUE(cursor), QTEXTCHARFORMAT_VALUE(format));
        }
    }
}
