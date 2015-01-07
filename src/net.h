#pragma once
#include <string>
#include <map>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>

#include "net_cookie_jar.h"

using namespace std;


class Net {
private:
	Net();
	Net(Net const&){};
	//Net &operator=(Net const&){};
	int httpCall(const string &call, const string &path, map<string, string> *headers, const string &requestData, string *responseData) ;
	void addHeadersToRequest(Poco::Net::HTTPRequest *request, map<string, string> *headers) ;	
	//Vector<Poco::Net::HTTPCookie> Net::getRequestCookies(const &Poco::Net::HTTPRequest request);
	static Net *instance_;
	CookieJar *jar_;
public:
	static Net *Instance();
	int httpGet(const string path, map<string, string> *headers, string *responseData) ;
	int httpDelete(const string path, map<string, string> *headers, string *responseData) ;
	int httpPost(const string path, map<string, string> *headers, const string &requestData, string *responseData) ;
	int httpPut(const string path, map<string, string> *headers, const string &requestData, string *responseData) ;
	string printf();
};
