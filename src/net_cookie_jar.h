#include <Poco/Net/HTTPCookie.h>
#include <map>

using namespace std;
class CookieJar{
public:
	CookieJar();
	map<string, Poco::Net::HTTPCookie> m_jar;
	void addCookie(Poco::Net::HTTPCookie cookie);
	int sendCookies();
	int removeExpiredCookies();
private: 

};