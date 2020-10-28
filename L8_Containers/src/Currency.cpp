#include "Currency.h"
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <cctype>

using std::for_each;


string currencyToStr(Currency type)
{
    string currencyStr;

    switch (type)
    {
    case EUR:
        return "EUR";
        break;
    case RUB:
        return "RUB";
        break;
    case PL:
        return "PL";
        break;
    case BYN:
        return "BYN";
        break;
    case USD:
        return "USD";
        break;
    default:
        assert(true);
        return "";
    };
}


Bill::Bill(double _value, Currency _curr): value(_value), cur( _curr){ }

Bill::~Bill(){ }


void Bill::remittance(Bill& toAccaunt, double summ){
    //TODO: 
}

Bill Bill::convertTo(Currency){
    //TODO:
    return Bill();
}

Bill Bill::operator-(double delta)
{
    return Bill(this->value - delta, this->cur);
}

Bill Bill::operator+(double delta){
    return Bill(this->value + delta, this->cur);
}

double Bill::converter(Currency from, Currency to, double summ){
    RATES.convertKoeff(from);
}

void Bill::operator=(const Bill& obj){
    if( cur == obj.cur )
        this->value = obj.value;
    assert( cur == obj.cur );
}

istream &operator>>(istream &is, Bill &bill)
{
    string curr;
    is >> bill.value >> curr;
    bill.cur = bill.strToCurrency(curr);
    return is;
}

ostream &operator<<(ostream &os, const Bill &bill)
{
    auto param{bill.value};
    int fpart = static_cast<int>((param - static_cast<int>(param)) * 1000); //narrow_cast
    string intpartStr{std::to_string(static_cast<int>(param))},
        fractpartStr{std::to_string(fpart)};
    std::stringstream ss;
    for_each(intpartStr.begin(), intpartStr.end(), [&ss, intpartStr, count = 3 - (intpartStr.size() % 3)](auto item) mutable {
        ss << item;
        ++count;
        if (count % 3 == 0)
            ss << ' ';
    });
    intpartStr = ss.str();
    intpartStr.pop_back();
    os << intpartStr + '.' + fractpartStr + ' ' + currencyToStr(bill.cur);
    return os;
}

Currency Bill::strToCurrency(string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    if (str == "EUR")
        return Currency::EUR;
    else if (str == "RUB")
        return Currency::RUB;
    else if (str == "PL")
        return Currency::PL;
    else if (str == "BYN")
        return Currency::BYN;
    else if (str == "USD")
        return Currency::USD;
    else
    {
        assert(true);
        return Currency::NONE;
    }
    return Currency::NONE;
}
