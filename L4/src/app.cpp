/*
1. Создать базовый класс по варианту, содержащий 2 или более полей, 
    и определить в нем конструктор, деструктор и метод вывода на 
    экран значений полей класса. 

2. Разработать производные классы, в которые добавить минимум 1 
    поле и собственные методы (конструктор, деструктор, метод 
    вывода на экран значений полей класса и метод, реализующий 
    задание по варианту). 

3. Создать объекты разработанных классов и проверить работу 
    реализованных в них методов.  

    Базовый класс       |       Производные классы         |        Метод
7   Телефон             |   Стационарный, Мобильный, Радио | Общая стоимость разговоров
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "LandlinePhone.h"
#include "MobylePhone.h"
#include "RadioPhone.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int main(int argc, char const *argv[])
{
    vector<AbstractPhone*> allTypesOfConnection = { new RadioPhone(334), new MobylePhone(), new LandlinePhone() };
    
    for(auto& phone : allTypesOfConnection)
    {
       phone->printInfo();

        phone->startCall();
         sleep_until(system_clock::now() + seconds(3));
        phone->endCall();
       
        
        cout << "How much i spend? You spend " << phone->ammountCost() << "$ in this period \n";
        cout << endl;
    }
    return 0;
}
