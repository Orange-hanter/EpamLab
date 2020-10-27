#pragma once
#include <iostream>
#include <string>


using std::istream;
using std::ostream;
using std::string;


enum Currency : unsigned int
{
    EUR,
    RUB,
    PL,
    BYN,
    USD,
    NONE
};
static const Currency ALL[] = {EUR, RUB, PL,
    BYN,
    USD,
    NONE};

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
    double value{0};
    Currency cur{EUR};

public:
    Bill() = default;
    Bill(double, Currency);
    ~Bill();

    void remittance(Bill& toAccaunt, double summ);
    Bill convertTo(Currency);

    Bill operator-(double);
    Bill operator+(double);

    
    static void converter(Currency from, Currency to, double summ);

    friend istream &operator>>(istream &is, Bill &bill);
    friend ostream &operator<<(ostream &os, const Bill &bill);

private:
    string currencyToStr(Currency type = NONE) const;
    Currency strToCurrency(string str);
};
