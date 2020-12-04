#include "PCH.h"
#include "Descriptor.h"
#include "Array.hpp"



int main(int argc, char const *argv[])
{
    Array<char> data;
    {
        Descriptor src{"C:/Users/Danil/OneDrive/Documents/EpamLab/L14/task.md", "r"};
        Array<char> tmp(2048);
        char * buf = new char[2048];
        do
        {
            size_t read_count = src.read(buf, 2048);

            if (read_count > 0)
            {
                tmp.pushArray(buf, read_count);
            }
        } while (!src.isEof());
        data = std::move(tmp);
    }
    std::ostream_iterator<char> out_it (std::cout,"");
    std::copy ( data.begin(), data.end(), out_it );
    return 0;
}
