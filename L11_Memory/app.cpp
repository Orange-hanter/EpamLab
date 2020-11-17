#include "../PHC.h"

// Task 1
struct Students {
    string firstName;
    string lastName;
    string eMail;
    short x = 0xAAAA;

};

void printStudent(const Students* student){
    cout << "First name: " << (*student).firstName << endl
        << "Last name: " << student->lastName << endl
        << "student e-mail: " << student->eMail << endl;
}

int main(int argc, char const *argv[])
{
    // Task 2 
    Students group_300[30];
    // Task 3
    Students* group_320 = new Students[30];
    
    // Task 4
    printStudent(group_300);
    printStudent(group_320);

    // Task 5
    cout << "Size of static array: " << sizeof(group_300)  << endl;
    cout << "Size of dynamyc array: " << sizeof(*group_320) * 30 << endl;

    // Task 6
    Students* begin = group_320;
    Students* end = group_320 + 30;
    for(Students* prev = begin; begin != end; ++begin){
        cout << "Element " << 30 - (end - begin) 
            << "\tAddress: " << begin
            << "\t\tShift: " << std::hex << reinterpret_cast<size_t>(begin) - reinterpret_cast<size_t>(prev)
            << endl;
            prev = begin;
    }

    // Task 7
    const auto p = group_320;
    cout << "Element has adress:\t\t\t\t\t" << p << endl
        << "\t internal element first name has adress\t\t" << &(p->firstName) << endl
        << "\t internal element last name has adress\t\t" << &(p->lastName) << endl
        << "\t internal element eMailk has adress\t\t" << &(p->eMail) << endl
        << "\t internal element x has adress\t\t\t" << &(p->x) << endl
        << "Adress of ending element is\t\t\t\t" << p+1
        << endl;

    //Task 8
    struct BadDataAlligment{
        int b;
        bool a;

    } bad;
    struct GoodDataAlligment{
        bool a;
        int b;

    } good;

    // THE END
    delete [] group_320;
    return EXIT_SUCCESS;
}
