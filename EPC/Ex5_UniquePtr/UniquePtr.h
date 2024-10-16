#pragma once
#include <iostream>
#include <functional>

template<typename T>
class UniquePtr {
private:
    T* ptr;
    std::function<void(T*)> deleter;

public:
    explicit UniquePtr(T* rawPtr = nullptr);
    UniquePtr(T* rawPtr, std::function<void(T*)> customDeleter);
    ~UniquePtr();

    // Delete copy constructor and copy assignment
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept;

    // Move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept;

    // Dereference operator
    T& operator*() const;

    // Arrow operator
    T* operator->() const;

    // Conversion to bool
    operator bool() const;

    // Release ownership
    T* release();

    // Reset the pointer
    void reset(T* newPtr = nullptr);

    // Swap managed object
    void swap(UniquePtr& other);

    // Get raw pointer
    T* get() const;
};
