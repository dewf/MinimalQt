#include "generated/Font.h"

#include "FontInternal.h"

#include <QStringList>

namespace Font
{
    void Owned_dispose(OwnedRef _this) {
        delete AS_QFONT_PTR(_this);
    }

    OwnedRef create() {
        return FONT_HEAP_NEW(QFont());
    }

    OwnedRef create(const std::string& family, const CreateOptions& opts) {
        return FONT_HEAP_NEW(QFont(
            QString::fromStdString(family),
                opts.getOrDefaultPointSize(-1),
                opts.getOrDefaultWeight(-1),
                opts.getOrDefaultItalic(false)));
    }

    OwnedRef create(const std::vector<std::string>& families, const CreateOptions& opts) {
        QStringList qStrings;
        for (auto &family : families) {
            qStrings.append(QString::fromStdString(family));
        }
        return FONT_HEAP_NEW(QFont(
            qStrings,
            opts.getOrDefaultPointSize(-1),
            opts.getOrDefaultWeight(-1),
            opts.getOrDefaultItalic(false)));
    }
}
