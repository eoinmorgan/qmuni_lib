#include <Poco/URI.h>
#include <string>
#include <vector>
#include <iostream>
#include "http.h"
#include "session_model.h"

using namespace std;

SessionModel() {
	m_uri = Poco::URI uri("http://bsecure/api/v0/session");
	m_token = "";
	return 0;
}

SessionModel(Poco::URI uriIn) {
	m_uri = uriIn;
	m_token = "";
	return 0;
}

SessionModel(Poco::URI uriIn, string tokenIn) {
	m_uri = uriIn;
	m_token = tokenIn;
	SessionModel mod_session = new SessionModel();
	return 0;
}


string login(string userName, string code){
	string input = "{\"email\":\""+userName+"\",\"code\":\""+code+"\"}"
	string output = HTTP::net_post(uri, input);

	return output;	
}

