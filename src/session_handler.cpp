#include <string>
#include <vector>
#include <iostream>

#include "session_handler.h"


using namespace std;


SessionHandler::SessionHandler(){
	m_uri = "http://bsecure/api/v0/session";
	cout << "bad construct" << endl;
	SessionModel m_session_model(m_uri);
	m_token = "";
	
	
}

SessionHandler::SessionHandler(string uri) {
	
	m_uri = uri;
	m_token = "";
	SessionModel m_session_model(m_uri);
	
	
}


int SessionHandler::login(string userName, string code) {
	 this->m_session_model.m_uri = m_uri;
	return  m_session_model.login(userName, code);
	
	
}

string SessionHandler::getUri() {
	return m_uri;
}

int SessionHandler::setUri(string uri) {
	m_uri = uri;
	
	return 0;
}

