#include "PCH.h"
#include "algorithm.hpp"

/*
    task 1 look at folder ../L4
*/

int main(int argc, char const *argv[])
{
    string str {"hello, my dear"};
    auto func([](auto it_l, auto it_r){
        return string(it_l, it_r);
    });
    
    list<string> separated;
    split(begin(str), end(str), back_inserter(separated), ',', func);
    copy(begin(separated), end(separated), ostream_iterator<string>{cout, "\n"});
    return 0;
}
