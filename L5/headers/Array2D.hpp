#pragma once
#include <cstddef>
#include <string.h>
#include <memory>
#include <ostream>

#ifdef __unix__
#include <bits/stdc++.h>
using std::size_t;
#elif _WIN32
#include <algorithm>
#endif

using std::max_element;
using std::min_element;
using std::sort;

class Array2D
{
private:
    int **_array;

    size_t rowCount;
    size_t colCount;

public:
    Array2D(size_t rowCount, size_t colCount, int fill = 0);
    Array2D(const Array2D &ptr);
    ~Array2D();

    friend std::ostream &operator<<(std::ostream &os, const Array2D &obj);

    friend int countRowOfSmalerAverage(const Array2D &obj, int value);

    int *operator[](const size_t);
};

Array2D::Array2D(size_t rowCount, size_t colCount, int fill) : rowCount(rowCount), colCount(colCount)
{
    _array = new int *[rowCount];
    for (size_t row = 0; row < rowCount; ++row)
    {
        _array[row] = new int[colCount];
       std::for_each(_array[row], _array[row] + colCount + 1, [fill](auto &obj){ obj = fill;});
    }
}

Array2D::~Array2D()
{
    for (auto i = 0; i < colCount; ++i)
        delete[] _array[i];
    delete[] _array;
}

int *Array2D::operator[](const size_t index)
{
    //TODO: remember how to use proxy pattern
    assert(index >= 0 && index < rowCount);
    return _array[index];
}

std::ostream &operator<<(std::ostream &os, const Array2D &obj)
{
    os << "Size of the object:" << obj.rowCount << 'x' << obj.colCount << std::endl;
    std::for_each(obj._array, obj._array + obj.rowCount, [&obj, &os](auto ptr) {
        std::for_each(ptr, ptr + (obj.colCount - 1), [&os](auto val) {
            os << val << ' ';
        });
        os << ptr[obj.colCount - 1] << std::endl;
    });
    return os;
}


int countRowOfSmalerAverage(const Array2D &obj, int value)
{
    size_t count = 0;
    std::for_each(obj._array, obj._array + obj.rowCount, [&](auto ptr) { 
        int sum = std::accumulate(ptr, ptr + obj.colCount, 0);
        sum < value ? count++ : (0);
    });
    return count;
}