#include <string>
#include <vector>
#include <iostream>

#include "session_model.h"

using namespace std;

class SessionHandler {
public:
	SessionHandler();
	SessionHandler(string uri);
	SessionHandler(string uriIn, string token, Model session);


	~SessionHandler();


	int login(string userName, string code);
	string getUri();
	int setUri(string uri);

	SessionModel *m_session_model;

	void debugJson();
private:
	string m_token;
	string m_uri;
	
};

