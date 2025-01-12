module TextCursor;

enum MoveMode {
    MoveAnchor,
    KeepAnchor
}

enum MoveOperation {
    NoMove,

    Start,
    Up,
    StartOfLine,
    StartOfBlock,
    StartOfWord,
    PreviousBlock,
    PreviousCharacter,
    PreviousWord,
    Left,
    WordLeft,

    End,
    Down,
    EndOfLine,
    EndOfWord,
    EndOfBlock,
    NextBlock,
    NextCharacter,
    NextWord,
    Right,
    WordRight,

    NextCell,
    PreviousCell,
    NextRow,
    PreviousRow
}

enum SelectionType {
    WordUnderCursor,
    LineUnderCursor,
    BlockUnderCursor,
    Document
}

@nodispose
opaque Handle;
opaque Owned extends Handle;

