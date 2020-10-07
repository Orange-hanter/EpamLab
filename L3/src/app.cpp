/*
1.	Разработать класс «вектор» (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива 
    Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента
2.	Ввести 2 массива по 10 элементов, используя различные конструкторы.
3.	Один из массивов отсортировать (четные варианты – по убыванию, нечетные – по возрастанию), найти минимальное, среднее и максимальное значение массива. 
4.	Для второго массива выполнить задание по варианту
*/

#include "Vector.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *arr{ new int[10]{1,2,3,4,5,6,7,8,9,10} };
    Vector vect(arr, 10);
    Vector vect2(vect);
    cout << vect.getSummAfterMin() << endl;
    vect.sort(true);
    cout << vect[0] << ' ' << vect[vect.size() - 1] << endl;
    vect.sort();
    cout << vect[0] << ' ' << vect[vect.size() - 1] << endl;

    vect2.push(11);
    for (size_t i = 0; i < vect2.size(); i++)
        cout << vect2[i] << ' ';

    cout << endl << vect2.getAverage() << endl;
    return 0;
}
