
#include <string>
#include <vector>
#include <iostream>

#include "qmuni.h"
#include "session_handler.h"
#include "conversation_model.h"


using namespace std;

SessionHandler::SessionHandler() {
	// TODO: make this go away, remove it from header and prototype
	m_uri = QAPI_BASE_URI;
	//plan on making it so the session handler is able to acceess and manipulate each of the models it is responsible for.  
	//Map<int,Model::Model> model_list_;
	m_session_model = new SessionModel(m_uri);

	m_token = "";
}

SessionHandler::SessionHandler(string uri) {
	m_uri = uri;
	m_session_model = new SessionModel(m_uri);
	m_token = "";
	//Map<int,Model> model_list_;
	SessionModel m_session_model(m_uri);
}

SessionHandler::~SessionHandler() {
	delete m_session_model;
	m_session_model = NULL;
}

int SessionHandler::login(string email, string code) {
	this->m_session_model->m_uri = m_uri;
	return m_session_model->login(email, code);
}

string SessionHandler::getUri() {
	return m_uri;
}

int SessionHandler::setUri(string uri) {
	m_uri = uri;
	
	return 0;
}
void SessionHandler::debugJson(string json){
m_session_model->debugJson(json);

}
/*
void SessionHandler::fetchConversationList(){
	
	m_session_model->fetchConversationList();

}

*/
