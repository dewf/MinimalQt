module PersistentModelIndex;

import ModelIndex;
import Variant;
import Enums;

@nodispose
opaque Handle {
    int hashCode();

    int column();
    Variant.Owned data(ItemDataRole role = DisplayRole); // should be 'int'
    ItemFlags flags_();
    bool isValid();

    // moved to AbstractItemModel.ni extension method
    // AbstractItemModel_Handle model(); // TODO: const

    // (since 6.0) void multiData(QModelRoleDataSpan roleDataSpan) const
    // TODO

    ModelIndex.Owned parent();
    int row();
    ModelIndex.Owned sibling(int row, int column);

    // void swap(QPersistentModelIndex &other)

    ModelIndex.Owned asModelIndex();

    // return 'this':
    Handle operator_assign(Handle other);
    Handle operator_assign(ModelIndex.Handle other);
}
opaque Owned extends Handle;

Owned create(ModelIndex.Handle index);
Owned create(Handle other);

// operators ==========================

// size_t qHash(const QPersistentModelIndex &key, size_t seed = 0)
// see 'hashCode' method

bool operator_notEqual(Handle lhs, ModelIndex.Handle rhs);
bool operator_notEqual(Handle lhs, Handle rhs);
bool operator_lessThan(Handle lhs, Handle rhs);
bool operator_equal(Handle lhs, ModelIndex.Handle rhs);
bool operator_equal(Handle lhs, Handle rhs);

// list ===============================

@nodispose
opaque List {
    int count();
    Owned itemAt(int index);
    Array<Owned> items();
}
opaque OwnedList extends List;
