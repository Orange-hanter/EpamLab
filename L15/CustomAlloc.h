#pragma once

template <typename T>
class CustomAlloc
{
public:
    CustomAlloc() = delete;
    CustomAlloc(const CustomAlloc&) noexcept{}

    T* allocate(const size_t& size)
    {
        auto ptr = reinterpret_cast<T*>(std::malloc(size * sizeof(T)));
        if (ptr) {
            return pointer;
        }
        throw std::bad_alloc();
    }

    void deallocate(T* pointer, size_t size) noexcept {
        std::free(pointer);
    }
};