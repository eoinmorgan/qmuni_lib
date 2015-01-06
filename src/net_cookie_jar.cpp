#include <string>
#include <iostream>
#include <map>

#include "net_cookie_jar.h"
#include "Poco/Net/NameValueCollection.h"

using namespace std;


CookieJar::CookieJar(){

	 m_jar = map<string, Poco::Net::HTTPCookie>();
	

}

void CookieJar::addCookie(const Poco::Net::HTTPCookie cookie){

	map<string , Poco::Net::HTTPCookie>::iterator jar_it;
	string name = cookie.getName();	
	m_jar[name]=cookie;
}

Poco::Net::NameValueCollection CookieJar::sendCookies(){

	// status = 0 a cookie failed to send
	// status = all cookies were sent
	int status = 0;
	Poco::Net::NameValueCollection result;
	std::map<string, Poco::Net::HTTPCookie>::iterator cookie_iterator = m_jar.begin();
	for(; cookie_iterator != m_jar.end(); ++cookie_iterator){
		result.add(cookie_iterator->second.getName(), cookie_iterator->second.getValue());
		// DEBUG:
		// cerr << "sent cookie: " << cookie_iterator->second.getName() << endl;
	}


	return result;
}
int CookieJar::removeExpiredCookies(){
	int cookiesRemoved = 0;
	return cookiesRemoved;
}
bool CookieJar::empty(){

	 bool result = m_jar.empty();

	return result;	
}

/*
vector<Poco::Net::HTTPCookie> Net::getRequestCookies(const &Poco::Net::HTTPRequest request)
{
	 Poco::URI uri = request.
	 vector<Poco::Net::HTTPCookie> cookies;


	return cookies;
}
*/

string CookieJar::printf(){
	string result="";
	for(map<string, Poco::Net::HTTPCookie>::iterator it = m_jar.begin(); it != m_jar.end(); ++it) {

		result = result + it->first;
	}

	return result;
}
