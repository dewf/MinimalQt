module Color;

import Enums;

enum NameFormat { HexRgb, HexArgb }
enum Spec { Rgb, Hsv, Cmyk, Hsl, ExtendedRgb, Invalid }

@nodispose
opaque Handle {
    int alpha();
    float alphaF();
    void setAlpha(int alpha);
    void setAlphaF(float alpha);

    // util method for testing
    Owned util_cloneWithAlpha(float alpha);
}
opaque Owned extends Handle;

Owned create();
Owned create(Rgb color);

// Owned create(Rgba64 rgba64); // TODO: this is a class

Owned create(string name); // for both the QString/const char* versions
Owned create(int r, int g, int b, int a = 255);

// QColor(QLatin1StringView name)

Owned create(GlobalColor color);

// static methods =====================================
Array<string> colorNames();
Owned fromCmyk(int c, int m, int y, int k, int a = 255);
Owned fromCmykF(float c, float m, float y, float k, float a = 1.0f);
Owned fromHsl(int h, int s, int l, int a = 255);
Owned fromHslF(float h, float s, float l, float a = 1.0f);
Owned fromHsv(int h, int s, int v, int a = 255);
Owned fromHsvF(float h, float s, float v, float a = 1.0f);
Owned fromRgb(Rgb rgb);
Owned fromRgb(int r, int g, int b, int a = 255);

// QColor fromRgba64(QRgba64 rgba64) // TODO: this is a class

Owned fromRgba64(ushort r, ushort g, ushort b, ushort a = 0xFFFF);
Owned fromRgbF(float r, float g, float b, float a = 1.0f);
Owned fromRgba(Rgb rgba);
Owned fromString(string name);
bool isValidColorName(string name);
