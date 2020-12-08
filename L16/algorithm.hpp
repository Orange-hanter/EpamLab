#pragma once
#include <algorithm>
using std::find;
using std::next;

template< typename InIt, typename OutIt, typename Splitter, typename Func>
InIt split(InIt begin_it, InIt end_it,  OutIt out_it, Splitter splitVal, Func bindFunc){
    while (begin_it != end_it)
    {
        auto sliceEnd( find(begin_it, end_it, splitVal) );
        *out_it++ = bindFunc(begin_it, sliceEnd);
        if( sliceEnd == end_it) return end_it;
        begin_it = next(sliceEnd);
    }
    
    return begin_it;
}