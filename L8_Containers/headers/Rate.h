/*
Адрес запроса: https://www.nbrb.by/api/exrates/rates[/{cur_id}]

Параметры (GET):

    ondate** – дата, на которую запрашивается курс (если не задана, то возвращается курс на сегодня)
    periodicity – периодичность установления курса (0 – ежедневно, 1 – ежемесячно)
    parammode – формат аргумента cur_id: 0 – внутренний код валюты, 1 – трехзначный цифровой  код валюты в соответствии со стандартом ИСО 4217, 2 – трехзначный буквенный код валюты (ИСО 4217). По умолчанию = 0

При использовании буквенного или цифрового кода валюты (ИСО 4217) учитывайте его значение на запрашиваемую дату.

Результат: Возвращает массив объектов класса Rate. Если указан cur_id, то возвращается один объект Rate.

Класс Rate содержит следующие свойства:

    Cur_ID – внутренний код
    Date – дата, на которую запрашивается курс
    Cur_Abbreviation – буквенный код
    Cur_Scale – количество единиц иностранной валюты
    Cur_Name – наименование валюты на русском языке во множественном, либо в единственном числе, в зависимости от количества единиц
    Cur_OfficialRate – курс*

Примеры использования:

    получение официального курса белорусского рубля по отношению к иностранным валютам, устанавливаемого ежедневно, на сегодня: https://www.nbrb.by/api/exrates/rates?periodicity=0
    получение официального курса белорусского рубля по отношению к иностранным валютам, устанавливаемого ежедневно, на 6 июля 2016 года: https://www.nbrb.by/api/exrates/rates?ondate=2016-7-6&periodicity=0
    получение официального курса белорусского рубля по отношению к иностранным валютам, устанавливаемого ежемесячно, на 1 июля 2016 года: https://www.nbrb.by/api/exrates/rates?ondate=2016-7-1&periodicity=1
    получение официального курса белорусского рубля по отношению к 1 Доллару США на сегодня: https://www.nbrb.by/api/exrates/rates/145 – по внутреннему коду валюты
    https://www.nbrb.by/api/exrates/rates/840?parammode=1 – по цифровому коду валюты (ИСО 4217)
    https://www.nbrb.by/api/exrates/rates/USD?parammode=2 – по буквенному коду валюты (ИСО 4217)
    получение официального курса белорусского рубля по отношению к 100 Российским рублям на 5 июля 2016 года: https://www.nbrb.by/api/exrates/rates/298?ondate=2016-7-5

*/

#pragma once

#include <string>
#include <map>

using std::string;
using std::pair;
using std::map;


enum Currency : unsigned int
{
    EUR,
    RUB,
    PL,
    BYN,
    USD,
    NONE
};
namespace currencySpase{
    static const Currency ALL[] = {EUR, RUB, PL, BYN, USD, NONE};
}

string currencyToStr(Currency type = NONE);
Currency strToCurrency(string str);

class Rate
{
private:
    map< pair<string,string>, double> rateMatrix;
    Currency localCurrency = Currency::BYN;
    

    string URL = R"(http://nbrb.by/api/exrates/rates/292)";

public:
     Rate();
    ~Rate(){};

    double rateMultiplayer(string from, string to);
    double rateMultiplayer(Currency from, Currency to);

    double converter(string from, string to, double summ);
    double converter(Currency from, Currency to, double summ);
};

