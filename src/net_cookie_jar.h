#pragma once

#include <map>

#include "Poco/Net/HTTPCookie.h"

using namespace std;

class CookieJar {
public:
	CookieJar();
	map<string, Poco::Net::HTTPCookie> m_jar;
	void addCookie(Poco::Net::HTTPCookie cookie);
	Poco::Net::NameValueCollection sendCookies();
	int removeExpiredCookies();
	string printf();
	bool empty();
};
