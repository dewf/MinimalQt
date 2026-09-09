module TextDocument;

import Object;
import Url;
import TextCursor;

@methodprefix("sig_")
interface SignalHandler {
    void baseUrlChanged(Url.Owned url);
    void blockCountChanged(int newBlockCount);
    void contentsChange(int position, int charsRemoved, int charsAdded);
    void contentsChanged();
    void cursorPositionChanged(TextCursor.Owned cursor);
    void documentLayoutChanged();
    void modificationChanged(bool changed);
    void redoAvailable(bool available);
    void undoAvailable(bool available);
    void undoCommandAdded();
}

@withflags(FindFlags)
enum FindFlag
{
    FindBackward        = 0x00001,
    FindCaseSensitively = 0x00002,
    FindWholeWords      = 0x00004
}

@withflags(MarkdownFeatures)
enum MarkdownFeature {
    MarkdownNoHTML = 0x0020 | 0x0040,
    MarkdownDialectCommonMark = 0,
    MarkdownDialectGitHub = 0x0004 | 0x0008 | 0x0400 | 0x0100 | 0x0200 | 0x0800 | 0x4000 | 0x100000
}

opaque Handle extends Object.Handle {
    // TODO

    // signals ================================
    SignalConnection connect_BaseUrlChanged(SignalHandler handler);
    SignalConnection connect_BlockCountChanged(SignalHandler handler);
    SignalConnection connect_ContentsChange(SignalHandler handler);
    SignalConnection connect_ContentsChanged(SignalHandler handler);
    SignalConnection connect_CursorPositionChanged(SignalHandler handler);
    SignalConnection connect_DocumentLayoutChanged(SignalHandler handler);
    SignalConnection connect_ModificationChanged(SignalHandler handler);
    SignalConnection connect_RedoAvailable(SignalHandler handler);
    SignalConnection connect_UndoAvailable(SignalHandler handler);
    SignalConnection connect_UndoCommandAdded(SignalHandler handler);
}

Handle create(Object.Handle parent = null);
Handle create(string text, Object.Handle parent = null);

// static methods ===================
// TODO
