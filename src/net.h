
#include <string>
#include <map>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>

using namespace std;

class Net {
public:
	int test;
	Net();
	istream& httpPost(string path, string &data, map<string, string> &headers);
	istream& httpPut(string uri, string &data, map<string, string> &headers);
	istream& httpGet(string uri, map<string, string> &headers);
	istream& httpDelete(string uri, map<string, string> &headers);
	
	

	void getCookie();
private:
	void addHeadersToRequest(Poco::Net::HTTPRequest &request, map<string, string> &headers);
	istream& httpCall(string call, string path, string &data, map<string, string> &headers);

	bool hasCoookie();
	
};

