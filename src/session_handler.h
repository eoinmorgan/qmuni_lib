#include <string>
#include <vector>
#include <iostream>

#include <Poco/URI.h>

#include "session_model.h"

using namespace std;

class SessionHandler {
public:
	SessionHandler(){}
	SessionHandler(Poco::URI uri){}
	SessionHandler(Poco::URI uriIn, string tokenIn, SessionModel session);

	int login(string user_name, string code);

	Poco::URI getUri();
	int setUri(Poco::URI uri);
private:
	string m_token;
	Poco::URI m_uri;
};

