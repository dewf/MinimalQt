#pragma once

template <typename T>
struct RefCountedWrapper {
private:
    int refCount = 1;
public:
    T value;
    explicit RefCountedWrapper(T init) : value(init) {}
protected:
    // publicly expose addRef() and release() on 'Owned'
    void addRefInternal() {
        refCount += 1;
    }
    void releaseInternal() {
        refCount -= 1;
        if (refCount == 0) {
            delete this;
        }
    }
    // publicly expose consume() on 'SafeReturn'
    T consumeInternal() {
        const auto ret = value;
        releaseInternal();
        return ret;
    }
};
