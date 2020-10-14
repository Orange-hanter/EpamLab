#include <iostream>
#include <string>
#include "Array2D.hpp"

using namespace std;



int main(int argc, char const *argv[])
{
    size_t n{5}, m{5};
    int taskValue = 3;
    Array2D arr(n, m);
    for (size_t i = 0; i < n; i++)
        arr[i][i] = i;
    arr[4][4] = 9;
    cout << arr;
    cout << "Count of row that have elements summ less then " << taskValue
        << ", are: " << countRowOfSmalerAverage(arr, taskValue) << endl;

    return EXIT_SUCCESS;
}

