#pragma once
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <new>
#define DEBUG
template <typename T>
class Array
{
private:
    T *_array;

    T *_begin;
    T *_end;

    size_t _size;
    size_t _usedSize;

public:
    Array();
    Array(T *array, size_t len);
    Array(size_t len, const T init = 0);
    Array(const Array &ptr);
    Array(Array &&ptr);
    ~Array();

    void push(T value);
    void pushArray(T* values, size_t len);
    T pop();
    size_t size();
    void erise();
    void reserve(size_t size);
   
    T* data();

    T* begin();
    T* end();

    T& operator[](const size_t&);
    Array<T>& operator= ( Array<T> && );
};

template <typename T>
Array<T>::Array()
{
    _size = 16;
    _usedSize = 0;
    _array = new(std::nothrow) T[_size];
    if (_array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }
    
    memset(_array, 0, _size);

    _begin = _array;
    _end = _array + _usedSize;
}

template <typename T>
Array<T>::Array(T *array, size_t len)
{
    if (array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }

    _usedSize = len;
    _size = _usedSize * 2;

    _array = new(std::nothrow) T[_size];
    if (_array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(T));

    _begin = _array;
    _end = _array + _usedSize;
}

template <typename T>
Array<T>::Array(size_t len, const T init)
{
    _usedSize = len;
    _size = _usedSize;

    _array = new(std::nothrow) T[_size];
    if (_array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }

    _begin = _array;
    _end = _array + _usedSize;
    //for_each(_array, _array + _usedSize, [init](auto i){ i = init;});
    for (auto ptr = _begin; ptr != _end; ++ptr){
        *ptr = init;
    }
    
}

template <typename T>
Array<T>::Array(const Array &ptr)
{
    #ifdef DEBUG
        cout << "Used copy constructor\n";
    #endif
    T *array = ptr._array;
    if (array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }

    _usedSize = ptr._usedSize;
    _size = _usedSize * 2;

    _array = new(nothrow) T[_size];
    if (_array == nullptr) {
        throw std::runtime_error("Attempt to init array by nullpointer\n");
    }
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(T));

    _begin = _array;
    _end = _array + _usedSize;
}

template <typename T>
Array<T>::Array(Array &&other){
    #ifdef DEBUG
        cout << "Used move constructor\n";
    #endif
    _size = other._size;
    _usedSize = other._usedSize;
    _array = other._array;
    other._array = nullptr;
    _begin = other._begin;
    _end = other._end;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
void Array<T>::push(T value)
{
    if (_usedSize == _size)
    {
        T *buf = new T[_size * 2];
        memcpy(buf, _array, _size);
        _size *= 2;

        delete[] _array;
        _array = buf;
        _begin = _array;
        _end = _array + _usedSize;
    }

    _array[_usedSize++] = value;
    _end++;
}

template<typename T>
void Array<T>::pushArray(T* values, size_t len){
    if(len > (_size - _usedSize))
        reserve(len - (_size - _usedSize));
    
    memcpy(_end, values, len);
    _usedSize += len;
    _end = _array + _usedSize;
    
}

template <typename T>
T Array<T>::pop()
{
    if (_usedSize > 0)
        return _array[--_usedSize];
    throw std::runtime_error("Buffer is empty\n");
    // TODO: rise error
}

template <typename T>
size_t Array<T>::size()
{
    return _usedSize;
}

template< typename T>
void Array<T>::erise(){
    for_each(this->_begin, this->_end, [](auto i){ i = 0;});
    _usedSize = 0;
    _end = _array;
}

template< typename T>
T* Array<T>::begin(){
    return _begin;
}

template< typename T>
T* Array<T>::end(){
    return _end;
}

template< typename T>
void Array<T>::reserve(size_t size){
    T *buf = new T[_size + size];
        memcpy(buf, _array, _size);
        _size += size;

        delete[] _array;
        _array = buf;
        _begin = _array;
        _end = _array + _usedSize;
}

template<typename T>
T* Array<T>::data()
{
    return this->_array;
}

template <typename T>
T& Array<T>::operator[](const size_t& index)
{
    if (index >= 0 && index < _size)
        return _array[index];
    throw std::out_of_range ("index mismatch\n");
}

template<typename T>
Array<T>& Array<T>::operator= ( Array<T> && other){
    #ifdef DEBUG
        cout << "Used move constructor\n";
    #endif
    _size = other._size;
    _usedSize = other._usedSize;
    _array = other._array;
    other._array = nullptr;
    _begin = other._begin;
    _end = other._end;
    return *this;
}