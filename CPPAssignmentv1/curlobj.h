#ifndef curlobj_hpp
#define curlobj_hpp

#include <stdio.h>
#include <string>
#include <stdlib.h>
//#include "curl/curl.h"


class CurlObj {
public:
	static int curlWriter(char* data, int size, int nmemb, std::string* buffer);
	CurlObj(std::string url);
	std::string getData();
protected:
	//CURL* curl;
	std::string curlBuffer;
};

#endif
