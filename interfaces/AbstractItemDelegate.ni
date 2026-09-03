module AbstractItemDelegate;

import Object;
import Widget;
import Size;
import ModelIndex;
import StyleOption; // ViewItem;
import Event;
import AbstractItemModel;
import Painter;

enum EndEditHint {
    NoHint,
    EditNextItem,
    EditPreviousItem,
    SubmitModelCache,
    RevertModelCache
}

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void closeEditor(Widget.Handle editor, EndEditHint hint);
    void commitData(Widget.Handle editor);
    void sizeHintChanged(ModelIndex.Handle index);
}

@nodispose
opaque Handle extends Object.Handle {
    Widget.Handle createEditor(Widget.Handle parent, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);
    void destroyEditor(Widget.Handle editor, ModelIndex.Handle index);
    bool editorEvent(Event.Handle event_, AbstractItemModel.Handle model, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);

    // moved to AbstractItemView.ni as extension method
    // bool helpEvent(HelpEvent event_, AbstractItemViewHandle view, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);

    void paint(Painter.Handle painter, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);
    void setEditorData(Widget.Handle editor, ModelIndex.Handle index);
    void setModelData(Widget.Handle editor, AbstractItemModel.Handle model, ModelIndex.Handle index);
    Size.Owned sizeHint(StyleOption.ViewItem.Handle option, ModelIndex.Handle index);
    void updateEditorGeometry(Widget.Handle editor, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);

    // signals ============================
    SignalConnection connect_CloseEditor(SignalHandler handler);
    SignalConnection connect_CommitData(SignalHandler handler);
    SignalConnection connect_SizeHintChanged(SignalHandler handler);
}
