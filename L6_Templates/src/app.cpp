/*
1. сделать шаблонную функцию для работы с числовыми данными (пара чисел и массив чисел) 
    и специальную функцию для работы со строками делая произведение чисел (одинаковые символы в обеих строках)
2. Сделать шаблон класса "массив" для работы с одномерым динамическим массивом и провенрить его работу на массивах разгого типа.
    -КОнструктор
    -Деструктор
    -Нахождение суммы элементов
    -Максимума
    -Минимума
    -Сортировки
    -Среднего
*/

#include <iostream>
#include <string>
#include "Array.hpp"
#include "Tools.h"

using namespace std;



int main(int argc, char const *argv[])
{
    int testArray[] = {1,2,3,4,5,6,7};
    cout << "Size of array: " << getSize(testArray) << endl;

    int testArray2[20];
    initArray(testArray2, 1);
    cout << "arr[0] = "<< testArray2[0] << " ... arr[10] = " << testArray2[10] << " ... arr[19] = "  << testArray2[19] << " ... "  << endl; 

    int *arr{ new int[10]{1,2,3,4,5,6,7,8,9,10} };
    cout << "Raw array is like -> {1,2,3,4,5,6,7,8,9,10}" << endl;

    Array<int> vect(arr, 10);
    Array<int> vect2(vect);
    
    cout << "Summ of all element:"
         << vect.getSummAfterMin() 
         << endl;

    vect.sort(true);
    cout << "First and last element after arrising sorting" 
        << endl
        << vect[0] << ' ' << vect[vect.size() - 1] 
        << endl;

    vect.sort();
    cout << "First and last element after decreasing sorting" 
        << endl
        << vect[0] << ' ' << vect[vect.size() - 1] 
        << endl;


    cout << "List of element after push command:" << endl;
    vect2.push(11);
    for (size_t i = 0; i < vect2.size(); i++)
        cout << vect2[i] << ' ';

    cout << endl  
        << "Result of average function:"
        << vect2.getAverage() 
        << endl;
    
  
    cout << "work(\"std\", \"strds\") -> " << work("std", "strds") << endl;
    cout << "work(\"abrakadabra\", \"kadabra\") -> " << work("abrakadabra", "kadabra") << endl;
    cout << "work(4,4) -> " << work(4,4) << endl;
    return EXIT_SUCCESS;
}

