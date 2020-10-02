#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <stdio.h>

/*
Task
Дана строка символов. Заменить в ней все рядом стоящие одинаковые символы на символ *.
*/

using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::string;
using std::swap;

class LabString
{
public:
    LabString(const char *initString = "")
    {
        size = strlen(initString) + 1;
        charset = new char[size];
        memcpy(charset, initString, size);
        reprocess();
    }

    void printString()
    {
        cout << charset << endl;
    }

    ~LabString()
    {
        delete[] charset;
    }

private:
    void replace(int start, int end, char simbol = '*')
    {
        for (size_t i = start; i < end; i++)
            charset[i] = simbol;
    }

    void reprocess()
    {
        auto startPos{-1};
        for (auto  i = 1; i <= size; i++)
        {
            if (startPos == -1 && charset[i] == charset[i - 1])
                startPos = i - 1;
            else if (startPos != -1 && (charset[i] != charset[i - 1] || i == size))
            {
                replace(startPos, i);
                startPos = -1;
            }
        }
    }

private:
    char *charset;
    size_t size;
};

int main()
{
    LabString str("Heloooooooo worlddd!!!");
    str.printString();
    cin.get();
    return 0;
}