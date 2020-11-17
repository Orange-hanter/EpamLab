#pragma once
#include <cstddef>
#include <string.h>
#include <memory>

#ifdef __unix__
#include <bits/stdc++.h>
using std::size_t;
#elif _WIN32
#include <algorithm>
#endif

using std::max_element;
using std::min_element;
using std::for_each;
using std::sort;

template <typename T>
class Array
{
private:
    T *_array;

    T *start;
    T *end;

    size_t _size;
    size_t _usedSize;

public:
    Array();
    Array(T *array, size_t len);
    Array(size_t len, const T init = 0);
    Array(const Array &ptr);
    ~Array();

    void push(T value);
    T pop();
    size_t size();
    void erise();
    void reserve(size_t size);
    T* begin();
    T* ends();

    void sortArray(bool derc = false);
    T getSummAfterMin();
    T getMin();
    T getMax();
    T getAverage();

    T& operator[](const size_t);
};

template <typename T>
Array<T>::Array()
{
    _size = 16;
    _usedSize = 0;
    _array = new T[_size];

    memset(_array, 0, _size);

    start = _array;
    end = _array + _usedSize;
}

template <typename T>
Array<T>::Array(T *array, size_t len)
{
    if (array == nullptr)
    {
        //TODO: rise error
        return;
    }

    _usedSize = len;
    _size = _usedSize * 2;

    _array = new T[_size];
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(T));

    start = _array;
    end = _array + _usedSize;
}

template <typename T>
Array<T>::Array(size_t len, const T init)
{

    _usedSize = len;
    _size = _usedSize;

    _array = new T[_size];

    start = _array;
    end = _array + _usedSize;
    for_each(_array, _array + _usedSize, [init](auto i){ i = init;});
}

template <typename T>
Array<T>::Array(const Array &ptr)
{
    T *array = ptr._array;
    if (array == nullptr)
    {
        //TODO: rise error
        return;
    }

    _usedSize = ptr._usedSize;
    _size = _usedSize * 2;

    _array = new T[_size];
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(T));

    start = _array;
    end = _array + _usedSize;
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
        start = _array;
        end = _array + _usedSize;
    }

    _array[_usedSize++] = value;
    end++;
}

template <typename T>
T Array<T>::pop()
{
    if (_usedSize > 0)
        return _array[--_usedSize];
    return 0;
    // TODO: rise error
}

template <typename T>
size_t Array<T>::size()
{
    return _usedSize;
}

template< typename T>
void Array<T>::erise(){
    for_each(this->start, this->end, [](auto i){ i = 0;});
}

template< typename T>
T* Array<T>::begin(){
    return start;
}

template< typename T>
T* Array<T>::ends(){
    return end;
}

template< typename T>
void Array<T>::reserve(size_t size){
    T *buf = new T[_size + size];
        memcpy(buf, _array, _size);
        _size += size;

        delete[] _array;
        _array = buf;
        start = _array;
        end = _array + _usedSize;
}

template <typename T>
void Array<T>::sortArray(bool decr)
{
    if (decr)
        std::sort(start, end);
    else
        std::sort(start, end, std::greater<T>());
}

template <typename T>
T Array<T>::getSummAfterMin()
{
    T summ = 0;
    for (auto ptr = min_element(start, end - 1); ptr != end; ptr++)
        summ += *ptr;
    return summ;
}

template <typename T>
T Array<T>::getMin()
{
    return *min_element(start, end - 1);
}

template <typename T>
T Array<T>::getMax()
{
    return *max_element(start, end - 1);
}

template <typename T>
T Array<T>::getAverage()
{
    T *buf{new T[_size]};
    memcpy(buf, _array, _usedSize * sizeof(T));
    std::sort(buf, buf + _usedSize);
    return buf[(_usedSize - 1) / 2];
}

template <typename T>
T& Array<T>::operator[](const size_t index)
{
    if (index >= 0 && index < _size)
        return _array[index];
    exit(1);
}