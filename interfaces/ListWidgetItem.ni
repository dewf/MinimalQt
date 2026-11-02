module ListWidgetItem;

import Brush;
import Enums;
import Variant;
import Font;
import Icon;
import Size;

enum ItemType { Type, UserType }

// NOT a value type, although it's not QObject-based, either
opaque Handle {
    Brush.Owned background();
    CheckState checkState();
    Handle clone();
    Variant.Owned data(int role);
    ItemFlags flags_();
    Font.Owned font();
    Brush.Owned foreground();
    Icon.Owned icon();
    bool isHidden();
    bool isSelected();

    // QListWidget *	listWidget() const
    // moved to extension method in ListWidget

    // virtual void	read(QDataStream &in)
    // TODO

    void setBackground(Brush.Handle brush);
    void setCheckState(CheckState state);
    void setData(int role, Variant.Handle value);
    void setFlags(ItemFlags flags_);
    void setFont(Font.Handle font);
    void setForeground(Brush.Handle brush);
    void setHidden(bool hide);
    void setIcon(Icon.Handle icon);
    void setSelected(bool select);
    void setSizeHint(Size.Handle size);
    void setStatusTip(string statusTip);
    void setText(string text);
    void setTextAlignment(Alignment alignment);
    void setToolTip(string toolTip);
    void setWhatsThis(string whatsThis);
    Size.Owned sizeHint();
    string statusTip();
    string text();
    int textAlignment();
    string toolTip();
    int type();
    string whatsThis();

    // virtual void	write(QDataStream &out) const
    // virtual bool	operator<(const QListWidgetItem &other) const
    // QListWidgetItem &	operator=(const QListWidgetItem &other)
}

// ctors

// first 3 ctors are in ListWidget.ni (due to circular dependency)
// QListWidgetItem(QListWidget *parent = nullptr, int type = Type)
// QListWidgetItem(const QString &text, QListWidget *parent = nullptr, int type = Type)
// QListWidgetItem(const QIcon &icon, const QString &text, QListWidget *parent = nullptr, int type = Type)

Handle create(Handle other);
