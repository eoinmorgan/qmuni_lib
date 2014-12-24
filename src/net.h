#include <string>
#include <map>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPRequest.h>

using namespace std;

class Net {
public:
	int httpGet(const string path, map<string, string> *headers, string *responseData) const;
	int httpDelete(const string path, map<string, string> *headers, string *responseData) const;
	int httpPost(const string path, map<string, string> *headers, const string &requestData, string *responseData) const;
	int httpPut(const string path, map<string, string> *headers, const string &requestData, string *responseData) const;
private:
	int httpCall(const string &call, const string &path, map<string, string> *headers, const string &requestData, string *responseData) const;
	void addHeadersToRequest(Poco::Net::HTTPRequest *request, map<string, string> *headers) const;
};
