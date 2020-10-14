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
