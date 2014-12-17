#include <string>
#include <vector>
#include <iostream>

#include <Poco/URI.h>

using namespace std;
using namespace Poco;

class Session {
public:
	Session();
	Session(URI uri);

	int login(string user_name, string code);

	URI getUri();
	int setUri(URI uri);
private:
	string token;
	URI uri;
};

