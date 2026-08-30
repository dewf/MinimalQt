#include "generated/Font.h"
#include "FontInternal.h"

using namespace ::PaintDevice;

#include "util/convert.h"

#define THIS (AS_QFONT_PTR(_this))
#define TAG_THIS (AS_QFONT_TAG_PTR(_this))

namespace Font
{
    namespace Tag {
        void Owned_dispose(OwnedRef _this) {
            delete TAG_THIS;
        }
    }

    bool Handle_bold(HandleRef _this) {
        return THIS->bold();
    }

    Capitalization Handle_capitalization(HandleRef _this) {
        return static_cast<Capitalization>(THIS->capitalization());
    }

    void Handle_clearFeatures(HandleRef _this) {
        THIS->clearFeatures();
    }

    void Handle_clearVariableAxes(HandleRef _this) {
        THIS->clearVariableAxes();
    }

    std::string Handle_defaultFamily(HandleRef _this) {
        return THIS->defaultFamily().toStdString();
    }

    bool Handle_exactMatch(HandleRef _this) {
        return THIS->exactMatch();
    }

    std::vector<std::string> Handle_families(HandleRef _this) {
        return toVectorStrings(THIS->families());
    }

    std::string Handle_family(HandleRef _this) {
        return THIS->family().toStdString();
    }

    std::vector<Tag::OwnedRef> Handle_featureTags(HandleRef _this) {
        return fromQList<QFont::Tag,Tag::OwnedRef>(THIS->featureTags(), [](auto tag) { return FONT_TAG_HEAP_NEW(tag); });
    }

    uint32_t Handle_featureValue(HandleRef _this, Tag::HandleRef tag) {
        return THIS->featureValue(QFONT_TAG_VALUE(tag));
    }

    bool Handle_fixedPitch(HandleRef _this) {
        return THIS->fixedPitch();
    }

    bool Handle_fromString(HandleRef _this, const std::string& descrip) {
        return THIS->fromString(QString::fromStdString(descrip));
    }

    HintingPreference Handle_hintingPreference(HandleRef _this) {
        return static_cast<HintingPreference>(THIS->hintingPreference());
    }

    bool Handle_isCopyOf(HandleRef _this, HandleRef f) {
        return THIS->isCopyOf(QFONT_VALUE(f));
    }

    bool Handle_isFeatureSet(HandleRef _this, Tag::HandleRef tag) {
        return THIS->isFeatureSet(QFONT_TAG_VALUE(tag));
    }

    bool Handle_isVariableAxisSet(HandleRef _this, Tag::HandleRef tag) {
        return THIS->isVariableAxisSet(QFONT_TAG_VALUE(tag));
    }

    bool Handle_italic(HandleRef _this) {
        return THIS->italic();
    }

    bool Handle_kerning(HandleRef _this) {
        return THIS->kerning();
    }

    std::string Handle_key(HandleRef _this) {
        return THIS->key().toStdString();
    }

    double Handle_letterSpacing(HandleRef _this) {
        return THIS->letterSpacing();
    }

    SpacingType Handle_letterSpacingType(HandleRef _this) {
        return static_cast<SpacingType>(THIS->letterSpacingType());
    }

    bool Handle_overline(HandleRef _this) {
        return THIS->overline();
    }

    int32_t Handle_pixelSize(HandleRef _this) {
        return THIS->pixelSize();
    }

    int32_t Handle_pointSize(HandleRef _this) {
        return THIS->pointSize();
    }

    double Handle_pointSizeF(HandleRef _this) {
        return THIS->pointSizeF();
    }

    OwnedRef Handle_resolve(HandleRef _this, HandleRef other) {
        return FONT_HEAP_NEW(THIS->resolve(QFONT_VALUE(other)));
    }

    void Handle_setBold(HandleRef _this, bool enable) {
        THIS->setBold(enable);
    }

    void Handle_setCapitalization(HandleRef _this, Capitalization caps) {
        THIS->setCapitalization(static_cast<QFont::Capitalization>(caps));
    }

    void Handle_setFamilies(HandleRef _this, const std::vector<std::string>& families) {
        THIS->setFamilies(toQStringList(families));
    }

    void Handle_setFamily(HandleRef _this, const std::string& family) {
        THIS->setFamily(QString::fromStdString(family));
    }

    void Handle_setFeature(HandleRef _this, Tag::HandleRef tag, uint32_t value) {
        THIS->setFeature(QFONT_TAG_VALUE(tag), value);
    }

    void Handle_setFixedPitch(HandleRef _this, bool enable) {
        THIS->setFixedPitch(enable);
    }

    void Handle_setHintingPreference(HandleRef _this, HintingPreference hintingPreference) {
        THIS->setHintingPreference(static_cast<QFont::HintingPreference>(hintingPreference));
    }

    void Handle_setItalic(HandleRef _this, bool enable) {
        THIS->setItalic(enable);
    }

    void Handle_setKerning(HandleRef _this, bool enable) {
        THIS->setKerning(enable);
    }

    void Handle_setLetterSpacing(HandleRef _this, SpacingType type, double spacing) {
        THIS->setLetterSpacing(static_cast<QFont::SpacingType>(type), spacing);
    }

    void Handle_setOverline(HandleRef _this, bool enable) {
        THIS->setOverline(enable);
    }

    void Handle_setPixelSize(HandleRef _this, int32_t pixelSize) {
        THIS->setPixelSize(pixelSize);
    }

    void Handle_setPointSize(HandleRef _this, int32_t pointSize) {
        THIS->setPointSize(pointSize);
    }

    void Handle_setPointSizeF(HandleRef _this, double pointSize) {
        THIS->setPointSizeF(pointSize);
    }

    void Handle_setStretch(HandleRef _this, int32_t factor) {
        THIS->setStretch(factor);
    }

    void Handle_setStrikeOut(HandleRef _this, bool enable) {
        THIS->setStrikeOut(enable);
    }

    void Handle_setStyle(HandleRef _this, Style style) {
        THIS->setStyle(static_cast<QFont::Style>(style));
    }

    void Handle_setStyleHint(HandleRef _this, StyleHint hint, StyleStrategy strategy /* StyleStrategy::PreferDefault */) {
        THIS->setStyleHint(static_cast<QFont::StyleHint>(hint), static_cast<QFont::StyleStrategy>(strategy));
    }

    void Handle_setStyleName(HandleRef _this, const std::string& styleName) {
        THIS->setStyleName(QString::fromStdString(styleName));
    }

    void Handle_setStyleStrategy(HandleRef _this, StyleStrategy s) {
        THIS->setStyleStrategy(static_cast<QFont::StyleStrategy>(s));
    }

    void Handle_setUnderline(HandleRef _this, bool enable) {
        THIS->setUnderline(enable);
    }

    void Handle_setVariableAxis(HandleRef _this, Tag::HandleRef tag, float value) {
        THIS->setVariableAxis(QFONT_TAG_VALUE(tag), value);
    }

    void Handle_setWeight(HandleRef _this, Weight weight) {
        THIS->setWeight(static_cast<QFont::Weight>(weight));
    }

    void Handle_setWordSpacing(HandleRef _this, double spacing) {
        THIS->setWordSpacing(spacing);
    }

    int32_t Handle_stretch(HandleRef _this) {
        return THIS->stretch();
    }

    bool Handle_strikeOut(HandleRef _this) {
        return THIS->strikeOut();
    }

    Style Handle_style(HandleRef _this) {
        return static_cast<Style>(THIS->style());
    }

    StyleHint Handle_styleHint(HandleRef _this) {
        return static_cast<StyleHint>(THIS->styleHint());
    }

    std::string Handle_styleName(HandleRef _this) {
        return THIS->styleName().toStdString();
    }

    StyleStrategy Handle_getStyleStrategy(HandleRef _this) {
        return static_cast<StyleStrategy>(THIS->styleStrategy());
    }

    void Handle_swap(HandleRef _this, HandleRef other) {
        // a bit weird because of our strange heap-allocated value type null handling
        // (null handle = default value)
        if (other != nullptr)
        {
            THIS->swap(*AS_QFONT_PTR(other));
        } else
        {
            // nothing to swap really
            *THIS = QFont();
        }
    }

    std::string Handle_toString2(HandleRef _this) {
        return THIS->toString().toStdString();
    }

    bool Handle_underline(HandleRef _this) {
        return THIS->underline();
    }

    void Handle_unsetFeature(HandleRef _this, Tag::HandleRef tag) {
        THIS->unsetFeature(QFONT_TAG_VALUE(tag));
    }

    void Handle_unsetVariableAxis(HandleRef _this, Tag::HandleRef tag) {
        THIS->unsetVariableAxis(QFONT_TAG_VALUE(tag));
    }

    std::vector<Tag::OwnedRef> Handle_variableAxisTags(HandleRef _this) {
        return fromQList<QFont::Tag,Tag::OwnedRef>(THIS->variableAxisTags(), [](auto tag) { return FONT_TAG_HEAP_NEW(tag); });
    }

    float Handle_variableAxisValue(HandleRef _this, Tag::HandleRef tag) {
        return THIS->variableAxisValue(QFONT_TAG_VALUE(tag));
    }

    Weight Handle_weight(HandleRef _this) {
        return static_cast<Weight>(THIS->weight());
    }

    double Handle_wordSpacing(HandleRef _this) {
        return THIS->wordSpacing();
    }

    void Owned_dispose(OwnedRef _this) {
        delete THIS;
    }

    OwnedRef create() {
        return FONT_HEAP_NEW();
    }

    OwnedRef create(HandleRef font, PaintDevice::HandleRef pd) {
        return FONT_HEAP_NEW(QFONT_VALUE(font), reinterpret_cast<QPaintDevice*>(pd));
    }

    OwnedRef create(const std::string& family, int32_t pointSize /* -1 */, int32_t weight /* -1 */, bool italic /* false */) {
        return FONT_HEAP_NEW(QString::fromStdString(family), pointSize, weight, italic);
    }

    OwnedRef create(const std::vector<std::string>& families, int32_t pointSize /* -1 */, int32_t weight /* -1 */, bool italic /* false */) {
        return FONT_HEAP_NEW(toQStringList(families), pointSize, weight, italic);
    }

    OwnedRef create(HandleRef font) {
        return FONT_HEAP_NEW(QFONT_VALUE(font));
    }
}
