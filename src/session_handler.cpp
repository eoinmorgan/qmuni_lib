#include <string>
#include <vector>
#include <iostream>

#include "session_handler.h"


using namespace std;


SessionHandler::SessionHandler() {
	m_uri = "http://bsecure/api/v0/session";
	m_session_model = new SessionModel(m_uri);
	m_token = "";
}

SessionHandler::SessionHandler(string uri) {
	
	m_uri = uri;
	m_session_model = new SessionModel(m_uri);
	m_token = "";

	SessionModel m_session_model(m_uri);
	
	

}

SessionHandler::~SessionHandler() {
	delete m_session_model;
	m_session_model = NULL;
}


int SessionHandler::login(string userName, string code) {
	 this->m_session_model->m_uri = m_uri;
	return  m_session_model->login(userName, code);
	
}

string SessionHandler::getUri() {
	return m_uri;
}

int SessionHandler::setUri(string uri) {
	m_uri = uri;
	
	return 0;
}
void SessionHandler::debugJson(){
	const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416} ";
	m_session_model->decodeJson(json);
	m_session_model->debugJson();
}

