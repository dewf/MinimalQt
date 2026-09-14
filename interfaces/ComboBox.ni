module ComboBox;

import Object;
import Size;
import Enums;
import Widget;
import Variant;
import AbstractItemModel;
import AbstractItemDelegate;
import AbstractItemView;
import Icon;
import Completer;
import LineEdit;
import Validator;
import ModelIndex;

@methodprefix("sig_")
interface SignalHandler extends Widget.SignalHandler {
    void activated(int index);
    void currentIndexChanged(int index);
    void currentTextChanged(string text);
    void editTextChanged(string text);
    void highlighted(int index);
    void textActivated(string text);
    void textHighlighted(string text);
}

enum InsertPolicy {
    NoInsert,
    InsertAtTop,
    InsertAtCurrent,
    InsertAtBottom,
    InsertAfterCurrent,
    InsertBeforeCurrent,
    InsertAlphabetically
}

enum SizeAdjustPolicy {
    AdjustToContents,
    AdjustToContentsOnFirstShow,
    AdjustToMinimumContentsLengthWithIcon
}

enum LabelDrawingMode {
    UseStyle,
    UseDelegate,
}

opaque Handle extends Widget.Handle {
    void addItem(string text, Variant.Handle userData = null);
    void addItem(Icon.Handle icon, string text, Variant.Handle userData = null);
    void addItems(Array<string> texts);
    Completer.Handle completer();
    int count();
    Variant.Owned currentData(int role = cast<int>(ItemDataRole.UserRole));
    int currentIndex();
    string currentText();
    bool duplicatesEnabled();
    int findData(Variant.Handle data, int role = cast<int>(ItemDataRole.UserRole), MatchFlags flags_ = MatchExactly | MatchCaseSensitive);
    int findText(string text, MatchFlags flags_ = MatchExactly | MatchCaseSensitive);
    bool hasFrame();
    void hidePopup();
    Size.Owned iconSize();
    void insertItem(int index, string text, Variant.Handle userData = null);
    void insertItem(int index, Icon.Handle icon, string text, Variant.Handle userData = null);
    void insertItems(int index, Array<string> list);
    InsertPolicy getInsertPolicy();
    void insertSeparator(int index);
    bool isEditable();
    Variant.Owned itemData(int index, int role = cast<int>(ItemDataRole.UserRole));
    AbstractItemDelegate.Handle itemDelegate();
    Icon.Owned itemIcon(int index);
    string itemText(int index);
    LabelDrawingMode getLabelDrawingMode();
    LineEdit.Handle lineEdit();
    int maxCount();
    int maxVisibleItems();
    int minimumContentsLength();
    AbstractItemModel.Handle model();
    int modelColumn();
    string placeholderText();
    void removeItem(int index);
    ModelIndex.Owned rootModelIndex();
    void setCompleter(Completer.Handle completer);
    void setDuplicatesEnabled(bool enable);
    void setEditable(bool editable);
    void setFrame(bool hasFrame);
    void setIconSize(Size.Handle size);
    void setInsertPolicy(InsertPolicy policy);
    void setItemData(int index, Variant.Handle value, int role = cast<int>(ItemDataRole.UserRole));
    void setItemDelegate(AbstractItemDelegate.Handle delegate_);
    void setItemIcon(int index, Icon.Handle icon);
    void setItemText(int index, string text);
    void setLabelDrawingMode(LabelDrawingMode labelDrawing);
    void setLineEdit(LineEdit.Handle edit);
    void setMaxCount(int max);
    void setMaxVisibleItems(int maxItems);
    void setMinimumContentsLength(int characters);
    void setModel(AbstractItemModel.Handle model);
    void setModelColumn(int visibleColumn);
    void setPlaceholderText(string placeholderText);
    void setRootModelIndex(ModelIndex.Handle index);
    void setSizeAdjustPolicy(SizeAdjustPolicy policy);
    void setValidator(Validator.ConstHandle validator);
    void setView(AbstractItemView.Handle itemView);
    void showPopup();
    SizeAdjustPolicy getSizeAdjustPolicy();
    Validator.ConstHandle validator();
    AbstractItemView.Handle view();
    void clear();
    void clearEditText();
    void setCurrentIndex(int index);
    void setCurrentText(string text);
    void setEditText(string text);

    // signals =============================
    SignalConnection connect_Activated(SignalHandler handler);
    SignalConnection connect_CurrentIndexChanged(SignalHandler handler);
    SignalConnection connect_CurrentTextChanged(SignalHandler handler);
    SignalConnection connect_EditTextChanged(SignalHandler handler);
    SignalConnection connect_Highlighted(SignalHandler handler);
    SignalConnection connect_TextActivated(SignalHandler handler);
    SignalConnection connect_TextHighlighted(SignalHandler handler);
}

Handle create(Widget.Handle parent = null);

// utility method:
Handle downcastFrom(Widget.Handle widget);
