#include <Poco/URI.h>
#include <string>
#include <vector>
#include <iostream>
#include "HTTP/http.h"
#include "session.h"

App::Session(){
	uri = URI uri("http://bsecure/api/v0/session");
	using namespace model
	Session mod_session = new Session();
	token = "";
	return 0;
}

App::Session(URI uirIn) {
	uri = uriIn;
	token = "";
	Session mod_session = new Session();
	return 0;
}

App::Session(UIR uriIn, string tokenIn){
	uri = uirIn;
	token = tokenIn;
	Session mod_session = new Session();
	return 0;
}
App::Session(UIR uriIn, string tokenIn, Model::Session session){
	uri = uirIn;
	token = tokenIn;
	mod_session = session;
	return 0;
}


string App :: login(string userName, string code){
	//keeping until i write model session code string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}"
	//par::encode_string(json_string);
	result = mod_session.login(userName, code);
	
	
	return result;
}

URI App :: getUri(){
	return uir;
}

int App :: setUri(Uri uriIn){
	uri = uriIn;
}