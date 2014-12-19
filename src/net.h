
#include <string>
#include <map>

#include <Poco/Net/MessageHeader.h>



using namespace std;


class Net {

public:

	string http_post(string path, string data, map<string, string> *headers);
	
	
	string http_put(string uri, string data, map<string, string> *headers);
	
	
	string http_get(string uri, string data, map<string, string> *headers);
	
	
	string http_delete(string uri, map<string, string> *headers);
private:
	
	int editHeader(Poco::Net::MessageHeader header, map<string, string> headers);
	string http_call(string call, string path, string *data, map<string, string> *headers);
};

