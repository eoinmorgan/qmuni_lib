#include <Poco/URI.h>
#include <string>

using namespace std;

class Net {

public:
	string http_post(Poco::URI uri, string data);
   	string http_put(Poco::URI uri, string data);
	string http_get(Poco::URI uri);
	string http_delete(Poco::URI uri);
};

