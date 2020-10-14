#include <iostream>
#include <vector>
#include <string>

#ifdef __unix__
#include <bits/stdc++.h>
using std::size_t;
#elif _WIN32
#include <algorithm>
#endif

using std::vector;
using std::for_each;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<float> piVec = {3.f, 0.14f, 0.0015f, 0.00009f};
    auto begin = [&]{return piVec.begin();};
    auto end = [&]{return piVec.end();};
   
   
    cout << "Chapter ONE" << endl;
    cout << "Task1: print all elements of vector" << endl
        << "Current vector include next elements: ";
    for_each(begin(), end(), [](auto item){cout << item << ' ';});
    cout << endl << endl;

    cout << "Task2: show count of movements if sort algorithm." << endl;
    size_t movements = 0;
    sort(begin(), end(), [&movements](auto a, auto b){ return ++movements, a > b; });
    cout << "movements = " << movements << endl << endl;


    cout << "Task3: find substring in string" << endl;
    auto QnA = []()->bool{ 
        std::string input; 
        cin >> input; 
        return std::string::npos != std::string("abracadabra").find(input);
        };
    cout << ( QnA() ? "Yes, it`s" : "No, it isn`t") << " consist that substring" << endl; 


    cout << endl << endl << "Chapter TWO" << endl;
    cout << "Task1: print all elements of vector" << endl;
    auto newVector = [](int Size) -> vector<int> {
        vector<int> v;
        for (size_t i = 0; i < Size; i++)
            v.push_back(i);
        return v;
    };
    auto vGen = newVector(20);
    for_each(vGen.begin(), vGen.end(), [](auto item){cout << item << ' ';});
    cout << endl;

    cout << endl << "Task2: modify vector" << endl;
    auto modifyVector = [vGen](int k) -> vector<int> {
        vector<int> v;
        for_each(vGen.begin() + 2, vGen.end(), [&v](auto item){v.push_back(item);});
        for (size_t i = 0; i < k; i++)
            v.push_back(v.back() + 1);
        return v;
    };

    vGen = modifyVector(2);
    for_each(vGen.begin(), vGen.end(), [](auto item){cout << item << ' ';});
    cout << endl;
    return EXIT_SUCCESS;
}
