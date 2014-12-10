#include <curl/curl.h>
#include <4DPlugin.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
    
}

int curlTest(void) {
	CURL *curl;
	CURLcode res;

	cout << "BSecure Client Library Test" << endl;
	cout << "###########################" << endl << endl;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://cweil.com/");
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	cout << endl;

	return EXIT_SUCCESS;
}

