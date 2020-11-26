#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::string;

#include <list>
// так как в задании не указан тип элементов,
// которые хранятся в списке, то давайте сделаем
// эту функцию шаблонной
// Параметр It — это тип итератора
template <class It>
size_t max_increasing_len(It p, It q)
{
    size_t summ{0}, buf{0};
    auto i = p, prev = p, start = p;
    if (p == q)
        return 0;
    
    for (; i != q; ++i)
    {
        if (*i > *prev)
        {
            ++buf;
            prev = i;
        }
        else
        {
            start++;
            prev = i = start;
            summ = summ < ++buf ? buf : summ;
            buf = 0;
            if(i == q) break;
        }
    }
    ++buf;
    return summ < buf ? buf : summ;
}
