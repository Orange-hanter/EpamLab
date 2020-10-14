#pragma once

#include "AbstractPhone.h"
#include <iostream>
class MobylePhone : public AbstractPhone
{
private:
    string telephoneNumber{"8-800-777-77-66"};
    string tarifName{"'Shagi za gigi'"};

public:
    MobylePhone()
    {
        tarif = 0.5;
        number = "8-127-355-35-35";
    }
    MobylePhone(string newTarifName, float tarifPrice) : tarifName(newTarifName)
    {
        tarif = tarifPrice;
        talkTime = 0;
    }
    ~MobylePhone() {}

    float ammountCost() override
    {
        return (float)talkTime * tarif * 1.25f; // with NDS
    }

    void printInfo() override
    {
        std::cout << "Mobyle type of connection."
                  << " TelephoneNumber is " << telephoneNumber
                  << ". Tarif is: " << tarifName
                  << ". Cost of conversation is equal " << tarif << "$/min" << std::endl;
    }
};