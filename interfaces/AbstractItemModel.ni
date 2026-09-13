module AbstractItemModel;

import Object;
import Size;
import Enums;
import ModelIndex;
import PersistentModelIndex;
import Variant;
import MimeData;
import SafeReturn;

enum LayoutChangeHint
{
    NoLayoutChangeHint,
    VerticalSortHint,
    HorizontalSortHint
}

@withflags(CheckIndexOptions)
enum CheckIndexOption {
    NoOption         = 0x0000,
    IndexIsValid     = 0x0001,
    DoNotUseParent   = 0x0002,
    ParentIsInvalid  = 0x0004,
}

@methodprefix("sig_")
interface SignalHandler extends Object.SignalHandler {
    void columnsAboutToBeInserted(ModelIndex.Handle parent, int first, int last);
    void columnsAboutToBeMoved(ModelIndex.Handle sourceParent, int sourceStart, int sourceEnd, ModelIndex.Handle destinationParent, int destinationColumn);
    void columnsAboutToBeRemoved(ModelIndex.Handle parent, int first, int last);
    void columnsInserted(ModelIndex.Handle parent, int first, int last);
    void columnsMoved(ModelIndex.Handle sourceParent, int sourceStart, int sourceEnd, ModelIndex.Handle destinationParent, int destinationColumn);
    void columnsRemoved(ModelIndex.Handle parent, int first, int last);
    void dataChanged(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight, Array<ItemDataRole> roles);
    void headerDataChanged(Orientation orientation, int first, int last);
    void layoutAboutToBeChanged(PersistentModelIndex.List parents, LayoutChangeHint hint);
    void layoutChanged(PersistentModelIndex.List parents, LayoutChangeHint hint);
    void modelAboutToBeReset();
    void modelReset();
    void rowsAboutToBeInserted(ModelIndex.Handle parent, int start, int end);
    void rowsAboutToBeMoved(ModelIndex.Handle sourceParent, int sourceStart, int sourceEnd, ModelIndex.Handle destinationParent, int destinationRow);
    void rowsAboutToBeRemoved(ModelIndex.Handle parent, int first, int last);
    void rowsInserted(ModelIndex.Handle parent, int first, int last);
    void rowsMoved(ModelIndex.Handle sourceParent, int sourceStart, int sourceEnd, ModelIndex.Handle destinationParent, int destinationRow);
    void rowsRemoved(ModelIndex.Handle parent, int first, int last);
}

@nodispose
opaque ConstHandle extends Object.Handle {
    ModelIndex.Owned buddy(ModelIndex.Handle index);
    bool canDropMimeData(MimeData.Handle data, DropAction action, int row, int column, ModelIndex.Handle parent);
    bool canFetchMore(ModelIndex.Handle parent);
    bool checkIndex(ModelIndex.Handle index, CheckIndexOptions options_ = CheckIndexOptions.NoOption);
    int columnCount(ModelIndex.Handle parent = null);
    Variant.Owned data(ModelIndex.Handle index, int role = cast<int>(ItemDataRole.DisplayRole));
    ItemFlags flags_(ModelIndex.Handle index);
    bool hasChildren(ModelIndex.Handle parent = null);
    bool hasIndex(int row, int column, ModelIndex.Handle parent = null);
    Variant.Owned headerData(int section, Orientation orientation, int role = cast<int>(ItemDataRole.DisplayRole));
    ModelIndex.Owned index(int row, int column, ModelIndex.Handle parent = null);
    Map<int, Variant.Owned> itemData(ModelIndex.Handle index);
    Array<ModelIndex.Owned> match(ModelIndex.Handle start, int role, Variant.Handle value, int hits = 1, MatchFlags flags_ = MatchStartsWith | MatchWrap);
    MimeData.Handle getMimeData(Array<ModelIndex.Handle> indexes);
    Array<string> mimeTypes();

    // void multiData(const QModelIndex &index, QModelRoleDataSpan roleDataSpan)
    // TODO

    ModelIndex.Owned parent(ModelIndex.Handle index);

    // QHash<int, QByteArray> roleNames()
    // for what?
    // Map<int, Array<byte>> roleNames();

    int rowCount(ModelIndex.Handle parent = null);
    ModelIndex.Owned sibling(int row, int column, ModelIndex.Handle index);
    Size.Owned span(ModelIndex.Handle index);
    DropActions supportedDragActions();
    DropActions supportedDropActions();

    // signals ============================
    SignalConnection connect_ColumnsAboutToBeInserted(SignalHandler handler);
    SignalConnection connect_ColumnsAboutToBeMoved(SignalHandler handler);
    SignalConnection connect_ColumnsAboutToBeRemoved(SignalHandler handler);
    SignalConnection connect_ColumnsInserted(SignalHandler handler);
    SignalConnection connect_ColumnsMoved(SignalHandler handler);
    SignalConnection connect_ColumnsRemoved(SignalHandler handler);
    SignalConnection connect_DataChanged(SignalHandler handler);
    SignalConnection connect_HeaderDataChanged(SignalHandler handler);
    SignalConnection connect_LayoutAboutToBeChanged(SignalHandler handler);
    SignalConnection connect_LayoutChanged(SignalHandler handler);
    SignalConnection connect_ModelAboutToBeReset(SignalHandler handler);
    SignalConnection connect_ModelReset(SignalHandler handler);
    SignalConnection connect_RowsAboutToBeInserted(SignalHandler handler);
    SignalConnection connect_RowsAboutToBeMoved(SignalHandler handler);
    SignalConnection connect_RowsAboutToBeRemoved(SignalHandler handler);
    SignalConnection connect_RowsInserted(SignalHandler handler);
    SignalConnection connect_RowsMoved(SignalHandler handler);
    SignalConnection connect_RowsRemoved(SignalHandler handler);
}

// IIRC, @nodispose because these are abstract and we can't create them?
@nodispose
opaque Handle extends ConstHandle {
    bool clearItemData(ModelIndex.Handle index);
    bool dropMimeData(MimeData.Handle data, DropAction action, int row, int column, ModelIndex.Handle parent);
    void fetchMore(ModelIndex.Handle parent);
    bool insertColumn(int column, ModelIndex.Handle parent = null);
    bool insertColumns(int column, int count, ModelIndex.Handle parent = null);
    bool insertRow(int row, ModelIndex.Handle parent = null);
    bool insertRows(int row, int count, ModelIndex.Handle parent = null);
    bool moveColumn(ModelIndex.Handle sourceParent, int sourceColumn, ModelIndex.Handle destinationParent, int destinationChild);
    bool moveColumns(ModelIndex.Handle sourceParent, int sourceColumn, int count, ModelIndex.Handle destinationParent, int destinationChild);
    bool moveRow(ModelIndex.Handle sourceParent, int sourceRow, ModelIndex.Handle destinationParent, int destinationChild);
    bool moveRows(ModelIndex.Handle sourceParent, int sourceRow, int count, ModelIndex.Handle destinationParent, int destinationChild);
    bool removeColumn(int column, ModelIndex.Handle parent = null);
    bool removeColumns(int column, int count, ModelIndex.Handle parent = null);
    bool removeRow(int row, ModelIndex.Handle parent = null);
    bool removeRows(int row, int count, ModelIndex.Handle parent = null);
    bool setData(ModelIndex.Handle index, Variant.Handle value, int role = cast<int>(ItemDataRole.EditRole));
    bool setHeaderData(int section, Orientation orientation, Variant.Handle value, int role = cast<int>(ItemDataRole.EditRole));
    bool setItemData(ModelIndex.Handle index, Map<int, Variant.Handle> roles);
    void sort(int column, SortOrder order = AscendingOrder);
    // slots ==============================
    void revert();
    void submit();
}

// subclass (implementation) stuff ================================================================================

namedbits ImplementationMethodMask {
    // required, so not in mask:
    // index, parent, rowCount, columnCount, data

    // optional:
    HasChildren,
    SetData,
    Flags,
    HeaderData,
    SetHeaderData,
    Sort
}

@methodprefix("im_")
interface ImplementationMethods {
    // required:
    void index(int row, int column, ModelIndex.Handle parent, ModelIndexReturn ret);
    void parent(ModelIndex.Handle index, ModelIndexReturn ret);
    int rowCount(ModelIndex.Handle parent);
    int columnCount(ModelIndex.Handle parent);
    void data(ModelIndex.Handle index, int role, VariantReturn ret);

    // optional (mask-activated):
    bool hasChildren(ModelIndex.Handle parent);
    bool setData(ModelIndex.Handle index, Variant.Handle value, int role);
    ItemFlags getFlags(ModelIndex.Handle index, ItemFlags baseFlags);
    void headerData(int section, Orientation orientation, int role, VariantReturn ret);
    bool setHeaderData(int section, Orientation orientation, Variant.Handle value, int role);
    void sort(int column, SortOrder order);
}

opaque Interior extends Handle {
    // "interior" methods, to call as if we're the C++ subclass:

    // signal emission
    void emitDataChanged(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight, Array<ItemDataRole> roles);
    void emitHeaderDataChanged(Orientation orientation, int first, int last);

    // for access to protected stuff from MethodDelegate
    void beginInsertRows(ModelIndex.Handle parent, int first, int last);
    void endInsertRows();

    void beginRemoveRows(ModelIndex.Handle parent, int first, int last);
    void endRemoveRows();

    void beginResetModel();
    void endResetModel();

    ModelIndex.Owned createIndex(int row, int column, size_t ptr);
}

Interior createImplementation(ImplementationMethods methods, ImplementationMethodMask mask);

// extension methods to break circular dependencies ==============

// ModelIndex extension methods:
ConstHandle ext_ModelIndex_model(ModelIndex.Handle index);

// PersistentModelIndex extension methods:
ConstHandle ext_PersistentModelIndex_model(PersistentModelIndex.Handle index);
