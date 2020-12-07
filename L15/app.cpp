#include "PCH.h"
#include "SharedPtr.hpp"
#include "Student.h"
#include "MyAlloc.hpp"

int main(int argc, char const *argv[])
{
    vector<Student, Mallocator<Student>> students;
    students.emplace(students.end(), "Daniil", 16, 'A', 1 );
    std::cerr << endl;
    students.emplace(students.end(), "Semen", 15, 'A', 1 );
    std::cerr << endl;
    students.emplace(students.end(), "Katia", 15, 'A', 2 );
    std::cerr << endl;
    students.emplace(students.end(), "Olga", 16, 'B', 2  );
    std::cerr << endl;
    students.emplace(students.end(), "Kirill", 17, 'C', 3);
    std::cerr << endl;

    Student sortObj;
    sortObj.setCompareble(1);
    auto itBegin = students.begin();
    auto itEnd = students.end();
    for_each(itBegin, itEnd, [](const auto & i){ cout << i << '\n';});
    sort(itBegin, itEnd, std::move(sortObj) );
    for_each(itBegin, itEnd, [](const auto & i){ cout << i << '\n';});

    cout << sortObj.counter;
    {
        SharedPtr<Student> prt(new Student());
        cout << "Shared ptr:" << *prt << prt->counter;
    }
    return 0;
}
