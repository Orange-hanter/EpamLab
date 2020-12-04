#include "Descriptor.h"
#define DEBUG

Descriptor::Descriptor(const char *file_name, const char *mode)
{
    #ifdef DEBUG
        cout << "FILE DESCRIPTOR OPENED\n";
    #endif
    _fileDescriptor = fopen(file_name, mode);
    if (!_fileDescriptor)
    {
        throw std::runtime_error("Failed to open file\n");
    }
}

Descriptor::Descriptor(FILE *descriptor)
{
    #ifdef DEBUG
        cout << "FILE DESCRIPTOR OPENED\n";
    #endif
    _fileDescriptor = descriptor;
    if (!_fileDescriptor)
    {
        throw std::runtime_error("Failed to open file\n");
    }
}

Descriptor::~Descriptor()
{
    #ifdef DEBUG
        cout << "FILE DESCRIPTOR CLOSED\n";
    #endif

    if (_fileDescriptor)
    {
        fclose(_fileDescriptor);
    }
}

size_t Descriptor::read(char *buffer, size_t size)
{
    size_t read_count = fread(buffer, sizeof(char), size, _fileDescriptor);
    if ((read_count != size) && ferror(_fileDescriptor))
    {
        throw std::runtime_error("Failed to open file\n");
    }
    return read_count;
}

void Descriptor::write(const char * buffer, size_t size)
{
    size_t writedSize = fwrite(buffer, sizeof(char), size, _fileDescriptor);
    if (writedSize != size)
    {
        throw std::runtime_error("Failed to write to file\n");
    }
}


bool Descriptor::isEof()
{
  return feof(_fileDescriptor);
}