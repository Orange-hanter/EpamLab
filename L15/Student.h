#include <ostream>
#include "PCH.h"

class Student
{
private:
    //data
    short age;
    short curse;
    string fullName;
    char group;
    //config information
    static short sortFieldId;
    bool decr;  //
public:
    static size_t counter;
public:
    explicit Student();
    explicit Student(string fullName, short age, char group, short curse);
    Student(const Student& other);
    Student(Student&& other);
    ~Student();

    bool operator() (const Student& l, const Student& r);
    Student &operator=(Student &&obj);

    void setCompareble(short sortFieldId);
    void setDirrection(bool decrease);

    friend std::ostream &operator<<(std::ostream &os, const Student &obj);
};
