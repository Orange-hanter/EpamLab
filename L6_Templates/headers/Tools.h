#pragma once
#include <stddef.h>

template <typename uType, std::size_t size>
size_t getSize(const uType (&arg)[size])
{
    return size;
}

template <typename uType, std::size_t count>
void initArray(uType (&array)[count], uType InitValue)
{
    for (size_t i = 0; i < count; i++)
        array[i] = InitValue;
}

template <typename uType>
uType work(uType arg1, uType arg2)
{
    return arg1 + arg2;
}

template <>
const char *work<const char *>(const char *arg1, const char *arg2)
{
    const char *ptr = strlen(arg1) > strlen(arg2) ? arg1 : arg2;
    const char *subStr = strlen(arg1) > strlen(arg2) ? arg2 : arg1;
    char *result = new char[strlen(ptr)];
    for (auto i = 0; *ptr != '\0'; ++ptr, ++subStr, ++i)
    {
        result[i] = *ptr == *subStr ? *ptr : '-';
    }
    return result;
}