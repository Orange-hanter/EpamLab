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
using std::sort;

template <typename T>
class Array2D
{
private:
    T **_array;

    size_t rowCount;
    size_t colCount;

public:
    Array2D(size_t rowCount, size_t colCount);
    Array2D(const Array2D &ptr);
    ~Array2D();

    size_t size();
    void sortArray(bool derc = false);
    T getSummAfterMin();
    T getMin();
    T getMax();
    T getAverage();

    T &operator[](const size_t);
};

template <typename T>
Array2D<T>::Array2D(size_t rowCount, size_t colCount)
{
    _array = new T *[rowCount];
    for (int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];
}

template <typename T>
Array2D<T>::Array2D(const Array2D &ptr)
{
    
}

template <typename T>
Array2D<T>::~Array2D()
{
    for(auto i = 0; i < colCount; ++i)
        delete [] _array[i];
    delete [] _array;
}


template <typename T>
T &Array2D<T>::operator[](const size_t index)
{
    //TODO: remember how to use proxy pattern
    exit(1);
}