#include "Bill.h"
#include <algorithm>
#include <assert.h>
#include <sstream>
#include <cctype>

using std::for_each;


Bill::Bill(double _value, Currency _curr): value(_value), cur( _curr){ RATES = new Rate();}

Bill::~Bill(){ delete RATES;}

void Bill::remittance(Bill& toAccaunt, double summInLocalCur){
    this->value -= summInLocalCur;
    auto gg = RATES->rateMultiplayer(this->cur, toAccaunt.cur);
    auto valueByRate = this->value * gg;
    toAccaunt.value += valueByRate;
}

Bill Bill::convertTo(Currency newCurrency){
    auto valueByRate = this->value * RATES->rateMultiplayer(newCurrency,this->cur);
    return Bill(valueByRate, newCurrency);
}

Bill Bill::operator-(double delta)
{
    if( this->value - delta < 0)
        throw ErrNegBalanceOperation();
    return Bill(this->value - delta, this->cur);
   
}

Bill Bill::operator+(double delta){
    return Bill(this->value + delta, this->cur);
}

void Bill::operator-=(double delta)
{
    if( this->value - delta < 0)
            throw ErrNegBalanceOperation();
    this->value -= delta;
}

void Bill::operator+=(double delta){
    this->value += delta;
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
    if( curr == "" || bill.value < 0)
        throw Bill::ErrInitFault();
    bill.cur = strToCurrency(curr);
    if( bill.cur == Currency::NONE)
        throw Bill::ErrInitFault();
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


