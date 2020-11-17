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

using namespace std;

class myC
{
public:
    string str;
public:
    myC()
    {
       try
        {
            throw std::exception();
            str = "Created";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        str += "!";
    }
};

int main(int argc, char const *argv[])
{
    int *arr{new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    myC cc;
    cout << cc.str;
    cout << "Raw array is like -> {1,2,3,4,5,6,7,8,9,10}" << endl;

    Array<int> vect(arr, 10);
    Array<int> vect2(vect);

    cout << "Summ of all element:"
         << vect.getSummAfterMin()
         << endl;

    vect.sortArray(true);
    cout << "First and last element after arrising sorting"
         << endl
         << vect[0] << ' ' << vect[vect.size() - 1]
         << endl;

    vect.sortArray();
    cout << "First and last element after decreasing sorting"
         << endl
         << vect[0] << ' ' << vect[vect.size() - 1]
         << endl;

    Array<int> vect3(13);
    cout << "Container initialithed by size: "
         << vect3.size()
         << endl;
    vect3.reserve(10);
    cout << "Container size after reserve: "
         << vect3.size()
         << endl;
    for_each(vect3.begin(), vect3.ends(), [](auto i) { cout << i << " "; });
    vect3.push(1);
    vect3[0] = 1;
    for_each(vect3.begin(), vect3.ends(), [](auto i) { cout << i << " "; });
    return EXIT_SUCCESS;
}
