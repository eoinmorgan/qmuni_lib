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
	cout << "good construct " << m_uri << endl; 
	SessionModel m_session_model(m_uri);
	
	
}


string SessionHandler::login(string userName, string code) {
	return  this->m_session_model.login(userName, code);
	
	
}

string SessionHandler::getUri() {
	return m_uri;
}

int SessionHandler::setUri(string uri) {
	m_uri = uri;
	
	return 0;
}

