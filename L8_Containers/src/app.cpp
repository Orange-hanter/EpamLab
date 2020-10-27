#include <iostream>
#include <string>
#include <assert.h>

#include <nlohmann/json.hpp>
#include <curl/curl.h>

using std::istream;
using std::ostream;

using std::cin;
using std::cout;

using std::for_each;
using std::string;

using json = nlohmann::json;

std::string curlBuffer;
size_t curlWriteFunc(char *data, size_t size, size_t nmemb, std::string *buffer)
{
  size_t result = 0;

  if (buffer != NULL)
  {
    buffer->append(data, size * nmemb);
    result = size * nmemb;
  }
  return result;
}

int main(int argc, char const *argv[])
{
  json array_not_object;
  char curlErrorBuffer[CURL_ERROR_SIZE];
  const char *urlPOST = "";
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if (curl)
  {
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curlErrorBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.nbrb.by/api/exrates/rates/292");
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
    array_not_object = json::parse(curlBuffer);
    cout << array_not_object["Cur_Abbreviation"];
    for (auto& el : array_not_object.items()) {
       std::cout << el.key() << " : " << el.value() << "\n";
    }
    std::cerr << curlErrorBuffer;
    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();



  //  Bill pocket;
  //  cin >> pocket;
  // cout << array_not_object.dump() << std::endl;
  return EXIT_SUCCESS;
}
