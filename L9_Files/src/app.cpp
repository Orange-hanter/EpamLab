#include <iostream>
#include <fstream>
#include <string>

#include "resources.h"
#include "model.h"

using std::cin;
using std::cout;
using std::string;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Russian");

    string str;
    char ch;
    string cmd;
    cin >> ch;
    if (ch == '"')
        do
        {
            cin >> ch;
            str += ch;
        } while (ch != '"');
    cout << cmd;
    return EXIT_SUCCESS;
}