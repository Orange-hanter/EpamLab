#include "Rate.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <assert.h>
#include <iostream>

using std::cerr;

using std::for_each;
using std::string;

using json = nlohmann::json;

size_t curlWriteFunc(char *data, size_t size, size_t nmemb, string *buffer)
{
  size_t result = 0;

  if (buffer != NULL)
  {
    buffer->append(data, size * nmemb);
    result = size * nmemb;
  }
  return result;
}


Rate::Rate()
{
    string localAbbr = currencyToStr(localCurrency);
    for( auto&& i : currencySpase::ALL)
    {
        string seck = currencyToStr( i );
        rateMatrix[ pair(localAbbr, seck) ] = 1;
    }

    json jsonObject;

    CURL *curl;
    CURLcode res;
    string curlBuffer;
    char curlErrorBuffer[CURL_ERROR_SIZE];

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curlErrorBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        // переходить по "Location:" указаному в HTTP заголовке
        //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        // не проверять сертификат удаленного сервера
        //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        // использовать метод POST для отправки данных
        //curl_easy_setopt(curl, CURLOPT_POST, 0);
        // параметры POST
        //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, urlPOST);
        // функция, вызываемая cURL для записи полученых данных
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteFunc);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << '\n';

        //here we are fetching data        
        jsonObject = json::parse(curlBuffer);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    string abbr = jsonObject["Cur_Abbreviation"];
    std::transform(abbr.begin(), abbr.end(), abbr.begin(), [](auto c) { return std::toupper(c); });
    double officialRate = jsonObject["Cur_OfficialRate"];
    rateMatrix[pair(localAbbr, abbr)] = officialRate;
    rateMatrix[pair(abbr, localAbbr)] = 1.0 / officialRate;
}

double Rate::rateMultiplayer(string from, string to){
    return rateMatrix[pair(from, to)];
}

double Rate::rateMultiplayer(Currency from, Currency to){
    string sFrom = currencyToStr(from);
    string sTo = currencyToStr(to);
    return rateMatrix[pair(sFrom, sTo)];

}

double Rate::converter(Currency from, Currency to, double summ){
    
    return summ * rateMultiplayer(from, to);
}

double Rate::converter(string from, string to, double summ){
    return summ * rateMultiplayer(from, to);
}


string currencyToStr(Currency type)
{
    string currencyStr;

    switch (type)
    {
    case EUR:
        return "EUR";
        break;
    case RUB:
        return "RUB";
        break;
    case PL:
        return "PL";
        break;
    case BYN:
        return "BYN";
        break;
    case USD:
        return "USD";
        break;
    default:
        assert(true);
        return "";
    };
}

Currency strToCurrency(string str)
{
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
    if (str == "EUR")
        return Currency::EUR;
    else if (str == "RUB")
        return Currency::RUB;
    else if (str == "PL")
        return Currency::PL;
    else if (str == "BYN")
        return Currency::BYN;
    else if (str == "USD")
        return Currency::USD;
    else
    {
        assert(true);
        return Currency::NONE;
    }
    return Currency::NONE;
}