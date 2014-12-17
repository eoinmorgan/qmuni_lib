#include <string>
#include <vector>
#include <iostream>

#include <Poco/URI.h>

#include "session_model.h"
#include "session_handler.h"

using namespace std;

SessionHandler::SessionHandler() {
	URI uri("http://bsecure/api/v0/session");
	
	SessionModel mod_session = SessionModel(uri);
	token = "";

	return 0;
}

SessionHandler::SessionHandler(URI uriIn) {
	uri = uriIn;
	token = "";
	Session mod_session = new Session(uri);

	return 0;
}

SessionHandler::SessionHandler(URI uriIn, string tokenIn) {
	uri = uriIn;
	token = tokenIn;
	Session mod_session = new Session(uri);

	return 0;
}

SessionHandler::SessionHandler(URI uriIn, string tokenIn, Model::Session session) {
	uri = uriIn;
	token = tokenIn;
	mod_session = session;

	return 0;
}

string SessionHandler::login(string userName, string code) {
	//par::encode_string(json_string);
	result = mod_session.login(userName, code);

	return result;
}

URI getUri() {
	return uri;
}

int setUri(URI uriIn) {
	uri = uriIn;
}

