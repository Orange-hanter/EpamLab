/*
1.	Разработать класс «вектор» (одномерный динамический массив). Методы класса: конструкторы, деструктор и методы преобразования массива: 
    Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента
2.	Ввести 2 массива по 10 элементов, используя различные конструкторы.
3.	Один из массивов отсортировать (четные варианты – по убыванию, нечетные – по возрастанию), 
        найти минимальное, 
        среднее и максимальное значение массива. 
4.	Для второго массива выполнить задание по варианту
*/
#include <cstddef>

//template<typename T>
class Vector
{
private:
    int *_array;

    int *start;
    int *end;

    unsigned int _size;
    unsigned int _usedSize;

public:
    Vector();
    Vector(int *array, size_t len);
    Vector(const Vector &ptr);
    ~Vector();

    void push(int value);
    int pop();
    int size();
    void sort(bool derc = false);
    int getSummAfterMin();
    int getMin();
    int getMax();
    int getAverage();

    int& operator[](const int);

};