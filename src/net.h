
#include <string>

using namespace std;

class Net {

public:
	string http_post(string uri, string data);
   	string http_put(string uri, string data);
	string http_get(string uri);
	string http_delete(string uri);
};

