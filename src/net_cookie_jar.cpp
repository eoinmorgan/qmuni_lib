#include "net_cookie_jar.h"

using namespace std;


CookieJar::CookieJar(){

	vector<Poco::Net::HTTPCookie> jar;
}

int CookieJar::addCookie(Poco::Net::HTTPCookie cookie){

	// status = -1 no set cook status found
	// status = 0 set cookie found and matches existing cookie name cookie overwritten 
	// status = 1 set cookie found and does not match any cookies in jar new cookie added
	int status = 0;


	return status;
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
