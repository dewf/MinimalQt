#include "generated/Icon.h"

#include <QIcon>
#include <utility>
#include "IconInternal.h"
#include "PixmapInternal.h"

namespace Icon
{
    class DeferredMatcher : public Deferred::Matcher {
    private:
        QIcon &ret;
    public:
        explicit DeferredMatcher(QIcon &ret) : ret(ret) {}
        void onEmpty(const Deferred::Empty *value) override {
            ret = QIcon();
        }
        void onFromHandle(const Deferred::FromHandle *value) override {
            ret = QICON_VALUE(value->handle);
        }
        void onFromThemeIcon(const Deferred::FromThemeIcon *value) override {
            ret = QIcon::fromTheme(static_cast<QIcon::ThemeIcon>(value->themeIcon));
        }
        void onFromFilename(const Deferred::FromFilename *value) override {
            ret = QIcon(QString::fromStdString(value->filename));
        }
        void onFromPixmap(const Deferred::FromPixmap *value) override {
            ret = QIcon(value->pixmap_->qPixmap);
        }
    };

    QIcon fromDeferred(const std::shared_ptr<Deferred::Base> &deferred) {
        QIcon ret;
        DeferredMatcher matcher(ret);
        deferred->match(&matcher);
        return ret;
    }

    void Owned_dispose(OwnedRef _this) {
        delete AS_QICON_PTR(_this);
    }

    OwnedRef create() {
        return ICON_HEAP_NEW();
    }

    OwnedRef create(ThemeIcon themeIcon) {
        auto qThemeIcon = static_cast<QIcon::ThemeIcon>(themeIcon);
        return ICON_HEAP_NEW(QIcon::fromTheme(qThemeIcon));
    }

    OwnedRef create(const std::string& filename) {
        return ICON_HEAP_NEW(QString::fromStdString(filename)); // ! using QIcon ctor
    }

    OwnedRef create(Pixmap::HandleRef pixmap) {
        return ICON_HEAP_NEW(pixmap->qPixmap); // same as above
    }
}
