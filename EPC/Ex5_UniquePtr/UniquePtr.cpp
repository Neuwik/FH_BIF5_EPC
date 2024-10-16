#include "UniquePtr.h"

// Constructor implementations
template<typename T>
UniquePtr<T>::UniquePtr(T* rawPtr) : ptr(rawPtr), deleter(nullptr) {}

template<typename T>
UniquePtr<T>::UniquePtr(T* rawPtr, std::function<void(T*)> customDeleter)
    : ptr(rawPtr), deleter(customDeleter) {}

template<typename T>
UniquePtr<T>::~UniquePtr() {
    reset();
}

// Move constructor
template<typename T>
UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept 
    : ptr(other.ptr), deleter(std::move(other.deleter)) {
    other.ptr = nullptr;
}

// Move assignment operator
template<typename T>
UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr&& other) noexcept {
    if (this != &other) {
        reset();
        ptr = other.ptr;
        deleter = std::move(other.deleter);
        other.ptr = nullptr;
    }
    return *this;
}

// Dereference operator
template<typename T>
T& UniquePtr<T>::operator*() const {
    return *ptr;
}

// Arrow operator
template<typename T>
T* UniquePtr<T>::operator->() const {
    return ptr;
}

// Conversion to bool
template<typename T>
UniquePtr<T>::operator bool() const {
    return ptr != nullptr;
}

// Release ownership
template<typename T>
T* UniquePtr<T>::release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}

// Reset the pointer
template<typename T>
void UniquePtr<T>::reset(T* newPtr) {
    if (ptr) {
        if (deleter) {
            deleter(ptr);
        } else {
            delete ptr;
        }
    }
    ptr = newPtr;
}

// Swap managed object
template<typename T>
void UniquePtr<T>::swap(UniquePtr& other) {
    std::swap(ptr, other.ptr);
    std::swap(deleter, other.deleter);
}

// Explicit template instantiation for types used in the main program
template class UniquePtr<Entity>;
template class UniquePtr<std::string>;