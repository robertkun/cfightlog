#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

int http_post(const char* postMsg) {
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.99.100:8080");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postMsg);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postMsg));

		res = curl_easy_perform(curl);
		if(res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			return -1;
		}

		curl_easy_cleanup(curl);
	} else {
		return -1;
	}

	return 0;
}