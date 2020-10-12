#pragma once
#include <string>
using std::string;

class AbstractPhone
{
private:
    string code;
    string number;
    float tarif;
    float talkTime;
public:
    AbstractPhone(){};
    virtual ~AbstractPhone() = 0;

    virtual float ammountCost() = 0;
    virtual void call(float duration) = 0;
};
