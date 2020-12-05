#include "PCH.h"
#include "SharedPtr.hpp"
#include "Student.h"


int main(int argc, char const *argv[])
{
    vector<Student> students;
    students.push_back(Student("Daniil", 16, 'A', 1));
    students.push_back(Student("Semen", 15, 'A', 1));
    students.push_back(Student("Katia", 15, 'A', 2));
    students.push_back(Student("Olga", 16, 'B', 2));
    students.push_back(Student("Kirill", 17, 'C', 3));

    Student sortObj;
    sortObj.setCompareble(1);
    auto itBegin = students.begin();
    auto itEnd = students.end();
    for_each(itBegin, itEnd, [](const auto & i){ cout << i << '\n';});
    sort(itBegin, itEnd, std::move(sortObj) );
    for_each(itBegin, itEnd, [](const auto & i){ cout << i << '\n';});

    cout << sortObj.counter;
    return 0;
}
