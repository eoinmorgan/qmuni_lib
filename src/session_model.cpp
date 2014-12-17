#include <Poco/URI.h>
#include <string>
#include <vector>
#include <iostream>
#include "http.h"
#include "session_model.h"

using namespace std;

SessionModel() {
	uri = URI uri("http://bsecure/api/v0/session");
	token = "";
	return 0;
}

SessionModel(URI uriIn) {
	uri = uriIn;
	token = "";
	return 0;
}

SessionModel(URI uriIn, string tokenIn) {
	uri = uriIn;
	token = tokenIn;
	SessionModel mod_session = new SessionModel();
	return 0;
}


string Mod::login(string userName, string code){
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}"
	string output = HTTP::net_post(uri, input);

	return output;	
}

