#pragma once
#include <iostream>
#include <deque>

namespace lab5 {

    template<class T>
    class allocator {
    private:
        T * _memory;
        std::deque<T*> _pointers_to_free_blocks;
        size_t _free_index;

    public:
        static const size_t MAX_SIZE = 500;
        using type_pointer = T*;
        using value_type = T;

        allocator();

        ~allocator() = default;

        type_pointer allocate(size_t n = 1);

        void deallocate(type_pointer pointer, size_t n);

        template<class U> struct rebind { typedef allocator<U> other; };

        template<typename... Args>
        void construct(type_pointer pointer, Args&&... args) { new (pointer) value_type(std::forward<Args>(args)...); }

        void destroy(type_pointer pointer) { pointer->~value_type(); }

    };

    template <typename T>
    allocator<T>::allocator() : _free_index(0) {
        void * bytes = ::operator new(MAX_SIZE * sizeof(T));
        _memory = static_cast<T*>(bytes);
        _pointers_to_free_blocks.resize(MAX_SIZE);
        for (size_t i = 0; i < MAX_SIZE; ++i) {
            _pointers_to_free_blocks[i] = _memory + i;
        }
    }


    template <typename T>
    T * allocator<T>::allocate(size_t n) {
        if (n > MAX_SIZE - _free_index) {
            throw std::logic_error("No memory left");
        }
        T * memory = _pointers_to_free_blocks[_free_index];
        _free_index += n;
        return memory;
    }


    template <typename T>
    void allocator<T>::deallocate(T * pointer, size_t n) {
        _free_index -= n;
    }


    template <typename T, typename U>
    constexpr bool operator==(allocator<T> & lhs, allocator<U> & rhs) {
        return true;
    }


    template <typename T, typename U>
    constexpr bool operator!=(allocator<T> & lhs, allocator<U> & rhs) {
        return false;
    }

}
