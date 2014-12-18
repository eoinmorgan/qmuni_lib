#include <string>
#include <vector>
#include <iostream>

#include "session_model.h"

using namespace std;

class SessionHandler {
public:
	SessionHandler(){}
	SessionHandler(string uri){}
	SessionHandler(string uriIn, string token, SessionModel session);

	int login(string user_name, string code);

	string getUri();
	int setUri(string uri);
private:
	string m_token;
	string m_uri;
	
};

