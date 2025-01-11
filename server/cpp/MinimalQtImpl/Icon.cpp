#include "generated/Icon.h"
#include "IconInternal.h"

#include "PixmapInternal.h"
#include "PainterInternal.h"
#include "util/convert.h"

#define THIS (AS_QICON_PTR(_this))

namespace Icon
{
    struct QModeState {
        QIcon::Mode mode;
        QIcon::State state;
    };

    static QModeState getOpts(const Handle::ModeStateOpts& opts) {
        QModeState ret;
        ret.mode = opts.mapOrDefaultMode([](auto mode_) { return static_cast<QIcon::Mode>(mode_); }, QIcon::Normal);
        ret.state = opts.mapOrDefaultState([](auto state_) { return static_cast<QIcon::State>(state_); }, QIcon::Off);
        return ret;
    }

    Size Handle_actualSize(HandleRef _this, Size size, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return toSize(THIS->actualSize(toQSize(size), mode, state));
    }

    void Handle_addFile(HandleRef _this, const std::string& fileName, const std::optional<Size>& size, const Handle::ModeStateOpts& opts) {
        const auto qSize = optionalMap<Size,QSize>(size, toQSize).value_or(QSize());
        const auto [mode, state] = getOpts(opts);
        THIS->addFile(QString::fromStdString(fileName), qSize, mode, state);
    }

    void Handle_addPixmap(HandleRef _this, Pixmap::HandleRef pixmap, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        THIS->addPixmap(QPIXMAP_VALUE(pixmap), mode, state);
    }

    std::vector<Size> Handle_availableSizes(HandleRef _this, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return fromQList<QSize,Size>(THIS->availableSizes(mode, state), toSize);
    }

    int64_t Handle_cacheKey(HandleRef _this) {
        return THIS->cacheKey();
    }

    bool Handle_isMask(HandleRef _this) {
        return THIS->isMask();
    }

    bool Handle_isNull(HandleRef _this) {
        return THIS->isNull();
    }

    std::string Handle_name(HandleRef _this) {
        return THIS->name().toStdString();
    }

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, Rect rect, const std::optional<Alignment>& alignment, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        Qt::Alignment qAlign;
        if (alignment.has_value()) qAlign = static_cast<Qt::Alignment>(alignment.value());
        THIS->paint(AS_QPAINTER_PTR(painter), toQRect(rect), qAlign, mode, state);
    }

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, int32_t x, int32_t y, int32_t w, int32_t h, const std::optional<Alignment>& alignment, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        Qt::Alignment qAlign;
        if (alignment.has_value()) qAlign = static_cast<Qt::Alignment>(alignment.value());
        THIS->paint(AS_QPAINTER_PTR(painter), x, y, w, h, qAlign, mode, state);
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, Size size, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return PIXMAP_HEAP_NEW(THIS->pixmap(toQSize(size), mode, state));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, int32_t extent, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return PIXMAP_HEAP_NEW(THIS->pixmap(extent, mode, state));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, Size size, double devicePixelRatio, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return PIXMAP_HEAP_NEW(THIS->pixmap(toQSize(size), devicePixelRatio, mode, state));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, int32_t w, int32_t h, const Handle::ModeStateOpts& opts) {
        const auto [mode, state] = getOpts(opts);
        return PIXMAP_HEAP_NEW(THIS->pixmap(w, h, mode, state));
    }

    void Handle_setIsMask(HandleRef _this, bool isMask) {
        THIS->setIsMask(isMask);
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        THIS->swap(QICON_VALUE(other));
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return ICON_HEAP_NEW();
    }

    OwnedRef create(Pixmap::HandleRef pixmap) {
        return ICON_HEAP_NEW(QPIXMAP_VALUE(pixmap));
    }

    OwnedRef create(const std::string& filename) {
        return ICON_HEAP_NEW(QString::fromStdString(filename));
    }

    OwnedRef create(HandleRef other) {
        return ICON_HEAP_NEW(QICON_VALUE(other));
    }

    std::vector<std::string> fallbackSearchPaths() {
        return toVectorStrings(QIcon::fallbackSearchPaths());
    }

    std::string fallbackThemeName() {
        return QIcon::fallbackThemeName().toStdString();
    }

    OwnedRef fromTheme(const std::string& name) {
        return ICON_HEAP_NEW(QIcon::fromTheme(QString::fromStdString(name)));
    }

    OwnedRef fromTheme(ThemeIcon icon) {
        return ICON_HEAP_NEW(QIcon::fromTheme(static_cast<QIcon::ThemeIcon>(icon)));
    }

    OwnedRef fromTheme(ThemeIcon icon, HandleRef fallback) {
        return ICON_HEAP_NEW(QIcon::fromTheme(static_cast<QIcon::ThemeIcon>(icon), QICON_VALUE(fallback)));
    }

    OwnedRef fromTheme(const std::string& name, HandleRef fallback) {
        return ICON_HEAP_NEW(QIcon::fromTheme(QString::fromStdString(name), QICON_VALUE(fallback)));
    }

    bool hasThemeIcon(const std::string& name) {
        return QIcon::hasThemeIcon(QString::fromStdString(name));
    }

    bool hasThemeIcon(ThemeIcon icon) {
        return QIcon::hasThemeIcon(static_cast<QIcon::ThemeIcon>(icon));
    }

    void setFallbackSearchPaths(const std::vector<std::string>& paths) {
        QIcon::setFallbackSearchPaths(toQStringList(paths));
    }

    void setFallbackThemeName(const std::string& name) {
        QIcon::setFallbackThemeName(QString::fromStdString(name));
    }

    void setThemeName(const std::string& name) {
        QIcon::setThemeName(QString::fromStdString(name));
    }

    void setThemeSearchPaths(const std::vector<std::string>& paths) {
        QIcon::setThemeSearchPaths(toQStringList(paths));
    }

    std::string themeName() {
        return QIcon::themeName().toStdString();
    }

    std::vector<std::string> themeSearchPaths() {
        return toVectorStrings(QIcon::themeSearchPaths());
    }
}
