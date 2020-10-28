#include <iostream>
#include <string>
#include <assert.h>

#include "Rate.h"

using std::istream;
using std::ostream;

using std::cin;
using std::cout;

using std::string;


int main(int argc, char const *argv[])
{
  Rate rate;
  //  Bill pocket;
  //  cin >> pocket;
   cout << rate.convertKoeff("BYN", "EUR") << std::endl;
  return EXIT_SUCCESS;
}
