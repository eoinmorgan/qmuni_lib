#include "net_cookie_jar.h"

using namespace std;


CookieJar::CookieJar(){

	map<string, Poco::Net::HTTPCookie> m_jar;

}

void CookieJar::addCookie(const Poco::Net::HTTPCookie cookie){

	map<string , Poco::Net::HTTPCookie>::iterator jar_it;
	string name = cookie.getName();	
	m_jar[name]=cookie;
}

int CookieJar::sendCookies(){

	// status = 0 a cookie failed to send
	// status = all cookies were sent
	int status = 0;


	return status;
}
int CookieJar::removeExpiredCookies(){
	int cookiesRemoved = 0;
	return cookiesRemoved;
}
