module ItemSelection;

import ModelIndex;
import ItemSelectionCommon;

@nodispose
opaque Handle {
    bool contains(ModelIndex.Handle index);
    ModelIndex.OwnedList indexes();
    void merge(Handle other, SelectionFlags command);
    void select(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight);
}

opaque Owned extends Handle;

Owned create();
Owned create(ModelIndex.Handle topLeft, ModelIndex.Handle bottomRight);
