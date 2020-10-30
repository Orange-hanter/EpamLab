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
          << "BYN -> EUR:\t" << rate->rateMultiplayer("BYN", "EUR") << std::endl
          << "EUR -> BYN:\t" << rate->rateMultiplayer("EUR", "BYN") << std::endl;
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
     catch (const Bill::ErrInitFault &e)
     {
          std::cerr << e << '\n'
                    << "Don`t worry, try again!\n";
          goto MARK;
     }

     cout << "Now you account have "
          << pocket;

     cout << "Sorry, but our service have a taxes. It cost 0.5 EUR per montn\n";
     Bill DaniilMegaSafeBank(100, Currency::BYN);
     pocket.remittance(DaniilMegaSafeBank, 0.5);

     cout << "Now you account have "
          << pocket
          << ".\nAnd bank account have "
          << DaniilMegaSafeBank
          << std::endl;

     cout << "Hello misster/maam. I`m verry sorry, but in out office made a misstake.\n"
          << "You don`t must pay taxes. For fix this situation, we give you bonus.\n"
          << "Our bank bring apologize\n";

     DaniilMegaSafeBank -= rate->converter(Currency::BYN, Currency::EUR, 1 * rate->rateMultiplayer(Currency::EUR, Currency::BYN));
     pocket += rate->converter(Currency::BYN, Currency::EUR, 1 * rate->rateMultiplayer(Currency::EUR, Currency::BYN));

     cout << "Now you account have "
          << pocket
          << ".\nAnd bank account have "
          << DaniilMegaSafeBank
          << std::endl;


     try
     {
          Bill kiprOfshore = pocket + 100000000;
          cout << kiprOfshore;
     }
     catch(const Bill::ErrNegBalanceOperation& e)
     {
          std::cerr << e << '\n';
     }
     
     return EXIT_SUCCESS;
}
