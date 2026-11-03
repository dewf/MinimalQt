module SignalBlocker;

import Object;

@nodispose
opaque Handle {
    void dismiss();
    void reblock();
    void unblock();
    // QSignalBlocker &	operator=(QSignalBlocker &&other)
}
@useparenttype
opaque Owned extends Handle;

Owned create(Object.Handle obj);
// QSignalBlocker(QSignalBlocker &&other)

// naive recursive approach didn't work :(

// group Recursive {
//     @nodispose
//     opaque Handle {
//     }
//     @useparenttype
//     opaque Owned extends Handle;

//     Owned create(Object.Handle root);
// }
