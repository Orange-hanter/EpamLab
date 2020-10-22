#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <sstream>
#include "Currency.h"

using std::istream;
using std::ostream;

using std::cin;
using std::cout;

using std::for_each;
using std::string;

int main(int argc, char const *argv[])
{
    Bill pocket;
    cin >> pocket;
    cout << pocket << std::endl;
    return EXIT_SUCCESS;
}
