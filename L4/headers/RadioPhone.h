#pragma once

#include "AbstractPhone.h"
#include <iostream>
using std::cout;
using std::endl;
class RadioPhone : public AbstractPhone
{
private:
    int freq;

public:
    RadioPhone() {}
    RadioPhone(int Freq) : freq(Freq) {}
    ~RadioPhone() {}

    void changeFreq(int newFreq)
    {
        freq = newFreq;
    }

    void startCall() override
    {
        cout << "START TRANSMITION\n";
        start = std::chrono::system_clock::now();
    };
    void endCall() override
    {
        cout << "ROGGER THAR. END\n";
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        talkTime += diff.count();
    };

    float ammountCost()
    {
        return 0.f;
    }

    void printInfo() override
    {
        cout << "Radio connection. Freq is " << freq << " MHz" << endl;
    }
};