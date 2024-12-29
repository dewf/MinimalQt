#pragma once

template <typename T>
struct RefCountedWrapper {
private:
    int refCount = 1;
public:
    T value;
    explicit RefCountedWrapper(T init) : value(init) {}
    void addRef() {
        refCount += 1;
    }
    void release() {
        refCount -= 1;
        if (refCount == 0) {
            delete this;
        }
    }
};
