#include "Vector.h"
#include <string.h>
#include <bits/stdc++.h>
#include <memory>

using std::max_element;
using std::min_element;
using std::sort;

Vector::Vector()
{
    _size = 16;
    _usedSize = 0;
    _array = new int[_size];

    memset(_array, 0, _size);

    start = _array;
    end = _array + _usedSize;
}

Vector::Vector(int *array, size_t len)
{
    if (array == nullptr)
    {
        //TODO: rise error
        return;
    }

    _usedSize = len;
    _size = _usedSize * 2;

    _array = new int[_size];
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(int));

    start = _array;
    end = _array + _usedSize;
}

Vector::Vector(const Vector &ptr)
{
    int *array = ptr._array;
    if (array == nullptr)
    {
        //TODO: rise error
        return;
    }

    _usedSize = ptr._usedSize;
    _size = _usedSize * 2;

    _array = new int[_size];
    memset(_array, 0, _size);
    memcpy(_array, array, _usedSize * sizeof(int));

    start = _array;
    end = _array + _usedSize;
}

Vector::~Vector()
{
    delete[] _array;
}

void Vector::push(int value)
{
    if (_usedSize == _size)
    {
        int *buf = new int[_size * 2];
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

int Vector::pop()
{
    if (_usedSize > 0)
        return _array[--_usedSize];
    return 0;
    // TODO: rise error
}

int Vector::size()
{
    return _usedSize;
}

void Vector::sort(bool decr)
{
    if (decr)
        std::sort(start, end);
    else
        std::sort(start, end, std::greater<int>());
}

int Vector::getSummAfterMin()
{
    int summ = 0;
    for (auto ptr = min_element(start, end - 1); ptr != end; ptr++)
        summ += *ptr;
    return summ;
}

int Vector::getMin()
{
    return *min_element(start, end - 1);
}

int Vector::getMax()
{
    return *max_element(start, end - 1);
}

int Vector::getAverage()
{
    int *buf{new int[_size]};
    memcpy(buf, _array, _usedSize * sizeof(int));
    std::sort(buf, buf + _usedSize);
    return buf[(_usedSize-1) / 2];
}

int &Vector::operator[](const int index)
{
    if (index >= 0 && index < _size)
        return _array[index];
    exit(1);
}