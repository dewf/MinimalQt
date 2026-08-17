module ModelIndex;

import Variant;
import Enums;

@nodispose
opaque Handle {
    int hashCode();

    int column();
    Variant.Owned data(ItemDataRole role = DisplayRole); // should be int, but our const-expression stuff doesn't support casts right now
    ItemFlags getFlags();
    size_t internalId(); // is there any real difference between this and internalPointer?
    bool isValid();

    // moved to AbstractItemModel.ni as extension method
    // AbstractItemModelHandle model(); // TODO: should be const

    // void multiData(...) TODO

    Owned parent();
    int row();
    Owned sibling(int row, int column);
    Owned siblingAtColumn(int column);
    Owned siblingAtRow(int row);
}
opaque Owned extends Handle;

Owned create(); // empty/invalid

// operators ==============================

bool operator_notEqual(Handle lhs, Handle rhs);
bool operator_lessThan(Handle lhs, Handle rhs);
bool operator_equal(Handle lhs, Handle rhs);

// list ===============================

@nodispose
opaque List {
    int count();
    Owned itemAt(int index);
    Array<Owned> items();
}
opaque OwnedList extends List;
