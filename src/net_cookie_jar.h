#include <Poco/Net/HTTPCookie.h>
#include <Vector>

using namespace std;
class CookieJar{
public:
	CookieJar();
	vector<Poco::Net::HTTPCookie> jar;
	int addCookie(Poco::Net::HTTPCookie cookie);
	int sendCookies();
	int removeExpiredCookies();
private: 

};