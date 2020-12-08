#include "PCH.h"
#include <random>
#include <chrono>
#include "Sort.hpp"

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

int main(int argc, char const *argv[])
{
    random_device rnd_device;
    mt19937 mersenne_engine{rnd_device()}; 
    uniform_int_distribution<int> dist{1, 100000};

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    vector<int> vec(200);
    generate(begin(vec), end(vec), gen);
    vector<int> vecCopy(vec);
    
    copy( begin(vec), end(vec), ostream_iterator<int>{cout, " "});
    cout << endl << endl;

    


    auto t1 = std::chrono::high_resolution_clock::now();
    merge_sort(vec, 0, 199);
    auto t2 = std::chrono::high_resolution_clock::now();

    copy( begin(vec), end(vec), ostream_iterator<int>{cout, " "});
    cout << endl << endl;

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    std::cout << duration << " microseconds for user sort" << endl << endl;



    t1 = std::chrono::high_resolution_clock::now();
    sort(begin(vecCopy), end(vecCopy));
    t2 = std::chrono::high_resolution_clock::now();

    copy( begin(vecCopy), end(vecCopy), ostream_iterator<int>{cout, " "});
    cout << endl << endl;

    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    std::cout << duration << " microseconds for STL sort" << endl << endl;
    return 0;
}
