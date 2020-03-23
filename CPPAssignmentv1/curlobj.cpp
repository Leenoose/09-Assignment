#include "curlobj.h"

int CurlObj::curlWriter(char* data, int size, int nmemb, std::string* buffer) {
	int result = 0;
	if (buffer != NULL) {
		buffer->append(data, size * nmemb);
		result = size * nmemb;
	}
	return result;
}

CurlObj::CurlObj(std::string url) {
	curl = curl_easy_init();
	if (!curl) {
		throw std::string("Curl did not initialize.");
	}

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_perform(curl);
};

std::string CurlObj::getData() {
	return curlBuffer;
}
