#include "Rate.h"
#include "Currency.h"
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
    string mainAbbreviature = currencyToStr(Currency::BYN);
    for( auto&& i : currencySpase::ALL)
    {
        string seck = currencyToStr( i );
        rateMatrix[ pair(mainAbbreviature, seck) ] = 1;
    }

    json jsonObject;
    char curlErrorBuffer[CURL_ERROR_SIZE];
    const char *urlPOST = "";
    CURL *curl;
    CURLcode res;
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
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        //here we are fetching data        
        cerr << curlBuffer;
        jsonObject = json::parse(curlBuffer);

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

        /*  TODO: доделать сбор всех курсов валют
        for (auto &el : array_not_object.items())
        {
            //std::cout << el.key() << " : " << el.value() << "\n";
        }
        */
    
    // TODO: make parsed abbreviation uppercase
    string Cur_Abbreviation = jsonObject["Cur_Abbreviation"];
    double Cur_OfficialRate = jsonObject["Cur_OfficialRate"];
    rateMatrix[pair(mainAbbreviature, Cur_Abbreviation)] = Cur_OfficialRate;
}

double Rate::convertKoeff(string from, string to){
    return rateMatrix[pair(from, to)];
}