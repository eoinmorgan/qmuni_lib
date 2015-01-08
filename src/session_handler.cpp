
#include <string>
#include <vector>
#include <iostream>

#include "qmuni.h"
#include "session_handler.h"
#include "conversation_model.h"
#include "net.h"


using namespace std;

SessionHandler::SessionHandler() {
	// TODO: make this go away, remove it from header and prototype
	uri_ = QAPI_BASE_URI + "/session/";
	//plan on making it so the session handler is able to acceess and manipulate each of the models it is responsible for.  
	//Map<int,Model::Model> model_list_;
	session_model_ = new SessionModel();
	m_token = "";
}

SessionHandler::SessionHandler(string uri) {
	uri_ = uri;
	session_model_ = new SessionModel(uri_);
	m_token = "";
	//Map<int,Model> model_list_;
	SessionModel session_model_(uri_);
}

SessionHandler::~SessionHandler() {
	delete session_model_;
	session_model_ = NULL;
}

string SessionHandler::getUri() {
	return uri_;
}

int SessionHandler::setUri(string uri) {
	uri_ = uri;
	
	return 0;
}
void SessionHandler::debugJson(string json){
session_model_->debugJson(json);

}
int SessionHandler::login(string email, string code) {
	session_model_->setEmail(email);
	session_model_->setCode(code);
	return session_model_->save();
}




void SessionHandler::fetchConversationList(){
	
	map<string, string> noHeaders;
	string conversation_uri = QAPI_BASE_URI + "/conversation/";
	
	int status_code = 0;
	string *output = new string();
	// DEBUG:
	//cerr << "URI IS ME:" << uri_ << endl;

	// TODO: this should be in the base model
	status_code = Net::Instance()->httpGet(conversation_uri, &noHeaders, output);

	// DEBUG:
	//cerr << "status code: " << status_code << endl;
	if (status_code == 200 ) {
		session_model_->parseJson(*output);		
	}

	// TODO:
	// fix printf method
	// cerr << net->printf();
	delete output;
	output = NULL;

}

string SessionHandler::printf(){
	return Net::Instance()->printf();
}


