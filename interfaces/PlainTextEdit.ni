module PlainTextEdit;

import Object;
import Widget;
import Point;
import Rect;
import Icon;
import Enums;
import AbstractScrollArea;
import TextOption;
import Menu;
import TextCursor;
import TextEdit;
import TextFormat;
import TextCharFormat;
import TextDocument;
import RegularExpression;
import Variant;
import Url;

@methodprefix("sig_")
interface SignalHandler extends AbstractScrollArea.SignalHandler {
    void blockCountChanged(int newBlockCount);
    void copyAvailable(bool yes);
    void cursorPositionChanged();
    void modificationChanged(bool changed);
    void redoAvailable(bool available);
    void selectionChanged();
    void textChanged();
    void undoAvailable(bool available);
    void updateRequest(Rect.Owned rect, int dy);
}

enum LineWrapMode {
    NoWrap,
    WidgetWidth
}

opaque Handle extends AbstractScrollArea.Handle {
    string anchorAt(Point.Handle pos);
    bool backgroundVisible();
    int blockCount();
    bool canPaste();
    bool centerOnScroll();
    Menu.Handle createStandardContextMenu();
    Menu.Handle createStandardContextMenu(Point.Handle position);
    TextCharFormat.Owned currentCharFormat();
    TextCursor.Owned cursorForPosition(Point.Handle pos);
    Rect.Owned cursorRect();
    Rect.Owned cursorRect(TextCursor.Handle cursor);
    int cursorWidth();
    TextDocument.Handle document();
    string documentTitle();
    void ensureCursorVisible();
    Array<TextEdit.ExtraSelection.Owned> extraSelections();
    bool find(string exp, TextDocument.FindFlags options_ = 0);
    bool find(RegularExpression.Handle exp, TextDocument.FindFlags options_ = 0);
    bool isReadOnly();
    bool isUndoRedoEnabled();
    LineWrapMode getLineWrapMode();
    Variant.Owned loadResource(int type, Url.Handle name);
    int maximumBlockCount();
    void mergeCurrentCharFormat(TextCharFormat.Handle modifier);
    void moveCursor(TextCursor.MoveOperation operation, TextCursor.MoveMode mode = MoveAnchor);
    bool overwriteMode();
    string placeholderText();

    // void print(QPagedPaintDevice *printer) const
    // TODO

    void setBackgroundVisible(bool visible);
    void setCenterOnScroll(bool enabled);
    void setCurrentCharFormat(TextCharFormat.Handle format);
    void setCursorWidth(int width);
    void setDocument(TextDocument.Handle document);
    void setDocumentTitle(string title);
    void setExtraSelections(Array<TextEdit.ExtraSelection.Handle> selections);
    void setLineWrapMode(LineWrapMode mode);
    void setMaximumBlockCount(int maximum);
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
    TextCursor.Owned textCursor();
    TextInteractionFlags getTextInteractionFlags();
    string toPlainText();
    TextOption.WrapMode wordWrapMode();

    void appendHtml(string html);
    void appendPlainText(string text);
    void centerCursor();
    void clear();
    void copy();
    void cut();
    void insertPlainText(string text);
    void paste();
    void redo();
    void selectAll();
    void setPlainText(string text);
    void undo();
    void zoomIn(int range = 1);
    void zoomOut(int range = 1);

    // signals ============================
    SignalConnection connect_BlockCountChanged(SignalHandler handler);
    SignalConnection connect_CopyAvailable(SignalHandler handler);
    SignalConnection connect_CursorPositionChanged(SignalHandler handler);
    SignalConnection connect_ModificationChanged(SignalHandler handler);
    SignalConnection connect_RedoAvailable(SignalHandler handler);
    SignalConnection connect_SelectionChanged(SignalHandler handler);
    SignalConnection connect_TextChanged(SignalHandler handler);
    SignalConnection connect_UndoAvailable(SignalHandler handler);
    SignalConnection connect_UpdateRequest(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string text, Widget.Handle parent = null);
