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
<<<<<<< HEAD
	SessionModel m_session_model;
	int login(string userName, string code);
=======
	~SessionHandler();
>>>>>>> e8629fb8ab58273b883403033198a95d670b0270

	string login(string userName, string code);
	string getUri();
	int setUri(string uri);

	SessionModel *m_session_model;
private:
	string m_token;
	string m_uri;
	
};

