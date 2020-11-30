#pragma once
#include "PCH.h"
#include "DBMS.h"
#include "resources.h"


PersonModel getRandRecord(){
    auto  gen_random ([](const int len) -> string {
    
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * 42);

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
    });
    
    PersonModel model;
    model.firstName = gen_random(5);
    model.seckondName = gen_random(5);
    model.lastName = gen_random(5);
    model.dBirth = rand();
    model.mBirth = rand();
    model.yBirth = rand();
    model.sex = rand() % 2 ? true : false;
    return model;
}

string getRecord(){
    string res, buf;
    cout << "First Name: ";
    cin >> buf; res += buf + ';';
    cout << "Seckond Name: ";
    cin >> buf; res += buf + ';';
    cout << "Seckond Name: ";
    cin >> buf; res += buf + ';';
    
    short date;
    cout << "Birth day: ";
    cin >> date; res += std::to_string(date) + ';';
    cout << "Birth month: ";
    cin >> date; res += std::to_string(date) + ';';
    cout << "Birth year: ";
    cin >> date; res += std::to_string(date) + ';';
    
    cout << "Male(y/n): ";
    cin >> buf;
    if(buf == "y")
        res += "false" + ';';
    else
        res += "true" + ';';

    return res;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Russian");
    DBMS db = DBMS();
    db.init();
    int menu {-1};
    bool work {true};
    while (work)
    {
        cout << menuRu << endl << "You choise:";
        cin >> menu;
        system("cls");
        short month {0};
        switch (menu)
        {
        case 1: //загрузить данные из файла 
            /* code */
            break;
        
        case 2: //ввести данные
            db.insert(PersonModel::makeModel(getRecord()));
            break;

        case 3: //добавление данных
            db.commit();
            break;

        case 4: //сортировка базы данных по алфавиту (по фамилии)
            db.selectWhere([](auto i){return true;});
            db.sortBy("firstName");
            break;

        case 6: //выбрать список людей, родившихся в заданном месяце
            cout << "Month(1-12):";
            cin >> month;
            db.selectWhere([month](PersonModel i){return i.mBirth == month;});
            break;

        case 9:
            for(auto& elem : db.getResult())
                cout << elem << endl;
            break;

        case 0:
            work = !work;
            break;
        default:
            break;
        }
        
        system("pause");
        system("cls");
    }
    return EXIT_SUCCESS;
}
