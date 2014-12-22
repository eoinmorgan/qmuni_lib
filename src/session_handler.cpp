#include <string>
#include <vector>
#include <iostream>

#include "session_handler.h"


using namespace std;


SessionHandler::SessionHandler(){
	m_uri = "http://bsecure/api/v0/session";
	
	SessionModel m_session_model(m_uri);
	m_token = "";
	
	
}

SessionHandler::SessionHandler(string uri) {
	m_uri = uri;
	m_token = "";
	SessionModel m_session_model(m_uri);
	
	
}


SessionHandler::SessionHandler(string uri, string token, SessionModel session) {
	m_uri = uri;
	m_token = token;
	m_session_model = session;
	
	
}

string SessionHandler::login(string userName, string code) {
	string result = m_session_model.login(userName, code);
	cout << result << endl;
	return  m_session_model.login(userName, code);
	
	
}

string SessionHandler::getUri() {
	return m_uri;
}

int SessionHandler::setUri(string uri) {
	m_uri = uri;
	
	return 0;
}

