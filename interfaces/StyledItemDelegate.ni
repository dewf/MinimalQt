module StyledItemDelegate;

import Object;
import AbstractItemDelegate;
import Widget;
import AbstractItemModel;
import ModelIndex;
import StyleOption; // ViewItem;

@methodprefix("sig_")
interface SignalHandler extends AbstractItemDelegate.SignalHandler;
// none extra

opaque Handle extends AbstractItemDelegate.Handle {
    // methods TODO (itemEditorFactory stuff)
    // no extra signals
}

Handle create(Object.Handle parent = null);

// subclass stuff ===============

namedbits DelegatedMethodMask {
    // just supporting a few for now
    CreateEditor,
    SetEditorData,
    SetModelData,
    DestroyEditor,
    UpdateEditorGeometry
    // others: TODO
}

@methodprefix("dm_")
interface DelegatedMethods {
    Widget.Handle createEditor(Widget.Handle parent, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);
    void setEditorData(Widget.Handle editor, ModelIndex.Handle index);
    void setModelData(Widget.Handle editor, AbstractItemModel.Handle model, ModelIndex.Handle index);
    void destroyEditor(Widget.Handle editor, ModelIndex.Handle index);
    void updateEditorGeometry(Widget.Handle editor, StyleOption.ViewItem.Handle option, ModelIndex.Handle index);
}

opaque Delegated extends Handle;
// no 'interior' methods yet

Delegated createDelegated(DelegatedMethods methods, DelegatedMethodMask mask, Object.Handle parent = null);
