module Label;

import Object;
import Frame;
import Icon;
import Enums;
import Pixmap;
import Widget;


interface SignalHandler extends Frame.SignalHandler {
    void linkActivated(string link);
    void linkHovered(string link);
}

opaque Handle extends Frame.Handle {
    Alignment alignment();
    Widget.Handle buddy();
    bool hasScaledContents();
    bool hasSelectedText();
    int indent();
    int margin();

    // QMovie * movie() const

    bool openExternalLinks();

    // (since 6.0) QPicture picture() const

    Pixmap.Owned pixmap();

    // (since 6.1) QTextDocument::ResourceProvider resourceProvider() const

    string selectedText();
    int selectionStart();
    void setAlignment(Alignment alignment);
    void setBuddy(Widget.Handle buddy);
    void setIndent(int indent);
    void setMargin(int margin);
    void setOpenExternalLinks(bool open);

    // (since 6.1) void setResourceProvider(const QTextDocument::ResourceProvider &provider)

    void setScaledContents(bool state);
    void setSelection(int start, int length);
    void setTextFormat(TextFormatEnum format);
    void setTextInteractionFlags(TextInteractionFlags flags_);
    void setWordWrap(bool on);
    string text();
    TextFormatEnum textFormat();
    TextInteractionFlags textInteractionFlags();
    bool wordWrap();
    void clear();

    // void setMovie(QMovie *movie)

    void setNum(int num);
    void setNum(double num);

    // void setPicture(const QPicture &picture)

    void setPixmap(Pixmap.Handle pixmap);
    void setText(string text);

    // signals ============================
    SignalConnection connect_LinkActivated(SignalHandler handler);
    SignalConnection connect_LinkHovered(SignalHandler handler);
}

Handle create(Widget.Handle parent = null, WindowFlags flags_ = 0);
Handle create(string text, Widget.Handle parent = null, WindowFlags flags_ = 0);
