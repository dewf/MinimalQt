module StyleOption;

import Widget;

enum OptionType {
    SO_Default, SO_FocusRect, SO_Button, SO_Tab, SO_MenuItem,
    SO_Frame, SO_ProgressBar, SO_ToolBox, SO_Header,
    SO_DockWidget, SO_ViewItem, SO_TabWidgetFrame,
    SO_TabBarBase, SO_RubberBand, SO_ToolBar, SO_GraphicsItem,

    SO_Complex = 0xf0000, SO_Slider, SO_SpinBox, SO_ToolButton, SO_ComboBox,
    SO_TitleBar, SO_GroupBox, SO_SizeGrip,

    SO_CustomBase = 0xf00,
    SO_ComplexCustomBase = 0xf000000
}

// I think they are all sharing these exact values, while redeclaring them for some reason ...
enum StyleOptionType { Type = cast<int>(OptionType.SO_Default) }
enum StyleOptionVersion { Version = 1 }

@nodispose
opaque Handle {
    void initFrom(Widget.Handle widget);

    // TODO: the real thing just has fields, not properties
    // Qt::LayoutDirection	direction
    // QFontMetrics	fontMetrics
    // QPalette	palette
    // QRect	rect
    // QStyle::State	state
    // QObject *	styleObject
    // int	type
    // int	version
}
@useparenttype
opaque Owned extends Handle;

Owned create(int version = cast<int>(StyleOptionVersion.Version), int type_ = cast<int>(OptionType.SO_Default));
Owned create(Handle other);


// ViewItem stuff ============================================
group ViewItem {

    enum Position { Left, Right, Top, Bottom }

    @withflags(ViewItemFeatures)
    enum ViewItemFeature {
        None = 0x00,
        WrapText = 0x01,
        Alternate = 0x02,
        HasCheckIndicator = 0x04,
        HasDisplay = 0x08,
        HasDecoration = 0x10,
        IsDecoratedRootColumn = 0x20,
        IsDecorationForRootColumn = 0x40,
    }

    enum ViewItemPosition { Invalid, Beginning, Middle, End, OnlyOne }

    @nodispose
    opaque Handle extends StyleOption.Handle {
        // TODO:
        // QBrush	backgroundBrush
        // Qt::CheckState	checkState
        // Qt::Alignment	decorationAlignment
        // QStyleOptionViewItem::Position	decorationPosition
        // QSize	decorationSize
        // Qt::Alignment	displayAlignment
        // QStyleOptionViewItem::ViewItemFeatures	features
        // QFont	font
        // QIcon	icon
        // QModelIndex	index
        // QLocale	locale
        // bool	showDecorationSelected
        // QString	text
        // Qt::TextElideMode	textElideMode
        // QStyleOptionViewItem::ViewItemPosition	viewItemPosition
        // const QWidget *	widget
    }
    @useparenttype
    opaque Owned extends Handle;

    Owned create();
    Owned create(Handle other);
}
