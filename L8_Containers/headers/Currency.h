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

class Rate
{
private:
    /* data */
public:
    Rate(/* args */);
    ~Rate();
};


class Bill
{
private:
    double value{0};
    Currency cur{EUR};

public:
    Bill() = default;
    ~Bill(){};

    friend istream &operator>>(istream &is, Bill &bill);
    friend ostream &operator<<(ostream &os, const Bill &bill);

private:
    string currencyToStr(Currency type = NONE) const;
    Currency strToCurrency(string str);
};
