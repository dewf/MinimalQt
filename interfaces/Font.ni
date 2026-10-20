module Font;

import PaintDevice;

enum Capitalization {
    MixedCase,
    AllUppercase,
    AllLowercase,
    SmallCaps,
    Capitalize
}

enum HintingPreference {
    PreferDefaultHinting        = 0,
    PreferNoHinting             = 1,
    PreferVerticalHinting       = 2,
    PreferFullHinting           = 3
}

enum SpacingType {
    PercentageSpacing,
    AbsoluteSpacing
}

enum Stretch {
    AnyStretch     =   0,
    UltraCondensed =  50,
    ExtraCondensed =  62,
    Condensed      =  75,
    SemiCondensed  =  87,
    Unstretched    = 100,
    SemiExpanded   = 112,
    Expanded       = 125,
    ExtraExpanded  = 150,
    UltraExpanded  = 200
}

enum Style {
    StyleNormal,
    StyleItalic,
    StyleOblique
}

enum StyleHint {
    Helvetica,  SansSerif = Helvetica,
    Times,      Serif = Times,
    Courier,    TypeWriter = Courier,
    OldEnglish, Decorative = OldEnglish,
    System,
    AnyStyle,
    Cursive,
    Monospace,
    Fantasy
}

enum StyleStrategy {
    PreferDefault           = 0x0001,
    PreferBitmap            = 0x0002,
    PreferDevice            = 0x0004,
    PreferOutline           = 0x0008,
    ForceOutline            = 0x0010,
    PreferMatch             = 0x0020,
    PreferQuality           = 0x0040,
    PreferAntialias         = 0x0080,
    NoAntialias             = 0x0100,
    NoSubpixelAntialias     = 0x0800,
    PreferNoShaping         = 0x1000,
    ContextFontMerging      = 0x2000,
    PreferTypoLineMetrics   = 0x4000,
    NoFontMerging           = 0x8000
}

enum Weight {
    Thin = 100,
    ExtraLight = 200,
    Light = 300,
    Normal = 400,
    Medium = 500,
    DemiBold = 600,
    Bold = 700,
    ExtraBold = 800,
    Black = 900
}

group Tag {
    @nodispose
    opaque Handle;
    @useparenttype
    opaque Owned extends Handle;
}

@nodispose
opaque Handle {
    bool bold();
    Capitalization capitalization();
    void clearFeatures();
    void clearVariableAxes();
    string defaultFamily();
    bool exactMatch();
    Array<string> families();
    string family();
    Array<Tag.Owned> featureTags();
    uint32 featureValue(Tag.Handle tag);
    bool fixedPitch();
    bool fromString(string descrip);
    HintingPreference hintingPreference();
    bool isCopyOf(Handle f);
    bool isFeatureSet(Tag.Handle tag);
    bool isVariableAxisSet(Tag.Handle tag);
    bool italic();
    bool kerning();
    string key();
    double letterSpacing();
    SpacingType letterSpacingType();
    bool overline();
    int pixelSize();
    int pointSize();
    double pointSizeF();
    Owned resolve(Handle other);
    void setBold(bool enable);
    void setCapitalization(Capitalization caps);
    void setFamilies(Array<string> families);
    void setFamily(string family);
    void setFeature(Tag.Handle tag, uint32 value);
    void setFixedPitch(bool enable);
    void setHintingPreference(HintingPreference hintingPreference);
    void setItalic(bool enable);
    void setKerning(bool enable);
    void setLetterSpacing(SpacingType type, double spacing);
    void setOverline(bool enable);
    void setPixelSize(int pixelSize);
    void setPointSize(int pointSize);
    void setPointSizeF(double pointSize);
    void setStretch(int factor);
    void setStrikeOut(bool enable);
    void setStyle(Style style);
    void setStyleHint(StyleHint hint, StyleStrategy strategy = PreferDefault);
    void setStyleName(string styleName);
    void setStyleStrategy(StyleStrategy s);
    void setUnderline(bool enable);
    void setVariableAxis(Tag.Handle tag, float value);
    void setWeight(Weight weight);
    void setWordSpacing(double spacing);
    int stretch();
    bool strikeOut();
    Style style();
    StyleHint styleHint();
    string styleName();
    StyleStrategy getStyleStrategy();
    void swap(Handle other);
    string toString2(); // +2 to avoid conflict with built-in .NET (we'd need to add 'new' or 'override', but the codegen doesn't do that presently)
    bool underline();
    void unsetFeature(Tag.Handle tag);
    void unsetVariableAxis(Tag.Handle tag);
    Array<Tag.Owned> variableAxisTags();
    float variableAxisValue(Tag.Handle tag);
    Weight weight();
    double wordSpacing();
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(Handle font, PaintDevice.Handle pd);
Owned create(string family, int pointSize = -1, int weight = -1, bool italic = false);
Owned create(Array<string> families, int pointSize = -1, int weight = -1, bool italic = false);
Owned create(Handle other);
