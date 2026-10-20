module ItemSelectionModel;

import Object;
import ModelIndex;
import AbstractItemModel;

@withflags(SelectionFlags)
enum SelectionFlag {
    NoUpdate       = 0x0000,
    Clear          = 0x0001,
    Select         = 0x0002,
    Deselect       = 0x0004,
    Toggle         = 0x0008,
    Current        = 0x0010,
    Rows           = 0x0020,
    Columns        = 0x0040,
    SelectCurrent  = Select | Current,
    ToggleCurrent  = Toggle | Current,
    ClearAndSelect = Clear | Select
}

// ItemSelection ===========================================================
group ItemSelection {
    @nodispose
    opaque Handle {
        bool contains(ModelIndex.Handle index);
        ModelIndex.OwnedList indexes();
        void merge(Handle other, SelectionFlags command);
        void select(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight);
    }
    @useparenttype
    opaque Owned extends Handle;

    Owned create();
    Owned create(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight);
}

// ItemSelectionModel =======================================================

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void currentChanged(ModelIndex.Handle current, ModelIndex.Handle previous);
    void currentColumnChanged(ModelIndex.Handle current, ModelIndex.Handle previous);
    void currentRowChanged(ModelIndex.Handle current, ModelIndex.Handle previous);
    void modelChanged(AbstractItemModel.Handle model);
    void selectionChanged(ItemSelection.Handle selected, ItemSelection.Handle deselected);
}

opaque Handle extends Object.Handle {
    bool columnIntersectsSelection(int column, ModelIndex.Handle parent = null);
    ModelIndex.Owned currentIndex();
    bool hasSelection();
    bool isColumnSelected(int column, ModelIndex.Handle parent = null);
    bool isRowSelected(int row, ModelIndex.Handle parent = null);
    bool isSelected(ModelIndex.Handle index);
    AbstractItemModel.Handle model();
    bool rowIntersectsSelection(int row, ModelIndex.Handle parent = null);
    ModelIndex.OwnedList selectedColumns(int row = 0);
    ModelIndex.OwnedList selectedIndexes();
    ModelIndex.OwnedList selectedRows(int column = 0);
    ItemSelection.Owned selection();
    void setModel(AbstractItemModel.Handle model);
    void clear();
    void clearCurrentIndex();
    void clearSelection();
    void reset();
    void select(ItemSelection.Handle selection, SelectionFlags command);
    void select(ModelIndex.Handle index, SelectionFlags command);
    void setCurrentIndex(ModelIndex.Handle index, SelectionFlags command);

    // signals ============================
    SignalConnection connect_CurrentChanged(SignalHandler handler);
    SignalConnection connect_CurrentColumnChanged(SignalHandler handler);
    SignalConnection connect_CurrentRowChanged(SignalHandler handler);
    SignalConnection connect_ModelChanged(SignalHandler handler);
    SignalConnection connect_SelectionChanged(SignalHandler handler);
}

Handle create(AbstractItemModel.Handle model = null);
Handle create(AbstractItemModel.Handle model, Object.Handle parent);
