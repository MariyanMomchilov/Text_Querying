#ifndef SHARED
#define SHARED
#include <iostream>

//basic sharing class for wrapping raw pointers

template <typename T>
class SharedPtr
{
private:
    T *raw_ptr;
    size_t *references;

public:
    explicit SharedPtr(T *_ptr = nullptr); // assuming that we wont have something like SharedPtr(&(*SharedPtrObj))
    SharedPtr(const SharedPtr<T> &obj);
    SharedPtr<T> &operator=(const SharedPtr<T> &obj);
    size_t count_references() const;
    T &operator*();
    //T operator*() const;
    T *operator->();
    T *operator->() const;
    bool operator==(const SharedPtr<T> rhs) const;
    bool operator!=(const SharedPtr<T> rhs) const;

    ~SharedPtr();
};

#endif