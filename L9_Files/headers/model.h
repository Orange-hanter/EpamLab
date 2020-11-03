#pragma once
#include <string>

using std::string;

typedef bool Sex;
#define female true
#define male false 


struct model
{
    string firstName;
    string seckondName;
    string lastName;

    //think how to use chrono or somth else
    short dBirth;
    short mBirth;
    short yBirth;
    Sex sex;
};
