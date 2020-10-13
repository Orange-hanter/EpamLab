#pragma once
#include <string>
#include <chrono>
using std::string;

class AbstractPhone
{
protected:
    string code;
    string number;
    float tarif;
    double talkTime;
    std::chrono::system_clock::time_point start;
public:
    AbstractPhone():talkTime(0){};
    virtual ~AbstractPhone(){};

    virtual float ammountCost() = 0;
    virtual void printInfo() = 0;

    virtual void startCall()
    {
        start = std::chrono::system_clock::now();
    };

    virtual void endCall()
    {
        auto end = std::chrono::system_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        talkTime += seconds.count() / 60.0;
    };
};
