#include "Student.h"

size_t Student::counter = 0;
short Student::sortFieldId = 3;
Student::Student(): age(32), curse(5), fullName("Ivan Ivanov"), group('C')
{
    Student::counter++;
}

Student::Student(string fullName, short age, char group, short curse):age(age), curse(curse), fullName(fullName), group(group)
{
    Student::counter++;
}

Student::Student(const Student& other): age(other.age), curse(other.curse), fullName(other.fullName), group(other.group)
{
    Student::counter++;
}

Student::Student(Student&& other): age(other.age), curse(other.curse), group(other.group)
{
    Student::counter++;
    fullName = std::move(other.fullName);
}

Student::~Student()
{
    Student::counter--;
    std::cerr << "Memory deallocated: " << *this;
}


 bool Student::operator() (const Student& l, const Student& r){
    switch (Student::sortFieldId)
    {
    case 1:
        return l.fullName > r.fullName;
        break;
    case 2:
        return l.age > r.age;
        break;
    
    case 3:
        return l.curse > r.curse;
    break;

    case 4:
        return l.group > r.group;
    break;

    default:
        throw std::runtime_error("Incorrect selected field of sorting\n");
        break;
    }
    
}

Student& Student::operator=(Student&& obj){
    this->age = obj.age;
    this->curse = obj.curse;
    this->group = obj.group;
    fullName = std::move(obj.fullName);
    return *this;
}

 void Student::setCompareble(short sortFieldId){
     Student::sortFieldId  = sortFieldId;
 }

void Student::setDirrection(bool decrease){
    this->decr = decrease;
}

std::ostream &operator<<(std::ostream &os, const Student &obj){
    os << obj.fullName << " " << obj.age << " " << obj.curse << " " << obj.group  << '\n';
    return os;
}