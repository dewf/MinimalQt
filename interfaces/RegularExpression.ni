module RegularExpression;

import Enums;

@withflags(PatternOptions)
enum PatternOption {
    NoPatternOption                = 0x0000,
    CaseInsensitiveOption          = 0x0001,
    DotMatchesEverythingOption     = 0x0002,
    MultilineOption                = 0x0004,
    ExtendedPatternSyntaxOption    = 0x0008,
    InvertedGreedinessOption       = 0x0010,
    DontCaptureOption              = 0x0020,
    UseUnicodePropertiesOption     = 0x0040
}

enum MatchType {
    NormalMatch = 0,
    PartialPreferCompleteMatch,
    PartialPreferFirstMatch,
    NoMatch
}

@withflags(MatchOptions)
enum MatchOption {
    NoMatchOption              = 0x0000,
    AnchorAtOffsetMatchOption  = 0x0001,
    // AnchoredMatchOption Q_DECL_ENUMERATOR_DEPRECATED_X("Use AnchorAtOffsetMatchOption instead") = AnchorAtOffsetMatchOption, // Rename@Qt6.0
    DontCheckSubjectStringMatchOption = 0x0002
}

@withflags(WildcardConversionOptions)
enum WildcardConversionOption {
    DefaultWildcardConversion = 0x0,
    UnanchoredWildcardConversion = 0x1,
    NonPathWildcardConversion = 0x2,
}

group Match {
    @nodispose
    opaque Handle {
        // TODO
    }
    opaque Owned extends Handle;
    // ctors/static: TODO
}

group MatchIterator {
    @nodispose
    opaque Handle {
        bool hasNext();
        bool isValid();
        MatchOptions getMatchOptions();
        MatchType getMatchType();
        Match.Owned next();
        Match.Owned peekNext();

        // implemented as extension method on RegularExpression handle (see bottom of file)
        // QRegularExpression	regularExpression() const

        void swap(Handle other);

        // operators ===========
        // QRegularExpressionMatchIterator &	operator=(QRegularExpressionMatchIterator &&iterator)
        // QRegularExpressionMatchIterator &	operator=(const QRegularExpressionMatchIterator &iterator)
    }
    opaque Owned extends Handle;

    Owned create();
    Owned create(Handle other);
}

@nodispose
opaque Handle {
    int captureCount();
    string errorString();

    MatchIterator.Owned globalMatch(string subject, size_t offset = 0, MatchType matchType = NormalMatch, MatchOptions matchOptions = NoMatchOption);

    bool isValid();

    Match.Owned match_(string subject, size_t offset = 0, MatchType matchType = NormalMatch, MatchOptions matchOptions = NoMatchOption);

    Array<string> namedCaptureGroups();
    void optimize();
    string pattern();
    size_t patternErrorOffset();
    PatternOptions getPatternOptions();
    void setPattern(string pattern);
    void setPatternOptions(PatternOptions options_);
    void swap(Handle other);

    // QRegularExpression &	operator=(QRegularExpression &&re)
    // QRegularExpression &	operator=(const QRegularExpression &re)
}
opaque Owned extends Handle;

Owned create();
Owned create(string pattern, PatternOptions options_ = NoPatternOption);
Owned create(Handle other);

// static methods ========================

string anchoredPattern(string expression);
string escape(string str);
Owned fromWildcard(string pattern, CaseSensitivity cs = CaseInsensitive, WildcardConversionOptions options_ = DefaultWildcardConversion);
string wildcardToRegularExpression(string pattern, WildcardConversionOptions options_ = DefaultWildcardConversion);

// operators =============================

// size_t	qHash(const QRegularExpression &key, size_t seed = 0)
// bool	operator!=(const QRegularExpression &lhs, const QRegularExpression &rhs)
// QDataStream &	operator<<(QDataStream &out, const QRegularExpression &re)
// QDebug	operator<<(QDebug debug, QRegularExpression::PatternOptions patternOptions)
// QDebug	operator<<(QDebug debug, const QRegularExpression &re)
// bool	operator==(const QRegularExpression &lhs, const QRegularExpression &rhs)
// QDataStream &	operator>>(QDataStream &in, QRegularExpression &re)

// extension method so C++ won't choke on it (since we no longer have 'fwdopaque')
Owned ext_MatchIterator_regularExpression(MatchIterator.Handle iterator);
