#include <string>
#include <vector>
#include <iostream>

#include <Poco/URI.h>

#include "session_handler.h"

using namespace std;


SessionHandler(){
	URI m_uri("http://bsecure/api/v0/session");
	
	SessionModel mod_session(m_uri);
	SessionHandler m_token = "";
	
	return 0;
}

SessionHandler(URI uriIn) {
	SessionHandler m_uri = uriIn;
	SessionHandler m_token = "";
	Session mod_session(m_uri);
	
	return 0;
}

SessionHandler(URI uriIn, string tokenIn) {
	SessionHandler m_uri = uriIn;
	SessionHandler m_token = tokenIn;
	Session mod_session = new Session(m_uri);
	
	return 0;
}

SessionHandler(URI uriIn, string tokenIn, SessionModel session) {
	SessionHandler m_uri = uriIn;
	SessionHandler m_token = tokenIn;
	mod_session = session;
	
	return 0;
}

string login(string userName, string code) {
	//par::encode_string(json_string);
	result = mod_session.login(userName, code);
	
	return result;
}

Poco::URI getUri() {
	return m_uri;
}

int setUri(Poco::URI uriIn) {
	m_uri = uriIn;
}

