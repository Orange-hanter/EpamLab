#pragma once

#include "AbstractPhone.h"

class RadioPhone : public AbstractPhone
{
private:
    int freq;
public:
    RadioPhone(){}
    RadioPhone(int Freq):freq(Freq) {}
    ~RadioPhone() {}

    void changeFreq(int freq);
};