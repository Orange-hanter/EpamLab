#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>

using std::istream;
using std::ostream;
using std::string;
using std::for_each;

enum Currency
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

//private:
    string currencyToStr(Currency type = NONE) const;
};


string Bill::currencyToStr(Currency type ) const{
    if (type == NONE)
        type = this->cur;
    string currencyStr;
    
    assert(type == NONE);
    
    switch (type)
    {
    case EUR: return "EUR"; break;
    case RUB: return "RUB"; break;
    case PL:  return "PL";  break;
    case BYN: return "BYN"; break;
    case USD: return "USD"; break;
    default:
        assert( true);
        return "";
    };
}

istream &operator>>(istream &is, Bill &bill)
{
    std::string value;
    is >> value;

    return is;
}

ostream &operator<<(ostream &os, const Bill &bill)
{
    double param{bill.value}, fractpart, intpart;
    intpart = static_cast<int>(param);
    fractpart = param - intpart;
    std::string intpartStr{std::to_string(intpart)};
    std::string fractpartStr{std::to_string(fractpart)};
    std::stringstream ss;
    for_each(intpartStr.begin(), intpartStr.end(), [&ss, intpartStr, count = 3 - (intpartStr.size()%3)](auto item) mutable {
        ss << item;
        ++count;
        if (count % 3 == 0)  ss << ' ';
    });
    intpartStr = ss.str();
    os << intpartStr + '.' + fractpartStr + bill.currencyToStr();
    return os;
}