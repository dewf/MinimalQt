module TextEdit;

import Object;
import Widget;
import Point;
import Rect;
import Enums;
import AbstractScrollArea;
import Menu;
import TextCursor;
import TextCharFormat;
import TextDocument;
import TextOption;
import RegularExpression;
import Url;
import Color;
import Font;
import Variant;

enum LineWrapMode {
    NoWrap,
    WidgetWidth,
    FixedPixelWidth,
    FixedColumnWidth
}

@withflags(AutoFormatting)
enum AutoFormattingFlag : uint32 {
    AutoNone = 0,
    AutoBulletList = 0x00000001,
    AutoAll = 0xffffffff
}

group ExtraSelection {
    @nodispose
    opaque Handle {
        TextCursor.Owned cursor();      // hmm, since Handle is a struct pointer (either ours or elsewhere), I don't think these would need to be owned - but then how could we convey that they are temporary values and can't be saved etc?
        TextCharFormat.Owned format();
    }
    opaque Owned extends Handle;

    Owned create(TextCursor.Handle cursor, TextCharFormat.Handle format);
}

interface SignalHandler extends AbstractScrollArea.SignalHandler {
    void copyAvailable(bool yes);
    void currentCharFormatChanged(TextCharFormat.Handle f);
    void cursorPositionChanged();
    void redoAvailable(bool available);
    void selectionChanged();
    void textChanged();
    void undoAvailable(bool available);
}

opaque Handle extends AbstractScrollArea.Handle {

    bool acceptRichText();
    Alignment alignment();
    string anchorAt(Point.Handle pos);
    AutoFormatting getAutoFormatting();
    bool canPaste();
    Menu.Handle createStandardContextMenu();
    Menu.Handle createStandardContextMenu(Point.Handle position);
    TextCharFormat.Owned currentCharFormat();
    Font.Owned currentFont();
    TextCursor.Owned cursorForPosition(Point.Handle pos);
    Rect.Owned cursorRect();
    Rect.Owned cursorRect(TextCursor.Handle cursor);
    int cursorWidth();
    TextDocument.Handle document();
    string documentTitle();
    void ensureCursorVisible();
    Array<ExtraSelection.Owned> extraSelections();
    bool find(string exp, TextDocument.FindFlags options_ = 0);
    bool find(RegularExpression.Handle exp, TextDocument.FindFlags options_ = 0);
    string fontFamily();
    bool fontItalic();
    double fontPointSize();
    bool fontUnderline();
    int fontWeight();
    bool isReadOnly();
    bool isUndoRedoEnabled();
    int lineWrapColumnOrWidth();
    LineWrapMode getLineWrapMode();
    Variant.Owned loadResource(int type, Url.Handle name);
    void mergeCurrentCharFormat(TextCharFormat.Handle modifier);
    void moveCursor(TextCursor.MoveOperation operation, TextCursor.MoveMode mode = MoveAnchor);
    bool overwriteMode();
    string placeholderText();

    // void print(QPagedPaintDevice *printer) const

    void setAcceptRichText(bool accept);
    void setAutoFormatting(AutoFormatting features);
    void setCurrentCharFormat(TextCharFormat.Handle format);
    void setCursorWidth(int width);
    void setDocument(TextDocument.Handle document);
    void setDocumentTitle(string title);
    void setExtraSelections(Array<ExtraSelection.Handle> selections);
    void setLineWrapColumnOrWidth(int w);
    void setLineWrapMode(LineWrapMode mode);
    void setOverwriteMode(bool overwrite);
    void setPlaceholderText(string placeholderText);
    void setReadOnly(bool ro);
    void setTabChangesFocus(bool b);
    void setTabStopDistance(double distance);
    void setTextCursor(TextCursor.Handle cursor);
    void setTextInteractionFlags(TextInteractionFlags flags_);
    void setUndoRedoEnabled(bool enable);
    void setWordWrapMode(TextOption.WrapMode policy);
    bool tabChangesFocus();
    double tabStopDistance();
    Color.Owned textBackgroundColor();
    Color.Owned textColor();
    TextCursor.Owned textCursor();
    TextInteractionFlags textInteractionFlags();
    string toHtml();
    string toMarkdown(TextDocument.MarkdownFeatures features = MarkdownDialectGitHub);
    string toPlainText();
    TextOption.WrapMode wordWrapMode();

    // slots

    void append(string text);
    void clear();
    void copy();
    void cut();
    void insertHtml(string text);
    void insertPlainText(string text);
    void paste();
    void redo();
    void scrollToAnchor(string name);
    void selectAll();
    void setAlignment(Alignment a);
    void setCurrentFont(Font.Handle f);
    void setFontFamily(string fontFamily);
    void setFontItalic(bool italic);
    void setFontPointSize(double s);
    void setFontUnderline(bool underline);
    void setFontWeight(int weight);
    void setHtml(string text);
    void setMarkdown(string markdown);
    void setPlainText(string text);
    void setText(string text);
    void setTextBackgroundColor(Color.Handle c);
    void setTextColor(Color.Handle c);
    void undo();
    void zoomIn(int range = 1);
    void zoomOut(int range = 1);

    // signals

    SignalConnection connect_CopyAvailable(SignalHandler handler);
    SignalConnection connect_CurrentCharFormatChanged(SignalHandler handler);
    SignalConnection connect_CursorPositionChanged(SignalHandler handler);
    SignalConnection connect_RedoAvailable(SignalHandler handler);
    SignalConnection connect_SelectionChanged(SignalHandler handler);
    SignalConnection connect_TextChanged(SignalHandler handler);
    SignalConnection connect_UndoAvailable(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string text, Widget.Handle parent = null);
