#include <iostream>
#include <fstream>

#include <string>
using std::cin;
using std::cout;
using std::string;

template <typename T>
void workerWithStream(T &is)
{
    //do smth
}

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        std::ifstream ifs{argv[1]};
        workerWithStream(ifs);
    }
    else
        workerWithStream(std::cin);

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
    cout << cmd
    return EXIT_SUCCESS;
}