module LineEdit;

import Object;
import Widget;
import Margins;
import Point;
import Icon;
import Enums;
import Action;
import Menu;
import Completer;
import Validator;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void cursorPositionChanged(int oldPos, int newPos);
    void editingFinished();
    void inputRejected();
    void returnPressed();
    void selectionChanged();
    void textChanged(string text);
    void textEdited(string text);
}

enum EchoMode { Normal, NoEcho, Password, PasswordEchoOnEdit }

enum ActionPosition {
    LeadingPosition,
    TrailingPosition
}

opaque Handle extends Widget.Handle {
    void addAction(Action.Handle action, ActionPosition position);
    Action.Handle addAction(Icon.Handle icon, ActionPosition position);
    Alignment alignment();
    void backspace();
    Completer.Handle completer();
    Menu.Handle createStandardContextMenu();
    void cursorBackward(bool mark, int steps = 1);
    void cursorForward(bool mark, int steps = 1);
    CursorMoveStyle cursorMoveStyle();
    int cursorPosition();
    int cursorPositionAt(Point.Handle pos);
    void cursorWordBackward(bool mark);
    void cursorWordForward(bool mark);
    void del();
    void deselect();
    string displayText();
    bool dragEnabled();
    EchoMode getEchoMode();
    void end(bool mark);
    bool hasAcceptableInput();
    bool hasFrame();
    bool hasSelectedText();
    void home(bool mark);
    string inputMask();
    void insert(string newText);
    bool isClearButtonEnabled();
    bool isModified();
    bool isReadOnly();
    bool isRedoAvailable();
    bool isUndoAvailable();
    int maxLength();
    string placeholderText();
    string selectedText();
    int selectionEnd();
    int selectionLength();
    int selectionStart();
    void setAlignment(Alignment flag);
    void setClearButtonEnabled(bool enable);
    void setCompleter(Completer.Handle completer);
    void setCursorMoveStyle(CursorMoveStyle style);
    void setCursorPosition(int position);
    void setDragEnabled(bool enabled);
    void setEchoMode(EchoMode mode);
    void setFrame(bool hasFrame);
    void setInputMask(string inputMask);
    void setMaxLength(int length);
    void setModified(bool modified);
    void setPlaceholderText(string text);
    void setReadOnly(bool state);
    void setSelection(int start, int length);
    void setTextMargins(Margins.Handle margins);
    void setTextMargins(int left, int top, int right, int bottom);
    void setValidator(Validator.ConstHandle validator);
    string text();
    Margins.Owned textMargins();
    Validator.ConstHandle validator();

    void clear();
    void copy();
    void cut();
    void paste();
    void redo();
    void selectAll();
    void setText(string text);
    void undo();

    // signals =================================
    SignalConnection connect_CursorPositionChanged(SignalHandler handler);
    SignalConnection connect_EditingFinished(SignalHandler handler);
    SignalConnection connect_InputRejected(SignalHandler handler);
    SignalConnection connect_ReturnPressed(SignalHandler handler);
    SignalConnection connect_SelectionChanged(SignalHandler handler);
    SignalConnection connect_TextChanged(SignalHandler handler);
    SignalConnection connect_TextEdited(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);
Handle create(string contents, Widget.Handle parent = null);
