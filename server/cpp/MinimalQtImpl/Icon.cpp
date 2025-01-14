#include "generated/Icon.h"
#include "IconInternal.h"

#include "PixmapInternal.h"
#include "PainterInternal.h"
#include "util/convert.h"

#define THIS (AS_QICON_PTR(_this))

namespace Icon
{
    // struct QModeState {
    //     QIcon::Mode mode;
    //     QIcon::State state;
    // };

    // static QModeState getOpts(const Handle::ModeStateOpts& opts) {
    //     QModeState ret;
    //     ret.mode = opts.mapOrDefaultMode([](auto mode_) { return static_cast<QIcon::Mode>(mode_); }, QIcon::Normal);
    //     ret.state = opts.mapOrDefaultState([](auto state_) { return static_cast<QIcon::State>(state_); }, QIcon::Off);
    //     return ret;
    // }

    Size Handle_actualSize(HandleRef _this, Size size, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return toSize(THIS->actualSize(toQSize(size), static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)));
    }

    void Handle_addFile(HandleRef _this, const std::string& fileName, const std::optional<Size>& size, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        const auto qSize = optionalMap<Size,QSize>(size, toQSize).value_or(QSize());
        THIS->addFile(QString::fromStdString(fileName), qSize, static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state));
    }

    void Handle_addPixmap(HandleRef _this, Pixmap::HandleRef pixmap, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        THIS->addPixmap(QPIXMAP_VALUE(pixmap), static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state));
    }

    std::vector<Size> Handle_availableSizes(HandleRef _this, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return fromQList<QSize,Size>(THIS->availableSizes(static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)), toSize);
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

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, Rect rect, Alignment alignment /* Alignment::AlignCenter */, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        THIS->paint(AS_QPAINTER_PTR(painter), toQRect(rect), static_cast<Qt::Alignment>(alignment.value), static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state));
    }

    void Handle_paint(HandleRef _this, Painter::HandleRef painter, int32_t x, int32_t y, int32_t w, int32_t h, Alignment alignment /* Alignment::AlignCenter */, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        THIS->paint(AS_QPAINTER_PTR(painter), x, y, w, h, static_cast<Qt::Alignment>(alignment.value), static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, Size size, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return PIXMAP_HEAP_NEW(THIS->pixmap(toQSize(size), static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, int32_t extent, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return PIXMAP_HEAP_NEW(THIS->pixmap(extent,  static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, Size size, double devicePixelRatio, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return PIXMAP_HEAP_NEW(THIS->pixmap(toQSize(size), devicePixelRatio, static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)));
    }

    Pixmap::OwnedRef Handle_pixmap(HandleRef _this, int32_t w, int32_t h, Mode mode /* Mode::Normal */, State state /* State::Off */) {
        return PIXMAP_HEAP_NEW(THIS->pixmap(w, h, static_cast<QIcon::Mode>(mode), static_cast<QIcon::State>(state)));
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
