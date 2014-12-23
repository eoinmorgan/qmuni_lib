
#include <string>
#include <map>

#include <Poco/Net/HTTPRequest.h>

using namespace std;

class Net {
public:
	int test;
	Net();
	string httpPost(string path, string &data, map<string, string> &headers);
	string httpPut(string uri, string &data, map<string, string> &headers);
	string httpGet(string uri, map<string, string> &headers);
	string httpDelete(string uri, map<string, string> &headers);
	void getCookie();
private:
	void addHeadersToRequest(Poco::Net::HTTPRequest &request, map<string, string> &headers);
	string httpCall(string call, string path, string &data, map<string, string> &headers);
};

