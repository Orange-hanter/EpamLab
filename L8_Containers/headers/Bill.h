#pragma once
#include <iostream>
#include <string>
#include "Rate.h"



using std::istream;
using std::ostream;
using std::string;


/*
Implementation on bill account in a bank. Bill keep a summ of money, and have next operations:
void remittance(Bill& toAccaunt, double summ) -> a sum of money sent, in payment for goods / денежный перевод
Bill convertTo(Currency) -> convert a valute of bill

Bill operator-(double) -> an decrease in the total bill
Bill operator+(double) -> an increase in the total bill
*/
class Bill
{
private:
    double value{-1};
    Currency cur{EUR};
    Rate* RATES = new Rate();
public:
    Bill() = default;
    Bill(double, Currency);
    ~Bill();

    void remittance(Bill& toAccaunt, double summ);
    Bill convertTo(Currency);

    //an decrease in the total bill
    Bill operator-(double);
    Bill operator+(double);

    void operator-=(double);
    void operator+=(double);

    void operator=(const Bill& obj);

    friend istream &operator>>(istream &is, Bill &bill);
    friend ostream &operator<<(ostream &os, const Bill &bill);

public:
    class ErrNegBalanceOperation {
        friend ostream &operator<<(ostream &is, const ErrNegBalanceOperation &obj){
                is << "\n\nERROR: Negative balance error. Trying to go beyond negative balance\n\n";
                return is;
        }
    };

    class ErrInitFault {
        friend ostream &operator<<(ostream &is, const ErrInitFault &obj){
                is << "\n\nERROR: Incorrectly entered data\n\n";
                return is;
        }
    };
};
