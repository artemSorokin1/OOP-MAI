#pragma once
#include "allocator.h"
#include <memory>


namespace lab5 {

    template <typename T, typename Allocator = lab5::allocator<T>>
    class vector {
    public:
        using value_pointer = T*;
        using value_type = T;
        using value_reference = T &;
        using AllocTraits = std::allocator_traits<Allocator>;
        using const_value_reference = const T &;

        template<typename U>
        class Vector_iterator {
        private:
            value_pointer pointer;
        public:
            Vector_iterator() = default;
            Vector_iterator(const Vector_iterator & other) : pointer(other.pointer) {}
            Vector_iterator(Vector_iterator && other) noexcept : pointer(other.pointer) { other.pointer = nullptr; }
            explicit Vector_iterator(const value_pointer & other_ptr) : pointer(other_ptr) {}

            Vector_iterator & operator=(const Vector_iterator & other) {
                pointer = other.pointer;
                return *this;
            }

            Vector_iterator & operator=(Vector_iterator && other) {
                pointer = other.pointer;
                return *this;
            }

            Vector_iterator & operator++() {
                ++pointer;
                return *this;
            }

            Vector_iterator operator++(int) {
                Vector_iterator before_increment(*this);
                ++pointer;
                return before_increment;
            }

            bool operator==(const Vector_iterator & other) const { return this->pointer == other.pointer; }

            bool operator!=(const Vector_iterator & other) const { return !(this->pointer == other.pointer); }

            value_reference operator*() const { return *pointer; }

        };

        using iterator = Vector_iterator<T>;
        using const_iterator = Vector_iterator<const T>;

        iterator begin();

        const_iterator begin() const;

        iterator end();

        const_iterator end() const;

        vector();

        explicit vector(size_t n, value_type value = value_type());

        ~vector();

        size_t size() const;

        size_t capacity() const;

        value_reference operator[](size_t index);

        const_value_reference operator[](size_t index) const;

        value_reference at(size_t index);

        void push_back(const_value_reference val);

        void emplace_back(value_reference val);

        const value_type back() const;

        void resize(size_t n);

        void reserve(size_t n);

        bool empty() const { return _size == 0; }

        vector(const vector & other);

        vector(vector && other);

        vector & operator=(const vector & other);

        vector & operator=(vector && other) noexcept;


    private:
        T * _base;
        size_t _size;
        size_t _capacity;
        Allocator _alloc;

    };


    template <typename T, typename Allocator>
    void vector<T, Allocator>::reserve(size_t n) {
        if (n <= _capacity)
            return;

        T * new_arr = AllocTraits::allocate(_alloc, n);
        size_t i = 0;
        try {
            for (; i < _size; ++i) {
                AllocTraits::construct(_alloc, new_arr + i, _base[i]);
            }
        } catch (...) {
            for (size_t j = 0; j < i; ++j) {
                AllocTraits::destroy(_alloc, new_arr + j);
            }
            AllocTraits::deallocate(_alloc, new_arr, n);
            throw;
        }
        for (size_t k = 0; k < _size; ++k) {
            AllocTraits::destroy(_alloc, _base + k);
        }
        AllocTraits::deallocate(_alloc, _base, n);
        _base = new_arr;
        _capacity = n;
    }


    template <typename T, typename Allocator>
    void vector<T, Allocator>::push_back(const T & val) {
        if (_size == _capacity)
            reserve(_capacity * 2);
        AllocTraits::construct(_alloc, _base + _size, val);
        ++_size;
    }


    template <typename T, typename Allocator>
    vector<T, Allocator>::vector() : _size(0), _capacity(1) { _base = AllocTraits::allocate(_alloc, 1); }


    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(size_t n, T value) : _size(n), _capacity(n) {
        _base = AllocTraits::allocate(_alloc, n);
        for (size_t i = 0; i < n; ++i) {
            AllocTraits::construct(_alloc, _base + i, value);
        }
    }


    template <typename T, typename Allocator>
    vector<T, Allocator>::~vector() {
        for (size_t i = 0; i < _size; ++i) {
            AllocTraits::destroy(_alloc, _base + i);
        }
        AllocTraits::deallocate(_alloc, _base, _capacity);
        _size = 0;
        _capacity = 0;
        _base = nullptr;
    }


    template <typename T, typename Allocator>
    size_t vector<T, Allocator>::size() const { return _size; }


    template <typename T, typename Allocator>
    size_t vector<T, Allocator>::capacity() const { return _capacity; }


    template <typename T, typename Allocator>
    T & vector<T, Allocator>::operator[](size_t index) {
        return _base[index];
    }


    template <typename T, typename Allocator>
    const T & vector<T, Allocator>::operator[](size_t index) const {
        return _base[index];
    }


    template <typename T, typename Allocator>
    T & vector<T, Allocator>::at(size_t index) {
        if (index >= _size)
            throw std::out_of_range("Segmentation fault");
        return _base[index];
    }


    template <typename T, typename Allocator>
    void vector<T, Allocator>::emplace_back(T & val) {
        if (_size == _capacity)
            reserve(_size * 2);
        AllocTraits::construct(_alloc, _base + _size, val);
        ++_size;
    }


    template <typename T, typename Allocator>
    const T vector<T, Allocator>::back() const { return _base[_size - 1]; }


    template <typename T, typename Allocator>
    void vector<T, Allocator>::resize(size_t n) {
        if (n > capacity()) {
            reserve(n);
            _capacity = n;
            _size = n;
        } else {
            for (size_t i = n; i < _size; ++i) {
                AllocTraits::destroy(_alloc, _base + i);
            }
            _size = n;
        }
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() {
        return vector::iterator(_base);
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const {
        return vector::const_iterator(_base);
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::iterator vector<T, Allocator>::end() {
        return ++(vector::iterator(_base + _size - 1));
    }


    template <typename T, typename Allocator>
    typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const {
        return ++(vector::const_iterator(_base + _size - 1));
    }


    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(const vector<T, Allocator> & other) : vector(other.size()) {
        for (size_t i = 0; i < other.size(); ++i) {
            this->_base[i] = other[i];
            AllocTraits::destroy(_alloc, other._base + i);
        }
        AllocTraits::deallocate(_alloc, other._base, other._size);
    }


    template <typename T, typename Allocator>
    vector<T, Allocator> & vector<T, Allocator>::operator=(vector<T, Allocator> &&other) noexcept {
        this->resize(other.size());

        for (size_t i = 0; i < other.size(); ++i) {
            *this[i] = other[i];
            AllocTraits::destroy(_alloc, other._base + i);
        }
        AllocTraits::deallocate(_alloc, other._base, other,size());
        other._base = nullptr;
        return *this;
    }


    template <typename T, typename Allocator>
    vector<T, Allocator> & vector<T, Allocator>::operator=(const vector<T, Allocator> &other) {
        if (this == &other)
            return *this;
        this->resize(other.size());

        for (size_t i = 0; i < other.size(); ++i) {
            *this[i] = other[i];
            AllocTraits::destroy(_alloc, other._base + i);
        }
        AllocTraits::deallocate(_alloc, other._base, other,size());
        return *this;
    }


    template <typename T, typename Allocator>
    vector<T, Allocator>::vector(vector<T, Allocator> && other) : vector(other.size()) {
        *this = std::move(other);
        other = nullptr;
    }

}


template <typename T, typename Allocator>
std::ostream & operator<< (std::ostream & out, const lab5::vector<T, Allocator> & vec) {
    if (vec.empty())
        return out;
    out << "[ ";
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        out << vec[i] << ", ";
    }
    out << vec[vec.size() - 1] << " ]";

    return out;
}


