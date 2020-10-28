#include <iostream>
#include <string>
#include <assert.h>

#include "Bill.h"

using std::istream;
using std::ostream;

using std::cin;
using std::cout;

using std::string;


int main(int argc, char const *argv[])
{
  Rate *rate = new Rate();
   cout << "Rates today:"
        << "BYN -> EUR" << rate->rateMultiplayer("BYN", "EUR") << std::endl
        << "EUR -> BYN" << rate->rateMultiplayer("EUR", "BYN") << std::endl;
  delete rate;


  Bill pocket;
  cout << "Try to create a new bill in DaniilMegaSafe(haha-no)Bank\n" 
       << "Let's create a deposit. Specify the amount and type of currency\n"
       << "(don`t forget about space)\n";
  MARK:
  try
  {
    cin >> pocket;
  }
  catch(const Bill::ErrInitFault& e)
  {
    std::cerr << e << '\n' 
              << "Don`t worry, try again!\n";
    goto MARK;
  }
  
  cout << "Now you account have " << pocket;
  
  


  return EXIT_SUCCESS;
}
