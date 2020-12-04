#pragma once
#include <stdio.h>
#include "PCH.h"


class Descriptor
{
private:
     FILE * _fileDescriptor;

public:
    explicit Descriptor(const char * file_name, const char * mode);
    explicit Descriptor(FILE* descriptor);
    ~Descriptor();

private:
    Descriptor(const Descriptor &) = delete;
    Descriptor & operator=(const Descriptor &) = delete;

public:
    size_t read(char * buffer, size_t size);
    void write( const char * buffer, size_t size);
    bool isEof();

};
