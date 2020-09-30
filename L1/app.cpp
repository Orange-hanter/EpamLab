#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

#define arrSize(x) (sizeof(x->marks) / sizeof(x->marks[0]))

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::swap;

struct student
{
	string name;
	string lastName;
	int marks[3];
};

string getRandomName()
{
	string names[] = {"Ivan", "Gosha", "Dima", "Vlad"};
	return names[rand() % 4];
}

string getRandomLastName()
{
	string lastNames[] = {"Ivanov", "Goshaov", "Demianov", "Vladislavov"};
	return lastNames[rand() % 4];
}

float average(int *pArray)
{
	auto len = sizeof(pArray) / sizeof(pArray[0]);
	int summ{0};
	for (auto i = 0; i < len; i++)
		if (pArray)
			summ += pArray[i];
	return summ / float(len);
}

void render_students(student *pStudents, int countStudents)
{
	cout << endl;
	cout << right << setw(15) << "Student N"
		 << right << setw(15) << "Name"
		 << right << setw(15) << "Lastname"
		 << right << setw(20) << "Average marks." << endl;
	for (auto i = 0; i < countStudents; i++)
	{

		cout << right << setw(15) << "Student " << i + 1 << ':' 
			 << right << setw(15) << pStudents[i].name 
			 << right << setw(15) << pStudents[i].lastName 
			 << right  << setw(20) << average(pStudents[i].marks) << endl;
	}
}

student *sort_iv(student *pStudents, int countStudents, bool decr = true)
{
	for (auto i = 0; i < countStudents; i++)
	{
		float max = average(pStudents[i].marks);
		for (auto j = i; j < countStudents; j++)
		{
			float max_candidat = average(pStudents[j].marks);
			if (decr)
				if (max < max_candidat)
				{
					swap(pStudents[i], pStudents[j]);
					break;
				}
			if (!decr)
				if (max > max_candidat)
				{
					swap(pStudents[i], pStudents[j]);
					break;
				}
		}
	}

	return pStudents;
}

student *sort_iv2(student *pStudents, int countStudents, bool decr = true)
{
	for (auto i = 0; i < countStudents; i++)
	{
		int max_position{i};
		float max = average(pStudents[i].marks);
		for (auto j = i; j < countStudents; j++)
		{
			float max_candidat = average(pStudents[j].marks);
			if (decr)
				if (max < max_candidat)
				{
					max_position = j;
					max = max_candidat;
				}
			if (!decr)
				if (max > max_candidat)
				{
					max_position = j;
					max = max_candidat;
				}
		}
		swap(pStudents[i], pStudents[max_position]);
	}

	return pStudents;
}

int main()
{
	cout << "Enter count of students:";
	int countStudents;
	cin >> countStudents;

	student *epam_lab = new student[countStudents];

	cout << "Fill info about students:" << endl;
	for (int i = 0; i < countStudents; i++)
	{
		cout << "Student " << i + 1 << " name: ";
		//cin >> epam_lab[i].name;
		epam_lab[i].name = getRandomName();
		cout << "lastname: ";
		//cin >> epam_lab[i].lastName;
		epam_lab[i].lastName = getRandomLastName();
		for (size_t mark_pos = 0; mark_pos < arrSize(epam_lab); mark_pos++) 
			epam_lab[i].marks[mark_pos] = rand() % 10;
	}

	render_students(epam_lab, countStudents);
	cout << "After sorting" << endl;
	render_students(sort_iv2(epam_lab, countStudents), countStudents);

	delete[] epam_lab;
	return 0;
}