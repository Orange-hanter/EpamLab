#pragma once

#include "abstractPhone.h"
#include <iostream>

class LandlinePhone : public AbstractPhone
{
private:

public:
    LandlinePhone() {
        tarif = 0.12f; 
        number = "8-127-355-35-35";
    }
    ~LandlinePhone() {}

    float ammountCost() override
    {
        return (float)talkTime * tarif; // with NDS
    }

    void printInfo() override
    {
        std::cout << "Landline type of connection."
                  << " TelephoneNumber is " << number
                  << ". Cost of conversation is equal " << tarif << "$/min" << std::endl;
    }
};