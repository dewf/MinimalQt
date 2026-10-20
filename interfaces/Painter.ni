module Painter;

import Point;
import PointF;
import Rect;
import RectF;
import Enums;
import Color;
import Pixmap;
import Font;
import Pen;
import Brush;
import TextOption;
import Region;
import Transform;
import Image;
import PaintDevice;
import PainterPath;
import Polygon;
import PolygonF;
import Gradient;

@withflags(RenderHints)
enum RenderHint {
    Antialiasing = 0x01,
    TextAntialiasing = 0x02,
    SmoothPixmapTransform = 0x04,
    VerticalSubpixelPositioning = 0x08,
    LosslessImageRendering = 0x40,
    NonCosmeticBrushPatterns = 0x80
}

enum CompositionMode {
    SourceOver,
    DestinationOver,
    Clear,
    Source,
    Destination,
    SourceIn,
    DestinationIn,
    SourceOut,
    DestinationOut,
    SourceAtop,
    DestinationAtop,
    Xor,

    //svg 1.2 blend modes
    Plus,
    Multiply,
    Screen,
    Overlay,
    Darken,
    Lighten,
    ColorDodge,
    ColorBurn,
    HardLight,
    SoftLight,
    Difference,
    Exclusion,

    // ROPs
    RasterOp_SourceOrDestination,
    RasterOp_SourceAndDestination,
    RasterOp_SourceXorDestination,
    RasterOp_NotSourceAndNotDestination,
    RasterOp_NotSourceOrNotDestination,
    RasterOp_NotSourceXorDestination,
    RasterOp_NotSource,
    RasterOp_NotSourceAndDestination,
    RasterOp_SourceAndNotDestination,
    RasterOp_NotSourceOrDestination,
    RasterOp_SourceOrNotDestination,
    RasterOp_ClearDestination,
    RasterOp_SetDestination,
    RasterOp_NotDestination
}

group PixmapFragment {
    @nodispose
    opaque Handle;
    @useparenttype
    opaque Owned extends Handle;

    enum Hint {
        OpaqueHint = 0x01
    }

    flags Hints {
        OpaqueHint = 0x01
    }

    Owned create(PointF.Handle pos, RectF.Handle sourceRect, double scaleX = 1, double scaleY = 1, double rotation = 0, double opacity = 1);
}


@nodispose
opaque Handle {
    Brush.Owned background();
    BGMode backgroundMode();
    bool begin(PaintDevice.Handle device);
    void beginNativePainting();
    RectF.Owned boundingRect(RectF.Handle rectangle, int flags_, string text);
    Rect.Owned boundingRect(Rect.Handle rectangle, int flags_, string text);
    RectF.Owned boundingRect(RectF.Handle rectangle, string text, TextOption.Handle option = null);
    Rect.Owned boundingRect(int x, int y, int w, int h, int flags_, string text);
    Brush.Owned brush();
    Point.Owned brushOrigin();
    RectF.Owned clipBoundingRect();
    PainterPath.Owned clipPath();
    Region.Owned clipRegion();
    Transform.Owned combinedTransform();
    CompositionMode getCompositionMode();
    PaintDevice.Handle device();
    Transform.Owned deviceTransform();
    void drawArc(RectF.Handle rectangle, int startAngle, int spanAngle);
    void drawArc(Rect.Handle rectangle, int startAngle, int spanAngle);
    void drawArc(int x, int y, int width, int height, int startAngle, int spanAngle);
    void drawChord(RectF.Handle rectangle, int startAngle, int spanAngle);
    void drawChord(Rect.Handle rectangle, int startAngle, int spanAngle);
    void drawChord(int x, int y, int width, int height, int startAngle, int spanAngle);
    void drawConvexPolygon(Array<PointF.Handle> points);
    void drawConvexPolygon(Polygon.Handle polygon);
    void drawConvexPolygon(PolygonF.Handle polygon);
    void drawConvexPolygon(Array<Point.Handle> points);
    void drawEllipse(RectF.Handle rectangle);
    void drawEllipse(Rect.Handle rectangle);
    void drawEllipse(Point.Handle center, int rx, int ry);
    void drawEllipse(PointF.Handle center, double rx, double ry);
    void drawEllipse(int x, int y, int width, int height);

    // void drawGlyphRun(const QPointF &position, const QGlyphRun &glyphs)

    void drawImage(RectF.Handle target, Image.Handle image, RectF.Handle source, ImageConversionFlags flags_ = AutoColor);
    void drawImage(Point.Handle point, Image.Handle image);
    void drawImage(PointF.Handle point, Image.Handle image);
    void drawImage(Rect.Handle rectangle, Image.Handle image);
    void drawImage(RectF.Handle rectangle, Image.Handle image);
    void drawImage(Point.Handle point, Image.Handle image, Rect.Handle source, ImageConversionFlags flags_ = AutoColor);
    void drawImage(PointF.Handle point, Image.Handle image, RectF.Handle source, ImageConversionFlags flags_ = AutoColor);
    void drawImage(Rect.Handle target, Image.Handle image, Rect.Handle source, ImageConversionFlags flags_ = AutoColor);
    void drawImage(int x, int y, Image.Handle image, int sx = 0, int sy = 0, int sw = -1, int sh = -1, ImageConversionFlags flags_ = AutoColor);

    // void drawLine(const QLineF &line)
    // void drawLine(const QLine &line)

    void drawLine(Point.Handle p1, Point.Handle p2);
    void drawLine(PointF.Handle p1, PointF.Handle p2);
    void drawLine(int x1, int y1, int x2, int y2);

    // void drawLines(const QLineF *lines, int lineCount)
    // void drawLines(const QList<QLine> &lines)
    // void drawLines(const QList<QLineF> &lines)

    void drawLines(Array<Point.Handle> pointPairs);
    void drawLines(Array<PointF.Handle> pointPairs);

    // void drawLines(const QLine *lines, int lineCount)

    void drawPath(PainterPath.Handle path);

    // void drawPicture(const QPointF &point, const QPicture &picture)
    // void drawPicture(const QPoint &point, const QPicture &picture)
    // void drawPicture(int x, int y, const QPicture &picture)

    void drawPie(RectF.Handle rectangle, int startAngle, int spanAngle);
    void drawPie(Rect.Handle rectangle, int startAngle, int spanAngle);
    void drawPie(int x, int y, int width, int height, int startAngle, int spanAngle);
    void drawPixmap(RectF.Handle target, Pixmap.Handle pixmap, RectF.Handle source);
    void drawPixmap(Point.Handle point, Pixmap.Handle pixmap);
    void drawPixmap(PointF.Handle point, Pixmap.Handle pixmap);
    void drawPixmap(Rect.Handle rectangle, Pixmap.Handle pixmap);
    void drawPixmap(Point.Handle point, Pixmap.Handle pixmap, Rect.Handle source);
    void drawPixmap(PointF.Handle point, Pixmap.Handle pixmap, RectF.Handle source);
    void drawPixmap(Rect.Handle target, Pixmap.Handle pixmap, Rect.Handle source);
    void drawPixmap(int x, int y, Pixmap.Handle pixmap);
    void drawPixmap(int x, int y, int width, int height, Pixmap.Handle pixmap);
    void drawPixmap(int x, int y, Pixmap.Handle pixmap, int sx, int sy, int sw, int sh);
    void drawPixmap(int x, int y, int w, int h, Pixmap.Handle pixmap, int sx, int sy, int sw, int sh);
    void drawPixmapFragments(Array<PixmapFragment.Handle> fragments, Pixmap.Handle pixmap, PixmapFragment.Hints hints = 0);
    void drawPoint(PointF.Handle position);
    void drawPoint(Point.Handle position);
    void drawPoint(int x, int y);
    void drawPoints(Array<PointF.Handle> points);
    void drawPoints(Polygon.Handle points);
    void drawPoints(PolygonF.Handle points);
    void drawPoints(Array<Point.Handle> points);
    void drawPolygon(Array<PointF.Handle> points, FillRule fillRule = OddEvenFill);
    void drawPolygon(Polygon.Handle points, FillRule fillRule = OddEvenFill);
    void drawPolygon(PolygonF.Handle points, FillRule fillRule = OddEvenFill);
    void drawPolygon(Array<Point.Handle> points, FillRule fillRule = OddEvenFill);
    void drawPolyline(Array<PointF.Handle> points);
    void drawPolyline(Polygon.Handle points);
    void drawPolyline(PolygonF.Handle points);
    void drawPolyline(Array<Point.Handle> points);
    void drawRect(RectF.Handle rectangle);
    void drawRect(Rect.Handle rectangle);
    void drawRect(int x, int y, int width, int height);
    void drawRects(Array<RectF.Handle> rectangles);
    void drawRects(Array<Rect.Handle> rectangles);
    void drawRoundedRect(RectF.Handle rect, double xRadius, double yRadius, SizeMode mode = AbsoluteSize);
    void drawRoundedRect(Rect.Handle rect, double xRadius, double yRadius, SizeMode mode = AbsoluteSize);
    void drawRoundedRect(int x, int y, int w, int h, double xRadius, double yRadius, SizeMode mode = AbsoluteSize);

    // void drawStaticText(const QPointF &topLeftPosition, const QStaticText &staticText)
    // void drawStaticText(const QPoint &topLeftPosition, const QStaticText &staticText)
    // void drawStaticText(int left, int top, const QStaticText &staticText)

    void drawText(PointF.Handle position, string text);
    void drawText(Point.Handle position, string text);
    void drawText(RectF.Handle rectangle, string text, TextOption.Handle option = null);
    void drawText(int x, int y, string text);
    void drawText(Rect.Handle rectangle, int flags_, string text, Rect.Handle outPtr_boundingRect = null);               // boundingRect is (optional) OUTPUT parameter!
    void drawText(RectF.Handle rectangle, int flags_, string text, RectF.Handle outPtr_boundingRect = null);             // same
    void drawText(int x, int y, int width, int height, int flags_, string text, Rect.Handle outPtr_boundingRect = null); // same
    void drawTiledPixmap(RectF.Handle rectangle, Pixmap.Handle pixmap, PointF.Handle position = null);
    void drawTiledPixmap(Rect.Handle rectangle, Pixmap.Handle pixmap, Point.Handle position = null);
    void drawTiledPixmap(int x, int y, int width, int height, Pixmap.Handle pixmap, int sx = 0, int sy = 0);
    bool end();
    void endNativePainting();
    void eraseRect(RectF.Handle rectangle);
    void eraseRect(Rect.Handle rectangle);
    void eraseRect(int x, int y, int width, int height);
    void fillPath(PainterPath.Handle path, Brush.Handle brush);
    void fillRect(RectF.Handle rectangle, Brush.Handle brush);
    void fillRect(Rect.Handle rectangle, Gradient.Preset preset);
    void fillRect(Rect.Handle rectangle, BrushStyle style);
    void fillRect(Rect.Handle rectangle, GlobalColor color);
    void fillRect(Rect.Handle rectangle, Brush.Handle brush);
    void fillRect(Rect.Handle rectangle, Color.Handle color);
    void fillRect(RectF.Handle rectangle, Gradient.Preset preset);
    void fillRect(RectF.Handle rectangle, BrushStyle style);
    void fillRect(RectF.Handle rectangle, GlobalColor color);
    void fillRect(RectF.Handle rectangle, Color.Handle color);
    void fillRect(int x, int y, int width, int height, Gradient.Preset preset);
    void fillRect(int x, int y, int width, int height, BrushStyle style);
    void fillRect(int x, int y, int width, int height, GlobalColor color);
    void fillRect(int x, int y, int width, int height, Brush.Handle brush);
    void fillRect(int x, int y, int width, int height, Color.Handle color);
    Font.Owned font();

    // QFontInfo fontInfo() const
    // QFontMetrics fontMetrics() const

    bool hasClipping();
    bool isActive();
    LayoutDirection layoutDirection();
    double opacity();

    // QPaintEngine * paintEngine() const

    Pen.Owned pen();
    RenderHints renderHints();
    void resetTransform();
    void restore();
    void rotate(double angle);
    void save();
    void scale(double sx, double sy);
    void setBackground(Brush.Handle brush);
    void setBackgroundMode(BGMode mode);
    void setBrush(Brush.Handle brush);
    void setBrush(BrushStyle style);
    void setBrushOrigin(PointF.Handle position);
    void setBrushOrigin(Point.Handle position);
    void setBrushOrigin(int x, int y);
    void setClipPath(PainterPath.Handle path, ClipOperation operation = ReplaceClip);
    void setClipRect(RectF.Handle rectangle, ClipOperation operation = ReplaceClip);
    void setClipRect(int x, int y, int width, int height, ClipOperation operation = ReplaceClip);
    void setClipRect(Rect.Handle rectangle, ClipOperation operation = ReplaceClip);
    void setClipRegion(Region.Handle region, ClipOperation operation = ReplaceClip);
    void setClipping(bool enable);
    void setCompositionMode(CompositionMode mode);
    void setFont(Font.Handle font);
    void setLayoutDirection(LayoutDirection direction);
    void setOpacity(double opacity);
    void setPen(Pen.Handle pen);
    void setPen(PenStyle style);
    void setPen(Color.Handle color);
    void setRenderHint(RenderHint hint, bool on = true);
    void setRenderHints(RenderHints hints, bool on = true);
    void setTransform(Transform.Handle transform, bool combine = false);
    void setViewTransformEnabled(bool enable);
    void setViewport(Rect.Handle rectangle);
    void setViewport(int x, int y, int width, int height);
    void setWindow(Rect.Handle rectangle);
    void setWindow(int x, int y, int width, int height);
    void setWorldMatrixEnabled(bool enable);
    void setWorldTransform(Transform.Handle matrix, bool combine = false);
    void shear(double sh, double sv);
    void strokePath(PainterPath.Handle path, Pen.Handle pen);
    bool testRenderHint(RenderHint hint);
    Transform.Owned transform();
    void translate(PointF.Handle offset);
    void translate(Point.Handle offset);
    void translate(double dx, double dy);
    bool viewTransformEnabled();
    Rect.Owned viewport();
    Rect.Owned window();
    bool worldMatrixEnabled();
    Transform.Owned worldTransform();
}
@useparenttype
opaque Owned extends Handle;

Owned create();
Owned create(PaintDevice.Handle device);
