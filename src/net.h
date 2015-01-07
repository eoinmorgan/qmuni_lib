#pragma once
#include <string>
#include <map>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>

#include "net_cookie_jar.h"

using namespace std;


class Net {
public:
	Net();
	CookieJar *m_jar;
	static int httpGet(const string path, map<string, string> *headers, string *responseData) ;
	static int httpDelete(const string path, map<string, string> *headers, string *responseData) ;
	static int httpPost(const string path, map<string, string> *headers, const string &requestData, string *responseData) ;
	static int httpPut(const string path, map<string, string> *headers, const string &requestData, string *responseData) ;
	string printf();
private:
	int httpCall(const string &call, const string &path, map<string, string> *headers, const string &requestData, string *responseData) ;
	static void addHeadersToRequest(Poco::Net::HTTPRequest *request, map<string, string> *headers) ;	
	//Vector<Poco::Net::HTTPCookie> Net::getRequestCookies(const &Poco::Net::HTTPRequest request);
};
