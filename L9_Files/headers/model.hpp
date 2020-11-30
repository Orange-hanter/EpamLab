#pragma once
#include "PCH.h"

typedef bool Sex;
#define female true
#define male false

class interfaceModel
{

public:
    virtual ~interfaceModel(){};
    virtual vector<string> elementList() = 0;
    //virtual auto operator[] (const char* name)  = 0;
    //friend virtual ostream& operator << (ostream &, const interfaceModel&) = 0;
    //friend virtual interfaceModel makeModel(const string & );
};

class PersonModel
{
public:
    // any firstName   = string();
    // any seckondName = string();
    // any lastName    = string();
    //
    // //think how to use chrono or somth else
    // any  dBirth = static_cast<uint16_t> (0);
    // any  mBirth = static_cast<uint16_t> (0);
    // any  yBirth = static_cast<uint16_t> (0);
    // any sex = static_cast<Sex>(false);

    string firstName;
    string seckondName;
    string lastName;
    short dBirth;
    short mBirth;
    short yBirth;
    Sex sex;

    enum elements : uint16_t
    {
        _firstName = 0,
        _seckondName,
        _lastName,
        _dBirth,
        _mBirth,
        _yBirth,
        _sex
    };

    static uint16_t fildId;

public:
    explicit PersonModel() {}

    PersonModel(const PersonModel &model)
    {
        firstName = model.firstName;
        seckondName = model.seckondName;
        lastName = model.lastName;
        dBirth = model.dBirth;
        mBirth = model.mBirth;
        yBirth = model.yBirth;
        sex = model.sex;
        ;
    }

    ~PersonModel() {}

    friend ostream &operator<<(ostream &os, const PersonModel &obj)
    {
        os << obj.firstName << ';'
           << obj.seckondName << ';'
           << obj.lastName << ';'
           << obj.dBirth << ';'
           << obj.mBirth << ';'
           << obj.yBirth << ';'
           << (obj.sex ? "true" : "false") << ';';
        return os;
    }

    static PersonModel makeModel(string &line, char separator = ';')
    {
        //TODO strip all witespace
        istringstream iss(line);
        PersonModel newModel = PersonModel();

        std::string token;

        std::getline(iss, token, ';');
        newModel.firstName = token;
        std::getline(iss, token, ';');
        newModel.seckondName = token;
        std::getline(iss, token, ';');
        newModel.lastName = token;
        std::getline(iss, token, ';');
        newModel.dBirth = std::stoi(token);
        std::getline(iss, token, ';');
        newModel.mBirth = std::stoi(token);
        std::getline(iss, token, ';');
        newModel.yBirth = std::stoi(token);
        std::getline(iss, token, ';');
        newModel.sex = token == "true" ? true : false;
        return newModel;
    }

    static string getMetaInformation()
    {
        return "firstName;seckondName;lastName;dBirth;mBirth;yBirth;sex;";
    }

    static bool isLess(const PersonModel &l, const PersonModel &r)
    {
        switch (fildId)
        {
        case 0: //firstName
            return l.firstName < r.firstName;
            break;
        case 1: //seckondName
            return l.seckondName < r.seckondName;
            break;
        case 2: //lastName
            return l.lastName < r.lastName;
            break;
        case 3: //dBirth
            return l.dBirth < r.dBirth;
            break;
        case 4: //mBirth
            return l.mBirth < r.mBirth;
            break;
        case 5: //yBirth
            return l.yBirth < r.yBirth;
            break;
        case 6: //sex
            return l.sex < r.sex;
            break;
        default:
            assert(false);
            return 0;
            break;
        }
    }

    static bool isGreat(const PersonModel &l, const PersonModel &r)
    {
        switch (fildId)
        {
        case 0: //firstName
            return l.firstName > r.firstName;
            break;

        case 1: //seckondName
            return l.seckondName > r.seckondName;
            break;
        case 2: //lastName
            return l.lastName > r.lastName;
            break;
        case 3: //dBirth
            return l.dBirth > r.dBirth;
            break;
        case 4: //mBirth
            return l.mBirth > r.mBirth;
            break;
        case 5: //yBirth
            return l.yBirth > r.yBirth;
            break;
        case 6: //sex
            return l.sex > r.sex;
            break;
        default:
            assert(false);
            return 0;
            break;
        }
    }

    static void setAccentField(const string &field)
    {
        if (field == "firstName")
        {
           PersonModel::fildId = PersonModel::elements::_firstName;
        }
        else if (field == "seckondName")
        {
            PersonModel::fildId = PersonModel::elements::_seckondName;
        }
        else if (field == "lastName")
        {
            PersonModel::fildId = PersonModel::elements::_lastName;
        }
        else if (field == "dBirth")
        {
            PersonModel::fildId = PersonModel::elements::_dBirth;
        }
        else if (field == "mBirth")
        {
            PersonModel::fildId = PersonModel::elements::_mBirth;
        }
        else if (field == "yBirth")
        {
            PersonModel::fildId = PersonModel::elements::_yBirth;
        }
        else if (field == "sex")
        {
            PersonModel::fildId = PersonModel::elements::_sex;
        }
        else
        {
            std::cerr << "ATTEMPT TO SORT TABLE BY NOT EXISTING NAME" << endl;
            //TODO rise the error
        }
    }
};

