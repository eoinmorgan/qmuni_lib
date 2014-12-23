#include <Poco/net>
#include <Vector>


class CookieJar{
public:
	CookJar();
	Vector<HTTPCookie> jar;
	int addCookie(Poco::HTTPCookie cookie);
	int sendCookies();
	int removeExpiredCookies();
private: 

};