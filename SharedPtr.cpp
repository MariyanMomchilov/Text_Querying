#ifndef SHAREDCPP
#define SHAREDCPP
#include "SharedPtr.hpp"

template <typename T>
SharedPtr<T>::SharedPtr(T *_ptr) : raw_ptr(_ptr), references(new size_t(0))
{
    if (raw_ptr != nullptr)
        ++(*references);
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &obj) : raw_ptr(obj.raw_ptr), references(obj.references)
{
    ++(*references);
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &obj)
{
    if (this != &obj)
    {
        --(*references);
        if (*references == 0)
            delete raw_ptr;
        references = obj.references;
        ++(*references);
        raw_ptr = obj.raw_ptr;
    }
    return *this;
}

template <typename T>
size_t SharedPtr<T>::count_references() const { return *references; }

template <typename T>
T &SharedPtr<T>::operator*()
{
    return *raw_ptr;
}

template <typename T>
T *SharedPtr<T>::operator->()
{
    return raw_ptr;
}

template <typename T>
T *SharedPtr<T>::operator->() const
{
    return raw_ptr;
}
template <typename T>
bool SharedPtr<T>::operator==(const SharedPtr<T> rhs) const
{
    return raw_ptr == rhs.raw_ptr && references == references;
}
template <typename T>
bool SharedPtr<T>::operator!=(const SharedPtr<T> rhs) const
{
    return !operator==(rhs);
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    --(*references);
    if (*references == 0)
    {
        delete raw_ptr;
        delete references;
        std::cout << "Deleted obj\n";
    }
}

#endif